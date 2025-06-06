/*
 * \file DelayedInvocation.h
 * \copyright :
 * \author : Bubnov V.V.
 * \date : 06.06.2025
 * \time : 13:52
 */

#pragma once

#include <QtCore>
#include <chrono>
#include <BoilerplateGlobal.h>

namespace qt {
namespace boilerplate {

class BOILERPLATE_API DelayedInvocation final : public QObject
{
//@formatter:off
    Q_OBJECT
//@formatter:on

public:
    using Function = std::function< void( void ) >;

public:
    explicit DelayedInvocation( QObject* parent ) noexcept;
    DelayedInvocation( Function function, QObject* parent ) noexcept;
    DelayedInvocation( Function function, std::chrono::milliseconds milliseconds, QObject* parent ) noexcept;
    ~DelayedInvocation() noexcept override;

public:
    void setFunction( Function function ) noexcept;
    void setDelay( std::chrono::milliseconds milliseconds ) noexcept;

public:
    void immediatelyInvoke() noexcept;
    void delayedInvoke() noexcept;
    void cancelDelayedInvoke() noexcept;

private slots:
    void onTimeout() noexcept;

private:
    void setup( std::chrono::milliseconds milliseconds ) noexcept;

private:
    QTimer* timer;
    Function function;
};

}
}