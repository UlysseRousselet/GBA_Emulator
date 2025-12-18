cmake_minimum_required(VERSION 3.25.1)
project(gba_emulator VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_EXPORT_COMPILE_COMMANDS On)

set(ENABLE_CLANG_TIDY "ON" CACHE STRING "Enable clang-tidy (OFF, ON, FULL)")
set_property(CACHE ENABLE_CLANG_TIDY PROPERTY STRINGS OFF ON FULL)

include(CPM.cmake)

find_package(Threads REQUIRED)

include(FetchContent)

if (WIN32)
    add_definitions(-D_WIN32_WINNT=0x0A00)
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB SOURCES "src/*.cpp" "src/game/*.cpp" "src/game/scene/*.cpp" "src/systems/*.cpp")

add_executable(gba_emulator ${SOURCES})

target_include_directories(gba_emulator PRIVATE
    ${PROJECT_SOURCE_DIR}/include/ECS/Components
    ${PROJECT_SOURCE_DIR}/include/ECS/Systems
    ${PROJECT_SOURCE_DIR}/include/ECS/Registry
    ${PROJECT_SOURCE_DIR}/include/ECS
    ${PROJECT_SOURCE_DIR}/include/Client
    ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(gba_emulator PRIVATE)

if(WIN32)
    FetchContent_Declare(
        SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.x
    )
    FetchContent_MakeAvailable(SFML)
    target_link_libraries(gba_emulator PRIVATE
        sfml-system sfml-window sfml-graphics sfml-audio ws2_32
    )
else()
    find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
    target_link_libraries(gba_emulator PRIVATE
        sfml-system sfml-window sfml-graphics sfml-audio sfml-network
    )
endif()

if (WIN32)
  add_custom_command(TARGET gba_emulator POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy ${FETCHCONTENT_BASE_DIR}/sfml-src/extlibs/bin/x64/openal32.dll $<TARGET_FILE_DIR:gba_emulator>
  )
endif()