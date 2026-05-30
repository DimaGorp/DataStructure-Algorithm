add_executable(list ${CMAKE_CURRENT_SOURCE_DIR}/list/list.cpp)

target_link_libraries(list PRIVATE linked_list)