cmake_minimum_required(VERSION 3.5.0)
project(Ceibo VERSION 0.1.0 LANGUAGES C CXX)

set (CMAKE_CXX_STANDARD 17)
set(DirectorioOutPut "${CMAKE_SOURCE_DIR}/bin/${CMAKE_SYSTEM_NAME}/${CMAKE_BUILD_TYPE}") #variable para facilitar los siguientes paths

include_directories(${CMAKE_SOURCE_DIR}/dependencies/glfw64/include/) #agrego el path donde va a estar el archivo de la biblioteca
include_directories(${CMAKE_SOURCE_DIR}/dependencies/glew/include/) #agrego el path donde va a estar el archivo de la biblioteca


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${DirectorioOutPut}") #path donde va a estar el executable de mi programa!


set(SOURCES
    src/main.cpp
    src/model.cpp
    src/view.cpp
    src/controller.cpp
)

add_definitions(-DGLEW_STATIC)

add_executable(Ceibo ${SOURCES}) #Crea el ejecutable del programa

target_link_libraries(Ceibo ${CMAKE_SOURCE_DIR}/dependencies/glfw64/lib-mingw-w64/libglfw3.a
                            ${CMAKE_SOURCE_DIR}/dependencies/glew/lib/Release/x64/glew32s.lib
                            opengl32.lib 
                            gdi32
                            kernel32
                            user32
                            ) #esto tiene que estar debajo del add_executable, alfinal, para que ya exista MyNeural...
