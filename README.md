# Meat Thermometer
## Arif Amzad

## Required Hardware
* STMicroelectronics Nucleo-G071RB
* OLED Display - 64x128 monochrome with blue and Yellow filter
* Custom PCB
* Custom Thermocouple probe

## Required Software
* STM32CubeMX
* IAR Embedded Workshop for Arm

## Custom PCB Schematic
![This is an image]()
![This is an image]()
![This is an image]()
![This is an image]()

## Meat Thermometer Setup
![This is an image]()

## Demonstration
The Meat Thermometer works by having the user first pick the type of meat they are cooking; Chicken, Beef, Lamb, Salmon, or Veggies. The user is then prometed to select the cooking temperature they desire; rare, medium-rare, medium, medium-well, or well-done. However, chicken does not allow the user to select any temperature but well-done due to risk of diesease. After selecting the cooking tmperature, the screen displays the target temperature and the actual temperature. A buzzer, RGB LED, and a red LED will be activated once the target cooking temperature is reached. 
Note: For the demonstation below, the temperature in the array was set to 10 for well-done beef.
