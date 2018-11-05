#################### Import the 'io_tools' library here ########################
find_library(TOOLS
             NAMES io_tools
             PATHS ${LIBRARY_OUTPUT_PATH})

#################### Create a library 'image' below this line ##################
add_library(image STATIC image.cc)

target_link_libraries(image ${TOOLS})

#################### Create example executable
add_executable(main main.cc)

target_link_libraries(main image)


