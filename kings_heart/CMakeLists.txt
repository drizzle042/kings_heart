cmake_minimum_required(VERSION 3.22.1)

project(
    kings_heart
    VERSION 1.0.0.0
    DESCRIPTION "Backend application for King's Heart"
    LANGUAGES CXX
)

if("${PROJECT_SOURCE_DIR}" STREQUAL "${PROJECT_BINARY_DIR}")
   message(FATAL_ERROR "In-source builds are not allowed.")
endif()

include(CTest)

set(PROJECT_MAIN_TARGET kings_heart)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(BUILD_TESTING OFF)

add_library(${PROJECT_MAIN_TARGET} STATIC)

find_package(Drogon REQUIRED)
find_package(spdlog REQUIRED)
find_package(cryptopp REQUIRED)
find_package(cpp-jwt REQUIRED)
find_package(bsoncxx REQUIRED)
find_package(mongocxx REQUIRED)

target_link_libraries(
    ${PROJECT_MAIN_TARGET}
    PRIVATE
    Drogon::Drogon
    spdlog::spdlog
    cryptopp::cryptopp
    cpp-jwt::cpp-jwt
    mongo::bsoncxx_static
    mongo::mongocxx_static
)

if(BUILD_TESTING)
    find_package(GTest REQUIRED)
    
    add_executable(FileRegistryTest)
    target_link_libraries(
        FileRegistryTest 
        PRIVATE 
        GTest::gtest_main
    )
    add_test(NAME TestFileRegistry COMMAND FileRegistryTest)
endif()

add_subdirectory(admin_app)
# add_subdirectory(generic_app)
add_subdirectory(http1.1_apis)
add_subdirectory(interfaces)
add_subdirectory(lib)