project(kings_heart LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(lib)
add_subdirectory(admin_app)

target_include_directories(
    ${PROJECT_NAME} 
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/interfaces
    ${CMAKE_CURRENT_SOURCE_DIR}/lib
)