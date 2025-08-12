# packages/engine/CMakeLists.txt
add_subdirectory(core)
add_subdirectory(renderer)  

if(EMSCRIPTEN)
  add_subdirectory(platforms/wasm)   # only with emscripten
else()
  add_subdirectory(platforms/win)    # only with native
endif()
