// ux_manager.c


#include "main.h"
#include "ux_manager.h"
#include <stdio.h>

// private defines


// Global Constants


// Modular Constants


// global variables
// Screens
ui_screen currentScreen;
ui_screen lastScreen;

// Display-wrapped values
// format seq (numeric): {<format string>, <error message>, <Xpos>, <Ypos>, <valid?>, <init value>}
DWfloat tempInC = {"%5.0f", " ----", 0, 0, false, 10000};
DWfloat tempInF = {"%4.0f", " ---", 0, 0, false, 10000};
DWfloat humidity = {"%5.1f", " ----", 0, 0, true, 40.1};
DWint16_t tempCJ_F = {"%5d", " !!!!", 0, 0, true, 0};
char menu[5][8] = {"Chicken", "Beef", "Lamb", "Salmon", "Veggie"};
int8_t index1 = 0;
int8_t index2 = 0;
char state[5][9] = {"Rare    ", "Med-Rare", "Medium  ", "Med-Well", "Well    "};
uint8_t finished = false;
char chic[5][5] = {"INV", "INV", "INV", "INV", "170"};
char beef[5][5] = {"125", "135", "145", "150", "160"};
char lamb[5][5] = {"140", "145", "165", "165", "170"};
char salm[5][5] = {"120", "125", "130", "135", "140"};
char vegg[5][5] = {"100", "115", "125", "135", "140"};


// format seq (string): {<format string>,  <error message>, <Xpos>, <Ypos>, <valid?>, "<init value>"


// modular variables


// module prototypes



