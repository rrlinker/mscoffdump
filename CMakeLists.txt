cmake_minimum_required(VERSION 3.7)

project(mscoffdump)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SOURCE_FILES
    "*.cpp"
)

set(LINK_LIBRARIES stdc++fs)

add_library(stdc++fs UNKNOWN IMPORTED)
set_property(TARGET stdc++fs PROPERTY IMPORTED_LOCATION "/usr/lib/libstdc++fs.a")

include_directories("${PROJECT_SOURCE_DIR}/vendor/wine")
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} ${LINK_LIBRARIES})

