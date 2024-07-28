cmake_minimum_required(VERSION 3.5.0)
project(Ceibo VERSION 0.1.0 LANGUAGES C CXX)

set (CMAKE_CXX_STANDARD 17)

set(DirectorioOutPut "${CMAKE_SOURCE_DIR}/bin/${CMAKE_SYSTEM_NAME}/${CMAKE_BUILD_TYPE}") #variable para facilitar los siguientes paths
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${DirectorioOutPut}") #path donde va a estar el executable de mi programa!


include_directories(${CMAKE_SOURCE_DIR}/dependencies/SFML/include/)
add_definitions(-DSFML_STATIC)

set(DIR_LIB ${CMAKE_SOURCE_DIR}/dependencies/SFML/lib/)
set(SOURCES
    src/main.cpp
    src/model.cpp
    src/view.cpp
    src/controller.cpp
)

add_executable(Ceibo ${SOURCES}) #Crea el ejecutable del programa

target_link_libraries(Ceibo ${CMAKE_SOURCE_DIR}dependencies/SFML/lib/libFLAC.a ${CMAKE_SOURCE_DIR}dependencies/SFML/lib/libfreetype.a ${CMAKE_SOURCE_DIR}dependencies/SFML/lib/libogg.a 
${CMAKE_SOURCE_DIR}dependencies/SFML/lib/libopenal32.a ${CMAKE_SOURCE_DIR}dependencies/SFML/lib/libsfml-audio-d.a ${CMAKE_SOURCE_DIR}dependencies/SFML/lib/libsfml-audio-s-d.a 
${CMAKE_SOURCE_DIR}dependencies/SFML/lib/libsfml-audio-s.a ${CMAKE_SOURCE_DIR}dependencies/SFML/lib/libsfml-audio.a ${CMAKE_SOURCE_DIR}dependencies/SFML/lib/libsfml-graphics-d.a 
${CMAKE_SOURCE_DIR}dependencies/SFML/lib/libsfml-graphics-s-d.a ${CMAKE_SOURCE_DIR}dependencies/SFML/lib/libsfml-graphics-s.a ${CMAKE_SOURCE_DIR}dependencies/SFML/lib/libsfml-graphics.a 
${CMAKE_SOURCE_DIR}dependencies/SFML/lib/libsfml-main-d.a ${CMAKE_SOURCE_DIR}dependencies/SFML/lib/libsfml-main.a ${CMAKE_SOURCE_DIR}dependencies/SFML/lib/libsfml-network-d.a 
${CMAKE_SOURCE_DIR}dependencies/SFML/lib/libsfml-network-s-d.a ${CMAKE_SOURCE_DIR}dependencies/SFML/lib/libsfml-network-s.a ${CMAKE_SOURCE_DIR}dependencies/SFML/lib/libsfml-network.a 
${CMAKE_SOURCE_DIR}dependencies/SFML/lib/libsfml-system-d.a ${CMAKE_SOURCE_DIR}dependencies/SFML/lib/libsfml-system-s-d.a ${CMAKE_SOURCE_DIR}dependencies/SFML/lib/libsfml-system-s.a 
${CMAKE_SOURCE_DIR}dependencies/SFML/lib/libsfml-system.a ${CMAKE_SOURCE_DIR}dependencies/SFML/lib/libsfml-window-d.a ${CMAKE_SOURCE_DIR}dependencies/SFML/lib/libsfml-window-s-d.a 
${CMAKE_SOURCE_DIR}dependencies/SFML/lib/libsfml-window-s.a ${CMAKE_SOURCE_DIR}dependencies/SFML/lib/libsfml-window.a ${CMAKE_SOURCE_DIR}dependencies/SFML/lib/libvorbis.a 
${CMAKE_SOURCE_DIR}dependencies/SFML/lib/libvorbisenc.a ${CMAKE_SOURCE_DIR}dependencies/SFML/lib/libvorbisfile.a
                            ) #esto tiene que estar debajo del add_executable, alfinal, para que ya exista MyNeural...
