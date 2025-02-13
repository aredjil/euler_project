cmake_minimum_required(VERSION 3.19)

project(gathering VERSION 1.0.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_BUILD_TYPE Release)

set(EXECUTABLE_NAME main.x)
find_package(OpenACC REQUIRED)

if(OpenACC_FOUND)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenACC_C_FLAGS}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenACC_CXX_FLAGS}")
    add_compile_definitions(OPENACC)
else()
    message(FATAL_ERROR "OpenACC is required but not found.")
endif()
# Add the executable target with its source files
add_executable(${EXECUTABLE_NAME} src/main.cpp src/gather.cpp)

# Include project headers
target_include_directories(${EXECUTABLE_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/include)

# Optimization flags
target_compile_options(${EXECUTABLE_NAME} PRIVATE -O3 -march=native -DNDEBUG)
