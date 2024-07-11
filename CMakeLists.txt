cmake_minimum_required(VERSION 3.5.0)
project(MyNeuralNetwork VERSION 0.1.0 LANGUAGES C CXX)

set(DirectorioOutPut "${CMAKE_SOURCE_DIR}/bin/${CMAKE_SYSTEM_NAME}/${CMAKE_BUILD_TYPE}") #variable para facilitar los siguientes paths
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${DirectorioOutPut}/libFiles") #path de los binanaies librerias staticas (las que se compilan con el el programa, los.lib files)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${DirectorioOutPut}/binDeLibraria") #creo que es donde se deja el bin de la libreria si eventualemnte quiero hacer una libreria
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${DirectorioOutPut}") #path donde va a estar el executable de mi programa!

#include_directories(.) #include directorios para que busque los archivos que necesti para compilar
#add_library() con esto se crean las librerias, los .lib y los .dll (si se pone la opcion SHARED), nose si es necesario para el linking
#target_link_libraries(${PROJECT_NAME} archivoDeLibrerias) es necesario decir que vamosa  querer linkerar los archivos con el el executable final

add_executable(MyNeuralNetwork main.cpp)

