#include <QApplication>
#include <QtCore/QSharedPointer>
#include <QDesktopWidget>
#include <QMessageBox>
#include <QFileDialog>
#include <QStyleFactory>
#include <QSysInfo>
#include <QtNetwork/QNetworkInterface>

#include <iostream>
#include <memory>

#include <odb/database.hxx>
#include <odb/transaction.hxx>
#include <odb/pgsql/database.hxx>

#include "include/produits.h"
#include "include/ventes.h"
#include "include/personnels.h"
#include "include/docsrelances.h"

#include "gui/models.h"
#include "gui/views.h"
#include "gui/mainwindow.h"
#include "gui/salesdialog.h"
//#include "gui/sessionmanager.h"


#define PGSQL 0
#define MYSQL 1
#define SQLITE 2

using namespace std;
using namespace odb::core;

constexpr int NBARTICLES = 10;
constexpr int QTE = 10;
constexpr ulong NBSORTIES {500000};
constexpr int ARRONDI = 25;  //All the prices are multiple of 25 CFA by default
constexpr int COEF = 1;  //Default minimum benefit by product 0% , sell price = PPCM(buy price x COEF,ARRONDI)

ostream& operator<< (ostream& os, const QString& s)
{
  return os << s.toStdString();
}

void set_con_params(int& argc ,char *argv[]);
void sellGoods(int argc ,char **argv);
void setupApplication();
void odbConnect();
void loadFromCSV();
void saveToCSV();
using Model = AbstractODBModel;

int main(int argc, char *argv[])
{
   try
    {
        QApplication app(argc, argv);
        QSharedPointer<odb::database> salespoint {new  odb::pgsql::database("salespoint","d0rc4566","salespoint","localhost",5432)};
        AbstractODBModel::DB = salespoint;
        setupApplication();
        session s;

        QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
        db.setDatabaseName("salespoint");
        db.setUserName("salespoint");
        db.setPassword("d0rc4566");
        db.setHostName("localhost");
        db.setPort(5432);
        for(auto netiface : QNetworkInterface::allInterfaces()){
            if(netiface.flags() == QNetworkInterface::IsRunning) qDebug() << netiface.name() << ": " <<netiface.hardwareAddress();
         }

        if (!db.open()){
            //QMessageBox::information(&mw ,qApp->applicationName(),db.lastError().text());
            qApp->exit(EXIT_FAILURE);
        }

//        MainWindow mw(false);
//        QAbstractItemModel* productmodel;
//        QDialog* product = mw.makeProductManagementTab(&productmodel);
//        QDialog* sales = mw.makeSalesManagementTab(productmodel);

//        mw.addWidget(sales);
//        mw.addWidget(mw.makeReportManagementTab());
//        mw.addWidget(product);

//        mw.addWidget(mw.makeStockManagementTab());
//        mw.addWidget(mw.makeAccountingManagementTab());
//        mw.addWidget(mw.makeProfileManagementTab());
//        mw.setWindowTitle(app.applicationName());

//        mw.showMaximized();
//        app.exec();

        MainWindow mw;
        mw.setWindowTitle(app.applicationName());

//        SessionManager smanager(&mw);
//        smanager.login(AbstractODBModel::DB);

//        if(smanager.loginSucceded()){
//            mw.setupUserSession(smanager.user());
//        }

        mw.showMaximized();
        app.exec();
        db.close();
    }
   catch (const std::exception& e)
   {
       qDebug() << e.what();
       qApp->exit(EXIT_FAILURE);
   }
}

void set_con_params(int& argc, char *argv[]){
    argv[1] = const_cast<char*>("--user");
    argv[2] = const_cast<char*>("salespoint");
    argv[3] = const_cast<char*>("--database");
    argv[4] = const_cast<char*>("salespoint");
    argv[5] = const_cast<char*>("--password");
    argv[6] = const_cast<char*>("d0rc4566");
    argv[7] = const_cast<char*>("--host");
    argv[8] = const_cast<char*>("localhost");
    argv[9] = const_cast<char*>("--port");
    argv[10] = const_cast<char*>("5432");
    argc = 11 ;
}

void setupApplication(){
    QApplication::setApplicationName("SalesPointi7");
    QApplication::setApplicationVersion("1.0.0");
    QApplication::setOrganizationName("Inteligy Software Entreprise(®)");
    QApplication::setOrganizationDomain({"www.inteligyware.com"});
    QApplication::setQuitOnLastWindowClosed(true);
    QApplication::setStyle(QStyleFactory::create("Fusion"));
}
void odbConnect(){
    try
    {
        QSharedPointer<odb::database> db {new  odb::pgsql::database("salespoint","d0rc4566","salespoint","localhost",5432)};
        session s;

     }

    catch (const odb::exception& excp)
    {
        cout << excp.what () << endl;
        qApp->exit(EXIT_FAILURE);
    }
}

