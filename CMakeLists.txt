# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(FAMILY rp2040)
set(BOARD pico_sdk)

# Initialise pico_sdk from installed location
# (note this can come from environment, CMake cache etc)

# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
    set(sdkVersion 2.2.0)
    set(toolchainVersion 14_2_Rel1)
    set(picotoolVersion 2.2.0)
    set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================
set(PICO_BOARD pico CACHE STRING "Board type")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(AuthDuck C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

set(PROJECT_SOURCE_DIR src)

# Add executable. Default name is the project name, version 0.1

include_directories(${PROJECT_SOURCE_DIR})

add_executable(AuthDuck
    ${PROJECT_SOURCE_DIR}/usb_descriptors.c
    ${PROJECT_SOURCE_DIR}/main.cpp
)

pico_enable_stdio_usb(AuthDuck 0)
pico_enable_stdio_uart(AuthDuck 1)

# pull in common dependencies
target_link_libraries(AuthDuck
    pico_stdlib
    tinyusb_common
    tinyusb_bsp
    tinyusb_device_base
)

# create map/bin/hex/uf2 file etc.
pico_add_extra_outputs(AuthDuck)