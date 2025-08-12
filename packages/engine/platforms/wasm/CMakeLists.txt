# Build this directory only when using emscripten
if(NOT EMSCRIPTEN)
  return()
endif()

add_executable(core_glue
  src/main.cpp
  src/bindings.cpp        
)

target_link_libraries(core_glue
  PRIVATE core
  PRIVATE renderer_gl
)


target_include_directories(core_glue PRIVATE
  "${CMAKE_CURRENT_LIST_DIR}/src"
)

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
