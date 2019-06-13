cmake_minimum_required(VERSION 3.7)

project(
    mscoffdump
    VERSION 1.0
    DESCRIPTION "Prints contents of MS COFF file into readable format"
    LANGUAGES CXX
)

file(GLOB SOURCE_FILES
    "*.cpp"
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

set_target_properties(
    ${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE stdc++fs
)

target_include_directories(
    ${PROJECT_NAME}
    PRIVATE "${PROJECT_SOURCE_DIR}/vendor/wine"
)
