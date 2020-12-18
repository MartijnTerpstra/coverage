cmake_minimum_required (VERSION 3.13)

project (coverage CXX)

add_library(mtmath INTERFACE)
add_library(mtmath::mtmath ALIAS mtmath)

target_include_directories(mtmath INTERFACE "${CMAKE_SOURCE_DIR}/mtmath")

enable_testing()

include(CTest)


Include(FetchContent)

FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG master
        GIT_SHALLOW 1
    )

FetchContent_GetProperties(googletest)

if(NOT googletest_POPULATED)
    FetchContent_Populate(googletest)
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
endif()

function(SETUP_TARGET TARGET_NAME)
    set_target_properties(${TARGET_NAME} PROPERTIES CXX_EXTENSIONS OFF)
    target_link_libraries(${TARGET_NAME} PRIVATE mtmath)

    if(MSVC)
        target_compile_options(
            ${TARGET_NAME}
            PRIVATE
                /EHsc /W1 /wd4996 /w14800
                $<$<CONFIG:Debug>:/Od>
                $<$<CONFIG:Release>:/O2>
        )
    else()
        target_compile_options(
            ${TARGET_NAME}
            PRIVATE
                -pedantic -fvisibility=hidden -Wall -Wshadow -Wno-deprecated-declarations
                $<$<CONFIG:Debug>:-O0 -g>
                $<$<CONFIG:Release>:-O2>
        )
    endif()

    target_compile_definitions(${TARGET_NAME} PRIVATE ${ARGN})
endfunction()

function(SETUP_BASIC_TEST TEST_NAME TEST_SOURCES)
    add_executable(${TEST_NAME} ${TEST_SOURCES})
    target_link_libraries(${TEST_NAME} PRIVATE gtest_main)
    SETUP_TARGET(${TEST_NAME} ${ARGN})
    add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
endfunction()

SETUP_BASIC_TEST(algorithm tests/algorithm.cpp)
