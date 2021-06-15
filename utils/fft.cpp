#include "fft.h"

void fft(const QVector<double> &input,
    QVector<std::complex<double>> &x_out,
    int N) {

    if (x_out.size() < N){
        x_out = QVector<std::complex<double>>(N);
    }

    // Make copy of array and apply window
    for (int i = 0; i < N; i++) {
        x_out[i] = std::complex<double>(input.at(i), 0);
        x_out[i] *= 1; // Window
    }

    // Start recursion
    fft_rec(x_out, N);
}

void fft_rec(QVector<std::complex<double>> &x, int N) {
    // Check if it is splitted enough
    if (N <= 1) {
        return;
    }

    // Split even and odd
    QVector<std::complex<double>> odd(N/2);
    QVector<std::complex<double>> even(N/2);
    for (int i = 0; i < N / 2; i++) {
        even[i] = x.at(i*2);
        odd[i] = x.at(i*2+1);
    }

    // Split on tasks
    fft_rec(even, N/2);
    fft_rec(odd, N/2);


    // Calculate DFT
    for (int k = 0; k < N / 2; k++) {
        std::complex<double> t = exp(std::complex<double>(0, -2 * M_PI * k / N)) * odd[k];
        x[k] = even[k] + t;
        x[N / 2 + k] = even[k] - t;
    }
}
