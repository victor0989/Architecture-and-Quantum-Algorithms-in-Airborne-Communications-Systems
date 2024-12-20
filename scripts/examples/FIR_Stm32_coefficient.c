#include <stdio.h>

#define N 4  // Número de coeficientes FIR

// Coeficientes FIR
float coeffs[N] = {0.1, 0.2, 0.3, 0.4};

// Buffer para las muestras previas
float buffer[N] = {0.0};

// Función FIR
float fir_filter(float input) {
    float output = 0.0;

    // Desplazar valores en el buffer
    for (int i = N - 1; i > 0; i--) {
        buffer[i] = buffer[i - 1];
    }

    // Insertar nueva muestra
    buffer[0] = input;

    // Calcular salida FIR
    for (int i = 0; i < N; i++) {
        output += coeffs[i] * buffer[i];
    }

    return output;
}

int main() {
    float signal[] = {1.0, 0.5, 0.3, 0.1, 0.0};  // Ejemplo de señal de entrada

    for (int i = 0; i < 5; i++) {
        float output = fir_filter(signal[i]);
        printf("Entrada: %.2f, Salida FIR: %.2f\n", signal[i], output);
    }

    return 0;
}
