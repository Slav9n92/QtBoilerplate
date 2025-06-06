cmake_minimum_required( VERSION 3.11 )
project( QtBoilerplate )

set( TARGET_NAME "QtBoilerplate" )

set( CMAKE_CXX_STANDARD 14 )
set( CMAKE_AUTOMOC ON )

option( QtBoilerplate_SHARED_BUILD "Build as shared library" OFF )
option( boilerplate_BUILD_TEST "Включает юнит тесты" OFF )

find_package( Qt5 REQUIRED COMPONENTS Core )

file( GLOB_RECURSE HEADER_FILES "include/*.h" )
file( GLOB_RECURSE SOURCE_FILES "src/*.cpp" )

if ( QtBoilerplate_SHARED_BUILD )
	add_library( ${TARGET_NAME} SHARED ${HEADER_FILES} ${SOURCE_FILES} )
	target_compile_definitions( ${TARGET_NAME} PUBLIC BOILERPLATE_SHARED_BUILD BOILERPLATE_EXPORTS )
else ()
	add_library( ${TARGET_NAME} STATIC ${HEADER_FILES} ${SOURCE_FILES} )
endif ()

target_include_directories( ${TARGET_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/ )
target_include_directories( ${TARGET_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/ )

target_link_libraries( ${TARGET_NAME} PUBLIC Qt5::Core )
set_target_properties( ${TARGET_NAME} PROPERTIES PUBLIC_HEADER "${HEADER_FILES}" )

if ( boilerplate_BUILD_TEST )
	include( testing.cmake )
endif ( boilerplate_BUILD_TEST )