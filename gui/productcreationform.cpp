#include "productcreationform.h"
#include "familycreationform.h"
#include "views.h"
#include "include/produits.h"
#include <QLineEdit>
#include <QDoubleValidator>
#include <QCompleter>
#include <QMessageBox>

#include "toolkit.h"

ProductCreationForm::ProductCreationForm(QWidget *parent): QDialog(parent){
    setupUi(this);

    cbox_med->setParent(this);
    cbox_med->setVisible(false);

    initValidators();
    saveDefaultsLabels();
    connectWidgets();
    gotoInitialState();
    last_inventory->setReadOnly(true);
    last_inventory->setEnabled(true);

}

void ProductCreationForm::connectWidgets(){

    connect(rbtn_medicament, SIGNAL(clicked(bool)), SLOT(selectProductType()));
    connect(rbtn_article, SIGNAL(clicked(bool)), SLOT(selectProductType()));

    connect(cbox_med, SIGNAL(activated(const QString&)), SLOT(gotoRelatedProductSelectedState(const QString&)));
    connect(cbox_article, SIGNAL(activated(const QString&)), SLOT(gotoRelatedProductSelectedState(const QString&)));
    connect(cbox_family, SIGNAL(currentIndexChanged(int)), SLOT(gotoFamilySelectedState()));

    connect(ckbox_vta, SIGNAL(clicked(bool)), vta, SLOT(setEnabled(bool)));
    connect(ckbox_reduction, SIGNAL(clicked(bool)), reduction, SLOT(setEnabled(bool)));

    connect(ledit_reference, SIGNAL(textChanged(const QString&)), SLOT(activateButtonSave()));
    connect(ledit_designation, SIGNAL(textChanged(const QString&)), SLOT(activateButtonSave()));
    connect(ledit_bar_code, SIGNAL(textChanged(const QString&)), SLOT(activateButtonSave()));
    connect(ledit_sale_price, SIGNAL(textChanged(const QString&)), SLOT(activateButtonSave()));
    connect(ledit_colise_mere, SIGNAL(textChanged(const QString&)), SLOT(activateButtonSave()));
    connect(ledit_colise_derive, SIGNAL(textChanged(const QString&)), SLOT(activateButtonSave()));

    connect(ledit_colise_derive, SIGNAL(textEdited(QString)), SLOT(setDerivedProductPriceValidator()));

    connect(pbtn_save, SIGNAL(clicked(bool)), SLOT(save()));
    connect(pbtn_clear, SIGNAL(clicked(bool)), SLOT(gotoInitialState()));
    connect(pbtn_quit, SIGNAL(clicked(bool)), SLOT(quit()));
}

void ProductCreationForm::setMedicamentComboBox(ODBProductModel *model){
    delete cbox_med->model();
    cbox_med->setEditable(true);
    cbox_med->setMaxVisibleItems(9);
    cbox_med->setInsertPolicy(QComboBox::NoInsert);

    auto sourceproxy = new RetailableProductProxyModel(true,this);
    sourceproxy->setSourceModel(model);
    sourceproxy->sort(ODBProductModel::DESIGNATION, Qt::AscendingOrder);
    cbox_med->setModel(sourceproxy);
    cbox_med->setModelColumn(ODBProductModel::DESIGNATION);

    auto proxy = new QSortFilterProxyModel(this);
    proxy->setSourceModel(cbox_med->model());
    proxy->setFilterCaseSensitivity(Qt::CaseInsensitive);
    proxy->setFilterKeyColumn(cbox_med->modelColumn());

    auto completer = new QCompleter(this);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    completer->setModel(proxy);
    completer->setCompletionColumn(cbox_med->modelColumn());
    completer->setCompletionMode(QCompleter::UnfilteredPopupCompletion);
    cbox_med->setCompleter(completer);
    connect(cbox_med, &QComboBox::editTextChanged, [proxy](const QString &txt){ proxy->setFilterRegExp("^"+txt);});
    connect(cbox_med->completer(), SIGNAL(activated(const QString&)), SLOT(gotoRelatedProductSelectedState(const QString&)));
}

