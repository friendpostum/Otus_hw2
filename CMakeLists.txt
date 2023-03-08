cmake_minimum_required(VERSION 3.2)
project(ip_filter)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG        release-1.11.0
)
FetchContent_MakeAvailable(googletest)

add_subdirectory(modules)
include_directories(modules)

add_executable(${PROJECT_NAME} main.cpp)
add_executable(test_ip_filter test_ip_filter.cpp)

target_include_directories(${PROJECT_NAME}
        PRIVATE "${CMAKE_BINARY_DIR}"
        )

target_link_libraries(${PROJECT_NAME} filter_lib)

target_link_libraries(test_ip_filter
        gtest
        gtest_main
        filter_lib
        )

if (MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE
            /W4
            )
else ()
    target_compile_options(${PROJECT_NAME} PRIVATE
            -Wall -Wextra -pedantic -Werror
            )
endif()

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_CONTACT example@example.com)
include(CPack)

enable_testing()
add_test(test_ip_filter test_ip_filter)