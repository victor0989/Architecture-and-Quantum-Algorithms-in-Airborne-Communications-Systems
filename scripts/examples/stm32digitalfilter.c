#include <stdio.h>
#define N 3  // Número de coeficientes FIR

float fir_filter(float input, float coeffs[], float buffer[]) {
    float output = 0.0;
    for (int i = N - 1; i > 0; i--) {
        buffer[i] = buffer[i - 1];  // Desplazar valores en el buffer
    }
    buffer[0] = input;  // Insertar nueva muestra

    for (int i = 0; i < N; i++) {
        output += coeffs[i] * buffer[i];  // Producto acumulativo
    }
    return output;
}

int main() {
    float coeffs[N] = {0.3, 0.4, 0.3};
    float buffer[N] = {0.0};

    float input_signal[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    for (int i = 0; i < 5; i++) {
        float output = fir_filter(input_signal[i], coeffs, buffer);
        printf("Input: %.2f, Output: %.2f\n", input_signal[i], output);
    }
    return 0;
}
