cmake_minimum_required(VERSION 4.0)

# Declare project as pure C
project(MyCProject VERSION 1.0.0 LANGUAGES C)

# Modern C23 standard configuration for CMake 4.x
set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

# Force MSVC flags globally so MSBuild applies /std:clatest to all C files
if(MSVC)
    add_compile_options(
        /std:clatest # Exposes MSVC's latest C23 compiler features (like nullptr)
        /W4 # High warning level
        /utf-8 # Match source and execution character sets
    )
endif()

# Define executable
add_executable(MyCProjectApp
    src/main.c
    src/two_sums.c
)

# Flexible Include Paths Setup
target_include_directories(MyCProjectApp
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# --------------------------------------------------------------------
# Package Management & Subdirectory Integration Placeholders
# --------------------------------------------------------------------

# Option A: Adding a local library (e.g., third_party/foo)
# add_subdirectory(third_party/foo)
# target_link_libraries(MyCProjectApp PRIVATE foo)

# Option B: Importing an external installed package via vcpkg/Conan
# find_package(CURL REQUIRED)
# target_link_libraries(MyCProjectApp PRIVATE CURL::libcurl)
