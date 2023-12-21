cmake_minimum_required(VERSION 3.10)

project(FlappyBird)

set(CMAKE_CXX_STANDARD 11)

find_package(raylib 2.5 REQUIRED)

# Add the source files from the src directory
file(GLOB SOURCES "src/*.cpp")

add_executable(flappy ${SOURCES})

target_link_libraries(flappy PRIVATE raylib)

# Custom target to run the executable
add_custom_target(run
    COMMAND ./flappy
    DEPENDS flappy
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Running flappy..."
)
