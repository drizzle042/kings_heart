target_include_directories(
    ${PROJECT_MAIN_TARGET} 
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)
target_sources(
    ${PROJECT_MAIN_TARGET} 
    PRIVATE
    File.cpp
)

if(BUILD_TESTING)
    add_executable(FileTest)
    target_link_libraries(FileTest PRIVATE GTest::gtest_main)
    add_test(NAME TestFile COMMAND FileTest)
    
    target_include_directories(
        FileTest
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
    )
    target_sources(
        FileTest
        PRIVATE
        File.cpp
        File.test.cpp
    )

    target_include_directories(
        FileRegistryTest
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
    )
    target_sources(
        FileRegistryTest
        PRIVATE
        File.cpp
    )
endif()