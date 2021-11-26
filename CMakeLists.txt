# =============================================================================
# General settings
# -----------------------------------------------------------------------------
cmake_minimum_required(VERSION 3.16.2)

project(
  Macasten-Code-Challenges
  VERSION 1.0.0
  DESCRIPTION "My project to resolve code Challenges"
  LANGUAGES CXX
)

# =============================================================================
# Compiler settings
# -----------------------------------------------------------------------------

# Define a parta onde sera colocado o binario resultante da compilação
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../output)

# Add executable
# To add libraries see: https://stackoverflow.com/questions/14306642/adding-multiple-executables-in-cmake
file( GLOB_RECURSE FILES_SOURCES *.cpp )
list( FILTER FILES_SOURCES EXCLUDE REGEX ".build.")

# Executables will have de folder Name
foreach( MAIN_SOURCE_FILE ${FILES_SOURCES} )
  get_filename_component(EXECUTABLE_DIRECTORY ${MAIN_SOURCE_FILE} DIRECTORY)
  get_filename_component(EXECUTABLE_NAME ${EXECUTABLE_DIRECTORY} NAME_WE)
  add_executable( ${EXECUTABLE_NAME} ${MAIN_SOURCE_FILE} )
endforeach( MAIN_SOURCE_FILE ${FILES_SOURCES} )