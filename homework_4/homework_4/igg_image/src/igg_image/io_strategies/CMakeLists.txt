# Find PNG Library
find_package(PNG REQUIRED)
# include_directories(${PNG_INCLUDE_DIR})

# Create startegies library
add_library(strategies
            dummy_strategy.cpp
            png_strategy.cpp
            ppm_strategy.cpp)

# Link strategies tp PNG
target_link_libraries(strategies ${PNG_LIBRARY})
