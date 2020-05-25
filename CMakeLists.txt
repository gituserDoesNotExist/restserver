cmake_minimum_required(VERSION 2.8)

project(restserver)

include_directories(/home/manfredbeutel/projects/restbed/distribution/include)

find_package(Threads REQUIRED)


MESSAGE("path ${CMAKE_ROOT}")
MESSAGE("include is ${INCLUDE}")

add_executable(result main.cpp)
target_link_libraries(result /home/manfredbeutel/projects/restbed/build/librestbed.a Threads::Threads)