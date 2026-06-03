add_executable(listEx ${CMAKE_CURRENT_SOURCE_DIR}/list/listEx.cpp)
add_executable(arrayEx ${CMAKE_CURRENT_SOURCE_DIR}/array/arrayEx.cpp)
target_link_libraries(listEx PRIVATE linked_list)
target_link_libraries(arrayEx PUBLIC array)