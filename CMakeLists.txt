cmake_minimum_required (VERSION 3.15)

## Project definition
set(project_title "PROJECT_TITLE")
set(project_description "PROJECT_DESCRIPTION")
set(project_author "Martin Homuth")
set(project_url "martinhomuth.de")
set(project_revised_date "20-02-16")
set(project_version_major 0)
set(project_version_minor 1)
set(project_version_patch 0)
set(project_version ${project_version_major}.${project_version_minor}.${project_version_patch})
set(project_copyright_date "2020")
set(project_copyright "Copyright © ${project_copyright_date} ${project_author}")

project(${project_title}
  VERSION ${project_version}
  DESCRIPTION ${project_description}
  HOMEPAGE_URL ${project_url}
  LANGUAGES C
  )

## Submodules
include(FetchContent)

## External Projects
add_subdirectory(external/CuTest)

## Project configuration

# Link this 'library' to set the c++ standard / compile-time options requested
add_library(project_options INTERFACE)
target_compile_features(project_options INTERFACE c_std_11)

# Link this 'library' to use the warnings specified in CompilerWarnings.cmake
add_library(project_warnings INTERFACE)

# standard compiler warnings
include(cmake/CompilerWarnings.cmake)
set_project_warnings(project_warnings)

include(cmake/StaticAnalyzers.cmake)

include(cmake/Sanitizers.cmake)
enable_sanitizers(project_options)

if (ENABLE_TESTING)
  enable_testing()
  message(STATUS "Building tests.")
  add_subdirectory(test)
endif()

add_subdirectory(src)

