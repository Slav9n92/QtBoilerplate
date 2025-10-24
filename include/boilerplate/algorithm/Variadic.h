/*
 * \file Variadic.h
 * \copyright :
 * \author : Bubnov V.V.
 * \date : 24.10.2025
 * \time : 12:29
 */

#pragma once

#include <algorithm>
#include <boilerplate/expected/Expected.h>

namespace qt {
namespace boilerplate {

template< typename UnaryFuncT >
void for_each_variadic( UnaryFuncT&& ) noexcept
{
}

template< typename UnaryFuncT, typename HeadT, typename... TailT >
void for_each_variadic( UnaryFuncT&& unaryFuncT, HeadT&& headT, TailT&& ... tailT ) noexcept
{
    unaryFuncT( std::forward< HeadT >( headT ) );
    for_each_variadic( std::forward< UnaryFuncT >( unaryFuncT ), std::forward< TailT >( tailT )... );
}

template< typename UnaryFuncT >
void for_each_range_variadic( UnaryFuncT&& ) noexcept
{
}

template< typename UnaryFuncT, typename HeadT, typename... TailT >
void for_each_range_variadic( UnaryFuncT&& unaryFuncT, HeadT&& headT, TailT&& ... tailT ) noexcept
{
    std::for_each( headT.begin(), headT.end(), unaryFuncT );
    for_each_range_variadic( std::forward< UnaryFuncT >( unaryFuncT ), std::forward< TailT >( tailT )... );
}

template< typename ReturnT, typename PredicateT >
Expected< ReturnT, Empty > find_if_variadic( PredicateT&& ) noexcept
{
    return { boilerplate::make_unexpected_type( Empty() ) };
}

template< typename ReturnT, typename PredicateT, typename HeadT, typename... TailT >
Expected< ReturnT, Empty > find_if_variadic( PredicateT&& predicateT, HeadT&& headT, TailT&& ... tailT ) noexcept
{
    const auto& success = predicateT( std::forward< HeadT >( headT ) );
    if( success ) { return { headT }; }
    return find_if_variadic< ReturnT >( std::forward< PredicateT >( predicateT ), std::forward< TailT >( tailT )... );
}

template< typename ReturnT, typename PredicateT >
Expected< ReturnT, Empty > find_if_range_variadic( PredicateT&& ) noexcept
{
    return { boilerplate::make_unexpected_type( Empty() ) };
}

template< typename ReturnT, typename PredicateT, typename HeadT, typename... TailT >
Expected< ReturnT, Empty > find_if_range_variadic( PredicateT&& predicateT, HeadT&& headT, TailT&& ... tailT ) noexcept
{
    const auto& found = std::find_if( headT.begin(), headT.end(), predicateT );
    if( found != headT.end() ) { return { *found }; }
    return find_if_range_variadic< ReturnT >( std::forward< PredicateT >( predicateT ), std::forward< TailT >( tailT )... );
}

template< typename PredicateT >
bool any_of_variadic( PredicateT&& ) noexcept
{
    return false;
}

template< typename PredicateT, typename HeadT, typename... TailT >
bool any_of_variadic( PredicateT&& predicateT, HeadT&& headT, TailT&& ... tailT ) noexcept
{
    const auto& success = predicateT( std::forward< HeadT >( headT ) );
    if( success ) { return true; }
    return any_of_variadic( std::forward< PredicateT >( predicateT ), std::forward< TailT >( tailT )... );
}

template< typename PredicateT >
bool any_of_range_variadic( PredicateT&& ) noexcept
{
    return false;
}

template< typename PredicateT, typename HeadT, typename... TailT >
bool any_of_range_variadic( PredicateT&& predicateT, HeadT&& headT, TailT&& ... tailT ) noexcept
{
    const auto any = std::any_of( headT.cbegin(), headT.cend(), predicateT );
    if( any ) { return true; }
    return any_of_range_variadic( std::forward< PredicateT >( predicateT ), std::forward< TailT >( tailT )... );
}

template< typename OperatorT, typename OutputT >
void transform_variadic( OperatorT&&, OutputT&& ) noexcept
{
}

template< typename OperatorT, typename OutputT, typename HeadT, typename... TailT >
void transform_variadic( OperatorT&& operatorT, OutputT&& outputT, HeadT&& headT, TailT&& ... tailT ) noexcept
{
    *outputT = operatorT( std::forward< HeadT >( headT ) );
    ++outputT;
    transform_variadic( std::forward< OperatorT >( operatorT ), std::forward< OutputT >( outputT ), std::forward< TailT >( tailT )... );
}

template< typename OperatorT, typename OutputT >
void transform_range_variadic( OperatorT&&, OutputT&& ) noexcept
{
}

template< typename OperatorT, typename OutputT, typename HeadT, typename... TailT >
void transform_range_variadic( OperatorT&& operatorT, OutputT&& outputT, HeadT&& headT, TailT&& ... tailT ) noexcept
{
    std::transform( headT.begin(), headT.end(), outputT, operatorT );
    transform_range_variadic( std::forward< OperatorT >( operatorT ), std::forward< OutputT >( outputT ), std::forward< TailT >( tailT )... );
}

template< typename ReturnT >
using transform_if_type = Expected< ReturnT, Empty >;

template< typename OperatorT, typename OutputT >
void transform_if_variadic( OperatorT&&, OutputT&& ) noexcept
{
}

template< typename OperatorT, typename OutputT, typename HeadT, typename... TailT >
void transform_if_variadic( OperatorT&& operatorT, OutputT&& outputT, HeadT&& headT, TailT&& ... tailT ) noexcept
{
    using operatorReturnType = std::decay_t< decltype( operatorT( headT ) ) >;
    using transformReturnType = transform_if_type< typename std::decay_t< decltype( outputT ) >::container_type::value_type >;
    static_assert( std::is_same< operatorReturnType, transformReturnType >::value, "Mismatch operator return type and output return type. Operator must return 'transform_if_type'" );

    const auto& result = operatorT( headT );
    if( result )
    {
        *outputT = *result;
        ++outputT;
    }
    transform_if_variadic( std::forward< OperatorT >( operatorT ), std::forward< OutputT >( outputT ), std::forward< TailT >( tailT )... );
}

template< typename OperatorT, typename OutputT >
void transform_if_range_variadic( OperatorT&&, OutputT&& ) noexcept
{
}

template< typename OperatorT, typename OutputT, typename HeadT, typename... TailT >
void transform_if_range_variadic( OperatorT&& operatorT, OutputT&& outputT, HeadT&& headT, TailT&& ... tailT ) noexcept
{
    using operatorReturnType = std::decay_t< decltype( operatorT( std::declval< typename std::decay_t< decltype( headT ) >::value_type >() ) ) >;
    using transformReturnType = transform_if_type< typename std::decay_t< decltype( outputT ) >::container_type::value_type >;
    static_assert( std::is_same< operatorReturnType, transformReturnType >::value, "Mismatch operator return type and output return type. Operator must return 'transform_if_type'" );

    for( auto it = headT.begin(); it != headT.end(); ++it )
    {
        const auto& result = operatorT( *it );
        if( result )
        {
            *outputT = *result;
            ++outputT;
        }
    }
    transform_if_range_variadic( std::forward< OperatorT >( operatorT ), std::forward< OutputT >( outputT ), std::forward< TailT >( tailT )... );
}

}
}