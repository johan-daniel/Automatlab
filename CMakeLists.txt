cmake_minimum_required(VERSION 3.20.0)

project(Automat'Lab VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 23)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

qt_standard_project_setup()

file(GLOB_RECURSE SOURCES src/*)
file(GLOB_RECURSE HEADERS include/*)
file(GLOB_RECURSE UIS ui/*)


foreach(file "========== FOUND SOURCES ==========" ${SOURCES})
    message("       ${file}")
endforeach()

foreach(file "========== FOUND HEADERS ==========" ${HEADERS})
    message("       ${file}")
endforeach()

foreach(file "========== FOUND UIS ==========" ${UIS})
    message("       ${file}")
endforeach()

add_compile_options(
  -Wall
  $<$<CONFIG:DEBUG>:-g3>
  $<$<CONFIG:DEBUG>:-Og>
  $<$<CONFIG:RELEASE>:-O3>
)


add_executable(automatlab ${SOURCES} ${HEADERS})
qt_wrap_ui(SOURCES ${UIS})
qt_add_ui(automatlab SOURCES ${UIS} INCLUDE_PREFIX ui/)
target_link_libraries(automatlab Qt6::Widgets)