target_include_directories(
    ${PROJECT_MAIN_TARGET} 
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)
target_sources(
    ${PROJECT_MAIN_TARGET} 
    PRIVATE
    Bagit.cpp
)

if(BUILD_TESTING)
    add_executable(BagitTest)
    target_link_libraries(BagitTest PRIVATE GTest::gtest_main)
    add_test(NAME TestBagit COMMAND BagitTest)
    
    target_include_directories(
        BagitTest
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
    )
    target_sources(
        BagitTest
        PRIVATE
        Bagit.cpp
        Bagit.test.cpp
    )

    target_include_directories(
        PayloadToJsonSerializerTest
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
    )
    target_sources(
        PayloadToJsonSerializerTest
        PRIVATE
        Bagit.cpp
    )
endif()