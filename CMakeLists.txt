cmake_minimum_required(VERSION 3.15)
project(
        "cubpackpp"
        VERSION 0.1.0
        LANGUAGES CXX
)
message(STATUS "Started CMake for ${PROJECT_NAME} v${PROJECT_VERSION}...")

include(cmake/StandardSettings.cmake)
include(cmake/Utils.cmake)
include(cmake/SourcesAndHeaders.cmake)

if (${PROJECT_NAME}_VERBOSE_OUTPUT)
    verbose_message("Found the following headers:")
    foreach (header IN LISTS headers)
        verbose_message("* ${header}")
    endforeach ()
    verbose_message("Found the following templates:")
    foreach (template IN LISTS templates)
        verbose_message("* ${template}")
    endforeach ()
endif ()

add_library(${PROJECT_NAME} SHARED STATIC ${sources} ${headers} ${templates})
target_include_directories(
        ${PROJECT_NAME}
        PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)
set_target_properties(
        ${PROJECT_NAME}
        PROPERTIES
        PUBLIC_HEADER include/cubpackpp/cubpackpp.h
        ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib/${CMAKE_BUILD_TYPE}"
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib/${CMAKE_BUILD_TYPE}"
        OUTPUT_NAME ${PROJECT_NAME}
        VERSION ${PROJECT_VERSION}
)
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)

add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})
verbose_message("Project is now aliased as ${PROJECT_NAME}::${PROJECT_NAME}.\n")

if(${PROJECT_NAME}_EXAMPLES)
    add_subdirectory(examples)
endif ()

