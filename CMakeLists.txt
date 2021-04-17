cmake_minimum_required(VERSION 3.10)

# set the project name
project(Keypad)

# Set compiler flags.
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -pedantic-errors")

include_directories (./include)

# add the executable
add_executable(main 
	src/main.cpp include/keypad.h src/keypad.cpp)


link_directories(${GTKMM_LIBRARY_DIRS})

include_directories(${GTKMM_INCLUDE_DIRS})

target_link_libraries(main ${GTKMM_LIBRARIES})


# Define the source files and dependencies for the executable.
set(SOURCE_FILES
        src/main.cpp
        src/keypad.cpp)

# Make the project root directory the working directory when we run.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)