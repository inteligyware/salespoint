/**
 * Project InteligyPharma
 * @author Gilles BENE
 * @version 1.0
 */


#ifndef _VENTE_H
#define _VENTE_H

#include "Sortie.h"


class Vente: public Sortie {
public: 
    
    Client getClient();
    
    /**
     * @param value
     */
    void setClient(Client value);
    
    Caisse getCaisse();
    
    /**
     * @param value
     */
    void setCaisse(Caisse value);
private: 
    Client client;
    Caisse caisse;
};

#endif //_VENTE_H