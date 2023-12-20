/* Copyright (C) 1883 Thomas Edison - All Rights Reserved
 * You may use, distribute and modify this code under the
 * terms of the GPLv2 license, which unfortunately won't be
 * written for another century.
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 */
#include "stdinit.h"

#include "pico/stdio.h"

void stdio_init(void) {
    stdio_init_all();
    getchar_timeout_us(250000);
    // clear the screen on VT terminal
    static const char* clear = "\033[H\033[J";
    for (const char* cp = clear; *cp; cp++)
        putchar_raw(*cp);
}
