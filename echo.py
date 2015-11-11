#!/usr/bin/env python

import serial
import time

ser = serial.Serial('/dev/ttyACM0', 9600, timeout = 0)

while 1:
    try:
        ser.write('Hello world')
        time.sleep(1)
        print ser.readline()
    except ser.SerialTimeoutException:
        print('Data could not be read')
        time.sleep(1)
