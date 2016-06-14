
include_directories(
  ${CMAKE_SOURCE_DIR}/include
)

if (APPLE)
  add_definitions(-std=c++14)
endif()

add_executable(YanaiLib main.cpp)

if (APPLE)
  find_library(COCOA_LIBRARY     Cocoa)
  find_library(OpenGL_LIBRARY    OpenGL)
  find_library(IOKIT_LIBRARY     IOKit)
  find_library(COREVIDEO_LIBRARY CoreVideo)
  set(EXTRA_LIBS
    ${COCOA_LIBRARY}
    ${OpenGL_LIBRARY}
    ${IOKIT_LIBRARY}
    ${COREVIDEO_LIBRARY}
    ${CMAKE_SOURCE_DIR}/lib/libglfw3.a
  )
endif()

target_link_libraries(YanaiLib ${EXTRA_LIBS})
