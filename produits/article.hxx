/**
 * Project InteligyPharma
 * @author Gilles BENE
 * @version 1.0
 */

#ifndef _ARTICLE_HXX
#define _ARTICLE_HXX

    #include "article.h"
    #include "../version.hxx"

    #pragma db object(Article) definition
    #pragma db member(Article::reference_) type("VARCHAR(10)") unique not_null
    #pragma db member(Article::famille_) not_null

    #ifdef ODB_COMPILER
        #include "produit.hxx"
        #include "famille.hxx"
    #endif

#endif //_ARTICLE_HXX
