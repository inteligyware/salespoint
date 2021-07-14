/**
 * Project InteligyPharma
 * @author Gilles BENE
 * @version 1.0
 */
#include "emballage.h"
#include "emballage-odb.hxx"

/**
 * Emballage implementation
 */

Emballage::Emballage(){}

Emballage::~Emballage(){}

Emballage::Emballage(const QString& libele, const QString& description)
{
    setLibele(libele);
    setDescription(description);
}

const QString& Emballage::getLibele() const
{
    return libele_;
}

void Emballage::setLibele(const QString& libele)
{
    libele_ = libele.simplified();
}

const QString& Emballage::getDescription() const
{
    return description_ ;
}

void Emballage::setDescription(const QString& description)
{
    description_ = description.simplified();
}

void Emballage::setTonnages(const LWPTonnage &tonnage)
{
    tonnages_.push_back(tonnage);
}

const odb::vector<LWPTonnage >& Emballage::getTonnages() const
{
    return tonnages_;
}
