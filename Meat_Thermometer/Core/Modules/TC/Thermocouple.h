// TC.h


// Header File for TC conversions


#ifndef _TC_CONVERT_
#define _TC_CONVERT_

// Includes
#include <stdint.h>


// Public Variables
extern const uint16_t TC_Table[];


// Public function Prototype
int16_t ConvertTC_Voltage2TempInC(uint16_t _counts);




#endif