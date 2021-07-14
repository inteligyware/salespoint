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
    quint16 id_;
    QString libele_;

    friend class odb::access;
    Fonction();
    void setId(quint16 id);

public:
    explicit Fonction(const QString& libele);
    quint16 getId() const;

    void setLibele(const QString& libele);
    const QString& getLibele() const;
};

#endif // _FONCTION_H
