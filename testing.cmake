cmake_minimum_required( VERSION 3.11 )

set( TARGET_NAME qt_boilerplate_testing )
enable_testing()

find_package( Qt5 REQUIRED COMPONENTS Test )

add_executable( ${TARGET_NAME} testing/Tests.cpp )

file( GLOB_RECURSE HEADER_FILES "testing/*.h" )
file( GLOB_RECURSE SOURCE_FILES "testing/*.cpp" )
target_sources( ${TARGET_NAME} PRIVATE ${HEADER_FILES} ${SOURCE_FILES} )
target_include_directories( ${TARGET_NAME} PRIVATE testing )

target_link_libraries( ${TARGET_NAME} PRIVATE
                       Qt5::Core
                       Qt5::Test
                       QtBoilerplate
)