![alt text](microcontrollerinator-3d.jpg)

# Microcontrollerinator
Simple custom devboard based on the RP2040 with an integraded 1 cell li-ion charger and Dr. Doofenshmirtz because why not.
This is my first complex pcb and to get my feet wet I mostly followed the example at https://blueprint.hackclub.com/starter-projects/devboard and added the BQ21040DBV battery charger. 

# How To Use
The board has the same pinout as the Raspberry Pi Pico exept ADC_VREF is GPIO23, 3V3_EN is GPIO24, and VSYS is GPIO25. GPIO29_ADC3 monitors the voltage of the battery multiplied by 1.3125 due to the resistor dividor. Pressing the switch will put the RP2040 into boot mode so it can be programed. The VBUS pin will output the current power supply voltage which will be 5v when plugged in but will be the direct battery voltage when unplugged. The battery pin headder has three pins, two for power and one for a thermistor to monitor temperature. The thermistor can be left hanging but there is a solder pad that enables a pull up resistor which is recomended in the charger datasheet.

# Schematic
![alt text](production/microcontrollerinator-schematic.jpg)
# PCB
![alt text](production/microcontrollerinator-pcb.jpg)

# Ordering
This bom file, the cpl position file, and the gerber zip files are in the production folder and formated to be orederd from https://jlcpcb.com/. The positions file needs to be edited a bit and there isn't an option to export the updated cpl file for JLCPCB so edit as show in the picture below. The USB header goes down a little, U2 pin 1 goes to the bottom left, U3 pin 1 goes to the top left, U4 pin 1 goes to the bottom left, and Q1 pin 1 goes to the top left.
| Id    | Designator                          | Footprint                                   | Quantity | Comment                     | Lcsc part |
| :---- | :---------------------------------- | :------------------------------------------ | :------- | :-------------------------- | :-------- |
| 1     | Y1                                  | Crystal_SMD_3225-4Pin_3.2x2.5mm             | 1        | 12MHz                       | C9002     |
| 2     | SW1                                 | SW_Push_SPST_NO_Alps_SKRK                   | 1        | SW_Push                     | C720477   |
| 3     | C16,C15                             | C_0402_1005Metric                           | 2        | 33pF                        | C1562     |
| 4     | C5,C3,C4,C8,C2,C11,C9,C12,C6,C7,C17 | C_0402_1005Metric                           | 11       | 0.1uF                       | C1525     |
| 5     | J4,J5                               | PinHeader_1x03_P2.54mm_Vertical             | 2        | Conn_01x03                  |           |
| 6     | R6,R11,R9,R5                        | R_0402_1005Metric                           | 4        | 1K                          | C11702    |
| 7     | R2,R1                               | R_0402_1005Metric                           | 2        | 5.1K                        | C25905    |
| 8     | U2                                  | SOT-23                                      | 1        | MCP1700x-330xxTT            | C39051    |
| 9     | C14,C13                             | C_0603_1608Metric                           | 2        | 10uF                        | C19702    |
| 10    | C10,C1,C19,C18                      | C_0402_1005Metric                           | 4        | 1uF                         | C52923    |
| 11    | J1                                  | USB_C_Receptacle_HRO_TYPE-C-31-M-12         | 1        | USB_C_Receptacle_USB2.0_14P | C165948   |
| 12    | U3                                  | Winbond_USON-8-1EP_3x2mm_P0.5mm_EP0.2x1.6mm | 1        | W25Q128JVS                  | C2843335  |
| 13    | D2                                  | LED_0603_1608Metric                         | 1        | LED                         | C2290     |
| 14    | U4                                  | SOT-23-6                                    | 1        | BQ21040DBV                  | C202311   |
| 15    | R8                                  | R_0402_1005Metric                           | 1        | 1.5K                        | C25867    |
| 16    | R12                                 | R_0402_1005Metric                           | 1        | 3.2K                        | C705066   |
| 17    | U1                                  | QFN-56-1EP_7x7mm_P0.4mm_EP3.2x3.2mm         | 1        | RP2040                      | C2040     |
| 18    | D1                                  | D_0402_1005Metric                           | 1        | D_Schottky                  | C28646371 |
| 19    | Q1                                  | SOT-23                                      | 1        | AO3401A                     | C15127    |
| 20    | R4,R3                               | R_0402_1005Metric                           | 2        | 27K                         | C11896    |
| 21    | R10,R7                              | R_0402_1005Metric                           | 2        | 10K                         | C25744    |
| 22    | J3,J2                               | PinHeader_1x20_P2.54mm_Vertical             | 2        | Conn_01x20                  |           |

![alt text](production/position-fix.jpg)
