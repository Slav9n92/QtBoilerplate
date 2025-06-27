/*
 * \file ExpectedMoc.cpp
 * \copyright :
 * \author : Bubnov V.V.
 * \date : 27.06.2025
 * \time : 13:51
 */

#include "ExpectedMoc.h"

namespace qt {
namespace boilerplate {
namespace testing {

ExpectedMoc::ExpectedMoc() noexcept
{
    ++ctor;
}

ExpectedMoc::ExpectedMoc( const ExpectedMoc& other ) noexcept
{
    ( void ) other;
    ++copyCtor;
}

ExpectedMoc::ExpectedMoc( ExpectedMoc&& other ) noexcept
{
    ( void ) other;
    ++moveCtor;
}

ExpectedMoc& ExpectedMoc::operator =( const ExpectedMoc& other ) noexcept
{
    if( this != &other ){ ++copyAssigment; }
    return *this;
}

ExpectedMoc& ExpectedMoc::operator =( ExpectedMoc&& other ) noexcept
{
    if( this != &other ){ ++moveAssigment; }
    return *this;
}

ExpectedMoc::~ExpectedMoc() noexcept
{
    ++dtor;
}

int ExpectedMoc::getCtorCount() noexcept
{
    return ctor;
}

int ExpectedMoc::getCopyCtorCount() noexcept
{
    return copyCtor;
}

int ExpectedMoc::getMoveCtorCount() noexcept
{
    return moveCtor;
}

int ExpectedMoc::getCopyAssigmentCount() noexcept
{
    return copyAssigment;
}

int ExpectedMoc::getMoveAssigmentCount() noexcept
{
    return moveAssigment;
}

int ExpectedMoc::getDtorCount() noexcept
{
    return dtor;
}

void ExpectedMoc::reset() noexcept
{
    ctor = 0;
    copyCtor = 0;
    moveCtor = 0;
    copyAssigment = 0;
    moveAssigment = 0;
    dtor = 0;
}

int ExpectedMoc::ctor = 0;
int ExpectedMoc::copyCtor = 0;
int ExpectedMoc::moveCtor = 0;
int ExpectedMoc::copyAssigment = 0;
int ExpectedMoc::moveAssigment = 0;
int ExpectedMoc::dtor = 0;

}
}
}