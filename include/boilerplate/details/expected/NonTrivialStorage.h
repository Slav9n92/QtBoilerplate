/*
 * \file NonTrivialStorage.h
 * \copyright :
 * \author : Bubnov V.V.
 * \date : 27.06.2025
 * \time : 11:27
 */

#pragma once

#include <utility>

#include "UnexpectedType.h"

namespace qt {
namespace boilerplate {
namespace details {

template< typename ValueT, typename ErrorT >
class NonTrivialStorage final
{
public:
    explicit NonTrivialStorage( const ValueT& value ) noexcept
            : valid( true )
    {
        new( &storage.value ) ValueT( value );
    }

    explicit NonTrivialStorage( ValueT&& value ) noexcept
            : valid( true )
    {
        new( &storage.value ) ValueT( std::move( value ) );
    }

public:
    explicit NonTrivialStorage( const UnexpectedType< ErrorT >& unexpected ) noexcept
            : valid( false )
    {
        new( &storage.error ) ErrorT( unexpected.error );
    }

    explicit NonTrivialStorage( UnexpectedType< ErrorT >&& unexpected ) noexcept
            : valid( false )
    {
        new( &storage.error ) ErrorT( std::move( unexpected.error ) );
    }

public:
    NonTrivialStorage( const NonTrivialStorage& other ) noexcept
    {
        swap( other );
    }

    NonTrivialStorage( NonTrivialStorage&& other ) noexcept
    {
        swap( std::move( other ) );
    }

    NonTrivialStorage& operator =( const NonTrivialStorage& other ) noexcept
    {
        if( this != &other )
        {
            reset();
            swap( other );
        }
        return *this;
    }

    NonTrivialStorage& operator =( NonTrivialStorage&& other ) noexcept
    {
        if( this != &other )
        {
            reset();
            swap( std::move( other ) );
        }
        return *this;
    }

public:
    ~NonTrivialStorage() noexcept
    {
        reset();
    }

public:
    bool isValid() const noexcept
    {
        return valid;
    }

    const ValueT& getValue() const noexcept
    {
        return storage.value;
    }

    ValueT& getValue() noexcept
    {
        return storage.value;
    }

    const ErrorT& getError() const noexcept
    {
        return storage.error;
    }

    ErrorT& getError() noexcept
    {
        return storage.error;
    }

public:
    ValueT release() noexcept
    {
        return std::move( storage.value );
    }

private:
    void swap( const NonTrivialStorage& other ) noexcept
    {
        if( other.valid ) { new( &storage.value ) ValueT( other.storage.value ); }
        else { new( &storage.error ) ErrorT( other.storage.error ); }
        valid = other.valid;
    }

    void swap( NonTrivialStorage&& other ) noexcept
    {
        if( other.valid ) { new( &storage.value ) ValueT( std::move( other.storage.value ) ); }
        else { new( &storage.error ) ErrorT( std::move( other.storage.error ) ); }
        valid = other.valid;
    }

    void reset() noexcept
    {
        if( isValid() ) { storage.value.~ValueT(); }
        else { storage.error.~ErrorT(); }
    }

private:
    union Storage
    {
        Storage() noexcept
        {
        }

        ~Storage() noexcept
        {
        }

        ValueT value;
        ErrorT error;
    };

private:
    Storage storage;
    bool valid;
};

}
}
}