cmake_minimum_required(VERSION 3.22.1)
project(
    kings_heart
    VERSION 1.0.0.0
    DESCRIPTION "Backend application for King's Heart"
    LANGUAGES CXX
)

include(CTest)

set(PROJECT_MAIN_TARGET kings_heart)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(BUILD_TESTING OFF)

add_library(${PROJECT_MAIN_TARGET} STATIC)

find_package(Drogon REQUIRED)
find_package(spdlog REQUIRED)
find_package(cpp-jwt REQUIRED)
find_package(mongocxx REQUIRED)
find_package(bsoncxx REQUIRED)

target_link_libraries(
    ${PROJECT_MAIN_TARGET}
    PRIVATE
    Drogon::Drogon
    spdlog::spdlog
    cpp-jwt::cpp-jwt
    mongo::mongocxx_static
    mongo::bsoncxx_static
)

if(BUILD_TESTING)
    find_package(GTest REQUIRED)
    find_package(jsoncpp REQUIRED)
    
    add_executable(PayloadToJsonSerializerTest)
    target_link_libraries(
        PayloadToJsonSerializerTest 
        PRIVATE 
        GTest::gtest_main
        jsoncpp_lib
    )
    add_test(NAME TestPayloadToJsonSerializer COMMAND PayloadToJsonSerializerTest)
    
    add_executable(FileRegistryTest)
    target_link_libraries(
        FileRegistryTest 
        PRIVATE 
        GTest::gtest_main
    )
    add_test(NAME TestFileRegistry COMMAND FileRegistryTest)
endif()

add_subdirectory(interfaces)
add_subdirectory(lib)
add_subdirectory(admin_app)