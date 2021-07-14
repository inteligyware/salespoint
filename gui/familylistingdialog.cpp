#include "views.h"
#include "models.h"
#include "familycreationform.h"

FamilyListingDialog::FamilyListingDialog(ODBFamilyModel *model , int defaultsortcolumn ,  QWidget *parent):
    ListingDialog(model,defaultsortcolumn,parent)
{
    setVisibleTail(true);
    setVisibleTailItem(ListingDialog::CLOSE,false);
    enableHeadItem(ListingDialog::CBOX,true);
//    view()->setColumnHidden(ODBFamilyModel::ID, true);
    form = new FamilyCreationForm(this);
}

FamilyCreationForm* FamilyListingDialog::creationForm() const{
    return form;
}

int FamilyListingDialog::addItem(){
    return form->showForm();
}

//void FamilyListingDialog::removeItems(){
//    auto selection_model = view()->selectionModel();
//    if(selection_model->hasSelection()){
//        auto index = selection_model->currentIndex();
//        auto id = proxyModel()->data(proxyModel()->index(index.row(),ODBFamilyModel::ID)).toLongLong();
//        dynamic_cast<ODBFamilyModel*>(sourceModel())->removeItemById(id);
//    }
//}

void FamilyListingDialog::removeItems(){
    auto selection_model = view()->selectionModel();
    if (!selection_model->hasSelection()) return ;

    auto indexes = selection_model->selectedRows();

    QList<ulong> list;
    for(auto& index : indexes)
        list.append(proxyModel()->data(proxyModel()->index(index.row(),ODBFamilyModel::ID)).toLongLong());

    dynamic_cast<ODBFamilyModel*>(sourceModel())->removeItemsByIds(list);
    emit selection_model->selectionChanged(QItemSelection(),QItemSelection());
}

void FamilyListingDialog::showItem(){
    addItem();
}
