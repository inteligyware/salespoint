// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

#ifndef DETAILSSORTIE_ODB_HXX
#define DETAILSSORTIE_ODB_HXX

// Begin prologue.
//
#include <odb/qt/version.hxx>
#if ODB_QT_VERSION != 2040000 // 2.4.0
#  error ODB and C++ compilers see different libodb-qt interface versions
#endif
#include <odb/qt/basic/pgsql/qstring-traits.hxx>
#include <odb/qt/basic/pgsql/qbyte-array-traits.hxx>
#include <odb/qt/basic/pgsql/quuid-traits.hxx>
#include <odb/qt/containers/qhash-traits.hxx>
#include <odb/qt/containers/qlist-traits.hxx>
#include <odb/qt/containers/qlinked-list-traits.hxx>
#include <odb/qt/containers/qmap-traits.hxx>
#include <odb/qt/containers/qset-traits.hxx>
#include <odb/qt/containers/qvector-traits.hxx>
#include <odb/qt/date-time/pgsql/qdate-traits.hxx>
#include <odb/qt/date-time/pgsql/qtime-traits.hxx>
#include <odb/qt/date-time/pgsql/qdate-time-traits.hxx>
#include <QtCore/QSharedPointer>
#include <odb/qt/smart-ptr/pointer-traits.hxx>
#include <odb/qt/smart-ptr/wrapper-traits.hxx>
#include <QtCore/QSharedPointer>


//
// End prologue.

#include <odb/version.hxx>

#if (ODB_VERSION != 20400UL)
#error ODB runtime version mismatch
#endif

#include <odb/pre.hxx>

#include "detailssortie.hxx"

#include "document-odb.hxx"
#include "../docsrelances/relancable-odb.hxx"
#include "relance-odb.hxx"
#include "fonction-odb.hxx"
#include "personne-odb.hxx"
#include "../personnels/personnel-odb.hxx"
#include "emballage-odb.hxx"
#include "fournisseur-odb.hxx"
#include "histprix-odb.hxx"
#include "prixfourn-odb.hxx"
#include "../produits/produit-odb.hxx"
#include "tonnage-odb.hxx"
#include "facture-odb.hxx"
#include "reglement-odb.hxx"
#include "sortie-odb.hxx"

#include <memory>
#include <cstddef>

#include <odb/core.hxx>
#include <odb/traits.hxx>
#include <odb/callback.hxx>
#include <odb/wrapper-traits.hxx>
#include <odb/pointer-traits.hxx>
#include <odb/container-traits.hxx>
#include <odb/session.hxx>
#include <odb/cache-traits.hxx>
#include <odb/result.hxx>
#include <odb/simple-object-result.hxx>

#include <odb/details/unused.hxx>
#include <odb/details/shared-ptr.hxx>

namespace odb
{
  // DetailsSortie
  //
  template <>
  struct class_traits< ::DetailsSortie >
  {
    static const class_kind kind = class_object;
  };

  template <>
  class access::object_traits< ::DetailsSortie >
  {
    public:
    typedef ::DetailsSortie object_type;
    typedef ::QSharedPointer< ::DetailsSortie > pointer_type;
    typedef odb::pointer_traits<pointer_type> pointer_traits;

    static const bool polymorphic = false;

    typedef ::quint64 id_type;

    static const bool auto_id = true;

    static const bool abstract = false;

    static id_type
    id (const object_type&);

    typedef
    odb::pointer_cache_traits<
      pointer_type,
      odb::session >
    pointer_cache_traits;

    typedef
    odb::reference_cache_traits<
      object_type,
      odb::session >
    reference_cache_traits;

    static void
    callback (database&, object_type&, callback_event);

    static void
    callback (database&, const object_type&, callback_event);
  };
}

#include <odb/details/buffer.hxx>

#include <odb/pgsql/version.hxx>
#include <odb/pgsql/forward.hxx>
#include <odb/pgsql/binding.hxx>
#include <odb/pgsql/pgsql-types.hxx>
#include <odb/pgsql/query.hxx>

namespace odb
{
  // DetailsSortie
  //
  template <typename A>
  struct pointer_query_columns< ::DetailsSortie, id_pgsql, A >
  {
    // id
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::quint64,
        pgsql::id_bigint >::query_type,
      pgsql::id_bigint >
    id_type_;

    static const id_type_ id;

    // qte
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::quint32,
        pgsql::id_integer >::query_type,
      pgsql::id_integer >
    qte_type_;

    static const qte_type_ qte;

    // prix_unitaire
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::quint32,
        pgsql::id_integer >::query_type,
      pgsql::id_integer >
    prix_unitaire_type_;

    static const prix_unitaire_type_ prix_unitaire;

    // remise
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        float,
        pgsql::id_real >::query_type,
      pgsql::id_real >
    remise_type_;

    static const remise_type_ remise;

