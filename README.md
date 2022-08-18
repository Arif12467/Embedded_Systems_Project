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
![This is an image](https://github.com/Arif12467/Embedded_Workshop_Project/blob/197d9d13b342226579b97ea98ab01ef3f55910cf/Circuit1.png)
![This is an image](https://github.com/Arif12467/Embedded_Workshop_Project/blob/197d9d13b342226579b97ea98ab01ef3f55910cf/Circuit2.png)
![This is an image](https://github.com/Arif12467/Embedded_Workshop_Project/blob/197d9d13b342226579b97ea98ab01ef3f55910cf/Circuit3.png)
![This is an image](https://github.com/Arif12467/Embedded_Workshop_Project/blob/197d9d13b342226579b97ea98ab01ef3f55910cf/Circuit4.png)

## Meat Thermometer Setup
![This is an image](https://github.com/Arif12467/Embedded_Workshop_Project/blob/a18527aabe906c07e97158c0e2838a4d401ca2ce/Meat_Thermometer_Setup.png)

## Demonstration
The meat thermometer works by having the user first pick the type of meat they are cooking; chicken, beef, lamb, salmon, or veggies. Then, the user is prompted to select the cooking temperature they desire; rare, medium-rare, medium, medium-well, or well-done. However, if chicken is selected, the meat thermometer does not allow the user to select any temperature but well-done. This restriction is due to the risk of disease. After selecting the cooking temperature, the screen displays the target and actual temperatures. A buzzer, RGB LED, and a red LED will be activated once the target cooking temperature is reached. The user can then reset the device by pressing the finish button.

Note: For the demonstration below, the temperature in the array was set to 10°F for well-done beef.

https://user-images.githubusercontent.com/78330724/185505303-d3eb8ad6-461b-47bb-be78-805549063029.mp4
