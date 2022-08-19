/***********************************************************************************************************************
* File Name    : Average.h
* Version      : 
* Device(s)    : All
* Tool-Chain   : IAR Systems [All]
* Description  : This file implements Averaging routines.
* Creation Date: 
***********************************************************************************************************************/
#ifndef AVERAGE_H
#define AVERAGE_H


#include <stdint.h>
#include <string.h>
#include "main.h"

/***********************************************************************************************************************
Macro definitions 
***********************************************************************************************************************/
#define AVERAGE_LENGTH_4 4
#define AVERAGE_LENGTH_8 8
#define AVERAGE_LENGTH_16 16

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/
typedef struct int16_4_running_ave {
  uint16_t raw_values[AVERAGE_LENGTH_4];
  unsigned int index;
  unsigned char filled;
  uint32_t total;
  uint16_t ave;
} int16_4_average;

typedef struct int16_8_running_ave {
  uint16_t raw_values[AVERAGE_LENGTH_8];
  unsigned int index;
  unsigned char filled;
  uint32_t total;
  uint16_t ave;
} int16_8_average;

typedef struct int16_16_running_ave {
  uint16_t raw_values[AVERAGE_LENGTH_16];
  unsigned int index;
  unsigned char filled;
  uint32_t total;
  uint16_t ave;
} int16_16_average;

typedef struct float_4_running_ave {
  float raw_values[AVERAGE_LENGTH_4];
  unsigned int index;
  unsigned char filled;
  float total;
  float ave;
} float_4_average;

typedef struct float_8_running_ave {
  float raw_values[AVERAGE_LENGTH_8];
  unsigned int index;
  unsigned char filled;
  float total;
  float ave;
} float_8_average;

typedef struct float_16_running_ave {
  float raw_values[AVERAGE_LENGTH_16];
  unsigned int index;
  unsigned char filled;
  float total;
  float ave;
} float_16_average;


/***********************************************************************************************************************
Global functions
***********************************************************************************************************************/
uint16_t Int16RunAverage4(uint16_t sample, int16_4_average * ave_slot);
uint16_t Int16RunAverage8(uint16_t sample, int16_8_average * ave_slot);
uint16_t Int16RunAverage16(uint16_t sample, int16_16_average * ave_slot);


void InitInt16RunAverage4(int16_4_average * ave_slot);
void InitInt16RunAverage8(int16_8_average * ave_slot);
void InitInt16RunAverage16(int16_16_average * ave_slot);


/***********************************************************************************************************************
Global variables
***********************************************************************************************************************/



#endif