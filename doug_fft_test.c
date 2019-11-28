/*
 * doug_fft_test.c
 *
 *  Created on: Nov 27, 2019
 *      Author: doug
 */

#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "fft.h"

#include "doug_fft_test.h"

//bool Fft_transformRadix2(double real[], double imag[], size_t n);



double orig[RADIX];
double real[RADIX];
double imag[RADIX];

double magnitudeValue[RADIX];
double phaseValue[RADIX];

double g_amplitude;
double g_freq;
double g_phase;

void make_sin_wave(double amplitude, double freq, double phase)
{
	int i;
	for (i=0; i<RADIX; i++)
	{
		real[i] =orig[i] = amplitude * cos((2 * PI * freq * i) + (2 * PI * phase));
		imag[i] = 0;
	}
}


void calcualte_magnitude_and_phase(void)
{
	int i;
	for (i=0; i<RADIX; i++)
	{
		magnitudeValue[i] = sqrt(real[i]*real[i] + imag[i]*imag[i]);
		//phaseValue[i] = (180.0/PI) * atan2(real[i], imag[i]);
		phaseValue[i] = (180.0/PI) * atan2(imag[i], real[i]);
	}
}


void doug_test(void)
{
	printf("Running doug_test.c\n");

	make_sin_wave(1000, (16.0/128.0), (32.0/128.0));

	Fft_transformRadix2(real, imag, RADIX);

	calcualte_magnitude_and_phase();

	for(;;)
	{
		;
	}

}
