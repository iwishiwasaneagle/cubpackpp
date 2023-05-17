#
# Print a message only if the `VERBOSE_OUTPUT` option is on
#
if (NOT COMMAND verbose_message)
    function(verbose_message content)
        if (${PROJECT_NAME}_VERBOSE_OUTPUT)
            message(STATUS ${content})
        endif ()
    endfunction()
endif ()

#
# Add a target for formating the project using `clang-format` (i.e: cmake --build build --target clang-format)
#
if (PROJECT_IS_TOP_LEVEL)
    function(add_clang_format_target)
        if (NOT ${PROJECT_NAME}_CLANG_FORMAT_BINARY)
            find_program(${PROJECT_NAME}_CLANG_FORMAT_BINARY clang-format)
        endif ()

        if (${PROJECT_NAME}_CLANG_FORMAT_BINARY)
            if (${PROJECT_NAME}_BUILD_EXECUTABLE)
                add_custom_target(clang-format
                        COMMAND ${${PROJECT_NAME}_CLANG_FORMAT_BINARY}
                        -i ${exe_sources} ${headers}
                        WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR})
            elseif (${PROJECT_NAME}_BUILD_HEADERS_ONLY)
                add_custom_target(clang-format
                        COMMAND ${${PROJECT_NAME}_CLANG_FORMAT_BINARY}
                        -i ${headers}
                        WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR})
            else ()
                add_custom_target(clang-format
                        COMMAND ${${PROJECT_NAME}_CLANG_FORMAT_BINARY}
                        -i ${sources} ${headers}
                        WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR})
            endif ()

            message(STATUS "Format the project using the `clang-format` target (i.e: cmake --build build --target clang-format).\n")
        endif ()
    endfunction()
endif ()