void ProductCreationForm::setArticleComboBox(ODBProductModel *model){
    delete cbox_article->model();
    cbox_article->setEditable(true);
    cbox_article->setMaxVisibleItems(9);
    cbox_article->setInsertPolicy(QComboBox::NoInsert);

    auto sourceproxy = new RetailableProductProxyModel(false,this); //false to select Only Retailable articles
    sourceproxy->setSourceModel(model);
    sourceproxy->sort(ODBProductModel::DESIGNATION, Qt::AscendingOrder);
    cbox_article->setModel(sourceproxy);
    cbox_article->setModelColumn(ODBProductModel::DESIGNATION);

    auto proxy = new QSortFilterProxyModel(this);
    proxy->setSourceModel(cbox_article->model());
    proxy->setFilterCaseSensitivity(Qt::CaseInsensitive);
    proxy->setFilterKeyColumn(cbox_article->modelColumn());

    auto completer = new QCompleter(this);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    completer->setModel(proxy);
    completer->setCompletionColumn(cbox_article->modelColumn());
    completer->setCompletionMode(QCompleter::UnfilteredPopupCompletion);
    cbox_article->setCompleter(completer);
    connect(cbox_article, &QComboBox::editTextChanged, [proxy](const QString &txt){ proxy->setFilterRegExp("^"+txt);});
    connect(cbox_article->completer(), SIGNAL(activated(const QString&)), SLOT(gotoRelatedProductSelectedState(const QString&)));

    //We select Other article by default emiting this signal
    emit rbtn_article->click();
}

void ProductCreationForm::setFamilyComboBoxModel(ODBFamilyModel* model){

    delete cbox_family->model();
    cbox_family->setEditable(true);
    cbox_family->setMaxVisibleItems(9);
    cbox_family->setInsertPolicy(QComboBox::NoInsert);

    auto uniqueproxy = new QSortFilterProxyModel(this);
    uniqueproxy->setSourceModel(model);
    uniqueproxy->sort(ODBFamilyModel::DESIGNATION, Qt::AscendingOrder);
    cbox_family->setModel(uniqueproxy);
    cbox_family->setModelColumn(ODBFamilyModel::DESIGNATION);

    auto proxy = new QSortFilterProxyModel(this);
    proxy->setSourceModel(cbox_family->model());
    proxy->setFilterCaseSensitivity(Qt::CaseInsensitive);
    proxy->setFilterKeyColumn(cbox_family->modelColumn());

    auto completer = new QCompleter(this);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    completer->setModel(proxy);
    completer->setCompletionColumn(cbox_family->modelColumn());
    completer->setCompletionMode(QCompleter::UnfilteredPopupCompletion);
    cbox_family->setCompleter(completer);
    connect(cbox_family, &QComboBox::editTextChanged, [proxy](const QString &txt){ proxy->setFilterRegExp("^"+txt);});
    connect(cbox_family->completer(), SIGNAL(activated(const QString&)), SLOT(gotoFamilySelectedState()));
}

void ProductCreationForm::setFamilyCreationForm(FamilyCreationForm*  family_form){
    form = family_form;
    connect(pbtn_new, SIGNAL(clicked(bool)), SLOT(addFamily()));
}

