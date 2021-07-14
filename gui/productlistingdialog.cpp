#include "views.h"
#include "models.h"
#include "productcreationform.h"
#include "familycreationform.h"

ProductListingDialog::ProductListingDialog(QAbstractItemModel *model , int defaultsortcolumn, FamilyCreationForm *familyform,  QWidget *parent) :
    ListingDialog(model,defaultsortcolumn,parent), family_form{familyform}
{
    setVisibleTail(true);
    setVisibleTailItem(ListingDialog::CLOSE,false);
    enableHeadItem(ListingDialog::CBOX,true);

    for( auto i = model->columnCount() - ODBProductModel::ID_PRODUIT_PARENT ; i > 0 ; i--)
        removeComboboxItem(ODBProductModel::ID_PRODUIT_PARENT);

    form = new ProductCreationForm(this);
    form->setFamilyCreationForm(family_form);
}

int ProductListingDialog::addItem(){
    auto productmodel = dynamic_cast<ODBProductModel*>(sourceModel());
    auto tmp = dynamic_cast<FamilyListingDialog*>(family_form->parent())->sourceModel();
    auto family_model = dynamic_cast<ODBFamilyModel*>(tmp);

    form->setMedicamentComboBox(productmodel);
    form->setArticleComboBox(productmodel);
    form->setFamilyComboBoxModel(family_model);

    form->gotoInitialState();
    return form->exec();
}

void ProductListingDialog::removeItems(){

}

void ProductListingDialog::showItem(){

}

ProductCreationForm* ProductListingDialog::creationForm() const{
    return form;
}
