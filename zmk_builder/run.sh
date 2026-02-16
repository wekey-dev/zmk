#!/bin/bash

docker compose run --rm wekey-builder

# BUILD Bootloader
# make BOARD=we6k_v1_5 all

# BUILD ZMK
# west build -p -b we6k_v15/nrf52840/zmk
# west build -p -b we6k_v15/nrf52840/zmk -S studio-rpc-usb-uart -- -DCONFIG_ZMK_STUDIO=y