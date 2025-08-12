find_package(SDL2 REQUIRED)
find_package(glad REQUIRED)

add_library(renderer_gl STATIC
  "src/renderer_gl.cpp"
  "src/renderer_gl.hpp"
)

target_link_libraries(renderer_gl
  PUBLIC core
  PRIVATE SDL2::SDL2 glad::glad
)


target_include_directories(renderer_gl PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/src
)

set_target_properties(renderer_gl PROPERTIES FOLDER "renderer")