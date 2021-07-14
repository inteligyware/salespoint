/**
 * Project InteligyPharma
 * @author Gilles BENE
 * @version 1.0
 */

#ifndef _DOCUMENT_HXX
#define _DOCUMENT_HXX

    #include "document.h"
    #include "../version.hxx"

    #pragma db object(Document) abstract definition
    #pragma db member(Document::id_) id auto
    //#pragma db member(Document::contenu_) null

#endif //_DOCUMENT_HXX
