find_package(SDL2 REQUIRED)
find_package(glad REQUIRED)


# core/CMakeLists.txt – ONLY the core lib; no add_subdirectory here
file(GLOB CORE_SOURCES CONFIGURE_DEPENDS
  "${CMAKE_CURRENT_LIST_DIR}/src/*.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/src/**/*.cpp"
)

add_library(renderer_gl STATIC ${CORE_SOURCES})
target_include_directories(renderer_gl 
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
	PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_compile_features(renderer_gl PUBLIC cxx_std_20)



target_link_libraries(renderer_gl
  PUBLIC core
  PRIVATE SDL2::SDL2 glad::glad
)


