# Simple program to monitor the voltage of the connected battery and display it to an oled screen.
from machine import ADC, I2C, Pin
from ssd1306 import SSD1306_I2C
import utime

i2c=I2C(0,sda=Pin(0), scl=Pin(1), freq=400000)
oled = SSD1306_I2C(128, 64, i2c)

batt_monitor = ADC(29) # GPIO 29

def display(text):
    oled.fill(0)
    oled.text(str(text), 0, 0)
    oled.show()

while True:
    batt_voltage = batt_monitor.read_u16() * (4.2 / 65535) # Multiply to get actual battery voltage after voltage dividor.
    print("Battery voltage: ", batt_voltage)
    display(batt_voltage)
    utime.sleep(0.2)
