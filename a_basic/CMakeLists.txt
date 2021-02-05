aux_source_directory(. SRCS)

add_definitions(-DSRC_PATH="${CMAKE_SOURCE_DIR}/a_basic")

#for each source: build an executable and install
foreach (example_source ${SRCS})
    get_filename_component(example_name ${example_source} NAME_WE)
    add_executable(${example_name} ${example_source})
    message(STATUS "add executable: ${example_name} fom source: ${example_source}")
    target_link_libraries(${example_name} PRIVATE ${DEPS})
endforeach (example_source)