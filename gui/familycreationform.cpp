#include "familycreationform.h"
#include <QMessageBox>

FamilyCreationForm::FamilyCreationForm(FamilyListingDialog *parent): QDialog(parent){
    setupUi(this);
    gotoInitialState();
    connectWidgets();
}

int FamilyCreationForm::showForm(){
    gotoInitialState();
    return exec();
}

void FamilyCreationForm::clear(){
    resetGeneralData();
}

void FamilyCreationForm::save(){
    auto spfamille = grabFamily();
    auto model = dynamic_cast<FamilyListingDialog*>(parent())->sourceModel();
    try{
        dynamic_cast<ODBFamilyModel*>(model)->addItem(spfamille);
        QMessageBox::information(this,tr("Creation de Famille"),tr("Operation reussie"));
        gotoInitialState();
        accept();
    }
    catch(const odb::exception& e){
        qDebug() << e.what();
        QMessageBox::warning(this,tr("Creation de Famille"),e.what());
        reject();
    }
}

SPFamille FamilyCreationForm::grabFamily() const{

    SPFamille famille {new Famille(ledit_reference->text().trimmed(),ledit_designation->text().trimmed())};
    auto desc = description->toPlainText().trimmed();
    if(!desc.isEmpty()) famille->setDescription(desc);
    _family.swap(famille);
    return _family;
}

SPFamille FamilyCreationForm::family() const{
   return _family;
}

void FamilyCreationForm::quit(){
    reject();
}

void FamilyCreationForm::resetGeneralData(){
    ledit_reference->clear();
    ledit_designation->clear();
    description->clear();
}

void FamilyCreationForm::gotoInitialState(){
    clear();
    bool disabled = true;
    pbtn_clear->setDisabled(disabled);
    pbtn_save->setDisabled(disabled);
    pbtn_quit->setDisabled(!disabled);
}

void FamilyCreationForm::activateButtonSave(){
    auto reference = ledit_reference->text().simplified();
    auto designation = ledit_designation->text().simplified();
    bool activated = !reference.isEmpty() && !designation.isEmpty();
    activated &=  isUnique(reference, ODBFamilyModel::REFERENCE);
    activated &=  isUnique(designation, ODBFamilyModel::DESIGNATION) ;
    pbtn_save->setEnabled(activated);
}

void FamilyCreationForm::activateButtonClear(){
    bool activated = !ledit_reference->text().trimmed().isEmpty() | !ledit_designation->text().trimmed().isEmpty();
    activated |=  !description->toPlainText().trimmed().isEmpty();
    pbtn_clear->setEnabled(activated);
}

bool FamilyCreationForm::isValidReference(const QString& reference) const{
    return isUnique(reference, ODBProductModel::REFERENCE);
}

bool FamilyCreationForm::isUnique(const QString& value, int column) const{
    auto model = dynamic_cast<FamilyListingDialog*>(parent())->sourceModel();
    return dynamic_cast<ODBFamilyModel*>(model)->isUnique(value,column);
}

void FamilyCreationForm::connectWidgets(){
    connect(pbtn_save, SIGNAL(clicked(bool)), SLOT(save()));
    connect(pbtn_clear, SIGNAL(clicked(bool)), SLOT(gotoInitialState()));
    connect(pbtn_quit, SIGNAL(clicked(bool)), SLOT(quit()));

    connect(ledit_reference, SIGNAL(textEdited(QString)), SLOT(activateButtonSave()));
    connect(ledit_designation, SIGNAL(textEdited(QString)), SLOT(activateButtonSave()));

    connect(ledit_reference, SIGNAL(textEdited(QString)), SLOT(activateButtonClear()));
    connect(ledit_designation, SIGNAL(textEdited(QString)), SLOT(activateButtonClear()));
    connect(description, SIGNAL(textChanged()), SLOT(activateButtonClear()));
}
