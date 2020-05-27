cmake_minimum_required(VERSION 2.8)

project(restserver)

set(MY_ROOT_DIR "/home/manfredbeutel/projects")
MESSAGE("Root dir set to: ${MY_ROOT_DIR}")

include_directories(${MY_ROOT_DIR}/restbed/distribution/include)
include_directories(${MY_ROOT_DIR}/ndi/NDI_SDK/include)

link_directories(/home/manfredbeutel/projects/ndi/NDI_SDK/lib/x86_64-linux-gnu/)

find_package(Threads REQUIRED)

add_executable(result main.cpp)
target_link_libraries(result libndi.so ${MY_ROOT_DIR}/restbed/build/librestbed.a Threads::Threads)