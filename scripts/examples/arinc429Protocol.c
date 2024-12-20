#include <stdio.h>

// Simulación de envío de datos en un bus ARINC 429
void send_arinc_message(uint32_t data) {
    // Dividir mensaje en 32 bits
    uint8_t label = (data >> 24) & 0xFF; 
    uint8_t sdi = (data >> 22) & 0x03; 
    uint8_t payload = (data >> 3) & 0x1FFFFF; 
    uint8_t parity = data & 0x01;

    printf("ARINC Message Sent:\n");
    printf("Label: %X, SDI: %X, Payload: %X, Parity: %X\n", label, sdi, payload, parity);
}

int main() {
    uint32_t example_data = 0x1A5C789F;
    send_arinc_message(example_data);
    return 0;
}
