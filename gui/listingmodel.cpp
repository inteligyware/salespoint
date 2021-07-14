#include "models.h"

ListingModel::ListingModel(QObject* parent): QSqlQueryModel(parent)
{
    _query = "SELECT s.id  as Numero , f.reference as Reference ,  ps.noms as Seller , \
                     date as Date, SUM(ds.qte*ds.prix_unitaire*(1 - ds.remise/100)) as Amount \
                     FROM sortie s LEFT JOIN personne ps ON s.responsable = ps.id \
                        LEFT JOIN detailssortie ds ON s.id = ds.sortie \
                        LEFT JOIN facture f ON  s.facture  = f.id  \
                            WHERE  s.id = ds.sortie AND s.responsable = ps.id  \
                                GROUP BY s.id , f.reference , ps.noms , date \
                                    ORDER BY Date DESC";

    _headers << tr("N°")
            << tr("Référence")
            << tr("Vendeur")
            << tr("Date")
            << tr("Montant");

    _querytitle = "Toutes Les Ventes";

    initAlignments();
}

ListingModel::ListingModel(const QString& query, const QStringList& header , const QString& title, QObject* parent):
    QSqlQueryModel(parent), _query {query} , _headers {header} , _querytitle {title}{
    initAlignments();
}

ListingModel::ListingModel(const ListingModelParam& param, QObject* parent){
    ListingModel(param.query,param.header,param.title, parent );
}

QVariant ListingModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if ( role == Qt::TextAlignmentRole)
        return QVariant(alignments[section]);
    return QSqlQueryModel::headerData(section , orientation , role);
}

QVariant ListingModel::data(const QModelIndex &index, int role) const{

    if(!index.isValid()) return QVariant();

    if ( role == Qt::TextAlignmentRole)
        return QVariant(alignments[index.column()]);

    return QSqlQueryModel::data(index,role);
}

void ListingModel::initModel(const QString& query, const QStringList& headers){
    int section = 0;
    setQuery(query);
    if(columnCount() == 0) return ;
    for(auto& header : headers) setHeaderData(section++ , Qt::Horizontal, header);
}

void ListingModel::initAlignments(){
    alignments.clear();
    for(auto i =  0 ; i < _headers.size() ; i++)
        alignments.push_back(Qt::AlignLeft|Qt::AlignVCenter);
}

void ListingModel::setAlignments(const QList<int>& columns , Qt::Alignment algnmt){
//    alignments.clear();
//    if(columnCount() == 0) return ;

//    for(auto i =  0 ; i < _headers.size() ; i++)
//        alignments.push_back(Qt::AlignLeft|Qt::AlignVCenter);
    for(auto pos : columns) alignments[pos] = algnmt;
}

void ListingModel::load(){
    initModel(query(),headers());
}

bool ListingModel::isUnique(const QString& value, int column) const{
    Q_ASSERT(column >= 0 && column < columnCount());
    return match(index(0, column), Qt::DisplayRole, value, 1, Qt::MatchFlags(Qt::MatchFixedString|Qt::MatchWrap)).isEmpty();
}

void ListingModel::resetModel(){
    beginResetModel();
        QSqlQueryModel::clear();
        initModel(query(),headers());
    endResetModel();
}

const QString& ListingModel::title() const{
    return _querytitle;
}

const QString& ListingModel::query() const{
    return _query;
}

const QStringList& ListingModel::headers() const{
    return _headers;
}
