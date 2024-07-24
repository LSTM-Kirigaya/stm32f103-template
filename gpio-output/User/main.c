#include "stm32f10x.h"
#include "Delay.h"

int main(void) {
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
    
    GPIO_InitTypeDef GPIO_initStructure;
    GPIO_initStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_initStructure.GPIO_Pin = GPIO_Pin_12;
    GPIO_initStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_initStructure);

    GPIO_WriteBit(GPIOB, GPIO_Pin_12, Bit_SET);
    
    while (1) {
        // GPIO_Write(GPIOA, ~0x0001);
        // Delay_ms(500);
        // GPIO_Write(GPIOA, ~0x0002);
        // Delay_ms(500);
        // GPIO_Write(GPIOA, ~0x0004);
        // Delay_ms(500);
        // GPIO_Write(GPIOA, ~0x0008);
        // Delay_ms(500);
        // GPIO_Write(GPIOA, ~0x0010);
        // Delay_ms(500);
    }
}
