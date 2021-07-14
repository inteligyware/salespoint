/**
 * Project InteligyPharma
 * @author Gilles BENE
 * @version 1.0
 */

#ifndef _FONCTION_H
#define _FONCTION_H

#include <QtCore/QString>
#include <odb/core.hxx>

class Fonction
{
private:
    quint32 id_;
    QString libele_;

    friend class odb::access;
    Fonction();
    void setId(quint32 id);

public:
    explicit Fonction(const QString& libele);
    quint32 getId() const;

    void setLibele(const QString& libele);
    const QString& getLibele() const;
};

#endif // _FONCTION_H
