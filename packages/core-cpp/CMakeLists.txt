cmake_minimum_required(VERSION 3.22)
project(core_cpp)

# Build a loadable Wasm module (no main())
add_executable(core_wasm
  src/core.cpp
  src/render/renderer.cpp
  src/app.cpp
  src/main.cpp
)

# Headers if you have any
target_include_directories(core_wasm PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# Put outputs under build dir
set_target_properties(core_wasm PROPERTIES
  OUTPUT_NAME core
  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/dist"
)

if (EMSCRIPTEN)
  target_link_options(core_wasm PRIVATE
    -sUSE_WEBGL2=1
    -sMODULARIZE=1 -sEXPORT_ES6=1
    -sENVIRONMENT=web
    -sALLOW_MEMORY_GROWTH=1
    -sFILESYSTEM=0
    -lembind

    # Only add malloc/free if you actually call them from JS
    # -sEXPORTED_FUNCTIONS=['_malloc','_free']

    -sEXPORTED_RUNTIME_METHODS=['HEAPF32','UTF8ToString','stringToUTF8','lengthBytesUTF8']

    -lembind
  )
endif()
