/**
 * Project InteligyPharma
 * @author Gilles BENE
 * @version 1.0
 */


#ifndef _RELANCABLE_H
#define _RELANCABLE_H

#include "document.h"

#include <odb/core.hxx>
#include <odb/vector.hxx>
#include <odb/qt/lazy-ptr.hxx>

class Relance;
class Relancable: public Document {

protected:
    odb::vector<QLazyWeakPointer<Relance>> relances_;

    friend class odb::access;
    Relancable();

public:

    virtual ~Relancable();
    virtual const QString getTitre() const = 0;
    virtual const QString getReference() const = 0;
};

#endif //_RELANCABLE_H
