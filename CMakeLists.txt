cmake_minimum_required(VERSION 3.20)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")
list(APPEND CMAKE_PREFIX_PATH "deps/")

include("common-config")
include("auto-toolchain")

# Configure project
project(
    ufs-${PROJECT_TARGET_NAME}
    DESCRIPTION "Hello World template for 8-bit platforms using CMake, targetting LLVM-MOS"
    LANGUAGES C CXX
    VERSION 1.0
)

# Try to determine which toolchain was used to specify additional options

if(LLVM_MOS)
    # Using the LLVM-MOS-SDK toolchain. We need to set some options for it
    message(STATUS "Using LLVM-MOS toolchain")
    include_directories(${LLVM_INCLUDE_DIRS})
    separate_arguments(LLVM_DEFINITIONS_LIST NATIVE_COMMAND ${LLVM_DEFINITIONS})
    add_definitions(${LLVM_DEFINITIONS_LIST})
    enable_language(ASM)
endif()


add_subdirectory("deps/libSDL2pp")

## Build SDL2pp
target_compile_features(SDL2pp PRIVATE cxx_std_17)


add_subdirectory("platform")

# Build the main project executable
add_executable(${CMAKE_PROJECT_NAME} "src/main.cpp")

# Add the project source code
add_subdirectory("src/")

# You can add custom commands to build resources and other things

# add_custom_command(
#     OUTPUT resource.bin
#     COMMAND make-resource -o resource.bin res-source1 res-source2
#     VERBATIM
# )


# Add some preprocessor defines
target_compile_definitions(${CMAKE_PROJECT_NAME} PUBLIC "$<$<CONFIG:DEBUG>:DEBUG>")
target_compile_definitions(${CMAKE_PROJECT_NAME}
    PUBLIC PROJECT_TARGET_NAME="${PROJECT_TARGET_NAME}"
)
