message(STATUS "Adding examples...")

set(examples
        simple_triangle.cpp
        so_many_triangles.cpp
        simple_rectangle.cpp
        )

foreach (example IN LISTS examples)
    get_filename_component(EXAMPLE_WITHOUT_EXT ${example} NAME_WE)
    set(EXAMPLE_NAME ${CMAKE_PROJECT_NAME}_${EXAMPLE_WITHOUT_EXT})

    add_executable(${EXAMPLE_NAME} ${example})
    target_link_libraries(${EXAMPLE_NAME} ${CMAKE_PROJECT_NAME})

    set_target_properties(
            ${EXAMPLE_NAME}
            PROPERTIES
            RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/examples/"
            OUTPUT_NAME ${EXAMPLE_NAME}
    )
    target_compile_features(${EXAMPLE_NAME} PUBLIC cxx_std_17)
    message(STATUS "* ${example}")


endforeach ()

list(LENGTH examples N_EXAMPLES)
message(STATUS "${N_EXAMPLES} examples have been added\n")

