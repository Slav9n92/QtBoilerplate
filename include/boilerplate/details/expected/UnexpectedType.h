/*
 * \file UnexpectedType.h
 * \copyright :
 * \author : Bubnov V.V.
 * \date : 06.06.2025
 * \time : 15:30
 */

#pragma once

#include <utility>

namespace qt {
namespace boilerplate {
namespace details {

template< typename ErrorT >
struct UnexpectedType final
{
public:
    explicit UnexpectedType( const ErrorT& error ) noexcept
            : error( error )
    {
    }

    explicit UnexpectedType( ErrorT&& error ) noexcept
            : error( std::move( error ) )
    {
    }

    UnexpectedType( const UnexpectedType& other ) noexcept = default;
    UnexpectedType( UnexpectedType&& other ) noexcept = default;
    UnexpectedType& operator =( const UnexpectedType& other ) noexcept = default;
    UnexpectedType& operator =( UnexpectedType&& other ) noexcept = default;

public:
    ErrorT error;
};

}
}
}