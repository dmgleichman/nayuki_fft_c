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

double hamming[RADIX];

double g_amplitude;
double g_freq;
double g_phase;

void make_cos_wave(double amplitude, double freq, double phase)
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



// Hamming Window w(n)Hamming = 0.54 – 0.46cos(2pn/N)
void make_hamming_window(void)
{
	int i;
	for (i=0; i<RADIX; i++)
	{
		hamming[i] = 0.54 - (0.46 * cos(2 * PI * i / RADIX));
	}
}

void apply_hamming_window(void)
{
	int i;
	for (i=0; i<RADIX; i++)
	{
		real[i] = real[i] * hamming[i];
	}
}

void doug_test(void)
{
	printf("Running doug_test.c\n");

	g_freq = 10.5;

	make_cos_wave(1, (g_freq/128.0), (0.0/128.0));

	make_hamming_window();
	apply_hamming_window();
	Fft_transformRadix2(real, imag, RADIX);

	calcualte_magnitude_and_phase();

	for(;;)
	{
		;
	}

}
