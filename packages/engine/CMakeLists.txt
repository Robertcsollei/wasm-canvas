add_subdirectory(core)
add_subdirectory(renderer)  

if(EMSCRIPTEN)
  add_subdirectory(platforms/wasm)   
else()
  add_subdirectory(platforms/win)    
endif()
