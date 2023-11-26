cmake_minimum_required(VERSION 3.5)

project(word_count LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(ENABLE_TESTS on)



find_package(Boost 1.82.0 REQUIRED COMPONENTS program_options )

if(ENABLE_TESTS)

    find_package(GTest)
    add_executable(test test/test.cpp word_counter.h word_counter.cpp )


    target_include_directories(test PRIVATE ${GTEST_INCLUDE_DIRS})

    target_link_libraries(test PRIVATE gtest gtest_main)

endif()




add_executable(${PROJECT_NAME}  main.cpp word_counter.h word_counter.cpp)
target_link_libraries(${PROJECT_NAME} PUBLIC Boost::program_options)