SPProduit ProductCreationForm::grabProduct(){

    SPProduit product{NULL}, parent_product{NULL};

    //Get the parent product if it is a derived product
    if(isDerivedProduct()){
        auto index = productComboBox()->view()->selectionModel()->currentIndex();
        auto pmodel = model();
        auto id = pmodel->data(pmodel->index(index.row(), ODBProductModel::ID_PRODUIT)).toLongLong();
        parent_product = dynamic_cast<ODBProductModel*>(dynamic_cast<ProductListingDialog*>(parent())->sourceModel())->getItemById(id);
//        parent_product = AbstractODBModel::DB->load<Produit>(id);
        qDebug() << "parent_id = " << id;
     }

    auto _reference = reference();
    auto designation = productLabel();
    //We instanciate a Medicament or an Article accordingly
    if(familyLabel().compare("MEDICAMENTS",Qt::CaseInsensitive) == 0){
        SPProduit medicament { new Medicament(_reference, designation, 1 , parent_product)};
        product = medicament;
    }
    else{
        auto index = cbox_family->view()->selectionModel()->currentIndex();
        auto fmodel = cbox_family->model();
        auto id = fmodel->data(fmodel->index(index.row(), ODBFamilyModel::ID)).toLongLong();
        SPFamille famille = AbstractODBModel::DB->load<Famille>(id);
        SPArticle article { new Article(famille, designation, 1 , parent_product)};
        product = article;
        qDebug() << "famille_id = " << id;
    }
    product->setReference(_reference);
    product->setPrixVente(salePrice());
    product->setPrixAchatMoy(purchasePrice());
    if(!isDerivedProduct()){
        product->setCodebare(bareCode());
        product->setQteColise(coliseMere());
        product->setRemise(remise());
    }
    else
        product->setQteColise(coliseDerive());

    _product.swap(product);
    return _product;
}

SPProduit ProductCreationForm::product() const{
    return _product;
}

void ProductCreationForm::gotoInitialState(){
    clear();
    lbl_purchase_price->setText(purchase_price_default_label);
    lbl_colise_mere->setText(colise_mere_default_label);

    bool disabled = true;
    gbox_article->setDisabled(disabled);
    gbox_theo_stock->setDisabled(disabled);
    gbox_inventory->setDisabled(disabled);
    gbox_inventory->setChecked(false);
    justification->setDisabled(disabled);

    ledit_colise_derive->setHidden(!disabled);
    lbl_colise_derive->setHidden(!disabled);

    pbtn_clear->setDisabled(disabled);
    pbtn_save->setDisabled(disabled);
    pbtn_quit->setDisabled(!disabled);
}

void ProductCreationForm::gotoRelatedProductSelectedState(){
    setDefaultsForDerivedProduct();
    lbl_purchase_price->setText(tr("P. Vente Mere: "));
    lbl_colise_mere->setText(colise_mere_default_label);

    bool enabled = true;
    gbox_article->setEnabled(enabled);

    ledit_bar_code->setEnabled(!enabled);
    ledit_puchase_price->setEnabled(!enabled);
    ledit_sale_price->setEnabled(enabled);

    ckbox_reduction->setEnabled(!enabled);
    ckbox_vta->setEnabled(!enabled);
    ckbox_reduction->setChecked(!enabled);
    ckbox_vta->setChecked(!enabled);
    vta->setEnabled(!enabled);
    reduction->setEnabled(!enabled);
    ledit_colise_mere->setEnabled(!enabled);
    ledit_colise_derive->setEnabled(enabled);

    ledit_colise_derive->setVisible(enabled);
    lbl_colise_derive->setVisible(enabled);

    gbox_inventory->setEnabled(!enabled);
    gbox_inventory->setChecked(false);

    pbtn_clear->setEnabled(enabled);
    pbtn_save->setEnabled(!enabled);

    setDerivedProductColiseAndReferenceValidators();
    setDerivedProductPriceValidator();
}

void ProductCreationForm::gotoRelatedProductSelectedState(const QString& parent_label){
    setDefaultsForDerivedProduct(parent_label);
    lbl_purchase_price->setText(tr("P. Vente Mere: "));
    lbl_colise_mere->setText(colise_mere_default_label);

    bool enabled = true;
    gbox_article->setEnabled(enabled);

    ledit_bar_code->setEnabled(!enabled);
    ledit_puchase_price->setEnabled(!enabled);
    ledit_sale_price->setEnabled(enabled);

    ckbox_reduction->setEnabled(!enabled);
    ckbox_vta->setEnabled(!enabled);
    ckbox_reduction->setChecked(!enabled);
    ckbox_vta->setChecked(!enabled);
    vta->setEnabled(!enabled);
    reduction->setEnabled(!enabled);
    ledit_colise_mere->setEnabled(!enabled);
    ledit_colise_derive->setEnabled(enabled);

    ledit_colise_derive->setVisible(enabled);
    lbl_colise_derive->setVisible(enabled);

    gbox_inventory->setEnabled(!enabled);
    gbox_inventory->setChecked(false);

    pbtn_clear->setEnabled(enabled);
    pbtn_save->setEnabled(!enabled);

    setDerivedProductColiseAndReferenceValidators();
    setDerivedProductPriceValidator();
}

