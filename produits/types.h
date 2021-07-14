#ifndef TYPES_H
#define TYPES_H

#include <QtCore/QSharedPointer>
#include <odb/qt/lazy-ptr.hxx>

class Emballage;
class Fournisseur;
class HistPrix;
class Medicament;
class PrixFourn;
class Produit;
class Tonnage;
class Article;
class Famille;

using SPEmballage = QSharedPointer<Emballage>;
using LSPEmballage = QLazySharedPointer<Emballage>;
using WPEmballage = QWeakPointer<Emballage>;
using LWPEmballage = QLazyWeakPointer<Emballage>;

using SPFournisseur = QSharedPointer<Fournisseur>;
using LSPFournisseur = QLazySharedPointer<Fournisseur>;
using WPFournisseur = QWeakPointer<Fournisseur>;
using LWPFournisseur = QLazyWeakPointer<Fournisseur>;

using SPHistPrix = QSharedPointer<HistPrix>;
using LSPHistPrix = QLazySharedPointer<HistPrix>;
using WPHistPrix = QWeakPointer<HistPrix>;
using LWPHistPrix = QLazyWeakPointer<HistPrix>;

using SPMedicament = QSharedPointer<Medicament>;
using LSPMedicament = QLazySharedPointer<Medicament>;
using WPMedicament = QWeakPointer<Medicament>;
using LWPMedicament = QLazyWeakPointer<Medicament>;

using SPPrixFourn = QSharedPointer<PrixFourn>;
using LSPPrixFourn = QLazySharedPointer<PrixFourn>;
using WPPrixFourn = QWeakPointer<PrixFourn>;
using LWPPrixFourn = QLazyWeakPointer<PrixFourn>;

using SPProduit = QSharedPointer<Produit>;
using LSPProduit = QLazySharedPointer<Produit>;
using WPProduit = QWeakPointer<Produit>;
using LWPProduit = QLazyWeakPointer<Produit>;

using SPTonnage = QSharedPointer<Tonnage>;
using LSPTonnage = QLazySharedPointer<Tonnage>;
using WPTonnage = QWeakPointer<Tonnage>;
using LWPTonnage = QLazyWeakPointer<Tonnage>;

using SPArticle = QSharedPointer<Article>;
using LSPArticle = QLazySharedPointer<Article>;
using WPArticle = QWeakPointer<Article>;
using LWPArticle = QLazyWeakPointer<Article>;

using SPFamille = QSharedPointer<Famille>;
using LSPFamille = QLazySharedPointer<Famille>;
using WPFamille = QWeakPointer<Famille>;
using LWPFamille = QLazyWeakPointer<Famille>;

#endif // TYPES_H
