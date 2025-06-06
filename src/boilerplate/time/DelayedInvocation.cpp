/*
 * \file DelayedInvocation.cpp
 * \copyright :
 * \author : Bubnov V.V.
 * \date : 06.06.2025
 * \time : 13:52
 */

#include <boilerplate/time/DelayedInvocation.h>

namespace qt {
namespace boilerplate {

namespace {
//@formatter:off
    constexpr auto DEFAULT_DELAY = std::chrono::milliseconds( 100 );
//@formatter:on
}

DelayedInvocation::DelayedInvocation( QObject* parent ) noexcept
        : DelayedInvocation( {}, DEFAULT_DELAY, parent )
{
}

DelayedInvocation::DelayedInvocation( DelayedInvocation::Function function, QObject* parent ) noexcept
        : DelayedInvocation( std::move( function ), DEFAULT_DELAY, parent )
{
}

DelayedInvocation::DelayedInvocation( DelayedInvocation::Function function, std::chrono::milliseconds milliseconds, QObject* parent ) noexcept
        : QObject( parent )
        , timer( new QTimer( this ) )
        , function( std::move( function ) )
{
    setup( milliseconds );
}

DelayedInvocation::~DelayedInvocation() noexcept
{
    cancelDelayedInvoke();
}

void DelayedInvocation::setFunction( DelayedInvocation::Function function ) noexcept
{
    const auto& active = timer->isActive();
    cancelDelayedInvoke();
    DelayedInvocation::function = std::move( function );
    if( active ) { delayedInvoke(); }
}

void DelayedInvocation::setDelay( std::chrono::milliseconds milliseconds ) noexcept
{
    const auto& active = timer->isActive();
    cancelDelayedInvoke();
    timer->setInterval( milliseconds );
    if( active ) { delayedInvoke(); }
}

void DelayedInvocation::immediatelyInvoke() noexcept
{
    onTimeout();
}

void DelayedInvocation::delayedInvoke() noexcept
{
    timer->start();
}

void DelayedInvocation::cancelDelayedInvoke() noexcept
{
    if( timer->isActive() ) { timer->stop(); }
}

void DelayedInvocation::onTimeout() noexcept
{
    if( function ) { function(); }
}

void DelayedInvocation::setup( std::chrono::milliseconds milliseconds ) noexcept
{
    timer->setSingleShot( true );
    timer->setInterval( milliseconds );

    connect( timer, &QTimer::timeout,
             this, &DelayedInvocation::onTimeout );
}

}
}