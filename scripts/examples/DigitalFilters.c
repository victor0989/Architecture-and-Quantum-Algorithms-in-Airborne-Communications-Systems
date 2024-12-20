// 1. Digital Filter Implementation in STM32 (C)
// Description: This example demonstrates the implementation of a low-pass FIR filter on an STM32 microcontroller. 
// The filter processes noisy input signals to produce a clean output.

//Code (C for STM32 in STM32CubeIDE):
#include "stm32f4xx_hal.h"

#define FILTER_TAP_NUM 5

// Coefficients for FIR Filter
float filter_coeff[FILTER_TAP_NUM] = {0.1, 0.15, 0.5, 0.15, 0.1};
float input_buffer[FILTER_TAP_NUM] = {0};

float fir_filter(float input) {
    float output = 0.0;

    // Shift buffer and add new input
    for (int i = FILTER_TAP_NUM - 1; i > 0; i--) {
        input_buffer[i] = input_buffer[i - 1];
    }
    input_buffer[0] = input;

    // Apply filter coefficients
    for (int i = 0; i < FILTER_TAP_NUM; i++) {
        output += input_buffer[i] * filter_coeff[i];
    }

    return output;
}

int main(void) {
    HAL_Init();
    while (1) {
        float noisy_signal = get_adc_input();  // Mock function for ADC input
        float clean_signal = fir_filter(noisy_signal);
        send_to_dac(clean_signal);            // Mock function for DAC output
    }
}
```

*********************************************************************************************************************************************************************

// 2. Digital Filter Implementation in Verilog (Low-Pass FIR Filter)
// Description: This example demonstrates the implementation of a low-pass FIR filter in Verilog. It processes a noisy digital signal and generates a filtered output.

// Code (Verilog):
module fir_filter #(parameter TAP_NUM = 5)(
    input wire clk,
    input wire reset,
    input wire [15:0] input_sample,
    output reg [15:0] output_sample
);
    reg [15:0] coeff[TAP_NUM-1:0] = {16'h0A00, 16'h1800, 16'h4000, 16'h1800, 16'h0A00};
    reg [15:0] delay_line[TAP_NUM-1:0];
    integer i;

    always @(posedge clk or posedge reset) begin
        if (reset) begin
            output_sample <= 16'h0;
            for (i = 0; i < TAP_NUM; i = i + 1) begin
                delay_line[i] <= 16'h0;
            end
        end else begin
            for (i = TAP_NUM-1; i > 0; i = i - 1) begin
                delay_line[i] <= delay_line[i-1];
            end
            delay_line[0] <= input_sample;

            output_sample <= 0;
            for (i = 0; i < TAP_NUM; i = i + 1) begin
                output_sample <= output_sample + (delay_line[i] * coeff[i]);
            end
        end
    end
endmodule
```
********************************************************************************************************************************************

3. Communication Structures (I2C for STM32)
Description: This example demonstrates configuring an I2C interface to communicate between an STM32 microcontroller and external devices.

// Code (C for STM32):
#include "stm32f4xx_hal.h"

I2C_HandleTypeDef hi2c1;

void i2c_init(void) {
    hi2c1.Instance = I2C1;
    hi2c1.Init.ClockSpeed = 100000;
    hi2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;
    hi2c1.Init.OwnAddress1 = 0x61;
    hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
    hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
    hi2c1.Init.OwnAddress2 = 0x00;
    hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
    hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
    HAL_I2C_Init(&hi2c1);
}

void i2c_write(uint8_t dev_addr, uint8_t reg_addr, uint8_t data) {
    uint8_t buffer[2] = {reg_addr, data};
    HAL_I2C_Master_Transmit(&hi2c1, dev_addr << 1, buffer, 2, HAL_MAX_DELAY);
}

**************************************************************************************************************************************************

// 4. Communication Structures (USART for STM32)
// Description: This example demonstrates USART communication for data transmission and reception.
#include "stm32f4xx_hal.h"

UART_HandleTypeDef huart2;

void usart_init(void) {
    huart2.Instance = USART2;
    huart2.Init.BaudRate = 9600;
    huart2.Init.WordLength = UART_WORDLENGTH_8B;
    huart2.Init.StopBits = UART_STOPBITS_1;
    huart2.Init.Parity = UART_PARITY_NONE;
    huart2.Init.Mode = UART_MODE_TX_RX;
    HAL_UART_Init(&huart2);
}

void usart_send(char *message) {
    HAL_UART_Transmit(&huart2, (uint8_t *)message, strlen(message), HAL_MAX_DELAY);
}

********************************************************************************************************************************************************

// 5. Conclusion
// Description: 
// These examples demonstrate the implementation of FIR filters, I2C, and USART communication for STM32 microcontrollers and FPGA designs. 
// Combining these techniques ensures robust processing and communication in critical systems.
