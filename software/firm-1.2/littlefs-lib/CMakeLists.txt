add_library(littlefs-lib INTERFACE)
target_include_directories(littlefs-lib INTERFACE ${CMAKE_CURRENT_LIST_DIR})
target_link_libraries(littlefs-lib INTERFACE hardware_flash)
target_sources(littlefs-lib INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}/lfs.c
    ${CMAKE_CURRENT_LIST_DIR}/lfs.h
    ${CMAKE_CURRENT_LIST_DIR}/lfs_util.h
    ${CMAKE_CURRENT_LIST_DIR}/pico_hal.c
    ${CMAKE_CURRENT_LIST_DIR}/pico_hal.h)

