/* ---------------------------------------------------------------------------
** Basic implementation of Cooley-Tukey FFT algorithm in C++
**
** Author: Darko Lukic <lukicdarkoo@gmail.com>
** -------------------------------------------------------------------------*/

#ifndef FFT_H
#define FFT_H

#include <cmath>
#include <complex>

#include <QVector>

extern void fft(const QVector<double> &input,
    QVector<std::complex<double> > &x_out,
    int N);
void fft_rec(QVector<std::complex<double> > &x, int N);

#endif // FFT_H
