#include "main.h"

I2C_HandleTypeDef hi2c1; // Definición del handler para I2C1

void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_I2C1_Init(void);

int main(void) {
    HAL_Init();  // Inicialización del hardware
    SystemClock_Config();  // Configuración del reloj del sistema
    MX_GPIO_Init();  // Inicialización de GPIO
    MX_I2C1_Init();  // Inicialización de I2C

    uint8_t slave_address = 0x68 << 1; // Dirección del esclavo (izquierda por 1 bit)
    uint8_t reg_address = 0x6B;        // Registro a escribir
    uint8_t data_to_write = 0x00;      // Dato a escribir

    while (1) {
        // Escribir un byte en el esclavo
        if (HAL_I2C_Mem_Write(&hi2c1, slave_address, reg_address, I2C_MEMADD_SIZE_8BIT, &data_to_write, 1, HAL_MAX_DELAY) == HAL_OK) {
            // Escritura exitosa
            HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5); // Toggle LED para indicar éxito
            HAL_Delay(500); // Retardo para visualización
        } else {
            // Error en la escritura
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET); // Apagar LED en caso de error
        }
    }
}

// Inicialización del periférico I2C
static void MX_I2C1_Init(void) {
    hi2c1.Instance = I2C1;
    hi2c1.Init.ClockSpeed = 100000;  // Velocidad del bus (100 kHz)
    hi2c1.Init.DutyCycle = I2C_DUTYCYCLE_2; // Duty cycle estándar
    hi2c1.Init.OwnAddress1 = 0;
    hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT; // Modo de direccionamiento de 7 bits
    hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
    hi2c1.Init.OwnAddress2 = 0;
    hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
    hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
    if (HAL_I2C_Init(&hi2c1) != HAL_OK) {
        Error_Handler(); // Gestión de errores
    }
}

// Inicialización de GPIO
static void MX_GPIO_Init(void) {
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    __HAL_RCC_GPIOA_CLK_ENABLE(); // Habilitar reloj para GPIOA

    GPIO_InitStruct.Pin = GPIO_PIN_5; // Configuración del LED
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
}

void Error_Handler(void) {
    // Gestión básica de errores
    while (1) {
        HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5); // Parpadeo continuo en caso de error
        HAL_Delay(100);
    }
}
