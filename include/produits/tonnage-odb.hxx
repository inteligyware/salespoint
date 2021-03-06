// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

#ifndef TONNAGE_ODB_HXX
#define TONNAGE_ODB_HXX

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

#include "tonnage.hxx"

#include "emballage-odb.hxx"
#include "fournisseur-odb.hxx"
#include "histprix-odb.hxx"
#include "prixfourn-odb.hxx"
#include "produit-odb.hxx"

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
  // Tonnage
  //
  template <>
  struct class_traits< ::Tonnage >
  {
    static const class_kind kind = class_object;
  };

  template <>
  class access::object_traits< ::Tonnage >
  {
    public:
    typedef ::Tonnage object_type;
    typedef ::QSharedPointer< ::Tonnage > pointer_type;
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
  // Tonnage
  //
  template <typename A>
  struct query_columns< ::Tonnage, id_pgsql, A >
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

    // nb_unite
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::quint32,
        pgsql::id_integer >::query_type,
      pgsql::id_integer >
    nb_unite_type_;

    static const nb_unite_type_ nb_unite;

    // qte_par_unite
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::quint32,
        pgsql::id_integer >::query_type,
      pgsql::id_integer >
    qte_par_unite_type_;

    static const qte_par_unite_type_ qte_par_unite;
  };

  template <typename A>
  const typename query_columns< ::Tonnage, id_pgsql, A >::id_type_
  query_columns< ::Tonnage, id_pgsql, A >::
  id (A::table_name, "\"id\"", 0);

  template <typename A>
  const typename query_columns< ::Tonnage, id_pgsql, A >::nb_unite_type_
  query_columns< ::Tonnage, id_pgsql, A >::
  nb_unite (A::table_name, "\"nb_unite\"", 0);

  template <typename A>
  const typename query_columns< ::Tonnage, id_pgsql, A >::qte_par_unite_type_
  query_columns< ::Tonnage, id_pgsql, A >::
  qte_par_unite (A::table_name, "\"qte_par_unite\"", 0);

  template <typename A>
  struct pointer_query_columns< ::Tonnage, id_pgsql, A >:
    query_columns< ::Tonnage, id_pgsql, A >
  {
  };

  template <>
  class access::object_traits_impl< ::Tonnage, id_pgsql >:
    public access::object_traits< ::Tonnage >
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

      // nb_unite_
      //
      int nb_unite_value;
      bool nb_unite_null;

      // qte_par_unite_
      //
      int qte_par_unite_value;
      bool qte_par_unite_null;

      std::size_t version;
    };

    struct extra_statement_cache_type;

    // produits_
    //
    struct produits_traits
    {
      static const char select_name[];
      static const char insert_name[];
      static const char update_name[];
      static const char delete_name[];

      static const unsigned int insert_types[];
      static const unsigned int update_types[];
      static const unsigned int delete_types[];

      static const std::size_t id_column_count = 1UL;
      static const std::size_t value_column_count = 1UL;
      static const std::size_t cond_column_count = 2UL;
      static const std::size_t data_column_count = 3UL;

      static const bool versioned = false;

      static const char insert_statement[];
      static const char select_statement[];
      static const char update_statement[];
      static const char delete_statement[];

      typedef ::odb::vector< ::QLazySharedPointer< ::Produit > > container_type;
      typedef
      odb::access::container_traits<container_type>
      container_traits_type;
      typedef container_traits_type::index_type index_type;
      typedef container_traits_type::value_type value_type;

      typedef smart_ordered_functions<index_type, value_type> functions_type;
      typedef pgsql::smart_container_statements< produits_traits > statements_type;

      struct cond_image_type
      {
        // index
        //
        long long index_value;
        bool index_null;

        std::size_t version;
      };

      struct data_image_type
      {
        // index
        //
        long long index_value;
        bool index_null;

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
            cond_image_type&);

      static void
      bind (pgsql::bind*,
            const pgsql::bind* id,
            std::size_t id_size,
            data_image_type&);

      static void
      bind (pgsql::bind*,
            const pgsql::bind* id,
            std::size_t id_size,
            cond_image_type&,
            data_image_type&);

      static void
      grow (data_image_type&,
            bool*);

      static void
      init (data_image_type&,
            index_type*,
            const value_type&);

      static void
      init (cond_image_type&, index_type);

      static void
      init (index_type&,
            value_type&,
            const data_image_type&,
            database*);

      static void
      insert (index_type, const value_type&, void*);

      static bool
      select (index_type&, value_type&, void*);

      static void
      update (index_type, const value_type&, void*);

      static void
      delete_ (index_type, void*);

      static void
      persist (const container_type&,
               statements_type&);

      static void
      load (container_type&,
            statements_type&);

      static void
      update (const container_type&,
              statements_type&);

      static void
      erase (const container_type*, statements_type&);
    };

    // emballages_
    //
    struct emballages_traits
    {
      static const char select_name[];
      static const char insert_name[];
      static const char update_name[];
      static const char delete_name[];

      static const unsigned int insert_types[];
      static const unsigned int update_types[];
      static const unsigned int delete_types[];

      static const std::size_t id_column_count = 1UL;
      static const std::size_t value_column_count = 1UL;
      static const std::size_t cond_column_count = 2UL;
      static const std::size_t data_column_count = 3UL;

      static const bool versioned = false;

      static const char insert_statement[];
      static const char select_statement[];
      static const char update_statement[];
      static const char delete_statement[];

      typedef ::odb::vector< ::QLazySharedPointer< ::Emballage > > container_type;
      typedef
      odb::access::container_traits<container_type>
      container_traits_type;
      typedef container_traits_type::index_type index_type;
      typedef container_traits_type::value_type value_type;

      typedef smart_ordered_functions<index_type, value_type> functions_type;
      typedef pgsql::smart_container_statements< emballages_traits > statements_type;

      struct cond_image_type
      {
        // index
        //
        long long index_value;
        bool index_null;

        std::size_t version;
      };

      struct data_image_type
      {
        // index
        //
        long long index_value;
        bool index_null;

        // value
        //
        details::buffer value_value;
        std::size_t value_size;
        bool value_null;

        std::size_t version;
      };

      static void
      bind (pgsql::bind*,
            const pgsql::bind* id,
            std::size_t id_size,
            cond_image_type&);

      static void
      bind (pgsql::bind*,
            const pgsql::bind* id,
            std::size_t id_size,
            data_image_type&);

      static void
      bind (pgsql::bind*,
            const pgsql::bind* id,
            std::size_t id_size,
            cond_image_type&,
            data_image_type&);

      static void
      grow (data_image_type&,
            bool*);

      static void
      init (data_image_type&,
            index_type*,
            const value_type&);

      static void
      init (cond_image_type&, index_type);

      static void
      init (index_type&,
            value_type&,
            const data_image_type&,
            database*);

      static void
      insert (index_type, const value_type&, void*);

      static bool
      select (index_type&, value_type&, void*);

      static void
      update (index_type, const value_type&, void*);

      static void
      delete_ (index_type, void*);

      static void
      persist (const container_type&,
               statements_type&);

      static void
      load (container_type&,
            statements_type&);

      static void
      update (const container_type&,
              statements_type&);

      static void
      erase (const container_type*, statements_type&);
    };

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

    static const std::size_t column_count = 3UL;
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
  class access::object_traits_impl< ::Tonnage, id_common >:
    public access::object_traits_impl< ::Tonnage, id_pgsql >
  {
  };

  // Tonnage
  //
}

#include "tonnage-odb.ixx"

#include <odb/post.hxx>

#endif // TONNAGE_ODB_HXX
