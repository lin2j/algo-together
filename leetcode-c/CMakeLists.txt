cmake_minimum_required(VERSION 3.22)
project("leetcode-c")

# the location of your cUnit header file
include_directories("/opt/homebrew/include/")
link_directories("/opt/homebrew/Cellar/cunit/2.1-3/lib")

set(SOURCE_FILES
        ds/priority_queue/priority_queue.h
        ds/priority_queue/priority_queue.c
        ds/priority_queue/priority_queue_test.c
        )
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} libcunit.a)
