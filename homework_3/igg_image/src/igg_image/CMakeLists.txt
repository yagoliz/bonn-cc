add_subdirectory(io_strategies)

# Add image library
add_library(image image.cpp)

target_link_libraries(image strategies)
