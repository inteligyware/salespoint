#ifndef SESSIONMANAGER_H
#define SESSIONMANAGER_H

#include <QDialog>
#include "ui_sessionmanager.h"
#include "models.h"

class SessionManager : public QDialog , private Ui::SessionManager
{
    Q_OBJECT
public:
    explicit SessionManager(QWidget *parent = 0);
//    void login(SPODBDatabase db);
    bool loginSucceded() { return _login_status ; }

private slots:
//    void login();
    void activateButtons();

private :
    bool _login_status {false};
//    SPUser _user;
};

#endif // SESSIONMANAGER_H
