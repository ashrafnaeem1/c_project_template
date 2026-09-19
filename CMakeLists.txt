cmake_minimum_required(VERSION 3.25)

project(MyCProject
    VERSION 1.0.0
    LANGUAGES C
    DESCRIPTION "Modern C23 project template (Windows x64 / MSVC + vcpkg)"
)

# ---------- C23 ----------
set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

# ---------- MSVC-specific flags ----------
if(MSVC)
    add_compile_options(
        /std:clatest # Full C23 support (nullptr, etc.)
        /W4 # High warning level
        /permissive- # Strict standard conformance
        /utf-8 # Source & execution charset
        /Zc:preprocessor # Conformant preprocessor
    )
    # Optional: treat warnings as errors in Release
    # add_compile_options($<$<CONFIG:Release>:/WX>)
endif()

# ---------- Executable ----------
add_executable(MyCProjectApp
    src/main.c
    src/two_sums.c
)

target_include_directories(MyCProjectApp
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# ---------- vcpkg example (uncomment when you add packages) ----------
# find_package(fmt CONFIG REQUIRED)          # example
# target_link_libraries(MyCProjectApp PRIVATE fmt::fmt)

# Optional: install target
# install(TARGETS MyCProjectApp RUNTIME DESTINATION bin)