void ProductCreationForm::gotoFamilySelectedState(){
    resetGeneralData();
    resetInventoryData();
    lbl_purchase_price->setText(purchase_price_default_label);
    lbl_colise_mere->setText(tr("Quantité Colisée"));
    bool enabled = true;
    gbox_article->setEnabled(enabled);

    ledit_bar_code->setEnabled(enabled);
    ledit_reference->setEnabled(enabled);
    ledit_designation->setEnabled(enabled);
    ledit_puchase_price->setEnabled(enabled);
    ledit_sale_price->setEnabled(enabled);

    ckbox_reduction->setEnabled(enabled);
    ckbox_vta->setEnabled(enabled);
    ckbox_reduction->setChecked(!enabled);
    ckbox_vta->setChecked(!enabled);
    vta->setEnabled(!enabled);
    reduction->setEnabled(!enabled);
    ledit_colise_mere->setEnabled(enabled);
    ledit_colise_derive->setEnabled(!enabled);

    ledit_colise_derive->setVisible(!enabled);
    lbl_colise_derive->setVisible(!enabled);

    gbox_inventory->setEnabled(enabled);
    gbox_inventory->setChecked(!enabled);

    pbtn_clear->setEnabled(enabled);
    pbtn_save->setEnabled(!enabled);

    clearDerivedProductColiseAndReferenceValidators();
    clearDerivedProductPriceValidator();
}

void ProductCreationForm::setDerivedProductColiseAndReferenceValidators(){
    //We first uninstall any previous existing validator before installing the new one
    auto colisee_mere = ledit_colise_mere->text().toInt();
    derive_colise_validator->setRange(1,colisee_mere - 1);

    auto reference = ledit_reference->text();
    auto designation = ledit_designation->text();
    ledit_reference->setToolTip(tr("Reference de la forme %1Dnn").arg(reference));
    ledit_designation->setToolTip(tr("Designation de la forme xxxxx%1xxx").arg(designation));

    //Reference should match "previous_referenceDnn"
    reference.prepend("^(").append(")([D][0-9]{1,2})$");
    ref_validator->setRegExp(QRegExp(reference));

    //Designation should match "xxxxxPREV_DESIGNATIONxxxxx"
    designation.prepend("^(([A-Z]{1,5}\\s[0-9]{0,3}){1,2})").append("((\\s[A-Z]{1,5}){0,2})$");
    desig_validator->setRegExp(QRegExp(designation));
}

void ProductCreationForm::setDerivedProductPriceValidator(){
    auto colisee_derive = ledit_colise_derive->text().toInt();
    auto colisee_mere = ledit_colise_mere->text().toInt();
    auto sale_price_mere = ledit_puchase_price->text().toDouble();
//    auto tmp_bottom = 1.1*sale_price_mere*colisee_derive/colisee_mere;
//    auto tmp_bottom = Produit::getCoef()*sale_price_mere*colisee_derive/colisee_mere;
    auto tmp_bottom = sale_price_mere*colisee_derive/colisee_mere;

    //15 % increase
    auto bottom_price = generateSalePrice(tmp_bottom, 15, Produit::getArrondi());

    if(bottom_price > sale_price_mere) bottom_price = sale_price_mere;
    sale_price_validator->setRange(bottom_price, sale_price_mere);

    ledit_sale_price->setText(QString("%1").arg(bottom_price));
    ledit_sale_price->setToolTip(tr("Prix compris entre %L1 et %L2").arg(bottom_price).arg(sale_price_mere));
}

void ProductCreationForm::clearDerivedProductColiseAndReferenceValidators(){

    ledit_reference->setToolTip(QString());
    ledit_designation->setToolTip(QString());

    derive_colise_validator->setRange(1,INT_MAX);
    ref_validator->setRegExp(QRegExp(QString("\\w+")));
    desig_validator->setRegExp(QRegExp(QString("(\\w+\\s\\w*)*")));
}

