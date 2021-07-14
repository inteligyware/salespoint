#ifndef FAMILYCREATIONFORM_H
#define FAMILYCREATIONFORM_H
#include "views.h"
#include "ui_familycreationform.h"
#include "include/produits.h"
#include <QDialog>

class FamilyCreationForm : public QDialog , private Ui::FamilyCreationForm
{
    Q_OBJECT

public:
    explicit FamilyCreationForm(FamilyListingDialog *parent);
    SPFamille family() const;

public slots:    
    int showForm();

private slots:
    void clear();
    void save();
    void quit();
    void resetGeneralData();
    void activateButtonSave();
    void activateButtonClear();
    void gotoInitialState();

private:
   void connectWidgets();
   bool isValidReference(const QString& reference) const;
   bool isUnique(const QString& value, int column)const;
   SPFamille grabFamily() const;

   mutable SPFamille _family {NULL};
};

#endif // FAMILYCREATIONFORM_H
