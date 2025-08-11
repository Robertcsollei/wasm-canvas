cmake_minimum_required(VERSION 3.22)
project(core_cpp)

add_library(core STATIC
  src/core.cpp
)

target_include_directories(core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

# Wasm-specific flags when using emscripten
if (EMSCRIPTEN)
  set_target_properties(core PROPERTIES
    OUTPUT_NAME "core"
    SUFFIX ".wasm"
    LINK_FLAGS "
      -s MODULARIZE=1
      -s EXPORT_ES6=1
      -s ENVIRONMENT=web
      -s ALLOW_MEMORY_GROWTH=1
      -s EXPORTED_RUNTIME_METHODS=['UTF8ToString','stringToUTF8','lengthBytesUTF8']
      -s FILESYSTEM=0
    "
  )
endif()
