# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Initialise pico_sdk from installed location
# (note this can come from environment, CMake cache etc)

# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.0.0)
set(toolchainVersion 13_2_Rel1)
set(picotoolVersion 2.0.0)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================
set(PICO_BOARD pico CACHE STRING "Board type")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(AccelerometerTest C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Add executable. Default name is the project name, version 0.1

add_executable(AccelerometerTest AccelerometerTest.cpp accel.h)

pico_set_program_name(AccelerometerTest "AccelerometerTest")
pico_set_program_version(AccelerometerTest "0.1")

# Modify the below lines to enable/disable output over UART/USB
pico_enable_stdio_uart(AccelerometerTest 0)
pico_enable_stdio_usb(AccelerometerTest 1)

add_subdirectory(lib/BMP5)
add_subdirectory(lib/commonBMP5)
add_subdirectory(lib/BMI08X)
add_subdirectory(lib/commonBMI08X)
add_subdirectory(lib/i2cLib)
add_subdirectory(lib/BMM350)
add_subdirectory(lib/commonBMM350)

# Add the standard library to the build
target_link_libraries(AccelerometerTest 
    pico_stdlib
    BMI08X
    COMMONBMI08X
    I2CLIB
)

# Add the standard include files to the build
target_include_directories(AccelerometerTest PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}
)

pico_add_extra_outputs(AccelerometerTest)

