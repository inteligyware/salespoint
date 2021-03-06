// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

#ifndef FAMILLE_ODB_HXX
#define FAMILLE_ODB_HXX

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

#include "famille.hxx"

#include "emballage-odb.hxx"
#include "fournisseur-odb.hxx"
#include "histprix-odb.hxx"
#include "prixfourn-odb.hxx"
#include "produit-odb.hxx"
#include "tonnage-odb.hxx"

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
  // Famille
  //
  template <>
  struct class_traits< ::Famille >
  {
    static const class_kind kind = class_object;
  };

  template <>
  class access::object_traits< ::Famille >
  {
    public:
    typedef ::Famille object_type;
    typedef ::QSharedPointer< ::Famille > pointer_type;
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
  // Famille
  //
  template <typename A>
  struct pointer_query_columns< ::Famille, id_pgsql, A >
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

    // reference
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::QString,
        pgsql::id_string >::query_type,
      pgsql::id_string >
    reference_type_;

    static const reference_type_ reference;

    // libele
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::QString,
        pgsql::id_string >::query_type,
      pgsql::id_string >
    libele_type_;

    static const libele_type_ libele;

    // description
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::QString,
        pgsql::id_string >::query_type,
      pgsql::id_string >
    description_type_;

    static const description_type_ description;

    // parent
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::quint32,
        pgsql::id_integer >::query_type,
      pgsql::id_integer >
    parent_type_;

    static const parent_type_ parent;
  };

  template <typename A>
  const typename pointer_query_columns< ::Famille, id_pgsql, A >::id_type_
  pointer_query_columns< ::Famille, id_pgsql, A >::
  id (A::table_name, "\"id\"", 0);

  template <typename A>
  const typename pointer_query_columns< ::Famille, id_pgsql, A >::reference_type_
  pointer_query_columns< ::Famille, id_pgsql, A >::
  reference (A::table_name, "\"reference\"", 0);

  template <typename A>
  const typename pointer_query_columns< ::Famille, id_pgsql, A >::libele_type_
  pointer_query_columns< ::Famille, id_pgsql, A >::
  libele (A::table_name, "\"libele\"", 0);

  template <typename A>
  const typename pointer_query_columns< ::Famille, id_pgsql, A >::description_type_
  pointer_query_columns< ::Famille, id_pgsql, A >::
  description (A::table_name, "\"description\"", 0);

  template <typename A>
  const typename pointer_query_columns< ::Famille, id_pgsql, A >::parent_type_
  pointer_query_columns< ::Famille, id_pgsql, A >::
  parent (A::table_name, "\"parent\"", 0);

  template <>
  class access::object_traits_impl< ::Famille, id_pgsql >:
    public access::object_traits< ::Famille >
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

      // reference_
      //
      details::buffer reference_value;
      std::size_t reference_size;
      bool reference_null;

      // libele_
      //
      details::buffer libele_value;
      std::size_t libele_size;
      bool libele_null;

      // description_
      //
      details::buffer description_value;
      std::size_t description_size;
      bool description_null;

      // parent_
      //
      int parent_value;
      bool parent_null;

      std::size_t version;
    };

    struct extra_statement_cache_type;

    // children_
    //
    struct children_traits
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

      typedef ::QVector< ::QLazyWeakPointer< ::Famille > > container_type;
      typedef
      odb::access::container_traits<container_type>
      container_traits_type;
      typedef container_traits_type::index_type index_type;
      typedef container_traits_type::value_type value_type;

      typedef ordered_functions<index_type, value_type> functions_type;
      typedef pgsql::container_statements< children_traits > statements_type;

      struct data_image_type
      {
        // value
        //
        int value_value;
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

    struct parent_tag;

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

    static const std::size_t column_count = 5UL;
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
  class access::object_traits_impl< ::Famille, id_common >:
    public access::object_traits_impl< ::Famille, id_pgsql >
  {
  };

  // Famille
  //
  template <>
  struct alias_traits<
    ::Famille,
    id_pgsql,
    access::object_traits_impl< ::Famille, id_pgsql >::parent_tag>
  {
    static const char table_name[];
  };

  template <>
  struct query_columns_base< ::Famille, id_pgsql >
  {
    // parent
    //
    typedef
    odb::alias_traits<
      ::Famille,
      id_pgsql,
      access::object_traits_impl< ::Famille, id_pgsql >::parent_tag>
    parent_alias_;
  };

  template <typename A>
  struct query_columns< ::Famille, id_pgsql, A >:
    query_columns_base< ::Famille, id_pgsql >
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

    // reference
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::QString,
        pgsql::id_string >::query_type,
      pgsql::id_string >
    reference_type_;

    static const reference_type_ reference;

    // libele
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::QString,
        pgsql::id_string >::query_type,
      pgsql::id_string >
    libele_type_;

    static const libele_type_ libele;

    // description
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::QString,
        pgsql::id_string >::query_type,
      pgsql::id_string >
    description_type_;

    static const description_type_ description;

    // parent
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::quint32,
        pgsql::id_integer >::query_type,
      pgsql::id_integer >
    parent_column_type_;

    typedef
    odb::query_pointer<
      odb::pointer_query_columns<
        ::Famille,
        id_pgsql,
        parent_alias_ > >
    parent_pointer_type_;

    struct parent_type_: parent_pointer_type_, parent_column_type_
    {
      parent_type_ (const char* t, const char* c, const char* conv)
        : parent_column_type_ (t, c, conv)
      {
      }
    };

    static const parent_type_ parent;
  };

  template <typename A>
  const typename query_columns< ::Famille, id_pgsql, A >::id_type_
  query_columns< ::Famille, id_pgsql, A >::
  id (A::table_name, "\"id\"", 0);

  template <typename A>
  const typename query_columns< ::Famille, id_pgsql, A >::reference_type_
  query_columns< ::Famille, id_pgsql, A >::
  reference (A::table_name, "\"reference\"", 0);

  template <typename A>
  const typename query_columns< ::Famille, id_pgsql, A >::libele_type_
  query_columns< ::Famille, id_pgsql, A >::
  libele (A::table_name, "\"libele\"", 0);

  template <typename A>
  const typename query_columns< ::Famille, id_pgsql, A >::description_type_
  query_columns< ::Famille, id_pgsql, A >::
  description (A::table_name, "\"description\"", 0);

  template <typename A>
  const typename query_columns< ::Famille, id_pgsql, A >::parent_type_
  query_columns< ::Famille, id_pgsql, A >::
  parent (A::table_name, "\"parent\"", 0);
}

#include "famille-odb.ixx"

#include <odb/post.hxx>

#endif // FAMILLE_ODB_HXX
