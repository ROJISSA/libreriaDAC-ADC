#include "MKL25Z4.h"
#include "stdio.h"
#include "DAC.h"

void DacInit(){
    SIM->SCGC6 |= SIM_SCGC6_DAC0_MASK;
    DAC0->C0 = DAC_C0_DACEN_MASK | DAC_C0_DACRFS_MASK;
}
void DacConversion(int valor0){
    DAC0->DAT[0].DATH = DAC_DATH_DATA1(valor0 >> 8);
    DAC0->DAT[0].DATH = DAC_DATH_DATA0(valor0 & 0xFF);
}
