cmake_minimum_required(VERSION 3.5.0)
project(Ceibo VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_COMPILER "C:/Program Files/Microsoft Visual Studio/2022/Professional/VC/Tools/MSVC/14.35.32215/bin/Hostx64/x64/cl.exe")

#set(DirectorioOutPut "${CMAKE_SOURCE_DIR}/bin/${CMAKE_SYSTEM_NAME}/${CMAKE_BUILD_TYPE}") #variable para facilitar los siguientes paths
set(DirectorioOutPut "${CMAKE_SOURCE_DIR}/bin/test/") #variable para facilitar los siguientes paths

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${DirectorioOutPut}") #path donde va a estar el executable de mi programa!

#add_definitions(-DSFML_STATIC)

set(DIR_LIB ${CMAKE_SOURCE_DIR}/dependencies/SFML-VS64/lib/)
#[[
set(SOURCES
    src/main.cpp
    src/model.cpp
    src/view.cpp
    src/controller.cpp
)]]

set(SOURCES src/mainTest.cpp)

add_executable(Ceibo ${SOURCES}) #Crea el ejecutable del programa

target_link_libraries(Ceibo PUBLIC ${DIR_LIB}sfml-system.lib
                                    ${DIR_LIB}sfml-window.lib
                            ${DIR_LIB}sfml-graphics.lib
                            opengl32 winmm gdi32 ) #esto tiene que estar debajo del add_executable, alfinal, para que ya exista MyNeural...

include_directories(${CMAKE_SOURCE_DIR}/dependencies/SFML-VS64/include/)