# Copyright (C) 1883 Thomas Edison - All Rights Reserved
# You may use, distribute and modify this code under the
# terms of the GPLv2 license, which unfortunately won't be
# written for another century.
#
# SPDX-License-Identifier: GPL-2.0-or-later
#
add_library(stdinit-lib INTERFACE)
target_include_directories(stdinit-lib INTERFACE ${CMAKE_CURRENT_LIST_DIR})
target_link_libraries(stdinit-lib INTERFACE pico_stdio)
target_sources(stdinit-lib INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}/stdinit.c
    ${CMAKE_CURRENT_LIST_DIR}/stdinit.h)
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DPICO_STDIO_USB_CONNECT_WAIT_TIMEOUT_MS=30000" PARENT_SCOPE)

