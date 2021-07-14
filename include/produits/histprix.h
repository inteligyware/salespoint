/**
 * Project InteligyPharma
 * @author Gilles BENE
 * @version 1.0
 */

#ifndef _HISTPRIX_H
#define _HISTPRIX_H

#include <QtCore/QDate>
#include <odb/qt/lazy-ptr.hxx>

#include "types.h"

class Produit;

class HistPrix {
private: 
    quint32 id_;
    quint64 prix_vente_;
    QDate date_fin_;
    LSPProduit produit_;

    friend class odb::access;
    HistPrix();

public:
    virtual ~HistPrix();
    HistPrix(quint64 prix_vente, SPProduit produit);
    void setPrixVente(quint64 prix_vente);
};

#endif //_HISTPRIX_H
