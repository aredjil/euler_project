cmake_minimum_required(VERSION 3.19)

project(gathering VERSION 1.0.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Find MPI
find_package(MPI REQUIRED)
find_package(OpenMP REQUIRED)

set(CMAKE_BUILD_TYPE Release)

set(EXECUTABLE_NAME main.x)

# Add the executable target with its source files
add_executable(${EXECUTABLE_NAME} src/main.cpp src/gather.cpp)

# Link MPI
target_link_libraries(${EXECUTABLE_NAME} PRIVATE MPI::MPI_CXX)

# Link OpenMP if found
if(OpenMP_CXX_FOUND)
    target_link_libraries(${EXECUTABLE_NAME} PUBLIC OpenMP::OpenMP_CXX)
endif()

# Include project headers
target_include_directories(${EXECUTABLE_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/include)

# Optimization flags
target_compile_options(${EXECUTABLE_NAME} PRIVATE -O3 -march=native -DNDEBUG)
