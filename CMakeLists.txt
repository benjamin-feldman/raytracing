cmake_minimum_required(VERSION 3.10)
project(MyProject)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Specify the executable
add_executable(main src/main.cpp)

# Specify the output directory
set_target_properties(main PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Custom command to run the executable and append output to img.ppm
add_custom_command(
    TARGET main
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E remove img.ppm
    COMMAND ${CMAKE_COMMAND} -E echo "Running main and appending output to img.ppm"
    COMMAND ${CMAKE_BINARY_DIR}/bin/main >> /img/img.ppm
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)
