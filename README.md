# Nayuki FFT in C

This is code from:

https://www.nayuki.io/page/free-small-fft-in-multiple-languages

From that page:

C (C99 and above) (pairs of reals)

    Download: fft.c, fft.h, fft-test.c

        Forward FFT (wrapper) (in-place): bool Fft_transform(double real[], double imag[], size_t n)
        Inverse FFT (wrapper) (in-place): bool Fft_inverseTransform(double real[], double imag[], size_t n)
        Forward FFT (radix-2) (in-place): bool Fft_transformRadix2(double real[], double imag[], size_t n)
        Forward FFT (Bluestein) (in-place): bool Fft_transformBluestein(double real[], double imag[], size_t n)
        Circular convolution (real): bool Fft_convolveReal(const double x[], const double y[], double out[], size_t n)
        Circular convolution (complex): bool Fft_convolveComplex(const double xreal[], const double ximag[], const double yreal[], const double yimag[], double outreal[], double outimag[], size_t n)

    When calling any of the above functions, all the argument arrays must have the same length. Each function returns true to indicate success or false to indicate failure.


