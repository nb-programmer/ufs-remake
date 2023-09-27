project(hal)

add_library(stub STATIC "stub.cpp")


# TODO: Add OPTION for this target

add_library(xsdl STATIC "xsdl.cpp")

# Require SDL2
find_package(SDL2 REQUIRED)

target_link_libraries(xsdl PRIVATE SDL2)
