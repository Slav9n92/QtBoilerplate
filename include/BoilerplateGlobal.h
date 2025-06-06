/*
 * \file BoilerplateGlobal.h
 * \copyright :
 * \author : Bubnov V.V.
 * \date : 05.06.2025
 * \time : 13:29
 */

#pragma once

#include <QtGlobal>

//@formatter:off
#ifdef BOILERPLATE_SHARED_BUILD
    #if defined( Q_OS_WIN )
        #ifdef BOILERPLATE_EXPORTS
            #define BOILERPLATE_API __declspec( dllexport )
        #else
            #define BOILERPLATE_API __declspec( dllimport )
        #endif
    #elif defined( Q_OS_LINUX )
        #define BOILERPLATE_API __attribute__( ( visibility( "default" ) ) )
    #endif
#else
    #define BOILERPLATE_API
#endif
//@formatter:on

//@formatter:off
#ifdef BOILERPLATE_SHARED_BUILD
    #ifdef Q_OS_LINUX
        #define BOILERPLATE_HIDE __attribute__( ( visibility( "hidden" ) ) )
    #else
        #define BOILERPLATE_HIDE
    #endif
#else
    #define BOILERPLATE_HIDE
#endif
//@formatter:on