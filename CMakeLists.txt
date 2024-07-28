cmake_minimum_required(VERSION 3.5.0)
project(Ceibo VERSION 0.1.0 LANGUAGES C CXX)

set (CMAKE_CXX_STANDARD 17)
set(DirectorioOutPut "${CMAKE_SOURCE_DIR}/bin/${CMAKE_SYSTEM_NAME}/${CMAKE_BUILD_TYPE}") #variable para facilitar los siguientes paths


include_directories(${CMAKE_SOURCE_DIR}/dependencies/SFML/include/)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${DirectorioOutPut}") #path donde va a estar el executable de mi programa!


set(SOURCES
    src/main.cpp
    src/model.cpp
    src/view.cpp
    src/controller.cpp
)

add_definitions(SFML_STATIC)

add_executable(Ceibo ${SOURCES}) #Crea el ejecutable del programa

target_link_libraries(Ceibo 
                            ) #esto tiene que estar debajo del add_executable, alfinal, para que ya exista MyNeural...