void ProductCreationForm::clearDerivedProductPriceValidator(){
    sale_price_validator->setRange(0,INT_MAX);
    ledit_sale_price->setToolTip(tr("Indiquer le prix de vente"));
}

void ProductCreationForm::clear(){
    cbox_family->setCurrentIndex(-1);
    resetGeneralData();
    resetInventoryData();
}

void ProductCreationForm::save(){
    auto model = dynamic_cast<ProductListingDialog*>(parent())->sourceModel();
    try{
        dynamic_cast<ODBProductModel*>(model)->addItem(grabProduct());
        QMessageBox::information(this,tr("Creation d'Article"),tr("Operation reussie"));
        gotoInitialState();
        accept();
    }
    catch(const odb::exception& e){
        qDebug() << e.what();
        QMessageBox::warning(this,tr("Creation d'Article"),e.what());
        reject();
    }
}

void ProductCreationForm::quit(){
    reject();
}

void ProductCreationForm::resetGeneralData(){
    cbox_med->setCurrentIndex(-1);
    cbox_article->setCurrentIndex(-1);
    ledit_bar_code->clear();
    ledit_reference->clear();
    ledit_designation->clear();
    ledit_puchase_price->clear();
    ledit_sale_price->clear();
    reduction->clear();
    vta->clear();
}

void ProductCreationForm::resetInventoryData(){
    ledit_colise_mere->clear();
    ledit_colise_derive->clear();
    last_inventory->setDateTime(QDateTime::currentDateTime());
    ledit_phys_gros->clear();
    ledit_phys_details->clear();
    ledit_phys_added_gros->clear();
    ledit_phys_added_details->clear();
    justification->clear();
    ledit_theo_gros->clear();
    ledit_theo_details->clear();
}

void ProductCreationForm::setDefaultsForDerivedProduct(){

    auto productdlg = dynamic_cast<ProductListingDialog*>(parent());
    if(!productdlg) return;

    auto pmodel = dynamic_cast<ODBProductModel*>(productdlg->sourceModel());
    if(!pmodel) return;

    auto designation = parentLabel();
    auto parent_prod = pmodel->getItemByLabel(designation);
    if(parent_prod.isNull()) return;

    cbox_family->setCurrentText(parent_prod->getLibeleFamille());
    ledit_designation->setText(parent_prod->getLibele());
    ledit_reference->setText(parent_prod->getReference());
    ledit_bar_code->setText(QString("%1").arg(parent_prod->getCodebare()));
    ledit_colise_mere->setText(QString("%1").arg(parent_prod->getQteColise()));
    ledit_puchase_price->setText(QString("%1").arg(parent_prod->getPrixVente()));
    reduction->setText(QString("%1").arg(parent_prod->getRemise()));

    ledit_sale_price->clear();
    ledit_colise_derive->clear();
}

void ProductCreationForm::setDefaultsForDerivedProduct(const QString& parent_label){

    auto productdlg = dynamic_cast<ProductListingDialog*>(parent());
    if(!productdlg) return;

    auto pmodel = dynamic_cast<ODBProductModel*>(productdlg->sourceModel());
    if(!pmodel) return;

    auto parent_prod = pmodel->getItemByLabel(parent_label);
    if(parent_prod.isNull()) return;

    cbox_family->setCurrentText(parent_prod->getLibeleFamille());
    ledit_designation->setText(parent_prod->getLibele());
    ledit_reference->setText(parent_prod->getReference());
    ledit_bar_code->setText(QString("%1").arg(parent_prod->getCodebare()));
    ledit_colise_mere->setText(QString("%1").arg(parent_prod->getQteColise()));
    ledit_puchase_price->setText(QString("%1").arg(parent_prod->getPrixVente()));
    reduction->setText(QString("%1").arg(parent_prod->getRemise()));

    ledit_sale_price->clear();
    ledit_colise_derive->clear();
}

