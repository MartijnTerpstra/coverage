cmake_minimum_required (VERSION 3.13)

project (mst CXX)

add_library(mst STATIC src/algorithm.cpp)
add_library(mst::mst ALIAS mst)

target_include_directories(mst PUBLIC "${CMAKE_SOURCE_DIR}/mst")

enable_testing()

include(CTest)


Include(FetchContent)

FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v2.13.1
    )

FetchContent_MakeAvailable(Catch2)

list (APPEND CMAKE_MODULE_PATH "${Catch2_SOURCE_DIR}/contrib")

include(Catch)

function(SETUP_TARGET TARGET_NAME)
    set_target_properties(${TARGET_NAME} PROPERTIES CXX_EXTENSIONS OFF)
    target_link_libraries(${TARGET_NAME} PRIVATE mst)

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
    target_link_libraries(${TEST_NAME} PRIVATE Catch2::Catch2)
    SETUP_TARGET(${TEST_NAME} ${ARGN})
    add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
    catch_discover_tests(${TEST_NAME})

endfunction()

SETUP_BASIC_TEST(algorithm tests/algorithm.cpp)