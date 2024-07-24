#include "stm32f10x.h"
#include "Delay.h"

void KEY_Init() {
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
    
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_10;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

    GPIO_Init(GPIOB, &GPIO_InitStructure);
}

uint8_t Key_GetNum() {
    uint8_t KeyNum = 0;
    if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_0) > 0) {
        // 刚刚按下按键，会发生一个20ms的抖动，通过 delay 消除抖动
        Delay_ms(20);
        // 直到松手
        while (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_0) > 0);
        // 松手后也会产生一段抖动，通过 delay 消除
        Delay_ms(20);
        KeyNum = 1;
    }

    if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_10) > 0) {
        // 刚刚按下按键，会发生一个20ms的抖动，通过 delay 消除抖动
        Delay_ms(20);
        // 直到松手
        while (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_10) > 0);
        // 松手后也会产生一段抖动，通过 delay 消除
        Delay_ms(20);
        KeyNum = 2;
    }

    return KeyNum;
}