void loadFromCSV(){
//    QString filename_produit = QFileDialog::getOpenFileName(Q_NULLPTR,QObject::tr("Import de Catalogue de Produit"),
//            QDir::currentPath(),
//            QObject::tr("Fichier CSV (*.csv)"),
//            Q_NULLPTR) ;

//    QString filename_famille = QFileDialog::getOpenFileName(Q_NULLPTR,QObject::tr("Import de Catalogue de Famille"),
//            QDir::currentPath(),
//            QObject::tr("Fichier CSV (*.csv)"),
//            Q_NULLPTR) ;

    QFile file_produit{"bd_santa_lucia.csv"};
    QFile file_familles{"famille_produit.csv"};

    if(file_produit.open(QIODevice::ReadOnly | QIODevice::Text)
            && file_familles.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QStringList items;
        QString line;

        QTextStream instream_familles(&file_familles);
        QVector<QString> ref_familles;
        QVector<SPFamille> familles;
        while(instream_familles.readLineInto(&line))
        {
           items = line.trimmed().split(QRegExp(";"));
           QString reference = items.takeFirst();
           QString libele = items.takeFirst();
           std::cout << " reference :  " << reference.toStdString() << "\n";

           ref_familles.push_back(reference);
           familles.push_back(SPFamille(new Famille(reference,libele)));

        }

        {
           try
            {
                transaction t(Model::DB->begin());
                    for(auto famille: familles)
                        Model::DB->persist(famille);
                t.commit();
            }
            catch (const odb::exception& excp)
            {
                 cout << excp.what () << endl;
            }
        }

        QTextStream instream_produit(&file_produit);
        instream_produit.setCodec("ISO-8859-15");
        QString reference, libele , famille, prix_achat, prix_vente, codebare;
        QVector<SPArticle> articles;
        QVector<QString> libeles;
        int i = 0;
        while(instream_produit.readLineInto(&line))
        {
           i++;
           items = line.trimmed().split(QRegExp(";"));
           reference = items.takeFirst().trimmed();
           libele = items.takeFirst().trimmed();

           if(libeles.contains(libele)){
               std::cout << i << " :  " << libele.toStdString() << "\n";
               continue;
           }
           else
               libeles.push_back(libele);

           famille = items.takeFirst();
           prix_achat = items.takeFirst(); //think to convert to float
           prix_vente = items.takeFirst(); //think to convert to long
           codebare = items.takeFirst().simplified();

           if(ref_familles.contains(famille))
           {
               SPArticle article{new Article(familles.at(ref_familles.indexOf(famille)), libele , 1)};
               articles.push_back(article);
               article->setPrixAchatMoy(prix_achat.toDouble());
               article->setPrixVente(prix_vente.toLong());
               article->setCodebare(codebare);
               article->setReference(reference);
               try
               {
                    transaction t(Model::DB->begin());
                       Model::DB->persist(article);
                    t.commit();
               }
               catch (const odb::exception& excp)
               {
                    cout << excp.what () << endl;
               }
           }
        }
    }
}

void saveToCSV(){
    QString filename = QFileDialog::getOpenFileName(
            Q_NULLPTR,
            QObject::tr("Pick a File"),
            QDir::currentPath(),
            QObject::tr("text files (*.txt *.log)"),
            Q_NULLPTR) ;

    QFile input_file{filename};
    QFile output_file{"bd_santa_lucia.csv"};

    if(input_file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        output_file.open(QIODevice::WriteOnly | QIODevice::Text);
        QTextStream instream(&input_file);
        QTextStream outstream(&output_file);

        instream.setCodec("ISO-8859-15");     
        outstream.setCodec(instream.codec());
        QString tmp,line, libele , famille, last ,
                prix_achat, prix_vente, codebare;
        int i = 0;
        while(instream.readLineInto(&line))
        {
           i++;
           QStringList items = line.trimmed().split(QRegExp("\\s{7,}"));

           if(items.size() < 4)
           {
              libele = items.takeAt(1);
              famille = libele.right(2);
              libele.chop(2);
              items.insert(1,libele.trimmed());
              items.insert(2,famille);
           }

           last = items.takeLast();
           QStringList lasts = last.split(QRegExp("\\s+"));
           prix_achat = lasts.takeFirst();
           items.append(prix_achat);
           tmp = lasts.takeFirst();
           QStringList bares = tmp.split(QRegExp(","));
           prix_vente = bares.takeFirst();
           items.append(prix_vente);
           codebare  = bares.takeFirst();
           codebare = codebare.right(codebare.size() - 6);
           items.append(codebare);
           if(codebare.size() > 13 || codebare.contains(QRegExp("\\D")))
               std::cout << "Line: " << i << " bd " << i + 4179
                         << " codebare :  " << codebare.toStdString() << "\n";

           outstream << items.takeFirst();
           while(!items.isEmpty()){
                QString item = items.takeFirst();
                outstream << item.prepend(";") ;
           }
           outstream << "\n";
        }
    }
}

