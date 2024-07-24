#include "stm32f10x.h"

// 使能 PA0 和 PA1，设置为推挽输出模式，完成 LED 驱动的初始化
void LED_Init() {
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

    GPIO_Init(GPIOA, &GPIO_InitStructure);

    // 默认熄灭 LED
    GPIO_WriteBit(GPIOA, GPIO_Pin_0 | GPIO_Pin_1, Bit_SET);   
}

// 打开对应端口的 LED 灯
void LED_ON(uint16_t GPIO_Pin) {
    GPIO_ResetBits(GPIOA, GPIO_Pin);
}

// 熄灭对应端口的 LED 灯
void LED_OFF(uint16_t GPIO_Pin) {
    GPIO_SetBits(GPIOA, GPIO_Pin);
}

void LED_TURN(uint16_t GPIO_Pin) {
    if (GPIO_ReadOutputDataBit(GPIOA, GPIO_Pin) == 0) {
        GPIO_SetBits(GPIOA, GPIO_Pin);
    } else {
        GPIO_ResetBits(GPIOA, GPIO_Pin);
    }
}