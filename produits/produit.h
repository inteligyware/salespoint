/**
 * Project InteligyPharma
 * @author Gilles BENE
 * @version 1.0
 */

#ifndef _PRODUIT_H
#define _PRODUIT_H

#include <QtCore/QString>
#include <QtCore/QDate>
#include <QtCore/QVector>
#include <QtCore/QSharedPointer>
#include <memory>

#include <odb/vector.hxx>
#include <odb/qt/lazy-ptr.hxx>

#include <odb/database.hxx>
#include <odb/transaction.hxx>

#include "types.h"

using namespace std;
using namespace odb::core;

class PrixFourn;
class Fournisseur;
class Tonnage;
class HistPrix;

class Produit:  public QEnableSharedFromThis<Produit>{

protected:
    static float scoef_;
    static quint8 arrondi_;

    ulong id_;
    QString libele_;
    QString codebare_;
    QString image_path_;
    qreal prix_achat_moy_;
    quint64 prix_vente_;
    float remise_;
    float qte_colise_;

    QVector<LWPProduit> children_;
    SPProduit parent_;

    odb::vector<LWPPrixFourn > prixfourns_;
    odb::vector<LWPTonnage > tonnages_;
    odb::vector<LWPHistPrix > hist_prixs_;

    friend class odb::access;
    friend class PrixFourn;
    friend class Tonnage;
    friend class DetailsSortie;
    friend void setProduitId(SPProduit& , ulong);

    Produit();
    void setId(ulong id);
    void setPrixfourns(const LWPPrixFourn& prixfourn);
    void setTonnages(const LWPTonnage& tonnage);
    void setParent(const SPProduit& parent);
    void setChildren(const SPProduit& child);
//    const SPProduit& getParent() const;

    quint64 calculPrixVente(qreal prix_achat_moy,float coef, quint8 arrondi) const;
    void setHistPrix(const LWPHistPrix& hist_prix);

public:

    Produit(const QString& libele,
        float qtecolise = 1,
        SPProduit parent = SPProduit {NULL}
        );

    virtual ~Produit();

    virtual QString type() const = 0;

    const SPProduit& getParent() const;

    static bool setCoef(float coef);
    static float getCoef();

    static void setArrondi(quint8 arrondi);
    static quint8 getArrondi();

    virtual const QString& getReference() const = 0;
    virtual void setReference(const QString& ref) = 0;
    virtual QString getLibeleFamille() const = 0;

    ulong getId() const;
    
    void setLibele(const QString& libele);
    const QString& getLibele() const;

    void setCodebare(const QString& codebare);
    const QString& getCodebare() const;

    void setImagePath(const QString& image_path);
    const QString& getImagePath() const;    

    void setPrixAchatMoy(qreal prix_achat_moy , const QSharedPointer<database>& db);
    void setPrixAchatMoy(qreal prix_achat_moy);
    qreal getPrixAchatMoy() const;

    void setRemise(float remise);
    float getRemise() const;

    void setQteColise(float);
    float getQteColise() const;

    void setPrixVente(quint64 prix_vente);
    quint64 getPrixVente() const;
    float gain() const ;

    const odb::vector<LWPPrixFourn >& getPrixfourns() const;

    const odb::vector<LWPTonnage >& getTonnages() const;

    const odb::vector<LWPHistPrix >& getHistPrix() const;

    const SPProduit& parent() const ;
    const QVector<SPProduit> getChildren() const;

    const SPProduit childAt(int pos) const;
    bool isChild() const;
    bool isRetailable() const ;
    bool isMedicament() const ;
//    void setActive(bool active);
//    bool isActive() const;
};

struct DBViewProduits{
    SPProduit produits;
};

struct ViewProduit{
    ulong id;
    QString libele;
    QString codebare;
    qreal prix_achat_moy;
    quint64 prix_vente;
    float remise;
    float qte_colise;
};

void setProduitId(SPProduit& , ulong);

#endif //_PRODUIT_H


