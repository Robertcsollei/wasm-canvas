# core/CMakeLists.txt – ONLY the core lib; no add_subdirectory here
file(GLOB CORE_SOURCES CONFIGURE_DEPENDS
  "${CMAKE_CURRENT_LIST_DIR}/src/*.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/src/**/*.cpp"
)

add_library(core STATIC ${CORE_SOURCES})
target_include_directories(core PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_compile_features(core PUBLIC cxx_std_20)
