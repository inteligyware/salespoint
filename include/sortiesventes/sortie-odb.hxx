// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

#ifndef SORTIE_ODB_HXX
#define SORTIE_ODB_HXX

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

#include "sortie.hxx"

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
#include "reglement-odb.hxx"

#include <memory>
#include <cstddef>
#include <string>

#include <odb/core.hxx>
#include <odb/traits.hxx>
#include <odb/callback.hxx>
#include <odb/wrapper-traits.hxx>
#include <odb/pointer-traits.hxx>
#include <odb/container-traits.hxx>
#include <odb/session.hxx>
#include <odb/cache-traits.hxx>
#include <odb/polymorphic-info.hxx>
#include <odb/result.hxx>
#include <odb/polymorphic-object-result.hxx>

#include <odb/details/unused.hxx>
#include <odb/details/shared-ptr.hxx>

namespace odb
{
  // Sortie
  //
  template <>
  struct class_traits< ::Sortie >
  {
    static const class_kind kind = class_object;
  };

  template <>
  class access::object_traits< ::Sortie >
  {
    public:
    typedef ::Sortie object_type;
    typedef ::QSharedPointer< ::Sortie > pointer_type;
    typedef odb::pointer_traits<pointer_type> pointer_traits;

    static const bool polymorphic = true;

    typedef ::Sortie root_type;
    typedef ::std::string discriminator_type;
    typedef polymorphic_map<object_type> map_type;
    typedef polymorphic_concrete_info<object_type> info_type;
    typedef polymorphic_abstract_info<object_type> abstract_info_type;

    static const std::size_t depth = 1UL;

    typedef ::ulong id_type;

    static const bool auto_id = true;

    static const bool abstract = true;

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
  // Sortie
  //
  template <typename A>
  struct pointer_query_columns< ::Sortie, id_pgsql, A >
  {
    // id
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::ulong,
        pgsql::id_bigint >::query_type,
      pgsql::id_bigint >
    id_type_;

    static const id_type_ id;

    // typeid_
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::std::string,
        pgsql::id_string >::query_type,
      pgsql::id_string >
    typeid__type_;

    static const typeid__type_ typeid_;

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

    // responsable
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::quint32,
        pgsql::id_integer >::query_type,
      pgsql::id_integer >
    responsable_type_;

    static const responsable_type_ responsable;

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
  const typename pointer_query_columns< ::Sortie, id_pgsql, A >::id_type_
  pointer_query_columns< ::Sortie, id_pgsql, A >::
  id (A::table_name, "\"id\"", 0);

  template <typename A>
  const typename pointer_query_columns< ::Sortie, id_pgsql, A >::typeid__type_
  pointer_query_columns< ::Sortie, id_pgsql, A >::
  typeid_ (A::table_name, "\"typeid\"", 0);

  template <typename A>
  const typename pointer_query_columns< ::Sortie, id_pgsql, A >::date_type_
  pointer_query_columns< ::Sortie, id_pgsql, A >::
  date (A::table_name, "\"date\"", 0);

  template <typename A>
  const typename pointer_query_columns< ::Sortie, id_pgsql, A >::responsable_type_
  pointer_query_columns< ::Sortie, id_pgsql, A >::
  responsable (A::table_name, "\"responsable\"", 0);

  template <typename A>
  const typename pointer_query_columns< ::Sortie, id_pgsql, A >::facture_type_
  pointer_query_columns< ::Sortie, id_pgsql, A >::
  facture (A::table_name, "\"facture\"", 0);

