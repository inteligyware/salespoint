#ifndef PRODUCT_CREATION_FORM_H
#define PRODUCT_CREATION_FORM_H

#include "ui_productcreationform.h"
#include "models.h"
#include <QDialog>

class FamilyCreationForm;

class ProductCreationForm : public QDialog , private Ui::ProductCreationForm
{
    Q_OBJECT

public:
    explicit ProductCreationForm(QWidget *parent = 0);
    void setFamilyComboBoxModel(ODBFamilyModel *model);    
    void setMedicamentComboBox(ODBProductModel *model);
    void setArticleComboBox(ODBProductModel *model);
    void setFamilyCreationForm(FamilyCreationForm*  family_form);

    QComboBox *familyComboBox();
    SPProduit product() const;

public slots:
    //Transition Fonction
    void gotoInitialState();

private slots:
    void clear();
    void save();
    void quit();
    void activateButtonSave();
    void selectProductType();
    void addFamily();

    //Transition Fonction slot
    void gotoRelatedProductSelectedState();
    void gotoRelatedProductSelectedState(const QString& parent_label);
    void gotoFamilySelectedState();

    void setDerivedProductPriceValidator();
    void setDerivedProductColiseAndReferenceValidators();

    void clearDerivedProductPriceValidator();
    void clearDerivedProductColiseAndReferenceValidators();

private:
   void connectWidgets();
   void resetGeneralData();
   void resetInventoryData();
   void setDefaultsForDerivedProduct();
   void setDefaultsForDerivedProduct(const QString& parent_label);

   bool isValidBareCode(const QString& barecode) const;
   bool isValidReference(const QString& reference) const;
   bool isValidDesignation(const QString& designation) const;
   bool isUniqueFromProduct(const QString& value, int column) const;
   bool isUniqueFromFamily(const QString& value, int column)const;
   bool isDerivedProduct() const;

   bool productDesignationExists(const QString& designation) const ;
   bool familyExists(const QString& designation) const;

   void initValidators();
   void saveDefaultsLabels();
   void setNotDerivedProductValidators();

   SPProduit grabProduct();

   QString parentLabel() const;
   QString familyLabel() const;
   QString productLabel() const;
   QString bareCode() const;
   QString reference() const;

   ulong salePrice() const;
   qreal purchasePrice() const;

   int coliseMere() const;
   uint coliseDerive() const;
   float remise();

   int grosPhysQty() const;
   int detailPhysQty() const;

   int grosTheoQty() const;
   int detailTheosQty() const;

   int addedGrosPhysQty() const;
   int addedDetailPhysQty() const;

   QComboBox *productComboBox() const;
   QAbstractItemModel* model()const;

   QString purchase_price_default_label, colise_mere_default_label;
   QRegExpValidator* ref_validator, *desig_validator;
   QIntValidator *derive_colise_validator, *sale_price_validator;
   FamilyCreationForm* form;

   mutable SPProduit _product {NULL};
};

#endif // PRODUCT_CREATION_FORM_H
