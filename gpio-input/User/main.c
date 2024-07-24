#include "stm32f10x.h"
#include "Delay.h"
#include "LED.h"
#include "KEY.h"

int main(void) {
    LED_Init();
    KEY_Init();
    
    uint8_t key;
    while (1) {
        key = Key_GetNum();
        if (key == 1) {
            LED_TURN(GPIO_Pin_0);
        }
        if (key == 2) {
            LED_TURN(GPIO_Pin_1);
        }
    }
}