  template <>
  class access::object_traits_impl< ::Sortie, id_pgsql >:
    public access::object_traits< ::Sortie >
  {
    public:
    typedef object_traits_impl<root_type, id_pgsql> root_traits;

    struct discriminator_image_type
    {
      details::buffer discriminator_value;
      std::size_t discriminator_size;
      bool discriminator_null;

      std::size_t version;
    };

    struct id_image_type
    {
      long long id_value;
      bool id_null;

      std::size_t version;
    };

    static map_type* map;
    static const abstract_info_type info;

    struct image_type
    {
      // id_
      //
      long long id_value;
      bool id_null;

      // typeid_
      //
      details::buffer typeid_value;
      std::size_t typeid_size;
      bool typeid_null;

      // date_
      //
      long long date_value;
      bool date_null;

      // responsable_
      //
      int responsable_value;
      bool responsable_null;

      // facture_
      //
      long long facture_value;
      bool facture_null;

      std::size_t version;
    };

    struct extra_statement_cache_type;

    // details_
    //
    struct details_traits
    {
      static const char select_name[];
      static const char insert_name[];
      static const char delete_name[];

      static const unsigned int insert_types[];

      static const std::size_t id_column_count = 1UL;
      static const std::size_t data_column_count = 2UL;

      static const bool versioned = false;

      static const char insert_statement[];
      static const char select_statement[];
      static const char delete_statement[];

      typedef ::SPDetails container_type;
      typedef
      odb::access::container_traits<container_type>
      container_traits_type;
      typedef container_traits_type::index_type index_type;
      typedef container_traits_type::value_type value_type;

      typedef ordered_functions<index_type, value_type> functions_type;
      typedef pgsql::container_statements< details_traits > statements_type;

      struct data_image_type
      {
        // value
        //
        long long value_value;
        bool value_null;

        std::size_t version;
      };

      static void
      bind (pgsql::bind*,
            const pgsql::bind* id,
            std::size_t id_size,
            data_image_type&);

      static void
      grow (data_image_type&,
            bool*);

      static void
      init (value_type&,
            const data_image_type&,
            database*);

      static void
      insert (index_type, const value_type&, void*);

      static bool
      select (index_type&, value_type&, void*);

      static void
      delete_ (void*);

      static void
      load (container_type&,
            statements_type&);
    };

    struct responsable_tag;
    struct facture_tag;

    using object_traits<object_type>::id;

    static id_type
    id (const id_image_type&);

    static id_type
    id (const image_type&);

    static discriminator_type
    discriminator (const image_type&);

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

    typedef
    pgsql::polymorphic_root_object_statements<object_type>
    statements_type;

    typedef statements_type root_statements_type;

    typedef pgsql::query_base query_base_type;

    static const std::size_t column_count = 5UL;
    static const std::size_t id_column_count = 1UL;
    static const std::size_t inverse_column_count = 0UL;
    static const std::size_t readonly_column_count = 1UL;
    static const std::size_t managed_optimistic_column_count = 0UL;
    static const std::size_t discriminator_column_count = 1UL;

    static const std::size_t separate_load_column_count = 0UL;
    static const std::size_t separate_update_column_count = 0UL;

    static const bool versioned = false;

    static const char persist_statement[];
    static const char find_statement[];
    static const char find_discriminator_statement[];
    static const char update_statement[];
    static const char erase_statement[];
    static const char query_statement[];
    static const char erase_query_statement[];

    static const char table_name[];

    static void
    persist (database&, object_type&, bool top = true, bool dyn = true);

    static pointer_type
    find (database&, const id_type&);

    static bool
    find (database&, const id_type&, object_type&, bool dyn = true);

    static bool
    reload (database&, object_type&, bool dyn = true);

    static void
    update (database&, const object_type&, bool top = true, bool dyn = true);

    static void
    erase (database&, const id_type&, bool top = true, bool dyn = true);

    static void
    erase (database&, const object_type&, bool top = true, bool dyn = true);

    static result<object_type>
    query (database&, const query_base_type&);

    static unsigned long long
    erase_query (database&, const query_base_type&);

    static const char persist_statement_name[];
    static const char find_statement_name[];
    static const char find_discriminator_statement_name[];
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

    static void
    discriminator_ (statements_type&,
                    const id_type&,
                    discriminator_type*);
  };

  template <>
  class access::object_traits_impl< ::Sortie, id_common >:
    public access::object_traits_impl< ::Sortie, id_pgsql >
  {
  };

