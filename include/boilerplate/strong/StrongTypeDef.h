/*
 * \file StrongTypeDef.h
 * \copyright :
 * \author : Bubnov V.V.
 * \date : 08.08.2025
 * \time : 17:09
 */

#pragma once

#include <functional>

namespace qt {
namespace boilerplate {

template< typename TagT, typename ValueT, typename ComparatorT = std::less< ValueT > >
class StrongTypeDef final
{
public:
    explicit StrongTypeDef( const ValueT& value ) noexcept
    //@formatter:off
            : value( value )
            , comparator( ComparatorT() )
    //@formatter:on
    {
    }

    explicit StrongTypeDef( ValueT&& value ) noexcept
    //@formatter:off
            : value( std::move( value ) )
            , comparator( ComparatorT() )
    //@formatter:on
    {
    }

    StrongTypeDef( const StrongTypeDef< TagT, ValueT, ComparatorT >& value ) noexcept = default;
    StrongTypeDef( StrongTypeDef< TagT, ValueT, ComparatorT >&& value ) noexcept = default;

    StrongTypeDef& operator =( const StrongTypeDef< TagT, ValueT, ComparatorT >& value ) noexcept = default;
    StrongTypeDef& operator =( StrongTypeDef< TagT, ValueT, ComparatorT >&& value ) noexcept = default;

public:
    bool operator <( const StrongTypeDef< TagT, ValueT, ComparatorT >& other ) const noexcept
    {
        return comparator( value, other.value );
    }

    bool operator >( const StrongTypeDef< TagT, ValueT, ComparatorT >& other ) const noexcept
    {
        return ( other < *this );
    }

    bool operator ==( const StrongTypeDef< TagT, ValueT, ComparatorT >& other ) const noexcept
    {
        return ( ( !( *this < other ) ) && ( !( other < *this ) ) );
    }

    bool operator !=( const StrongTypeDef< TagT, ValueT, ComparatorT >& other ) const noexcept
    {
        return !( *this == other );
    }

    bool operator <=( const StrongTypeDef< TagT, ValueT, ComparatorT >& other ) const noexcept
    {
        return ( ( *this < other ) || ( *this == other ) );
    }

    bool operator >=( const StrongTypeDef< TagT, ValueT, ComparatorT >& other ) const noexcept
    {
        return ( ( *this > other ) || ( *this == other ) );
    }

public:
    ValueT& getValue() noexcept
    {
        return value;
    }

    const ValueT& getValue() const noexcept
    {
        return value;
    }

private:
    ValueT value;
    ComparatorT comparator;
};

}
}