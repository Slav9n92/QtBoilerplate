/*
 * \file Expected.h
 * \copyright :
 * \author : Bubnov V.V.
 * \date : 06.06.2025
 * \time : 15:26
 */

#pragma once

#include <utility>
#include <boilerplate/details/expected/UnexpectedType.h>
#include <boilerplate/details/expected/NonTrivialStorage.h>
#include <boilerplate/details/expected/TrivialStorage.h>

namespace qt {
namespace boilerplate {

template< typename ErrorT >
auto make_unexpected_type( ErrorT&& error ) noexcept -> details::UnexpectedType< std::decay_t< ErrorT > >
{
    return details::UnexpectedType< std::decay_t< ErrorT > >( std::forward< ErrorT >( error ) );
}

template< typename ValueT, typename ErrorT >
class Expected final
{
public:
    Expected( const ValueT& value ) noexcept
            : storage( value )
    {
    }

    Expected( ValueT&& value ) noexcept
            : storage( std::move( value ) )
    {
    }

    Expected( const details::UnexpectedType< ErrorT >& unexpectedType ) noexcept
            : storage( unexpectedType )
    {
    }

    Expected( details::UnexpectedType< ErrorT >&& unexpectedType ) noexcept
            : storage( std::move( unexpectedType ) )
    {
    }

    Expected( const Expected< ValueT, ErrorT >& other ) noexcept = default;
    Expected& operator =( const Expected< ValueT, ErrorT >& other ) noexcept = default;

    Expected( Expected< ValueT, ErrorT >&& other ) noexcept = default;
    Expected& operator =( Expected< ValueT, ErrorT >&& other ) noexcept = default;

public:
    explicit operator bool() const noexcept
    {
        return hasValue();
    }

    const ValueT& operator *() const noexcept
    {
        return getValue();
    }

    ValueT& operator *() noexcept
    {
        return getValue();
    }

public:
    bool hasValue() const noexcept
    {
        return storage.isValid();
    }

    ValueT& getValue() noexcept
    {
        return storage.getValue();
    }

    const ValueT& getValue() const noexcept
    {
        return storage.getValue();
    }

    ErrorT& getError() noexcept
    {
        return storage.getError();
    }

    const ErrorT& getError() const noexcept
    {
        return storage.getError();
    }

public:
    ValueT release() noexcept
    {
        return storage.release();
    }

private:
    using StorageType = typename std::conditional<
            std::is_trivially_constructible< ValueT >::value && std::is_trivially_destructible< ValueT >::value &&
            std::is_trivially_constructible< ErrorT >::value && std::is_trivially_destructible< ErrorT >::value,
            details::TrivialStorage< ValueT, ErrorT >, details::NonTrivialStorage< ValueT, ErrorT >
    >::type;

    StorageType storage;
};

//---------------------------

struct Empty final
{
};

template< typename ErrorT >
using NotExpected = Expected< Empty, ErrorT >;

}
}