#include "stm32f4xx.h"

void UART_Init(void) {
    USART2->BRR = 0x0683; // Configurar baud rate
    USART2->CR1 |= USART_CR1_TE | USART_CR1_RE | USART_CR1_UE; // Habilitar TX, RX, USART
}

void UART_SendChar(char c) {
    while (!(USART2->SR & USART_SR_TXE)); // Esperar a que el buffer esté vacío
    USART2->DR = c;
}

int main() {
    UART_Init();
    while (1) {
        UART_SendChar('A'); // Enviar carácter 'A'
    }
}
