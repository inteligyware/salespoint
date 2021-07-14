#include "sessionmanager.h"
#include <QString>

SessionManager::SessionManager(QWidget *parent) : QDialog(parent)
{
    setupUi(this);
    ledt_login_->setValidator(new QRegExpValidator(QRegExp("([a-z]*[0-9]*[A-Z]*)*") , ledt_login_));
    connect(btn_connect_, SIGNAL(clicked(bool)) , this , SLOT(login()));
    connect(ledt_login_, SIGNAL(textEdited(QString)) , this , SLOT(activateButtons()));
    connect(ledt_pwd_, SIGNAL(textEdited(QString)) , this , SLOT(activateButtons()));
}

//void SessionManager::login(SPODBDatabase db){
//    showFullScreen();
//    try
//    {
//        transaction t( db->begin());
//            SPUser user {NULL};
//            user = db->query_one<User>(
//                    query<User>::login == ledt_login_->text().trimmed().toLower()
//                    && query<User>::password == ledt_pwd_->text().trimmed());
//        t.commit();

//        if(! user.isNull()){
//            _login_status = true;
//            close();
//        }
//        else
//            QMessageBox::information(this,qApp->applicationName(),QString("Login ou Mot de passe érroné\n Vérifiez et rééssayez"));
//    }
//    catch(const odb::exception& e){
//        QMessageBox::information(this,qApp->applicationName(),QString(e.what()));
//    }
//    close();
//}

void SessionManager::activateButtons(){
    if (ledt_login_->text().trimmed().isEmpty() || ledt_pwd_->text().trimmed().isEmpty()
            || ledt_login_->text().trimmed().length() < 4
            || ledt_pwd_->text().trimmed().length() < 8)
        btn_connect_->setEnabled(false);
    else
        btn_connect_->setEnabled(true);
}
