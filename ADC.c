#include "MKL25Z4.h"
#include "stdio.h"
#include "Libreria_ADC.h"
#include "Delay.h"

void ADCx_SC1n(){
    SIM->SCGC6 |= SIM_SCGC6_ADC0_MASK;
}
void ADCn->SC1[0]{
    ADC0->CFG1 = ADC_CFG1_MODE(3);
    ADC0->CFG1 = ADC_CFG1_ADICLK(1);
    ADC0->CFG1 = ADC_CFG1_ADIV(0);
}
void SIM_SCGC6(){
    ADC0->SC3 = ADC_SC3_AVG3_MASK;
    ADC0->SC3 = ADC_SC3_AVGS(3);
}
void ADCx_Rn(){
   while(ADC->SC3 & ADC_SC3_CAL_MASK);
}
void ADC->R[0]{
}
