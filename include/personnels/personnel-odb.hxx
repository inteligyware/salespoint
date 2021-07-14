// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

#ifndef PERSONNEL_ODB_HXX
#define PERSONNEL_ODB_HXX

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

#include "personnel.hxx"

#include "fonction-odb.hxx"
#include "personne-odb.hxx"

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
  // Personnel
  //
  template <>
  struct class_traits< ::Personnel >
  {
    static const class_kind kind = class_object;
  };

  template <>
  class access::object_traits< ::Personnel >
  {
    public:
    typedef ::Personnel object_type;
    typedef ::QSharedPointer< ::Personnel > pointer_type;
    typedef odb::pointer_traits<pointer_type> pointer_traits;

    static const bool polymorphic = true;

    typedef ::Personne root_type;
    typedef ::Personne base_type;
    typedef object_traits<root_type>::discriminator_type discriminator_type;
    typedef polymorphic_concrete_info<root_type> info_type;

    static const std::size_t depth = 2UL;

    typedef object_traits< ::Personne >::id_type id_type;

    static const bool auto_id = false;

    static const bool abstract = false;

    static id_type
    id (const object_type&);

    typedef
    odb::pointer_cache_traits<
      object_traits<root_type>::pointer_type,
      odb::session >
    pointer_cache_traits;

    typedef
    odb::reference_cache_traits<
      root_type,
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
  // Personnel
  //
  template <typename A>
  struct pointer_query_columns< ::Personnel, id_pgsql, A >:
    pointer_query_columns< ::Personne, id_pgsql, typename A::base_traits >
  {
    // Personne
    //
    typedef pointer_query_columns< ::Personne, id_pgsql, typename A::base_traits > Personne;

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

    // matricule
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::QString,
        pgsql::id_string >::query_type,
      pgsql::id_string >
    matricule_type_;

    static const matricule_type_ matricule;

    // date_naissance
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::QDate,
        pgsql::id_date >::query_type,
      pgsql::id_date >
    date_naissance_type_;

    static const date_naissance_type_ date_naissance;

    // date_embauche
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::QDate,
        pgsql::id_date >::query_type,
      pgsql::id_date >
    date_embauche_type_;

    static const date_embauche_type_ date_embauche;

    // salaire
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::quint32,
        pgsql::id_integer >::query_type,
      pgsql::id_integer >
    salaire_type_;

    static const salaire_type_ salaire;

    // fonction
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::quint16,
        pgsql::id_smallint >::query_type,
      pgsql::id_smallint >
    fonction_type_;

    static const fonction_type_ fonction;
  };

  template <typename A>
  const typename pointer_query_columns< ::Personnel, id_pgsql, A >::id_type_
  pointer_query_columns< ::Personnel, id_pgsql, A >::
  id (A::table_name, "\"id\"", 0);

  template <typename A>
  const typename pointer_query_columns< ::Personnel, id_pgsql, A >::matricule_type_
  pointer_query_columns< ::Personnel, id_pgsql, A >::
  matricule (A::table_name, "\"matricule\"", 0);

  template <typename A>
  const typename pointer_query_columns< ::Personnel, id_pgsql, A >::date_naissance_type_
  pointer_query_columns< ::Personnel, id_pgsql, A >::
  date_naissance (A::table_name, "\"date_naissance\"", 0);

  template <typename A>
  const typename pointer_query_columns< ::Personnel, id_pgsql, A >::date_embauche_type_
  pointer_query_columns< ::Personnel, id_pgsql, A >::
  date_embauche (A::table_name, "\"date_embauche\"", 0);

  template <typename A>
  const typename pointer_query_columns< ::Personnel, id_pgsql, A >::salaire_type_
  pointer_query_columns< ::Personnel, id_pgsql, A >::
  salaire (A::table_name, "\"salaire\"", 0);

  template <typename A>
  const typename pointer_query_columns< ::Personnel, id_pgsql, A >::fonction_type_
  pointer_query_columns< ::Personnel, id_pgsql, A >::
  fonction (A::table_name, "\"fonction\"", 0);

  template <>
  class access::object_traits_impl< ::Personnel, id_pgsql >:
    public access::object_traits< ::Personnel >
  {
    public:
    typedef polymorphic_entry<object_type, id_pgsql> entry_type;
    typedef object_traits_impl<root_type, id_pgsql> root_traits;
    typedef object_traits_impl<base_type, id_pgsql> base_traits;

    typedef root_traits::id_image_type id_image_type;

    static const info_type info;

    struct image_type
    {
      base_traits::image_type* base;

      // id_
      //
      int id_value;
      bool id_null;

      // matricule_
      //
      details::buffer matricule_value;
      std::size_t matricule_size;
      bool matricule_null;

      // date_naissance_
      //
      int date_naissance_value;
      bool date_naissance_null;

      // date_embauche_
      //
      int date_embauche_value;
      bool date_embauche_null;

      // salaire_
      //
      int salaire_value;
      bool salaire_null;

      // fonction_
      //
      short fonction_value;
      bool fonction_null;

      std::size_t version;
    };

    struct extra_statement_cache_type;

    struct fonction_tag;

    using object_traits<object_type>::id;

    static bool
    grow (image_type&,
          bool*,
          std::size_t = depth);

    static void
    bind (pgsql::bind*,
          const pgsql::bind* id,
          std::size_t id_size,
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
          database*,
          std::size_t = depth);

    static void
    init (id_image_type&, const id_type&);

    static bool
    check_version (const std::size_t*, const image_type&);

    static void
    update_version (std::size_t*, const image_type&, pgsql::binding*);

    typedef
    pgsql::polymorphic_derived_object_statements<object_type>
    statements_type;

    typedef
    pgsql::polymorphic_root_object_statements<root_type>
    root_statements_type;

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
    static const char* const find_statements[depth];
    static const std::size_t find_column_counts[depth];
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
    static const char* const find_statement_names[depth];
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
           const id_type*,
           std::size_t = depth);

    static void
    load_ (statements_type&,
           object_type&,
           bool reload,
           std::size_t = depth);

    static void
    load_ (database&, root_type&, std::size_t);
  };

  template <>
  class access::object_traits_impl< ::Personnel, id_common >:
    public access::object_traits_impl< ::Personnel, id_pgsql >
  {
  };

  // Personnel
  //
  template <>
  struct alias_traits<
    ::Fonction,
    id_pgsql,
    access::object_traits_impl< ::Personnel, id_pgsql >::fonction_tag>
  {
    static const char table_name[];
  };

  template <>
  struct query_columns_base< ::Personnel, id_pgsql >
  {
    // fonction
    //
    typedef
    odb::alias_traits<
      ::Fonction,
      id_pgsql,
      access::object_traits_impl< ::Personnel, id_pgsql >::fonction_tag>
    fonction_alias_;
  };

  template <typename A>
  struct query_columns< ::Personnel, id_pgsql, A >:
    query_columns_base< ::Personnel, id_pgsql >,
    query_columns< ::Personne, id_pgsql, typename A::base_traits >
  {
    // Personne
    //
    typedef query_columns< ::Personne, id_pgsql, typename A::base_traits > Personne;

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

    // matricule
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::QString,
        pgsql::id_string >::query_type,
      pgsql::id_string >
    matricule_type_;

    static const matricule_type_ matricule;

    // date_naissance
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::QDate,
        pgsql::id_date >::query_type,
      pgsql::id_date >
    date_naissance_type_;

    static const date_naissance_type_ date_naissance;

    // date_embauche
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::QDate,
        pgsql::id_date >::query_type,
      pgsql::id_date >
    date_embauche_type_;

    static const date_embauche_type_ date_embauche;

    // salaire
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::quint32,
        pgsql::id_integer >::query_type,
      pgsql::id_integer >
    salaire_type_;

    static const salaire_type_ salaire;

    // fonction
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::quint16,
        pgsql::id_smallint >::query_type,
      pgsql::id_smallint >
    fonction_column_type_;

    typedef
    odb::query_pointer<
      odb::pointer_query_columns<
        ::Fonction,
        id_pgsql,
        fonction_alias_ > >
    fonction_pointer_type_;

    struct fonction_type_: fonction_pointer_type_, fonction_column_type_
    {
      fonction_type_ (const char* t, const char* c, const char* conv)
        : fonction_column_type_ (t, c, conv)
      {
      }
    };

    static const fonction_type_ fonction;
  };

  template <typename A>
  const typename query_columns< ::Personnel, id_pgsql, A >::id_type_
  query_columns< ::Personnel, id_pgsql, A >::
  id (A::table_name, "\"id\"", 0);

  template <typename A>
  const typename query_columns< ::Personnel, id_pgsql, A >::matricule_type_
  query_columns< ::Personnel, id_pgsql, A >::
  matricule (A::table_name, "\"matricule\"", 0);

  template <typename A>
  const typename query_columns< ::Personnel, id_pgsql, A >::date_naissance_type_
  query_columns< ::Personnel, id_pgsql, A >::
  date_naissance (A::table_name, "\"date_naissance\"", 0);

  template <typename A>
  const typename query_columns< ::Personnel, id_pgsql, A >::date_embauche_type_
  query_columns< ::Personnel, id_pgsql, A >::
  date_embauche (A::table_name, "\"date_embauche\"", 0);

  template <typename A>
  const typename query_columns< ::Personnel, id_pgsql, A >::salaire_type_
  query_columns< ::Personnel, id_pgsql, A >::
  salaire (A::table_name, "\"salaire\"", 0);

  template <typename A>
  const typename query_columns< ::Personnel, id_pgsql, A >::fonction_type_
  query_columns< ::Personnel, id_pgsql, A >::
  fonction (A::table_name, "\"fonction\"", 0);
}

#include "personnel-odb.ixx"

#include <odb/post.hxx>

#endif // PERSONNEL_ODB_HXX