// ***************
// Start Of Code
// ***************
// Screen switching utility that manages pre-, post-, and screen switch conditions
void SwitchScreens(ui_screen screen_no)
{
  lastScreen = currentScreen;

  
#pragma diag_suppress= Pa149
  // what must be done before current screen is switched out
  switch (lastScreen) {
  }
  
  
  // what must be done before screen is switched in
  switch (screen_no) {
  }
#pragma diag_warning= Pa149
  
  // Switch the screens
  switch (screen_no) {
  case MAIN:
    // clear the screen from the previos dispayed data
    SSD1306_Clear();
    // Put up the "persistant" info (like data labels)
    SSD1306_GotoXY (0, 0);
    SSD1306_Puts ("Welcome!", &Font_11x18, SSD1306_COLOR_WHITE);
    SSD1306_GotoXY (0, 20);
    SSD1306_Puts ("Temp: ", &Font_11x18, SSD1306_COLOR_WHITE);
    SSD1306_GotoXY(2, 44);
    SSD1306_Puts("Menu", &Font_7x10, SSD1306_COLOR_WHITE);
    SSD1306_DrawCircle(16, 58, 4, SSD1306_COLOR_WHITE);
    SSD1306_DrawCircle(48, 58, 4, SSD1306_COLOR_WHITE);
    SSD1306_DrawCircle(80, 58, 4, SSD1306_COLOR_WHITE);
    SSD1306_DrawCircle(112, 58, 4, SSD1306_COLOR_WHITE);
    // Set u X/Y coordinates for "live" data to be displayed on this screen
    tempInF.xPos = 55;
    tempInF.yPos = 20;
    // Send a screen update (note this does not update the live data)
    break;
  case MENU:
    SSD1306_Clear();
    SSD1306_GotoXY (0, 0);
    SSD1306_Puts ("Menu:", &Font_11x18, SSD1306_COLOR_WHITE);
    SSD1306_GotoXY (0, 20);
    SSD1306_Puts ("Food: ", &Font_11x18, SSD1306_COLOR_WHITE);
    SSD1306_GotoXY(2, 44);
    SSD1306_Puts("Back", &Font_7x10, SSD1306_COLOR_WHITE);
    SSD1306_DrawCircle(16, 58, 4, SSD1306_COLOR_WHITE);
    SSD1306_GotoXY(41, 44);
    SSD1306_Puts("Up", &Font_7x10, SSD1306_COLOR_WHITE);
    SSD1306_DrawCircle(48, 58, 4, SSD1306_COLOR_WHITE);
    SSD1306_GotoXY(66, 44);
    SSD1306_Puts("Down", &Font_7x10, SSD1306_COLOR_WHITE);
    SSD1306_DrawCircle(80, 58, 4, SSD1306_COLOR_WHITE);
    SSD1306_GotoXY(105, 44);
    SSD1306_Puts("OK", &Font_7x10, SSD1306_COLOR_WHITE);
    SSD1306_DrawCircle(112, 58, 4, SSD1306_COLOR_WHITE);
    break;
  case PROCESS:
    //finished = false;
    index2 = 0;
    SSD1306_Clear();
    SSD1306_GotoXY (0, 0);
    SSD1306_Puts ("Temperature:", &Font_11x18, SSD1306_COLOR_WHITE);
     SSD1306_GotoXY(2, 44);
    SSD1306_Puts("Back", &Font_7x10, SSD1306_COLOR_WHITE);
    SSD1306_DrawCircle(16, 58, 4, SSD1306_COLOR_WHITE);
    SSD1306_GotoXY(41, 44);
    SSD1306_Puts("Up", &Font_7x10, SSD1306_COLOR_WHITE);
    SSD1306_DrawCircle(48, 58, 4, SSD1306_COLOR_WHITE);
    SSD1306_GotoXY(66, 44);
    SSD1306_Puts("Down", &Font_7x10, SSD1306_COLOR_WHITE);
    SSD1306_DrawCircle(80, 58, 4, SSD1306_COLOR_WHITE);
    SSD1306_GotoXY(105, 44);
    SSD1306_Puts("OK", &Font_7x10, SSD1306_COLOR_WHITE);
    SSD1306_DrawCircle(112, 58, 4, SSD1306_COLOR_WHITE);
    
    break;
   case TEMP_CHECK: 
    SSD1306_Clear();
    SSD1306_GotoXY (0,0);
    SSD1306_Puts ("Done-Temp:", &Font_11x18, SSD1306_COLOR_WHITE);
    SSD1306_GotoXY (0, 20);
    SSD1306_Puts ("Temp:", &Font_11x18, SSD1306_COLOR_WHITE);
    SSD1306_GotoXY(0, 44);
    SSD1306_Puts("Set:", &Font_11x18, SSD1306_COLOR_WHITE);
    SSD1306_GotoXY(102, 44);
    SSD1306_Puts("Fin", &Font_7x10, SSD1306_COLOR_WHITE);
    SSD1306_DrawCircle(112, 58, 4, SSD1306_COLOR_WHITE);
    tempInF.xPos = 50;
    tempInF.yPos = 20;
    break;
  
  }
  
  SSD1306_UpdateScreen(); //display

  currentScreen = screen_no;
  
#pragma diag_suppress= Pa149
  // what must be done after screen is switched in
  switch (currentScreen) {
  }
#pragma diag_warning= Pa149
  
}

//// Keyboard Processor
//
//uint8_t ProcessKeyCode (uint16_t key_code)
//{
//  switch (key_code) {
//  case 0:
//    break;
//  case 1:
//    break;
//  case 2:
//    break;
//  case 3:
//    break;
//  }
//  
//  return true;
//}

