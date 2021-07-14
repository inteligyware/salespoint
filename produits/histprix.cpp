/**
 * Project InteligyPharma
 * @author Gilles BENE
 * @version 1.0
 */

#include "histprix.h"
#include "histprix-odb.hxx"

/**
 * HistPrix implementation
 */

HistPrix::HistPrix(){}
HistPrix::~HistPrix(){}

HistPrix::HistPrix(quint64 prix_vente, SPProduit produit)
{
    prix_vente_ = prix_vente;
    produit_ = produit;
    date_fin_ = QDate::currentDate();
}

void HistPrix::setPrixVente(quint64 prix_vente)
{
    prix_vente_ = prix_vente;
}
