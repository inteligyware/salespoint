// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

#ifndef REGLEMENT_ODB_HXX
#define REGLEMENT_ODB_HXX

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

#include "reglement.hxx"

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
#include "detailssortie-odb.hxx"
#include "facture-odb.hxx"
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
  // Reglement
  //
  template <>
  struct class_traits< ::Reglement >
  {
    static const class_kind kind = class_object;
  };

  template <>
  class access::object_traits< ::Reglement >
  {
    public:
    typedef ::Reglement object_type;
    typedef ::QSharedPointer< ::Reglement > pointer_type;
    typedef odb::pointer_traits<pointer_type> pointer_traits;

    static const bool polymorphic = false;

    typedef ::quint32 id_type;

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
  // Reglement
  //
  template <typename A>
  struct pointer_query_columns< ::Reglement, id_pgsql, A >
  {
    // id
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::quint32,
        pgsql::id_integer >::query_type,
      pgsql::id_integer >
    id_type_;

    static const id_type_ id;

    // montant
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::quint32,
        pgsql::id_integer >::query_type,
      pgsql::id_integer >
    montant_type_;

    static const montant_type_ montant;

    // date
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::QDateTime,
        pgsql::id_timestamp >::query_type,
      pgsql::id_timestamp >
    date_type_;

    static const date_type_ date;

    // facture
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::ulong,
        pgsql::id_bigint >::query_type,
      pgsql::id_bigint >
    facture_type_;

    static const facture_type_ facture;
  };

  template <typename A>
  const typename pointer_query_columns< ::Reglement, id_pgsql, A >::id_type_
  pointer_query_columns< ::Reglement, id_pgsql, A >::
  id (A::table_name, "\"id\"", 0);

  template <typename A>
  const typename pointer_query_columns< ::Reglement, id_pgsql, A >::montant_type_
  pointer_query_columns< ::Reglement, id_pgsql, A >::
  montant (A::table_name, "\"montant\"", 0);

  template <typename A>
  const typename pointer_query_columns< ::Reglement, id_pgsql, A >::date_type_
  pointer_query_columns< ::Reglement, id_pgsql, A >::
  date (A::table_name, "\"date\"", 0);

  template <typename A>
  const typename pointer_query_columns< ::Reglement, id_pgsql, A >::facture_type_
  pointer_query_columns< ::Reglement, id_pgsql, A >::
  facture (A::table_name, "\"facture\"", 0);

  template <>
  class access::object_traits_impl< ::Reglement, id_pgsql >:
    public access::object_traits< ::Reglement >
  {
    public:
    struct id_image_type
    {
      int id_value;
      bool id_null;

      std::size_t version;
    };

    struct image_type
    {
      // id_
      //
      int id_value;
      bool id_null;

      // montant_
      //
      int montant_value;
      bool montant_null;

      // date_
      //
      long long date_value;
      bool date_null;

      // facture_
      //
      long long facture_value;
      bool facture_null;

      std::size_t version;
    };

    struct extra_statement_cache_type;

    struct facture_tag;

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

    static const std::size_t column_count = 4UL;
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
  class access::object_traits_impl< ::Reglement, id_common >:
    public access::object_traits_impl< ::Reglement, id_pgsql >
  {
  };

  // Reglement
  //
  template <>
  struct alias_traits<
    ::Relancable,
    id_pgsql,
    access::object_traits_impl< ::Reglement, id_pgsql >::facture_tag>
  {
    static const char table_name[];
  };

  template <>
  struct alias_traits<
    ::Facture,
    id_pgsql,
    access::object_traits_impl< ::Reglement, id_pgsql >::facture_tag>
  {
    typedef alias_traits<
      ::Relancable,
      id_pgsql,
      access::object_traits_impl< ::Reglement, id_pgsql >::facture_tag>
    base_traits;

    static const char table_name[];
  };

  template <>
  struct query_columns_base< ::Reglement, id_pgsql >
  {
    // facture
    //
    typedef
    odb::alias_traits<
      ::Facture,
      id_pgsql,
      access::object_traits_impl< ::Reglement, id_pgsql >::facture_tag>
    facture_alias_;
  };

  template <typename A>
  struct query_columns< ::Reglement, id_pgsql, A >:
    query_columns_base< ::Reglement, id_pgsql >
  {
    // id
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::quint32,
        pgsql::id_integer >::query_type,
      pgsql::id_integer >
    id_type_;

    static const id_type_ id;

    // montant
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::quint32,
        pgsql::id_integer >::query_type,
      pgsql::id_integer >
    montant_type_;

    static const montant_type_ montant;

    // date
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::QDateTime,
        pgsql::id_timestamp >::query_type,
      pgsql::id_timestamp >
    date_type_;

    static const date_type_ date;

    // facture
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::ulong,
        pgsql::id_bigint >::query_type,
      pgsql::id_bigint >
    facture_column_type_;

    typedef
    odb::query_pointer<
      odb::pointer_query_columns<
        ::Facture,
        id_pgsql,
        facture_alias_ > >
    facture_pointer_type_;

    struct facture_type_: facture_pointer_type_, facture_column_type_
    {
      facture_type_ (const char* t, const char* c, const char* conv)
        : facture_column_type_ (t, c, conv)
      {
      }
    };

    static const facture_type_ facture;
  };

  template <typename A>
  const typename query_columns< ::Reglement, id_pgsql, A >::id_type_
  query_columns< ::Reglement, id_pgsql, A >::
  id (A::table_name, "\"id\"", 0);

  template <typename A>
  const typename query_columns< ::Reglement, id_pgsql, A >::montant_type_
  query_columns< ::Reglement, id_pgsql, A >::
  montant (A::table_name, "\"montant\"", 0);

  template <typename A>
  const typename query_columns< ::Reglement, id_pgsql, A >::date_type_
  query_columns< ::Reglement, id_pgsql, A >::
  date (A::table_name, "\"date\"", 0);

  template <typename A>
  const typename query_columns< ::Reglement, id_pgsql, A >::facture_type_
  query_columns< ::Reglement, id_pgsql, A >::
  facture (A::table_name, "\"facture\"", 0);
}

#include "reglement-odb.ixx"

#include <odb/post.hxx>

#endif // REGLEMENT_ODB_HXX
