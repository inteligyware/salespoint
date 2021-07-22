#include "famille.h"
#include "famille-odb.hxx"


void Famille::setId(quint32 id){
    id_ = id;
}

Famille::Famille(){}
Famille::~Famille(){}

Famille::Famille(const QString& reference, const QString& libele){
    setId(0);
    setLibele(libele);
    setReference(reference);
}

quint32 Famille::getId() const{
    return id_;
}
void Famille::setReference(const QString& reference){
    if(!reference.isEmpty())
        reference_ = reference;
}

const QString& Famille::getReference() const{
    return reference_;
}

bool Famille::isUnique(const QString& reference , const QSharedPointer<database>& db) const{
    bool unique = true;
    transaction t(db->begin());
        if(db->query_one<Famille>(query<Famille>::reference == reference)) unique = false;
    t.commit();
    return unique;
}

void Famille::setLibele(const QString& libele){
    libele_ = libele.simplified().toUpper();
}

const QString&  Famille::getLibele(){
    return libele_;
}

void Famille::setDescription(const QString& description){
    description_ = description.simplified();
}

const QString&  Famille::getDescription() const{
    return description_;
}

void Famille::unchild(const SPFamille& child){

    if(child.isNull()) return;
    for(auto tmp: children_)
       if (tmp.load()->getLibele() == child->getLibele() ){
           children_.removeOne(child);
           break;
       }
}

void Famille::setChildren(const SPFamille& child){

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

odb::vector<SPFamille> Famille::getChildren() const{
    odb::vector<SPFamille> children;
    for (auto var: children_)
       children.push_back(var.load());
    return children;
}

void Famille::setParent(const SPFamille& parent){
    //Reparenthood is possible
    if(!parent_.isNull()) parent_->unchild(sharedFromThis());
    parent_ = parent;
    if(!parent_.isNull()) parent_->setChildren(sharedFromThis());
}

const SPFamille& Famille::getParent() const{
    return parent_;
}

const SPFamille& Famille::parent() const{
    return getParent();
}

SPFamille Famille::childAt(int pos) const {
          return children_[pos].load();
 }

bool Famille::isChild() const{
    return !parent_.isNull();
}