  // Sortie
  //
  template <>
  struct alias_traits<
    ::Personne,
    id_pgsql,
    access::object_traits_impl< ::Sortie, id_pgsql >::responsable_tag>
  {
    static const char table_name[];
  };

  template <>
  struct alias_traits<
    ::Personnel,
    id_pgsql,
    access::object_traits_impl< ::Sortie, id_pgsql >::responsable_tag>
  {
    typedef alias_traits<
      ::Personne,
      id_pgsql,
      access::object_traits_impl< ::Sortie, id_pgsql >::responsable_tag>
    base_traits;

    static const char table_name[];
  };

  template <>
  struct alias_traits<
    ::Relancable,
    id_pgsql,
    access::object_traits_impl< ::Sortie, id_pgsql >::facture_tag>
  {
    static const char table_name[];
  };

  template <>
  struct alias_traits<
    ::Facture,
    id_pgsql,
    access::object_traits_impl< ::Sortie, id_pgsql >::facture_tag>
  {
    typedef alias_traits<
      ::Relancable,
      id_pgsql,
      access::object_traits_impl< ::Sortie, id_pgsql >::facture_tag>
    base_traits;

    static const char table_name[];
  };

  template <>
  struct query_columns_base< ::Sortie, id_pgsql >
  {
    // responsable
    //
    typedef
    odb::alias_traits<
      ::Personnel,
      id_pgsql,
      access::object_traits_impl< ::Sortie, id_pgsql >::responsable_tag>
    responsable_alias_;

    // facture
    //
    typedef
    odb::alias_traits<
      ::Facture,
      id_pgsql,
      access::object_traits_impl< ::Sortie, id_pgsql >::facture_tag>
    facture_alias_;
  };

  template <typename A>
  struct query_columns< ::Sortie, id_pgsql, A >:
    query_columns_base< ::Sortie, id_pgsql >
  {
    // id
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::ulong,
        pgsql::id_bigint >::query_type,
      pgsql::id_bigint >
    id_type_;

    static const id_type_ id;

    // typeid_
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::std::string,
        pgsql::id_string >::query_type,
      pgsql::id_string >
    typeid__type_;

    static const typeid__type_ typeid_;

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

    // responsable
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::quint32,
        pgsql::id_integer >::query_type,
      pgsql::id_integer >
    responsable_column_type_;

    typedef
    odb::query_pointer<
      odb::pointer_query_columns<
        ::Personnel,
        id_pgsql,
        responsable_alias_ > >
    responsable_pointer_type_;

    struct responsable_type_: responsable_pointer_type_, responsable_column_type_
    {
      responsable_type_ (const char* t, const char* c, const char* conv)
        : responsable_column_type_ (t, c, conv)
      {
      }
    };

    static const responsable_type_ responsable;

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
  const typename query_columns< ::Sortie, id_pgsql, A >::id_type_
  query_columns< ::Sortie, id_pgsql, A >::
  id (A::table_name, "\"id\"", 0);

  template <typename A>
  const typename query_columns< ::Sortie, id_pgsql, A >::typeid__type_
  query_columns< ::Sortie, id_pgsql, A >::
  typeid_ (A::table_name, "\"typeid\"", 0);

  template <typename A>
  const typename query_columns< ::Sortie, id_pgsql, A >::date_type_
  query_columns< ::Sortie, id_pgsql, A >::
  date (A::table_name, "\"date\"", 0);

  template <typename A>
  const typename query_columns< ::Sortie, id_pgsql, A >::responsable_type_
  query_columns< ::Sortie, id_pgsql, A >::
  responsable (A::table_name, "\"responsable\"", 0);

  template <typename A>
  const typename query_columns< ::Sortie, id_pgsql, A >::facture_type_
  query_columns< ::Sortie, id_pgsql, A >::
  facture (A::table_name, "\"facture\"", 0);
}

#include "sortie-odb.ixx"

#include <odb/post.hxx>

#endif // SORTIE_ODB_HXX