//void sellGoods(int argc, char **argv)
//{
//    try
//    {
//       unique_ptr<database> db { new odb::pgsql::database(argc,argv)};
//       {
//           Produit::setArrondi(ARRONDI);
//           Produit::setCoef(COEF);

//           qsrand(QTime::currentTime().msecsSinceStartOfDay());

//           ulong total_echange{0} ;
//           ulong total_destockage{0};
//           ulong nbproduits{0} ;
//           ulong nbechanges{0} ;
//           ulong nbdestockages{0} ;
//           ulong nbsorties {qrand() % NBSORTIES };

//           using  spProduit = QSharedPointer<Produit>;
//           using  spPersonnel = QSharedPointer<Personnel>;
//           using  spFournisseur = QSharedPointer<Fournisseur>;

//           //using spSortie = QSharedPointer<Sortie>;
//           using  spDestockage = QSharedPointer<Destockage>;
//           using  spEchangeSortie = QSharedPointer<EchangeSortie>;
//           using  spDetailsSortie = QSharedPointer<DetailsSortie>;
//           using  spFacture = QSharedPointer<Facture>;

//           using  spDetails = QVector<spDetailsSortie>;
//           using  wpDetails = spDetails;

//           QVector<spProduit> produits;
//           QVector<spPersonnel> vendeurs;
//           QVector<spPersonnel> magasiniers;
//           QVector<spFournisseur> fournisseurs;

//           //session s;
//           transaction t (db->begin ());
//           //t1.tracer (stderr_tracer);

//           {
//                using ResultMed = odb::result<Medicament>;
//                ResultMed rMed {db->query<Medicament>()};

//                for( auto iMed = rMed.begin() ; iMed != rMed.end() ; ++iMed )
//                    produits.push_back(( spProduit) iMed.load());
//                nbproduits = produits.size();
//           }

//           {


//                using  ResultPers = odb::result<Personnel>;
//                ResultPers rVend {db->query<Personnel>(odb::query<Personnel>::fonction == "Vendeur")};

//                for( auto iVend = rVend.begin() ; iVend != rVend.end() ; ++iVend )
//                     vendeurs.push_back(( spPersonnel) iVend.load());

//                 ResultPers rMag {db->query<Personnel>(odb::query<Personnel>::fonction == "Magasinier")};

//                 for( auto iMag = rMag.begin(); iMag != rMag.end() ; ++iMag )
//                     magasiniers.push_back(( spPersonnel) iMag.load());

//                 using  ResultFour = odb::result<Fournisseur>;
//                 ResultFour rFour (db->query<Fournisseur>());
//                 for( auto iFour = rFour.begin() ; iFour != rFour.end() ; ++iFour )
//                      fournisseurs.push_back(( spFournisseur) iFour.load());
//           }

//           t.commit();

//           if ( !produits.isEmpty() && (( !vendeurs.isEmpty() && !fournisseurs.isEmpty() ) || !magasiniers.isEmpty() ))
//           for( ulong j = 0 ; j < nbsorties ; j++ )
//           {
//               ulong n = qrand() %  NBARTICLES;
//               if (n > 0 )
//               {
//                   if(  qrand() % 2 == 0  && !vendeurs.isEmpty() && !fournisseurs.isEmpty() )
//                   {
//                      spEchangeSortie spEchangeSorite0 ( new EchangeSortie(vendeurs[qrand() % vendeurs.size() ] , fournisseurs[qrand() % fournisseurs.size() ]  , 1.15 ));

//                      for( ulong k = 0 ; k < n ; k++ )
//                         spEchangeSorite0->addDetails( produits[qrand() % nbproduits] , qrand() % QTE);