    // produit
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::ulong,
        pgsql::id_bigint >::query_type,
      pgsql::id_bigint >
    produit_type_;

    static const produit_type_ produit;

    // sortie
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::ulong,
        pgsql::id_bigint >::query_type,
      pgsql::id_bigint >
    sortie_type_;

    static const sortie_type_ sortie;
  };

  template <typename A>
  const typename pointer_query_columns< ::DetailsSortie, id_pgsql, A >::id_type_
  pointer_query_columns< ::DetailsSortie, id_pgsql, A >::
  id (A::table_name, "\"id\"", 0);

  template <typename A>
  const typename pointer_query_columns< ::DetailsSortie, id_pgsql, A >::qte_type_
  pointer_query_columns< ::DetailsSortie, id_pgsql, A >::
  qte (A::table_name, "\"qte\"", 0);

  template <typename A>
  const typename pointer_query_columns< ::DetailsSortie, id_pgsql, A >::prix_unitaire_type_
  pointer_query_columns< ::DetailsSortie, id_pgsql, A >::
  prix_unitaire (A::table_name, "\"prix_unitaire\"", 0);

  template <typename A>
  const typename pointer_query_columns< ::DetailsSortie, id_pgsql, A >::remise_type_
  pointer_query_columns< ::DetailsSortie, id_pgsql, A >::
  remise (A::table_name, "\"remise\"", 0);

  template <typename A>
  const typename pointer_query_columns< ::DetailsSortie, id_pgsql, A >::produit_type_
  pointer_query_columns< ::DetailsSortie, id_pgsql, A >::
  produit (A::table_name, "\"produit\"", 0);

  template <typename A>
  const typename pointer_query_columns< ::DetailsSortie, id_pgsql, A >::sortie_type_
  pointer_query_columns< ::DetailsSortie, id_pgsql, A >::
  sortie (A::table_name, "\"sortie\"", 0);

  template <>
  class access::object_traits_impl< ::DetailsSortie, id_pgsql >:
    public access::object_traits< ::DetailsSortie >
  {
    public:
    struct id_image_type
    {
      long long id_value;
      bool id_null;

      std::size_t version;
    };

    struct image_type
    {
      // id_
      //
      long long id_value;
      bool id_null;

      // qte_
      //
      int qte_value;
      bool qte_null;

      // prix_unitaire_
      //
      int prix_unitaire_value;
      bool prix_unitaire_null;

      // remise_
      //
      float remise_value;
      bool remise_null;

      // produit_
      //
      long long produit_value;
      bool produit_null;

      // sortie_
      //
      long long sortie_value;
      bool sortie_null;

      std::size_t version;
    };

    struct extra_statement_cache_type;

    struct produit_tag;
    struct sortie_tag;

    using object_traits<object_type>::id;

    static id_type
    id (const id_image_type&);

    static id_type
    id (const image_type&);

    static bool
    grow (image_type&,
          bool*);

    static void
    bind (pgsql::bind*,
          image_type&,
          pgsql::statement_kind);

    static void
    bind (pgsql::bind*, id_image_type&);

    static bool
    init (image_type&,
          const object_type&,
          pgsql::statement_kind);

    static void
    init (object_type&,
          const image_type&,
          database*);

    static void
    init (id_image_type&, const id_type&);

    typedef pgsql::object_statements<object_type> statements_type;

    typedef pgsql::query_base query_base_type;

    static const std::size_t column_count = 6UL;
    static const std::size_t id_column_count = 1UL;
    static const std::size_t inverse_column_count = 0UL;
    static const std::size_t readonly_column_count = 0UL;
    static const std::size_t managed_optimistic_column_count = 0UL;

    static const std::size_t separate_load_column_count = 0UL;
    static const std::size_t separate_update_column_count = 0UL;

    static const bool versioned = false;

    static const char persist_statement[];
    static const char find_statement[];
    static const char update_statement[];
    static const char erase_statement[];
    static const char query_statement[];
    static const char erase_query_statement[];

    static const char table_name[];

    static void
    persist (database&, object_type&);

    static pointer_type
    find (database&, const id_type&);

    static bool
    find (database&, const id_type&, object_type&);

    static bool
    reload (database&, object_type&);

    static void
    update (database&, const object_type&);

    static void
    erase (database&, const id_type&);

    static void
    erase (database&, const object_type&);

    static result<object_type>
    query (database&, const query_base_type&);

    static unsigned long long
    erase_query (database&, const query_base_type&);

    static const char persist_statement_name[];
    static const char find_statement_name[];
    static const char update_statement_name[];
    static const char erase_statement_name[];
    static const char query_statement_name[];
    static const char erase_query_statement_name[];

    static const unsigned int persist_statement_types[];
    static const unsigned int find_statement_types[];
    static const unsigned int update_statement_types[];

    public:
    static bool
    find_ (statements_type&,
           const id_type*);

    static void
    load_ (statements_type&,
           object_type&,
           bool reload);
  };

