/*
 * Copyright (c) 2020 The ZMK Contributors
 *
 * SPDX-License-Identifier: MIT
 */

#include <kernel.h>
#include <device.h>
#include <init.h>
#include <drivers/gpio.h>
#include <sys/sys_io.h>
#include <devicetree.h>

static int pinmux_wekey_init(const struct device *port) {
    ARG_UNUSED(port);
#if CONFIG_BOARD_WE65I_3_0
    #if CONFIG_BOARD_CHARGER_CTRL
        const struct device *p0 = device_get_binding("GPIO_0");
        gpio_pin_configure(p0, 13, GPIO_OUTPUT);
        gpio_pin_set(p0, 13, 0);
    #else
        gpio_pin_configure(p0, 13, GPIO_INPUT);
    #endif
#elif CONFIG_BOARD_WE65I_2_2
    #if CONFIG_BOARD_CHARGER_CTRL
        const struct device *p0 = device_get_binding("GPIO_0");
        gpio_pin_configure(p0, 10, GPIO_OUTPUT);
        gpio_pin_set(p0, 10, 0);
    #else
        gpio_pin_configure(p0, 10, GPIO_INPUT);
    #endif
#elif CONFIG_BOARD_WE65_2_0
    #if CONFIG_BOARD_CHARGER_CTRL
        const struct device *p0 = device_get_binding("GPIO_0");
        gpio_pin_configure(p0, 4, GPIO_OUTPUT);
        gpio_pin_set(p0, 4, 0);
    #else
        gpio_pin_configure(p0, 4, GPIO_INPUT);
    #endif
#elif CONFIG_BOARD_WE65_2_3
    #if CONFIG_BOARD_CHARGER_CTRL
        const struct device *p0 = device_get_binding("GPIO_0");
        gpio_pin_configure(p0, 13, GPIO_OUTPUT);
        gpio_pin_set(p0, 13, 0);
    #else
        gpio_pin_configure(p0, 13, GPIO_INPUT);
    #endif
#elif CONFIG_BOARD_WE60_2_0
    #if CONFIG_BOARD_CHARGER_CTRL
        const struct device *p0 = device_get_binding("GPIO_0");
        gpio_pin_configure(p0, 4, GPIO_OUTPUT);
        gpio_pin_set(p0, 4, 0);
    #else
        gpio_pin_configure(p0, 4, GPIO_INPUT);
    #endif
#endif

    return 0;
}

SYS_INIT(pinmux_wekey_init, APPLICATION, CONFIG_APPLICATION_INIT_PRIORITY);
