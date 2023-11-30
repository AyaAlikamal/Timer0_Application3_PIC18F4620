/* 
 * File:   application.c
 * Author: AyaAli
 * Created on September 22, 2023, 10:24 AM
 */
#include "application.h"
void Timer0_Defualt_Hundeler(void);
volatile uint_16 time_250ms = ZERO_INIT, time_500ms = ZERO_INIT;
timer0_config_t Counter1_obj={
.TMR0_Interrupt_Hundeler = Timer0_Defualt_Hundeler,
.timer0_mode = TIMER0_COUNTER_MODE_CFG,
.timer0_conter_edge = TIMER0_RAISING_EDG_COFG,
.timer0_register_size = TIMER0_16BIT_MODE_CFG,
.timer0_prescaler_enable = TIMER0_PRESCALLER_DISABLE_COUNTER_CFG,
.timer0_preload_value = 0
};
timer0_config_t Timer1_obj={
.TMR0_Interrupt_Hundeler = Timer0_Defualt_Hundeler,
.timer0_mode = TIMER0_TIMER_MODE_CFG,
.timer0_conter_edge = TIMER0_RAISING_EDG_COFG,
.timer0_register_size = TIMER0_16BIT_MODE_CFG,
.timer0_prescaler_enable = TIMER0_PRESCALLER_ENABLE_COUNTER_CFG,
.prescaler_value = TIMER0_PRESACLER_VALUE_4,
.timer0_preload_value = 3036
};

led_t led1={
.Port_Name = PORTC_INDEX,
.pin = PIN0,
.led_statues = LED_OFF
};
led_t led2={
.Port_Name = PORTC_INDEX,
.pin = PIN1,
.led_statues = LED_OFF
};
int main() {
   
Std_ReturnType ret = E_NOT_OK;
application_initialize();
ret = Timer0_Init(&Timer1_obj);
ret = led_initialize(&led1);
ret = led_initialize(&led2);

while(1){
    if(time_250ms == 1){
    time_250ms = 0;
    led_toggle(&led1);
    }
    else{}
     if(time_500ms == 2){
    led_toggle(&led2);
    time_500ms = 0;
    }
     else{}
}
 return (EXIT_SUCCESS);
}
void application_initialize(void){
   Std_ReturnType ret = E_NOT_OK;
//   ECU_Layer_initialize();

}

void Timer0_Defualt_Hundeler(void){
time_250ms = 1;
time_500ms ++;
}