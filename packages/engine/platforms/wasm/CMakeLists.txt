# Build this directory only when using emscripten
if(NOT EMSCRIPTEN)
  return()
endif()

# One executable that contains your wasm "main" + optional bindings
add_executable(core_glue
  src/main.cpp
  src/bindings.cpp        # optional embind; remove if you don't use it
)

target_link_libraries(core_glue
  PRIVATE core
  PRIVATE renderer_gl
)


# Tell it where to find core headers (app.h, api.hpp)
target_include_directories(core_glue PRIVATE
  "${CMAKE_CURRENT_LIST_DIR}/src"
)

# Typical emscripten link flags
target_link_options(core_glue PRIVATE
  --bind                 # if bindings.cpp uses <emscripten/bind.h>
  -sMODULARIZE=1
  -sEXPORT_ES6=1
  -sENVIRONMENT=web
  -sALLOW_MEMORY_GROWTH=1
  -sWASM_BIGINT=1
  -sFILESYSTEM=0
)

set_target_properties(core_glue PROPERTIES
  OUTPUT_NAME core
  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/dist"
  FOLDER "platforms/wasm"
)
