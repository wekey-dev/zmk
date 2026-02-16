FROM ubuntu:noble

ENV DEBIAN_FRONTEND=noninteractive

# ZMK / Zephyr dependencies (+ protoc for ZMK Studio RPC / nanopb)
RUN apt-get update && apt-get install -y --no-install-recommends \
    git cmake ninja-build gperf ccache dfu-util device-tree-compiler \
    wget python3-dev python3-pip python3-setuptools python3-venv \
    xz-utils file make gcc gcc-multilib g++-multilib libsdl2-dev libmagic1 \
    python3 python-is-python3 \
    protobuf-compiler \
    && rm -rf /var/lib/apt/lists/*

# ARM GNU Toolchain (full, with newlib) for nRF52_Bootloader
ARG ARM_GCC_VERSION=15.2.Rel1
ARG ARM_GCC_TAR=arm-gnu-toolchain-15.2.Rel1-x86_64-arm-none-eabi.tar.xz
RUN apt-get update && apt-get install -y --no-install-recommends ca-certificates wget xz-utils \
    && wget -q "https://developer.arm.com/-/media/Files/downloads/gnu/${ARM_GCC_VERSION}/binrel/${ARM_GCC_TAR}" -O /tmp/arm-gcc.tar.xz \
    && tar -xJf /tmp/arm-gcc.tar.xz -C /opt && rm /tmp/arm-gcc.tar.xz \
    && ln -s /opt/arm-gnu-toolchain-*-x86_64-arm-none-eabi /opt/arm-none-eabi-gcc \
    && rm -rf /var/lib/apt/lists/*
ENV PATH="/opt/arm-none-eabi-gcc/bin:${PATH}"

# Python tools: west (ZMK), intelhex (nRF52_Bootloader)
RUN pip3 install --no-cache-dir --break-system-packages west intelhex pyelftools protobuf grpcio-tools

# Zephyr/ZMK: use ARM GCC instead of Zephyr SDK
ENV ZEPHYR_TOOLCHAIN_VARIANT=gnuarmemb
ENV GNUARMEMB_TOOLCHAIN_PATH=/opt/arm-none-eabi-gcc

WORKDIR /workspace

CMD ["/bin/bash"]
