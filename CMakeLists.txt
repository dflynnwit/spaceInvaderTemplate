cmake_minimum_required(VERSION 3.21)
project(CMakeSFMLProject LANGUAGES CXX)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)


add_executable(CMakeSFMLProject src/main.cpp src/ship.h src/ship.cpp src/game.h)
target_link_libraries(CMakeSFMLProject PRIVATE sfml-graphics)
target_compile_features(CMakeSFMLProject PRIVATE cxx_std_17)
if (WIN32 AND BUILD_SHARED_LIBS)
    add_custom_command(TARGET CMakeSFMLProject POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:CMakeSFMLProject> $<TARGET_FILE_DIR:CMakeSFMLProject> COMMAND_EXPAND_LISTS)
endif()

install(TARGETS CMakeSFMLProject)

## Space invaders
file(GLOB_RECURSE SOURCES src/*.cpp src/*.h)
add_executable(src ${SOURCES} src/ship.h src/ship.cpp src/game.h)
target_include_directories(src SYSTEM PRIVATE ${SFML_INCS})
target_link_libraries(src sfml-graphics)