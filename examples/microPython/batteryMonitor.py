# Simple program to monitor the voltage of the connected battery.
import machine
import utime

batt_monitor = machine.ADC(29) # GPIO 29

while True:
    batt_voltage = batt_monitor.read_u16() * (4.2 / 65535) # Multiply to get actual battery voltage after voltage dividor.
    print("Battery voltage: ", batt_voltage)
    utime.sleep(0.2)