void ProductCreationForm::activateButtonSave(){
    auto _reference = reference();
    auto designation = productLabel();
    bool activated = !_reference.isEmpty() & !designation.isEmpty() & familyExists(familyLabel());
    if(isDerivedProduct()) {
        activated &= isValidDesignation(designation) & isValidReference(_reference);
        activated &= salePrice() > 0 && coliseDerive() >= 1;
    }
    else{
        activated &= isUniqueFromProduct(designation, ODBProductModel::DESIGNATION);
        activated &= isUniqueFromProduct(_reference, ODBProductModel::REFERENCE);
        if( !bareCode().isEmpty()) activated &= isUniqueFromProduct(bareCode(), ODBProductModel::CODEBARE);
        activated &= salePrice() > 0 && coliseMere() >= 1;
    }
    pbtn_save->setEnabled(activated);
}

void ProductCreationForm::addFamily(){
   if (form->showForm() == QDialog::Accepted)
        familyComboBox()->lineEdit()->setText(form->family()->getLibele());
}

void ProductCreationForm::selectProductType(){
    gotoInitialState();    
    cbox_article->setVisible(rbtn_article->isChecked());
    cbox_med->setVisible(!rbtn_article->isChecked());
    cbox_family->setEnabled(rbtn_article->isChecked());
    pbtn_new->setEnabled(rbtn_article->isChecked());
    cbox_family->setCurrentIndex(-1); //We kind of clear this cbox
    if(!rbtn_article->isChecked()){
        emit cbox_family->currentIndexChanged(-1);
        cbox_family->setCurrentText(cbox_med->model()->index(0,ODBProductModel::FAMILLE).data().toString());
    }
}

bool ProductCreationForm::isValidBareCode(const QString& barecode) const{
    return isUniqueFromProduct(barecode, ODBProductModel::CODEBARE);
}

bool ProductCreationForm::isValidReference(const QString& reference) const{
    auto product_reference = reference.simplified();
    bool productReferenceIsUnique = isUniqueFromProduct(product_reference, ODBProductModel::REFERENCE);
    bool parentExists = true;
    bool productReferenceContainsParentReference = true;

    if(isDerivedProduct()){

        QModelIndex index = productComboBox()->view()->selectionModel()->currentIndex();
        QAbstractItemModel* productmodel = model();

        auto parent_reference = productmodel->data(productmodel->index(index.row(), ODBProductModel::REFERENCE)).toString();
        auto parent_designation = productComboBox()->lineEdit()->text().simplified();

        parentExists = productDesignationExists(parent_designation);
        productReferenceContainsParentReference = product_reference.contains(parent_reference, Qt::CaseInsensitive);
        productReferenceContainsParentReference &= product_reference.size() > parent_reference.size();
    }
    return parentExists && productReferenceIsUnique && productReferenceContainsParentReference;

}

bool ProductCreationForm::isValidDesignation(const QString& designation) const{
    auto product_designation = designation.simplified();
    bool productDesignationIsUnique = isUniqueFromProduct(product_designation, QProductModel::DESIGNATION);
    bool parentExists = true;
    bool designationContainsParentDesignation = true;

    if(isDerivedProduct()){
        auto parent_designation = productComboBox()->lineEdit()->text().simplified();
        parentExists = productDesignationExists(parent_designation);
        designationContainsParentDesignation = product_designation.contains(parent_designation,Qt::CaseInsensitive);
        designationContainsParentDesignation &= product_designation.size() > parent_designation.size();
    }
    return parentExists && productDesignationIsUnique && designationContainsParentDesignation;
}

bool ProductCreationForm::isUniqueFromProduct(const QString& value, int column) const{
    return model()->match(model()->index(0, column), Qt::DisplayRole, value, 1, Qt::MatchFlags(Qt::MatchFixedString|Qt::MatchWrap)).isEmpty();
}

bool ProductCreationForm::isUniqueFromFamily(const QString& value, int column) const{
    QAbstractItemModel* model = cbox_family->model();
    return model->match(model->index(0, column), Qt::DisplayRole, value, 1, Qt::MatchFlags(Qt::MatchFixedString|Qt::MatchWrap)).isEmpty();
}

