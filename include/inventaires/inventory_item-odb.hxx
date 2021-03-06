// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

#ifndef INVENTORY_ITEM_ODB_HXX
#define INVENTORY_ITEM_ODB_HXX

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
//
// End prologue.

#include <odb/version.hxx>

#if (ODB_VERSION != 20400UL)
#error ODB runtime version mismatch
#endif

#include <odb/pre.hxx>

#include "inventory_item.hxx"

#include "inventory-odb.hxx"
#include "fonction-odb.hxx"
#include "personne-odb.hxx"
#include "../personnels/personnel-odb.hxx"
#include "emballage-odb.hxx"
#include "fournisseur-odb.hxx"
#include "histprix-odb.hxx"
#include "prixfourn-odb.hxx"
#include "../produits/produit-odb.hxx"
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
  // InventoryItem
  //
  template <>
  struct class_traits< ::InventoryItem >
  {
    static const class_kind kind = class_object;
  };

  template <>
  class access::object_traits< ::InventoryItem >
  {
    public:
    typedef ::InventoryItem object_type;
    typedef ::QSharedPointer< ::InventoryItem > pointer_type;
    typedef odb::pointer_traits<pointer_type> pointer_traits;

    static const bool polymorphic = false;

    typedef ::ulong id_type;

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
  // InventoryItem
  //
  template <typename A>
  struct pointer_query_columns< ::InventoryItem, id_pgsql, A >
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

    // qte_theo_gros
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::quint32,
        pgsql::id_integer >::query_type,
      pgsql::id_integer >
    qte_theo_gros_type_;

    static const qte_theo_gros_type_ qte_theo_gros;

    // qte_theo_details
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::quint32,
        pgsql::id_integer >::query_type,
      pgsql::id_integer >
    qte_theo_details_type_;

    static const qte_theo_details_type_ qte_theo_details;

    // qte_phys_gros
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::quint32,
        pgsql::id_integer >::query_type,
      pgsql::id_integer >
    qte_phys_gros_type_;

    static const qte_phys_gros_type_ qte_phys_gros;

    // qte_phys_details
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::quint32,
        pgsql::id_integer >::query_type,
      pgsql::id_integer >
    qte_phys_details_type_;

    static const qte_phys_details_type_ qte_phys_details;

    // qte_ajoute_gros
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::quint32,
        pgsql::id_integer >::query_type,
      pgsql::id_integer >
    qte_ajoute_gros_type_;

    static const qte_ajoute_gros_type_ qte_ajoute_gros;

    // qte_ajoute_details
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::quint32,
        pgsql::id_integer >::query_type,
      pgsql::id_integer >
    qte_ajoute_details_type_;

    static const qte_ajoute_details_type_ qte_ajoute_details;

    // justification
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::QString,
        pgsql::id_string >::query_type,
      pgsql::id_string >
    justification_type_;

    static const justification_type_ justification;

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

    // inventory
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::ulong,
        pgsql::id_bigint >::query_type,
      pgsql::id_bigint >
    inventory_type_;

    static const inventory_type_ inventory;
  };

  template <typename A>
  const typename pointer_query_columns< ::InventoryItem, id_pgsql, A >::id_type_
  pointer_query_columns< ::InventoryItem, id_pgsql, A >::
  id (A::table_name, "\"id\"", 0);

  template <typename A>
  const typename pointer_query_columns< ::InventoryItem, id_pgsql, A >::qte_theo_gros_type_
  pointer_query_columns< ::InventoryItem, id_pgsql, A >::
  qte_theo_gros (A::table_name, "\"qte_theo_gros\"", 0);

  template <typename A>
  const typename pointer_query_columns< ::InventoryItem, id_pgsql, A >::qte_theo_details_type_
  pointer_query_columns< ::InventoryItem, id_pgsql, A >::
  qte_theo_details (A::table_name, "\"qte_theo_details\"", 0);

  template <typename A>
  const typename pointer_query_columns< ::InventoryItem, id_pgsql, A >::qte_phys_gros_type_
  pointer_query_columns< ::InventoryItem, id_pgsql, A >::
  qte_phys_gros (A::table_name, "\"qte_phys_gros\"", 0);

  template <typename A>
  const typename pointer_query_columns< ::InventoryItem, id_pgsql, A >::qte_phys_details_type_
  pointer_query_columns< ::InventoryItem, id_pgsql, A >::
  qte_phys_details (A::table_name, "\"qte_phys_details\"", 0);

  template <typename A>
  const typename pointer_query_columns< ::InventoryItem, id_pgsql, A >::qte_ajoute_gros_type_
  pointer_query_columns< ::InventoryItem, id_pgsql, A >::
  qte_ajoute_gros (A::table_name, "\"qte_ajoute_gros\"", 0);

  template <typename A>
  const typename pointer_query_columns< ::InventoryItem, id_pgsql, A >::qte_ajoute_details_type_
  pointer_query_columns< ::InventoryItem, id_pgsql, A >::
  qte_ajoute_details (A::table_name, "\"qte_ajoute_details\"", 0);

  template <typename A>
  const typename pointer_query_columns< ::InventoryItem, id_pgsql, A >::justification_type_
  pointer_query_columns< ::InventoryItem, id_pgsql, A >::
  justification (A::table_name, "\"justification\"", 0);

  template <typename A>
  const typename pointer_query_columns< ::InventoryItem, id_pgsql, A >::produit_type_
  pointer_query_columns< ::InventoryItem, id_pgsql, A >::
  produit (A::table_name, "\"produit\"", 0);

  template <typename A>
  const typename pointer_query_columns< ::InventoryItem, id_pgsql, A >::inventory_type_
  pointer_query_columns< ::InventoryItem, id_pgsql, A >::
  inventory (A::table_name, "\"inventory\"", 0);

  template <>
  class access::object_traits_impl< ::InventoryItem, id_pgsql >:
    public access::object_traits< ::InventoryItem >
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

      // qte_theo_gros_
      //
      int qte_theo_gros_value;
      bool qte_theo_gros_null;

      // qte_theo_details_
      //
      int qte_theo_details_value;
      bool qte_theo_details_null;

      // qte_phys_gros_
      //
      int qte_phys_gros_value;
      bool qte_phys_gros_null;

      // qte_phys_details_
      //
      int qte_phys_details_value;
      bool qte_phys_details_null;

      // qte_ajoute_gros_
      //
      int qte_ajoute_gros_value;
      bool qte_ajoute_gros_null;

      // qte_ajoute_details_
      //
      int qte_ajoute_details_value;
      bool qte_ajoute_details_null;

      // justification_
      //
      details::buffer justification_value;
      std::size_t justification_size;
      bool justification_null;

      // produit_
      //
      long long produit_value;
      bool produit_null;

      // inventory_
      //
      long long inventory_value;
      bool inventory_null;

      std::size_t version;
    };

    struct extra_statement_cache_type;

    struct produit_tag;
    struct inventory_tag;

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

    static const std::size_t column_count = 10UL;
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
  class access::object_traits_impl< ::InventoryItem, id_common >:
    public access::object_traits_impl< ::InventoryItem, id_pgsql >
  {
  };

  // InventoryItem
  //
  template <>
  struct alias_traits<
    ::Produit,
    id_pgsql,
    access::object_traits_impl< ::InventoryItem, id_pgsql >::produit_tag>
  {
    static const char table_name[];
  };

  template <>
  struct alias_traits<
    ::Inventory,
    id_pgsql,
    access::object_traits_impl< ::InventoryItem, id_pgsql >::inventory_tag>
  {
    static const char table_name[];
  };

  template <>
  struct query_columns_base< ::InventoryItem, id_pgsql >
  {
    // produit
    //
    typedef
    odb::alias_traits<
      ::Produit,
      id_pgsql,
      access::object_traits_impl< ::InventoryItem, id_pgsql >::produit_tag>
    produit_alias_;

    // inventory
    //
    typedef
    odb::alias_traits<
      ::Inventory,
      id_pgsql,
      access::object_traits_impl< ::InventoryItem, id_pgsql >::inventory_tag>
    inventory_alias_;
  };

  template <typename A>
  struct query_columns< ::InventoryItem, id_pgsql, A >:
    query_columns_base< ::InventoryItem, id_pgsql >
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

    // qte_theo_gros
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::quint32,
        pgsql::id_integer >::query_type,
      pgsql::id_integer >
    qte_theo_gros_type_;

    static const qte_theo_gros_type_ qte_theo_gros;

    // qte_theo_details
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::quint32,
        pgsql::id_integer >::query_type,
      pgsql::id_integer >
    qte_theo_details_type_;

    static const qte_theo_details_type_ qte_theo_details;

    // qte_phys_gros
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::quint32,
        pgsql::id_integer >::query_type,
      pgsql::id_integer >
    qte_phys_gros_type_;

    static const qte_phys_gros_type_ qte_phys_gros;

    // qte_phys_details
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::quint32,
        pgsql::id_integer >::query_type,
      pgsql::id_integer >
    qte_phys_details_type_;

    static const qte_phys_details_type_ qte_phys_details;

    // qte_ajoute_gros
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::quint32,
        pgsql::id_integer >::query_type,
      pgsql::id_integer >
    qte_ajoute_gros_type_;

    static const qte_ajoute_gros_type_ qte_ajoute_gros;

    // qte_ajoute_details
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::quint32,
        pgsql::id_integer >::query_type,
      pgsql::id_integer >
    qte_ajoute_details_type_;

    static const qte_ajoute_details_type_ qte_ajoute_details;

    // justification
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::QString,
        pgsql::id_string >::query_type,
      pgsql::id_string >
    justification_type_;

    static const justification_type_ justification;

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

    // inventory
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::ulong,
        pgsql::id_bigint >::query_type,
      pgsql::id_bigint >
    inventory_column_type_;

    typedef
    odb::query_pointer<
      odb::pointer_query_columns<
        ::Inventory,
        id_pgsql,
        inventory_alias_ > >
    inventory_pointer_type_;

    struct inventory_type_: inventory_pointer_type_, inventory_column_type_
    {
      inventory_type_ (const char* t, const char* c, const char* conv)
        : inventory_column_type_ (t, c, conv)
      {
      }
    };

    static const inventory_type_ inventory;
  };

  template <typename A>
  const typename query_columns< ::InventoryItem, id_pgsql, A >::id_type_
  query_columns< ::InventoryItem, id_pgsql, A >::
  id (A::table_name, "\"id\"", 0);

  template <typename A>
  const typename query_columns< ::InventoryItem, id_pgsql, A >::qte_theo_gros_type_
  query_columns< ::InventoryItem, id_pgsql, A >::
  qte_theo_gros (A::table_name, "\"qte_theo_gros\"", 0);

  template <typename A>
  const typename query_columns< ::InventoryItem, id_pgsql, A >::qte_theo_details_type_
  query_columns< ::InventoryItem, id_pgsql, A >::
  qte_theo_details (A::table_name, "\"qte_theo_details\"", 0);

  template <typename A>
  const typename query_columns< ::InventoryItem, id_pgsql, A >::qte_phys_gros_type_
  query_columns< ::InventoryItem, id_pgsql, A >::
  qte_phys_gros (A::table_name, "\"qte_phys_gros\"", 0);

  template <typename A>
  const typename query_columns< ::InventoryItem, id_pgsql, A >::qte_phys_details_type_
  query_columns< ::InventoryItem, id_pgsql, A >::
  qte_phys_details (A::table_name, "\"qte_phys_details\"", 0);

  template <typename A>
  const typename query_columns< ::InventoryItem, id_pgsql, A >::qte_ajoute_gros_type_
  query_columns< ::InventoryItem, id_pgsql, A >::
  qte_ajoute_gros (A::table_name, "\"qte_ajoute_gros\"", 0);

  template <typename A>
  const typename query_columns< ::InventoryItem, id_pgsql, A >::qte_ajoute_details_type_
  query_columns< ::InventoryItem, id_pgsql, A >::
  qte_ajoute_details (A::table_name, "\"qte_ajoute_details\"", 0);

  template <typename A>
  const typename query_columns< ::InventoryItem, id_pgsql, A >::justification_type_
  query_columns< ::InventoryItem, id_pgsql, A >::
  justification (A::table_name, "\"justification\"", 0);

  template <typename A>
  const typename query_columns< ::InventoryItem, id_pgsql, A >::produit_type_
  query_columns< ::InventoryItem, id_pgsql, A >::
  produit (A::table_name, "\"produit\"", 0);

  template <typename A>
  const typename query_columns< ::InventoryItem, id_pgsql, A >::inventory_type_
  query_columns< ::InventoryItem, id_pgsql, A >::
  inventory (A::table_name, "\"inventory\"", 0);
}

#include "inventory_item-odb.ixx"

#include <odb/post.hxx>

#endif // INVENTORY_ITEM_ODB_HXX