  template <>
  class access::object_traits_impl< ::DetailsSortie, id_common >:
    public access::object_traits_impl< ::DetailsSortie, id_pgsql >
  {
  };

  // DetailsSortie
  //
  template <>
  struct alias_traits<
    ::Produit,
    id_pgsql,
    access::object_traits_impl< ::DetailsSortie, id_pgsql >::produit_tag>
  {
    static const char table_name[];
  };

  template <>
  struct alias_traits<
    ::Sortie,
    id_pgsql,
    access::object_traits_impl< ::DetailsSortie, id_pgsql >::sortie_tag>
  {
    static const char table_name[];
  };

  template <>
  struct query_columns_base< ::DetailsSortie, id_pgsql >
  {
    // produit
    //
    typedef
    odb::alias_traits<
      ::Produit,
      id_pgsql,
      access::object_traits_impl< ::DetailsSortie, id_pgsql >::produit_tag>
    produit_alias_;

    // sortie
    //
    typedef
    odb::alias_traits<
      ::Sortie,
      id_pgsql,
      access::object_traits_impl< ::DetailsSortie, id_pgsql >::sortie_tag>
    sortie_alias_;
  };

  template <typename A>
  struct query_columns< ::DetailsSortie, id_pgsql, A >:
    query_columns_base< ::DetailsSortie, id_pgsql >
  {
    // id
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::quint64,
        pgsql::id_bigint >::query_type,
      pgsql::id_bigint >
    id_type_;

    static const id_type_ id;

    // qte
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::quint32,
        pgsql::id_integer >::query_type,
      pgsql::id_integer >
    qte_type_;

    static const qte_type_ qte;

    // prix_unitaire
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::quint32,
        pgsql::id_integer >::query_type,
      pgsql::id_integer >
    prix_unitaire_type_;

    static const prix_unitaire_type_ prix_unitaire;

    // remise
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        float,
        pgsql::id_real >::query_type,
      pgsql::id_real >
    remise_type_;

    static const remise_type_ remise;

    // produit
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::ulong,
        pgsql::id_bigint >::query_type,
      pgsql::id_bigint >
    produit_column_type_;

    typedef
    odb::query_pointer<
      odb::pointer_query_columns<
        ::Produit,
        id_pgsql,
        produit_alias_ > >
    produit_pointer_type_;

    struct produit_type_: produit_pointer_type_, produit_column_type_
    {
      produit_type_ (const char* t, const char* c, const char* conv)
        : produit_column_type_ (t, c, conv)
      {
      }
    };

    static const produit_type_ produit;

    // sortie
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::ulong,
        pgsql::id_bigint >::query_type,
      pgsql::id_bigint >
    sortie_column_type_;

    typedef
    odb::query_pointer<
      odb::pointer_query_columns<
        ::Sortie,
        id_pgsql,
        sortie_alias_ > >
    sortie_pointer_type_;

    struct sortie_type_: sortie_pointer_type_, sortie_column_type_
    {
      sortie_type_ (const char* t, const char* c, const char* conv)
        : sortie_column_type_ (t, c, conv)
      {
      }
    };

    static const sortie_type_ sortie;
  };

  template <typename A>
  const typename query_columns< ::DetailsSortie, id_pgsql, A >::id_type_
  query_columns< ::DetailsSortie, id_pgsql, A >::
  id (A::table_name, "\"id\"", 0);

  template <typename A>
  const typename query_columns< ::DetailsSortie, id_pgsql, A >::qte_type_
  query_columns< ::DetailsSortie, id_pgsql, A >::
  qte (A::table_name, "\"qte\"", 0);

  template <typename A>
  const typename query_columns< ::DetailsSortie, id_pgsql, A >::prix_unitaire_type_
  query_columns< ::DetailsSortie, id_pgsql, A >::
  prix_unitaire (A::table_name, "\"prix_unitaire\"", 0);

  template <typename A>
  const typename query_columns< ::DetailsSortie, id_pgsql, A >::remise_type_
  query_columns< ::DetailsSortie, id_pgsql, A >::
  remise (A::table_name, "\"remise\"", 0);

  template <typename A>
  const typename query_columns< ::DetailsSortie, id_pgsql, A >::produit_type_
  query_columns< ::DetailsSortie, id_pgsql, A >::
  produit (A::table_name, "\"produit\"", 0);

  template <typename A>
  const typename query_columns< ::DetailsSortie, id_pgsql, A >::sortie_type_
  query_columns< ::DetailsSortie, id_pgsql, A >::
  sortie (A::table_name, "\"sortie\"", 0);
}

#include "detailssortie-odb.ixx"

#include <odb/post.hxx>

#endif // DETAILSSORTIE_ODB_HXX
