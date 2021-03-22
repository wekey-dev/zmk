/*
 * Copyright (c) 2020 The ZMK Contributors
 *
 * SPDX-License-Identifier: MIT
 */

#define DT_DRV_COMPAT zmk_behavior_outputs

#include <device.h>
#include <devicetree.h>
#include <drivers/behavior.h>

#include <dt-bindings/zmk/outputs.h>

#include <zmk/behavior.h>
#include <zmk/endpoints.h>

#include <bluetooth/conn.h>
#include <zmk/ble.h>

#include <logging/log.h>
LOG_MODULE_DECLARE(zmk, CONFIG_ZMK_LOG_LEVEL);

#if DT_HAS_COMPAT_STATUS_OKAY(DT_DRV_COMPAT)

static int on_keymap_binding_pressed(struct zmk_behavior_binding *binding,
                                     struct zmk_behavior_binding_event event) {
    switch (binding->param1) {
    case OUT_TOG:
        return zmk_endpoints_toggle();
    case OUT_USB:
        return zmk_endpoints_select(ZMK_ENDPOINT_USB);
    case OUT_BLE:
        return zmk_endpoints_select(ZMK_ENDPOINT_BLE);
    case OUT_USB_ONLY:
        zmk_endpoints_select(ZMK_ENDPOINT_USB);
        return zmk_ble_prof_none();
    case OUT_BT_0:
        zmk_endpoints_select(ZMK_ENDPOINT_BLE);
        return zmk_ble_prof_switch(0);
    case OUT_BT_1:
        zmk_endpoints_select(ZMK_ENDPOINT_BLE);
        return zmk_ble_prof_switch(1);
    case OUT_BT_2:
        zmk_endpoints_select(ZMK_ENDPOINT_BLE);
        return zmk_ble_prof_switch(2);
    default:
        LOG_ERR("Unknown output command: %d", binding->param1);
    }

    return -ENOTSUP;
}

static int on_keymap_binding_released(struct zmk_behavior_binding *binding,
                                      struct zmk_behavior_binding_event event) {
    return ZMK_BEHAVIOR_OPAQUE;
}

static int behavior_out_init(const struct device *dev) { return 0; }

static const struct behavior_driver_api behavior_outputs_driver_api = {
    .binding_pressed = on_keymap_binding_pressed,
    .binding_released = on_keymap_binding_released,
};

DEVICE_AND_API_INIT(behavior_out, DT_INST_LABEL(0), behavior_out_init, NULL, NULL, APPLICATION,
                    CONFIG_KERNEL_INIT_PRIORITY_DEFAULT, &behavior_outputs_driver_api);

#endif /* DT_HAS_COMPAT_STATUS_OKAY(DT_DRV_COMPAT) */