bool ProductCreationForm::productDesignationExists(const QString& designation) const{
    return !model()->match(model()->index(0, ODBProductModel::DESIGNATION), Qt::DisplayRole, designation, 1, Qt::MatchFlags(Qt::MatchFixedString|Qt::MatchWrap)).isEmpty();
}

bool ProductCreationForm::familyExists(const QString& designation) const{
    QAbstractItemModel* model = cbox_family->model();
    return !designation.isEmpty() && !model->match(model->index(0, ODBFamilyModel::DESIGNATION), Qt::DisplayRole, designation, 1, Qt::MatchFlags(Qt::MatchFixedString|Qt::MatchWrap)).isEmpty();
}

bool ProductCreationForm::isDerivedProduct() const{
      return !parentLabel().isEmpty() && productDesignationExists(parentLabel());
}

void ProductCreationForm::initValidators(){
    //match any float from 0 to 100
    auto validator = new QRegExpValidator(QRegExp("[0-9]{1,2}|[0-9]{1,2}[.|,][0-9]{0,2}|100"), this);
    vta->setValidator(validator);
    reduction->setValidator(validator);

    ref_validator = new QRegExpValidator(this);
    ledit_reference->setValidator(ref_validator);

    desig_validator = new QRegExpValidator(this);
    ledit_designation->setValidator(desig_validator);

    ledit_puchase_price->setValidator(new QIntValidator(0,INT_MAX,this));
    ledit_colise_mere->setValidator(new QIntValidator(1,INT_MAX,this));

    derive_colise_validator = new QIntValidator(this);
    ledit_colise_derive->setValidator(derive_colise_validator);

    sale_price_validator = new QIntValidator(this);
    ledit_sale_price->setValidator(sale_price_validator);

    auto barcode_validator = new QRegExpValidator(this);
    barcode_validator->setRegExp(QRegExp(QString("\\w+")));
    ledit_bar_code->setValidator(barcode_validator);
}

void ProductCreationForm::saveDefaultsLabels(){
    //We save the default labels captions
    purchase_price_default_label = lbl_purchase_price->text();
    colise_mere_default_label = lbl_colise_mere->text();
}

QString ProductCreationForm::parentLabel() const{
    return productComboBox()->currentText().simplified();
}

QString ProductCreationForm::familyLabel() const{
    return cbox_family->lineEdit()->text().trimmed();
}

QString ProductCreationForm::productLabel() const{
    return ledit_designation->text().trimmed();
}

QString ProductCreationForm::bareCode() const{
    return ledit_bar_code->text().simplified();
}

QString ProductCreationForm::reference() const{
    return ledit_reference->text().simplified();
}

ulong ProductCreationForm::salePrice() const{
    return ledit_sale_price->text().simplified().toLong();
}

qreal ProductCreationForm::purchasePrice() const{
    return ledit_puchase_price->text().simplified().toDouble();
}

int ProductCreationForm::coliseMere() const{
    return ledit_colise_mere->text().simplified().toInt();
}

uint ProductCreationForm::coliseDerive() const{
    return ledit_colise_derive->text().simplified().toInt();
}

float ProductCreationForm::remise(){
    return reduction->text().simplified().toFloat();
}

int ProductCreationForm::grosPhysQty() const{
    return ledit_phys_gros->text().simplified().toInt();
}

int ProductCreationForm::detailPhysQty() const{
    return ledit_phys_details->text().simplified().toInt();
}

int ProductCreationForm::addedGrosPhysQty() const{
    return ledit_phys_added_gros->text().simplified().toInt();
}

int ProductCreationForm::addedDetailPhysQty() const{
    return ledit_phys_added_details->text().simplified().toInt();
}

int ProductCreationForm::grosTheoQty() const{
    return ledit_theo_gros->text().simplified().toInt();
}

int ProductCreationForm::detailTheosQty() const{
    return ledit_theo_details->text().toInt();
}

QAbstractItemModel* ProductCreationForm::model() const{
    return productComboBox()->model();
}

QComboBox* ProductCreationForm::productComboBox() const{
    if(cbox_med->isVisible())
        return cbox_med;
    else
        return cbox_article;
}

QComboBox* ProductCreationForm::familyComboBox(){
    return cbox_family;
}
