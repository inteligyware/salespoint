/**
 * Project InteligyPharma
 * @author Gilles BENE
 * @version 1.0
 */

#include "produit.h"
#include "produit-odb.hxx"
#include "histprix-odb.hxx"
#include "emballage-odb.hxx"

#include <QString>
#include <QDate>
#include <QSharedPointer>

#include <odb/vector.hxx>
#include <odb/qt/lazy-ptr.hxx>

#include <cmath>

/**
 * Produit implementation
 */

float Produit::scoef_ = 1.25;
quint8 Produit::arrondi_ = 25;

Produit::Produit() {}
Produit::~Produit() {
    prixfourns_.clear();
    children_.clear();
    tonnages_.clear();
    hist_prixs_.clear();
}

Produit::Produit(const QString& libele,
                 float qtecolise,
                 SPProduit parent): prix_achat_moy_{0},remise_{0}, qte_colise_{1}, parent_{parent}
{
    setId(0);
    setLibele(libele);
    if(!parent.isNull()){
        setParent(parent);
        parent->setChildren(sharedFromThis());
    }
    setQteColise(qtecolise);
}

void Produit::setId(ulong id){

    id_ = id;
}

ulong Produit::getId() const{
    return id_;
}

void Produit::setLibele(const QString& libele){
    libele_ = libele.simplified().toUpper();
}

const QString& Produit::getLibele() const{
    return libele_ ;
}

void Produit::setCodebare(const QString& codebare){

    if( codebare.simplified() != "" ) codebare_ = codebare.simplified().toUpper();
}
const QString& Produit::getCodebare() const{

    return codebare_;
}

void Produit::setImagePath(const QString& image_path){
    image_path_ = image_path.simplified();
}

const QString& Produit::getImagePath() const{
    return image_path_ ;
}

bool Produit::setCoef(float coef)
{
   bool valid = ( coef > -1 && coef < 2 ) ;

   if ( valid ) scoef_ = coef;

   return valid ;
}

void Produit::setArrondi(quint8 arrondi)
{
    arrondi_ = arrondi;
}

float Produit::getCoef()
{
    return scoef_;
}

quint8 Produit::getArrondi()
{
    return arrondi_;
}

void Produit::setPrixAchatMoy(qreal prix_achat_moy , const  QSharedPointer<database>& db)
{
    quint64 old_prix_vente = getPrixVente();
    prix_achat_moy_ = prix_achat_moy;

    if ( getId() != 0 )  //check wether the object is persistent

    if( old_prix_vente != 0 && old_prix_vente != calculPrixVente( prix_achat_moy , Produit::getCoef() , Produit::getArrondi()))
    {

        typedef odb::query<HistPrix> query;
        SPHistPrix tmp = db->query_one<HistPrix>( query::produit->id == getId() && query::date_fin == QDate::currentDate());

        if (tmp.isNull())
        {
            SPHistPrix courrant (new HistPrix(old_prix_vente, sharedFromThis()));
            setHistPrix(courrant);
            db->update(sharedFromThis());
            db->persist(courrant);
        }
        else
        {
            tmp->setPrixVente(old_prix_vente);
            db->update(tmp);
        }
    }
}

void Produit::setPrixAchatMoy(qreal prix_achat_moy){
    prix_achat_moy_ = prix_achat_moy;
}

qreal Produit::getPrixAchatMoy() const
{
    return prix_achat_moy_;
}

void Produit::setRemise(float remise){
    if(remise >= 0 && remise < 100)
        remise_ = remise;
}

float Produit::getRemise() const{
    return remise_;
}

void Produit::setQteColise(float qte){
    if(qte >= 1){
        if(!isChild())
            qte_colise_ = qte;
        else if (qte < parent()->getQteColise())
            qte_colise_ = qte;
    }
}

float Produit::getQteColise() const{
    return qte_colise_;
}

quint64 Produit::calculPrixVente(qreal prix_achat_moy, float coef, quint8 arrondi) const
{
    quint64 prix = ceil(coef*prix_achat_moy);
    return ( prix + ( arrondi - prix % arrondi ) % arrondi);
}

void Produit::setPrixVente(quint64 prix_vente){
    //prix_vente_ = getPrixVente();
    prix_vente_ = prix_vente;
}

quint64 Produit::getPrixVente() const
{
    return prix_vente_!= 0 ? prix_vente_ :
                             calculPrixVente( getPrixAchatMoy() , getCoef() , getArrondi());
}

float Produit::gain() const {
     return 100*(getPrixVente() / getPrixAchatMoy() - 1 ) ;
}

void Produit::setPrixfourns(const LWPPrixFourn& prixfourn)
{
    prixfourns_.push_back(prixfourn);
}

const odb::vector<LWPPrixFourn >& Produit::getPrixfourns() const
{
    return prixfourns_;
}

void Produit::setTonnages(const LWPTonnage& tonnage)
{
    tonnages_.push_back(tonnage);
}

const odb::vector<LWPTonnage >& Produit::getTonnages() const
{
    return tonnages_;
}

void Produit::setParent(const SPProduit& parent){
    //Reparenthood is impossible
    if(!parent.isNull() && parent_.isNull()){
       parent_ = parent;
       parent_->setChildren(sharedFromThis());
    }
 }

void Produit::setChildren(const SPProduit& child){

    if(child.isNull()) return;
    bool exist = false;

    for (auto tmp: children_) {
       if (tmp.load()->getLibele() == child->getLibele() ){
           exist = true;
           break;
       }
    }

    if(!exist) children_.push_back(child);
}

const SPProduit& Produit::getParent() const{
    return parent_;
}

const SPProduit& Produit::parent() const{
    return getParent();
}

const QVector<SPProduit> Produit::getChildren() const{
   QVector<SPProduit> children;
   for(auto child : children_)
       children.push_back(child.load());
   return children;
}

const SPProduit Produit::childAt(int pos) const {
          return children_[pos].load();
 }

bool Produit::isChild() const{
    return !parent().isNull();
}

bool Produit::isRetailable() const{
    return (!isChild() && qte_colise_ > 1);
}

bool Produit::isMedicament() const {
    return type().contains("Medicament", Qt::CaseInsensitive);
}

void Produit::desactivate(){
    return ;
}

quint32 Produit::getQteGros(){
    return numeric_limits<int>::max();
}

quint32 Produit::getQteDetails(){
   return numeric_limits<int>::max();
}

void Produit::setHistPrix(const LWPHistPrix& hist_prix){
    hist_prixs_.push_back(hist_prix);
}

const odb::vector<LWPHistPrix> &Produit::getHistPrix() const{
    return hist_prixs_;
}

void setProduitId(SPProduit& prod , ulong id){
    prod->setId(id);
}
