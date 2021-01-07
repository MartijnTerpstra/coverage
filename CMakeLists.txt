cmake_minimum_required (VERSION 3.13)

project (mst CXX)

option(MST_RUN_TESTS "Build tests for mst utility library" OFF)

if(UNIX)
set(platform_name "linux")

elseif(WIN32)
set(platform_name "windows")

else() ## platform neither linux nor windows

message(FATAL_ERROR "Platform not found")

endif()

add_library(mst STATIC
    src/${platform_name}/mplatform.cpp
    src/${platform_name}/mthreading.cpp
    src/${platform_name}/mthreading_rw_lock.cpp
    src/${platform_name}/mthreading_slim.cpp
    src/muuid.cpp)

target_compile_features(mst 
	PUBLIC cxx_std_11)

if(UNIX)
target_link_libraries(mst
	PUBLIC pthread)
endif()

add_library(mst::mst ALIAS mst)

target_include_directories(mst PUBLIC "${CMAKE_SOURCE_DIR}/mst")

if(MST_RUN_TESTS)

add_subdirectory(tests)

endif()