//                      total_echange += spEchangeSorite0->getMontant();
/*                      cout << ++nbechanges << " ) " << typeid(*(spEchangeSorite0)).name() << " nb : " \
                           << spEchangeSorite0->getDetails().size() << "  Vendeur : " \
                           << spEchangeSorite0->getResponsable()->getNoms() << " " \
                           << spEchangeSorite0->getResponsable()->getPrenoms() << "  Date : " \
                           << spEchangeSorite0->getDate().toString(Qt::RFC2822Date) << "  Montant : " \
                          << spEchangeSorite0->getMontant() << " FCFA" << endl;
*/
//                      spFacture spFacture0 (new Facture(spEchangeSorite0));
//                      spEchangeSorite0->setFacture(spFacture0);

//                      //Make facture and  echange persistent

//                      transaction t (db->begin ());
//                      //t2.tracer (stderr_tracer);

//                      db->persist(spFacture0);
//                      db->persist(spEchangeSorite0);

//                      wpDetails wpDetails0 (spEchangeSorite0->getDetails());

//                      foreach (auto det, wpDetails0)
//                      {
/*                          cout << det->getProduit()->getId() << " - " \
                               << det->getProduit()->getLibele() << " " \
                               << det->getQte() << " " \
                               << det->getProduit()->getPrixVente() << " " \
                               << det->getMontant() << endl;
*/
//                           //Make the details persistent
//                           db->persist( det );
//                      }
//                      cout << endl;
//                      t.commit();
//                    }

//                else if(!magasiniers.isEmpty())
//                {
//                    spDestockage spDestockage0 ( new Destockage( magasiniers[qrand() % magasiniers.size()] ));

//                    for( ulong k = 0 ; k < n ; k++ )
//                       spDestockage0->addDetails( produits[qrand() % nbproduits] , qrand() % QTE);

//                    total_destockage += spDestockage0->getMontant();
/*                    cout << ++nbdestockages << " ) " << typeid(*(spDestockage0)).name() << " nb : " \
                         << spDestockage0->getDetails().size() << "  Magasinier : " \
                         << spDestockage0->getResponsable()->getNoms() << " " \
                         << spDestockage0->getResponsable()->getPrenoms() << "  Date : " \
                         << spDestockage0->getDate().toString(Qt::RFC2822Date) << "  Montant : " \
                         << spDestockage0->getMontant() << " FCFA" << endl;
*/

//                    //Make destockage persistent

//                    transaction t (db->begin ());
//                    //t2.tracer (stderr_tracer);
//                    db->persist(spDestockage0);

//                    wpDetails wpDetails0 ( spDestockage0->getDetails());
//                    foreach (auto det, wpDetails0)
//                    {

/*                        cout << det->getProduit()->getId() << " - " \
                             << det->getProduit()->getLibele() << " " \
                             << det->getQte() << " " \
                             << det->getProduit()->getPrixVente() << " " \
                             << det->getMontant() << endl;
*/
//                        //Make the details persistent
//                        db->persist( det );
//                    }
//                    cout << endl;
//                    t.commit();
//                 }
//              }
//           }
//           cout << "Echanges  " << nbechanges << " : " << total_echange << " FCFA" << endl;
//           cout << "Destockages " << nbdestockages << " : " << total_destockage << " FCFA" << endl;
//           cout << "Total " << nbechanges + nbdestockages << " : " << total_destockage + total_echange << " FCFA" <<endl;
//       }
//    }

//    catch (const odb::exception& excp)
//    {
//      cerr << excp.what () << endl;
//      qApp->exit(EXIT_FAILURE);
//    }
//}

//int main(int argc, char *argv[])
//{
//    try{
//        QApplication app(argc, argv);
//        QSharedPointer<odb::database> db {new  odb::pgsql::database("salespoint","d0rc4566","salespoint","localhost",5432)};
//        Model::DB = db;
////        convertToCSV();
//        importFromCSV();
//        session s;
//        app.exec();
//    }
//    catch (const odb::exception& excp)
//    {
//         cout << excp.what () << endl;
//         qApp->exit(EXIT_FAILURE);
//    }
//}

//int main(int argc, char *argv[])
//{
//   try
//    {
//        QApplication app(argc, argv);
//        QSharedPointer<odb::database> db {new  odb::pgsql::database("salespoint","d0rc4566","salespoint","localhost",5432)};
//        IAbstractDataModel::DB = db;
//        configApp(app);
//        session s;
//        SalesDialog sdlg;
//        sdlg.setWindowTitle(app.applicationName());
//        sdlg.showMaximized();
//        app.exec();
//    }
//   catch (const odb::exception& excp)
//   {
//       cout << excp.what () << endl;
//       qApp->exit(EXIT_FAILURE);
//   }
//}
