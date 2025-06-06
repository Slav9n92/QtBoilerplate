/*
 * \file TrivialStorage.h
 * \copyright :
 * \author : Bubnov V.V.
 * \date : 06.06.2025
 * \time : 16:36
 */

#pragma once

#include <utility>

#include "UnexpectedType.h"

namespace qt {
namespace boilerplate {
namespace details {

template< typename ValueT, typename ErrorT >
class TrivialStorage final
{
public:
    explicit TrivialStorage( const ValueT& value ) noexcept
            : valid( true )
    {
        storage.value = value;
    }

    explicit TrivialStorage( ValueT&& value ) noexcept
            : valid( true )
    {
        storage.value = std::move( value );
    }

public:
    explicit TrivialStorage( const UnexpectedType< ErrorT >& unexpected ) noexcept
            : valid( false )
    {
        storage.error = unexpected.error;
    }

    explicit TrivialStorage( UnexpectedType< ErrorT >&& unexpected ) noexcept
            : valid( false )
    {
        storage.error = std::move( unexpected.error );
    }

public:
    TrivialStorage( const TrivialStorage& other ) noexcept
    {
        swap( other );
    }

    TrivialStorage( TrivialStorage&& other ) noexcept
    {
        swap( std::move( other ) );
    }

    TrivialStorage& operator =( const TrivialStorage& other ) noexcept
    {
        if( this != &other ) { swap( other ); }
        return *this;
    }

    TrivialStorage& operator =( TrivialStorage&& other ) noexcept
    {
        if( this != &other ) { swap( std::move( other ) ); }
        return *this;
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

private:
    void swap( const TrivialStorage& other ) noexcept
    {
        if( other.valid ) { storage.value = other.storage.value; }
        else { storage.error = other.storage.error; }
        valid = other.valid;
    }

    void swap( TrivialStorage&& other ) noexcept
    {
        if( other.valid ) { storage.value = std::move( other.storage.value ); }
        else { storage.error = std::move( other.storage.error ); }
        valid = other.valid;
    }

private:
    union Storage
    {
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