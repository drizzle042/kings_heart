target_include_directories(
    ${PROJECT_MAIN_TARGET} 
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
target_sources(
    ${PROJECT_MAIN_TARGET} 
    PRIVATE
    App.cpp
)