/*
 * \file ExpectedMoc.h
 * \copyright :
 * \author : Bubnov V.V.
 * \date : 27.06.2025
 * \time : 13:51
 */

#pragma once

namespace qt {
namespace boilerplate {
namespace testing {

class ExpectedMoc final
{
public:
    ExpectedMoc() noexcept;
    ExpectedMoc( const ExpectedMoc& other ) noexcept;
    ExpectedMoc( ExpectedMoc&& other ) noexcept;
    ExpectedMoc& operator=( const ExpectedMoc& other ) noexcept;
    ExpectedMoc& operator=( ExpectedMoc&& other ) noexcept;
    ~ExpectedMoc() noexcept;

public:
    static int getCtorCount() noexcept;
    static int getCopyCtorCount() noexcept;
    static int getMoveCtorCount() noexcept;
    static int getCopyAssigmentCount() noexcept;
    static int getMoveAssigmentCount() noexcept;
    static int getDtorCount() noexcept;

public:
    static void reset() noexcept;

private:
    static int ctor;
    static int copyCtor;
    static int moveCtor;
    static int copyAssigment;
    static int moveAssigment;
    static int dtor;
};

}
}
}