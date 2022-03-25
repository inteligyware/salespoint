/**
 * Project InteligyPharma
 * @author Gilles BENE
 * @version 1.0
 */


#ifndef _EMBALLAGE_H
#define _EMBALLAGE_H

#include <QtCore/QString>

#include <odb/vector.hxx>
#include <odb/qt/lazy-ptr.hxx>
#include "types.h"

class Tonnage;
class Emballage {
private: 

    QString libele_;
    QString description_;
    odb::vector<LWPTonnage >tonnages_;

    Emballage();
    void setTonnages(const LWPTonnage& tonnage);
    friend class odb::access;
    friend class Tonnage;

public:

    virtual ~Emballage();
    Emballage(const QString& libele, const QString& description = "");
    const QString& getLibele() const;
    void setLibele(const QString& libele);

    const QString& getDescription() const;
    void setDescription(const QString& description);

    const odb::vector<LWPTonnage>& getTonnages() const;

};

#endif //_EMBALLAGE_H
