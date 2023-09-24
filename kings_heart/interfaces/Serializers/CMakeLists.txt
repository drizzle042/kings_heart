target_include_directories(
    ${PROJECT_MAIN_TARGET} 
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

if(BUILD_TESTING)
    target_include_directories(
        PayloadToJsonSerializerTest
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
    )
endif()