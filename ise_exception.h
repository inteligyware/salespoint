#ifndef _ISE_EXCEPTION_H
#define _ISE_EXCEPTION_H

#include <stdexcept>
#include <QtCore/QRegularExpression>
#include <QtCore/QSharedPointer>

struct ise_exception : std::exception
{

    const char* what() const throw() = 0;
};

struct double_price_assignement_exception : ise_exception
{
      
    const char* what() const throw()
    {
        return ("ise_exception : double_price_assignement");
    }
    
    
};

struct null_or_negative_price_exception : ise_exception
{
  
    const char* what() const throw()
    {
        return ("ise_exception : null_or_negative_price__assignement");
    }
};

struct null_or_negative_quantity_exception : ise_exception
{

    const char* what() const throw()
    {
        return ("ise_exception : null_or_negative_quantity_assignement");
    }
};



struct null_shared_pointer_exception : ise_exception
{

    const char* what() const throw()
    {
        return ("ise_exception : null_shared_pointer_assignement");
    }
};


struct double_unique_object_assignement_exception : ise_exception
{

    const char* what() const throw()
    {
        return ("ise_exception : double_unique_object_assignement");
    }
};

template <typename T> class ise_adv_exception : public std::exception{

    QSharedPointer< T > elt_;
    std::string msg_;

public:

    ise_adv_exception( const std::string& msg, QSharedPointer<T> elt)
    {
        msg_ = msg;
        elt_ = elt;
    }

    const char* what() const throw()
    {
        quint8 i, k;
        std::string ch("0123456789");
        std::string msg ( typeid(*this).name() + std::string(" ") + typeid(*elt_).name() + std::string(" : ") + msg_);

        for( i = 0 ; i < ch.length(); i++)
            while ( (k = msg.find(ch[i])) >= 0 && k <= msg.length() ) msg.erase(k,1);
        return msg.c_str();
     }
};

#endif // _ISE_EXCEPTION_H
