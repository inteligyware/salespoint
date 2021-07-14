/**
 * Project InteligyPharma
 * @author Gilles BENE
 * @version 1.0
 */


#ifndef _RELANCE_H
#define _RELANCE_H

#include <QtCore/QDateTime>

#include <odb/core.hxx>
#include <odb/qt/lazy-ptr.hxx>

class Relancable;

class Relance {
private:
    unsigned long id_;
    QDateTime date_;
    quint16 delais_;
    QLazySharedPointer<Relancable> relancee_;

    friend class odb::access;
    Relance();
    void setId(unsigned long id);
    void setDate();

public:
    virtual ~Relance();
    Relance(const QSharedPointer<Relancable>& relancee);
    unsigned long getId() const;
    QDateTime getDate() const;
    const QLazySharedPointer<Relancable>& getRelancee() const ;
  };

#endif //_RELANCE_H