// context sensitive keyboard processor
uint8_t ProcessKeyCodeInContext (uint16_t key_code)
{
  switch (currentScreen) {
  case  MAIN:
    switch (key_code) {
    case 0:
      SwitchScreens(MENU);
      break;
    case 1:
      break;
    case 2:
      break;
    case 3:
      break;
    }
    break;
  case  MENU:
    switch (key_code) {
    case 0:
      SwitchScreens(MAIN);
      break;
    case 1:
      index1--;
      if(index1 < 0) index1 = 4;
      break;
    case 2:
      index1++;
      if(index1 > 4) index1 = 0;
      break;
    case 3:
      SwitchScreens(PROCESS);
      index2 = index2 + 4;
      break;
    }
    break;
 
  case  PROCESS:
    switch (key_code) {
    case 0:
      SwitchScreens(MENU);
      break;
    case 1:
      if(index1 == 0) {
        index2 = 4;
      }
      else {
        index2--;
        if(index2 < 0) index2 = 4;
      }
      break;
    case 2:
      if(index1 == 0) {
        index2 = 4;
      }
      else {
      index2++;
      if(index2 > 4) index2 = 0;
      }      
      break;
    case 3:
      finished = true;
      SwitchScreens(TEMP_CHECK);
      break;
    }
    break;
  case  TEMP_CHECK:
    switch (key_code) {
    case 0:
      break;
    case 1:
      break;
    case 2:
      break;
    case 3:
      finished = false;
      SwitchScreens(MENU);
      break;
    }
    break;
    break;
  }
  return true;
}

void UpdateScreenValues(void)
{
  char displayString[25];
  
  switch (currentScreen) {
  case MAIN:
    SSD1306_GotoXY (tempInF.xPos, tempInF.yPos);
    if (tempInF.valid) {
      sprintf(displayString, tempInF.format, tempInF.data);
      SSD1306_Puts(displayString, &Font_11x18, SSD1306_COLOR_WHITE);
    }
    else 
      SSD1306_Puts(tempInF.invalidMsg, &Font_11x18, SSD1306_COLOR_WHITE);
    break;
  case MENU:
    SSD1306_GotoXY(50, 20);
    sprintf(displayString, "%7s", menu[index1]);
    SSD1306_Puts(displayString, &Font_11x18, SSD1306_COLOR_WHITE);
    break;
  case PROCESS:
    //index2 = temp2State(tempInC.data);
    SSD1306_GotoXY(0, 20);
    if(tempInC.valid) {
      SSD1306_Puts(state[index2], &Font_11x18, SSD1306_COLOR_WHITE);
    } 
    else { 
      SSD1306_Puts("Temp Error", &Font_11x18, SSD1306_COLOR_WHITE);
    }
    
    if (finished) {
      SSD1306_GotoXY(105, 44);
      SSD1306_Puts("OK", &Font_7x10, SSD1306_COLOR_WHITE);
    }
    break;
  case TEMP_CHECK:
    SSD1306_GotoXY (tempInF.xPos, tempInF.yPos);
    if (tempInF.valid) {
      sprintf(displayString, tempInF.format, tempInF.data);
      SSD1306_Puts(displayString, &Font_11x18, SSD1306_COLOR_WHITE);
     
    }
    else 
      SSD1306_Puts(tempInF.invalidMsg, &Font_11x18, SSD1306_COLOR_WHITE);
    SSD1306_GotoXY(60,44);
    switch (index1) {
    case 0:
      sprintf(displayString, "%3s", chic[index2]);
      SSD1306_Puts(displayString, &Font_11x18, SSD1306_COLOR_WHITE);
      break;
    case 1:
      sprintf(displayString, "%3s", beef[index2]);
      SSD1306_Puts(displayString, &Font_11x18, SSD1306_COLOR_WHITE);
      break;
    case 2:
      sprintf(displayString, "%3s", lamb[index2]);
      SSD1306_Puts(displayString, &Font_11x18, SSD1306_COLOR_WHITE);
      break;
    case 3:
      sprintf(displayString, "%3s", salm[index2]);
      SSD1306_Puts(displayString, &Font_11x18, SSD1306_COLOR_WHITE);
      break;
    case 4:
      sprintf(displayString, "%3s", vegg[index2]);
      SSD1306_Puts(displayString, &Font_11x18, SSD1306_COLOR_WHITE);
      break;
    }
    break;
  }
  SSD1306_UpdateScreen(); //display
}

/* int8_t temp2State(float temp)
{
  int8_t i;
  for (i = 4; i >= 0;i--){
    if(temp > tempture[index1][i]) return i > index2 ? i : index2;
  }
  return i > index2 ? i : index2;
}
*/

uint8_t GetKeycode(void)
{
  return HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13);
}