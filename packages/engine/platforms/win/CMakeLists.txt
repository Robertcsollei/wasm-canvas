add_executable(core_dbg WIN32 src/main.cpp "src/test.h")

target_link_libraries(core_dbg
  PRIVATE core
  PRIVATE renderer_gl
)

target_include_directories(core_dbg PRIVATE
  "${CMAKE_CURRENT_LIST_DIR}/src"
)

# Per-config output dirs for Visual Studio (multi-config generator)
foreach(cfg Debug Release RelWithDebInfo MinSizeRel)
  set_target_properties(core_dbg PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY_${cfg} "${CMAKE_BINARY_DIR}/dist/${cfg}")
endforeach()

# Tell VS exactly what to debug (no guessing)
set_target_properties(core_dbg PROPERTIES
  VS_DEBUGGER_COMMAND "$<TARGET_FILE:core_dbg>"
  VS_DEBUGGER_WORKING_DIRECTORY "$<TARGET_FILE_DIR:core_dbg>"
)



