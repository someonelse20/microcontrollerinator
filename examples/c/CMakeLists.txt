cmake_minimum_required(VERSION 3.13)

# initialize the SDK based on PICO_SDK_PATH
# note: this must happen before project()
include(pico_sdk_import.cmake)

project(batteryMonitor C CXX ASM)

# initialize the Raspberry Pi Pico SDK
pico_sdk_init()

# rest of your project

add_executable(batteryMonitor
		batteryDrain.c
        )

# Add pico_stdlib library which aggregates commonly used features
target_link_libraries(batteryMonitor pico_stdlib hardware_adc)

pico_enable_stdio_usb(batteryMonitor 1)
pico_enable_stdio_uart(batteryMonitor 0)

# create map/bin/hex/uf2 file in addition to ELF.
pico_add_extra_outputs(batteryMonitor)

