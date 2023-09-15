#include "MKL25Z4.h"
#include "stdio.h"
#include "ADC.h"

void AdcInit(){
    SIM->SCGC6 |= SIM_SCGC6_ADC0_MASK;
    ADC0->CFG1 = ADC_CFG1_MODE(3) | ADC_CFG1_ADICLK(1) | ADC_CFG1_ADIV(0);
    ADC0->SC3 = ADC_SC3_AVGE_MASK | ADC_SC3_AVGS(3);
    while (ADC0->SC3 & ADC_SC3_CAL_MASK);
}
int AdcConversion(int canal){
    ADC0->SC1[0] = ADC_SC3_ADCH(canal);
    while (!(ADC0->SC1[0] & ADC_SC1_COCO_MASK));
    int ValorMedio = ADC0->R[0];
    int ValorTotal = ((3,6 * ValorMedio)/65535);
    return ValorTotal;
}
