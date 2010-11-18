/*
 *	This file is part of the OpenPCR control software.
 *
 *  OpenPCR control software is free software: you can redistribute it and/or
 *  modify it under the terms of the GNU General Public License as published
 *  by the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  OpenPCR control software is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef _PCR_INCLUDES_H_
#define _PCR_INCLUDES_H_

#include "WProgram.h"

//fixes for incomplete C++ implementation, defined in util.cpp
void* operator new(size_t size);
void operator delete(void * ptr);
void sprintFloat(char* str, float val, int decimalDigits);
extern "C" void __cxa_pure_virtual(void);

//defines
#define STEP_NAME_LENGTH 16
#define MAX_CYCLE_ITEMS 16

enum PcrStatus {
  ESuccess = 0,
  ETooManySteps = 32,
  ENoProgram,
  ENoPower
};

#define SUCCEEDED(status) (status == ESuccess)

typedef struct {
  double dState; // Last position input
  double iState; // Integrator state
  double iMax, iMin; 

  // Maximum and minimum allowable integrator state
  double iGain, // integral gain
    pGain, // proportional gain
    dGain; // derivative gain
} SPid;

unsigned short htons(unsigned short val);

double UpdatePID(SPid * pid, double error, double position);

#endif

