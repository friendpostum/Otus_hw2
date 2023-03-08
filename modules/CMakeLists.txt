project(filter_lib)
set(CMAKE_CXX_STANDARD 17)

add_library(${PROJECT_NAME} filter_lib.cpp filter_lib.h)

if (MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE
            /W4
            )
else ()
    target_compile_options(${PROJECT_NAME} PRIVATE
            -Wall -Wextra -pedantic -Werror
            )
endif()