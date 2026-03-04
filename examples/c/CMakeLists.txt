cmake_minimum_requred(VERSION 3.13)
add_executable(batteryMonitor
        batteryMonitor.c
        )

include(pico_sdk_import.cmake)
pico_sdk_init()

target_link_libraries(batteryMonitor pico_stdlib hardware_adc)

# create map/bin/hex file etc.
pico_add_extra_outputs(batteryMonitor)

# add url via pico_set_program_url
example_auto_set_url(batteryMonitor)
