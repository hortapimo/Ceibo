cmake_minimum_required(VERSION 3.5.0)
project(Ceibo VERSION 0.1.0 LANGUAGES C CXX)

set(DirectorioOutPut "${CMAKE_SOURCE_DIR}/bin/${CMAKE_SYSTEM_NAME}/${CMAKE_BUILD_TYPE}") #variable para facilitar los siguientes paths
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${DirectorioOutPut}") #path donde va a estar el executable de mi programa!

set(CMAKE_WINDOWS_VERSION 10.0)  


option(BUILD_SHARED_LIBS "Build shared libraries" OFF)
include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)
add_definitions(-DSFML_STATIC)

file(GLOB_RECURSE SOURCES "src/*.cpp" "src/utilitis/*.cpp")

add_executable(Ceibo ${SOURCES}) #Crea el ejecutable del programa

target_link_libraries(Ceibo PRIVATE sfml-graphics sfml-window sfml-system)
target_compile_features(Ceibo PRIVATE cxx_std_17)
