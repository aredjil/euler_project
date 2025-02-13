cmake_minimum_required(VERSION 3.10)

# Set compilers explicitly
set(CMAKE_C_COMPILER nvc)
set(CMAKE_CXX_COMPILER nvc++)

project(gathering VERSION 1.0.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_BUILD_TYPE Release)
set(EXECUTABLE_NAME main.x)

# Set OpenACC flags correctly
set(OPENACC_FLAGS -acc -Minfo=accel)

# Create the executable target
add_executable(${EXECUTABLE_NAME} 
    src/main.cpp 
    src/gather.cpp
)

# Add include directories
target_include_directories(${EXECUTABLE_NAME} 
    PRIVATE 
    ${PROJECT_SOURCE_DIR}/include
)

# Set compiler options
target_compile_options(${EXECUTABLE_NAME} 
    PRIVATE
    ${OPENACC_FLAGS}
    -O3
    -march=native
    -DNDEBUG
)

# Set linker options
target_link_options(${EXECUTABLE_NAME} 
    PRIVATE
    ${OPENACC_FLAGS}
)

# Print configuration summary
message(STATUS "Project configuration summary:")
message(STATUS "  C++ compiler: ${CMAKE_CXX_COMPILER}")
message(STATUS "  C++ compiler version: ${CMAKE_CXX_COMPILER_VERSION}")
message(STATUS "  Build type: ${CMAKE_BUILD_TYPE}")
message(STATUS "  OpenACC flags: ${OPENACC_FLAGS}")





















































