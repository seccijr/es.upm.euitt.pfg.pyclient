cmake_minimum_required(VERSION 2.8)
set(CMAKE_TOOLCHAIN_FILE cmake/ArduinoToolchain.cmake)
set(PROJECT_NAME PyClient)
set(ArduinoUnit_RECURSE true)
project(${PROJECT_NAME})

register_hardware_platform(${ARDUINO_SDK_PATH}/hardware/arduino/avr/)
print_board_list()
print_programmer_list()

file(GLOB pyclient_SRCS
    "*.cpp")

file(GLOB pyclient_HDRS
    "*.h")

generate_arduino_firmware(test
    SRCS ${pyclient_SRCS}
    HDRS ${pyclient_HDRS}
    BOARD uno
    SERIAL picocom @SERIAL_PORT@ -b 9600 -l
    PORT  /dev/ttyACM0)
