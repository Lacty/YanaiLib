
# set include directory
include_directories(
  ${CMAKE_SOURCE_DIR}/include
)

# set compiler option
if (APPLE)
  add_definitions(-std=c++14)
endif()

add_executable(YanaiLib main.cpp)


# find library
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
    ${CMAKE_SOURCE_DIR}/lib/osx/libglfw3.a
    ${CMAKE_SOURCE_DIR}/lib/osx/libFTGL.a
    ${CMAKE_SOURCE_DIR}/lib/osx/libfreetype.a
  )
elseif(MSVC)
  set(EXTRA_LIBS
    ${CMAKE_SOURCE_DIR}/lib/win/OpenGL32.lib
    ${CMAKE_SOURCE_DIR}/lib/win/freetype.lib
    ${CMAKE_SOURCE_DIR}/lib/win/ftgld.lib
    ${CMAKE_SOURCE_DIR}/lib/win/glfw3d.lib
  )
endif()

target_link_libraries(YanaiLib ${EXTRA_LIBS})