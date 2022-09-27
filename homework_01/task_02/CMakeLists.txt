cmake_minimum_required(VERSION 3.10)

set(PROJECT_NAME task_02)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE source_list "src/*.cpp" "src/*.hpp")
file(GLOB_RECURSE main_source_list "src/main.cpp")
file(GLOB_RECURSE test_source_list "src/*.cpp")
file(GLOB_RECURSE test_list "src/*test.cpp")

message("source_list ${source_list}")
message("test_source_list ${test_source_list}")
message("main_source_list ${main_source_list}")

list(REMOVE_ITEM test_source_list ${main_source_list})
list(REMOVE_ITEM source_list ${test_list})
message("test_source_list ${test_source_list}")
message("source_list ${source_list}")

include_directories(${PROJECT_NAME} PUBLIC src)

add_executable(${PROJECT_NAME} ${source_list})

Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG v3.1.0
)

FetchContent_MakeAvailable(Catch2)

add_executable(tests_02 ${test_source_list})
target_link_libraries(tests_02 PRIVATE Catch2::Catch2WithMain)
