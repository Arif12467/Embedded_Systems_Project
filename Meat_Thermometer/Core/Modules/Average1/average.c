/***********************************************************************************************************************
* File Name    : Average.c
* Version      : 
* Device(s)    : All
* Tool-Chain   : IAR Systems [All]
* Description  : This file implements Averaging routines using a running average. Your choices of avarage size
*                is 4, 8, or 16 samples.
* Creation Date: 4/8/2019
* Current Rev  : rev2.1 9/17/2021
***********************************************************************************************************************/

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
//#include <stdio.h>
//#include <string.h>
#include "Average.h"


/***********************************************************************************************************************
Pragma directive
***********************************************************************************************************************/


/***********************************************************************************************************************
Global/module variables and functions
***********************************************************************************************************************/



/***********************************************************************************************************************
module function prototypes
***********************************************************************************************************************/




/***********************************************************************************************************************
code start
***********************************************************************************************************************/
//averaging routine for floats with 4 history elements
float FloatRunAverage4(float sample, float_4_average * ave_slot)
{
  ave_slot->total -= ave_slot->raw_values[ave_slot->index];
  ave_slot->total += sample;
  ave_slot->raw_values[ave_slot->index] = sample;
  
  ave_slot->index++;
  if (ave_slot->index >= AVERAGE_LENGTH_4) {
    ave_slot->index = 0;
    ave_slot->filled = true;
  }
  
  if (ave_slot->filled == true) {
    ave_slot->ave = ave_slot->total / AVERAGE_LENGTH_4;
  }
  else {
    ave_slot->ave = ave_slot->total / (ave_slot->index);
  }
  
  return ave_slot->ave;
}


//averaging routine for floats with 8 history elements
float FloatRunAverage8(float sample, float_8_average * ave_slot)
{
  ave_slot->total -= ave_slot->raw_values[ave_slot->index];
  ave_slot->total += sample;
  ave_slot->raw_values[ave_slot->index] = sample;
  
  ave_slot->index++;
  if (ave_slot->index >= AVERAGE_LENGTH_8) {
    ave_slot->index = 0;
    ave_slot->filled = true;
  }
  
  if (ave_slot->filled == true) {
    ave_slot->ave = ave_slot->total / AVERAGE_LENGTH_8;
  }
  else {
    ave_slot->ave = ave_slot->total / (ave_slot->index);
  }
  
  return ave_slot->ave;
}


//averaging routine for floats with 16 history elements
float FloatRunAverage16(float sample, float_16_average * ave_slot)
{
  ave_slot->total -= ave_slot->raw_values[ave_slot->index];
  ave_slot->total += sample;
  ave_slot->raw_values[ave_slot->index] = sample;
  
  ave_slot->index++;
  if (ave_slot->index >= AVERAGE_LENGTH_16) {
    ave_slot->index = 0;
    ave_slot->filled = true;
  }
  
  if (ave_slot->filled == true) {
    ave_slot->ave = ave_slot->total / AVERAGE_LENGTH_16;
  }
  else {
    ave_slot->ave = ave_slot->total / (ave_slot->index);
  }
  
  return ave_slot->ave;
}


//averaging routine for ints with 4 history elements
uint16_t Int16RunAverage4(uint16_t sample, int16_4_average * ave_slot)
{
  ave_slot->total -= ave_slot->raw_values[ave_slot->index];
  ave_slot->total += sample;
  ave_slot->raw_values[ave_slot->index] = sample;
  
  ave_slot->index++;
  if (ave_slot->index >= AVERAGE_LENGTH_4) {
    ave_slot->index = 0;
    ave_slot->filled = true;
  }
  
  if (ave_slot->filled == true) {
    ave_slot->ave = ave_slot->total / AVERAGE_LENGTH_4;
  }
  else {
    ave_slot->ave = ave_slot->total / (ave_slot->index);
  }
  
  return ave_slot->ave;
}


//averaging routine for ints with 8 history elements
uint16_t Int16RunAverage8(uint16_t sample, int16_8_average * ave_slot)
{
  ave_slot->total -= ave_slot->raw_values[ave_slot->index];
  ave_slot->total += sample;
  ave_slot->raw_values[ave_slot->index] = sample;
  
  ave_slot->index++;
  if (ave_slot->index >= AVERAGE_LENGTH_8) {
    ave_slot->index = 0;
    ave_slot->filled = true;
  }
  
  if (ave_slot->filled == true) {
    ave_slot->ave = ave_slot->total / AVERAGE_LENGTH_8;
  }
  else {
    ave_slot->ave = ave_slot->total / (ave_slot->index);
  }
  
  return ave_slot->ave;
}


//averaging routine for ints with 16 history elements
uint16_t Int16RunAverage16(uint16_t sample, int16_16_average * ave_slot)
{
  ave_slot->total -= ave_slot->raw_values[ave_slot->index];
  ave_slot->total += sample;
  ave_slot->raw_values[ave_slot->index] = sample;
  
  ave_slot->index++;
  if (ave_slot->index >= AVERAGE_LENGTH_16) {
    ave_slot->index = 0;
  }
  
  if (ave_slot->filled == true) {
    ave_slot->ave = ave_slot->total / AVERAGE_LENGTH_16;
  }
  else {
    int i;
    for (i = 1; i<AVERAGE_LENGTH_16;i++) ave_slot->raw_values[i] = sample;
    ave_slot->total = sample * AVERAGE_LENGTH_16;
    ave_slot->ave = sample;
    ave_slot->filled = true;
  }
  
  return ave_slot->ave;
}


void InitInt16RunAverage4(int16_4_average * ave_slot)
{
  int i;
    
  for (i=0; i< AVERAGE_LENGTH_4; i++) ave_slot->raw_values[i] = 0;
  ave_slot->filled = false;
  ave_slot->index = 0;
  ave_slot->total = 0;
  ave_slot->ave = 0;
}


void InitInt16RunAverage8(int16_8_average * ave_slot)
{
  int i;
    
  for (i=0; i< AVERAGE_LENGTH_8; i++) ave_slot->raw_values[i] = 0;
  ave_slot->filled = false;
  ave_slot->index = 0;
  ave_slot->total = 0;
  ave_slot->ave = 0;
}


void InitInt16RunAverage16(int16_16_average * ave_slot)
{
  int i;
    
  for (i=0; i< AVERAGE_LENGTH_16; i++) ave_slot->raw_values[i] = 0;
  ave_slot->filled = false;
  ave_slot->index = 0;
  ave_slot->total = 0;
  ave_slot->ave = 0;
}

