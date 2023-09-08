#include "MKL25Z4.h"
#include "stdio.h"
#include "Libreria_DAC.h"

void SIM_SCGC2(){
    SIM->SCGC2 |= SIM_SCGC2_DAC0_MASK;
}
void DACx_C0(){
    DAC0->C0 = DAC_C0_DACEN_MASK;
    DAC0->C0 = DAC_C0_DACRFS_MASK;
}
void DACx_DATnL(){
    DAC0->DAT[0].DATH = DAC_DATH_DATA1(valor>>8);
}
void DACx_DATnH(){
    DAC0->DAT[0].DATL = DAC_DATL_DATA0(valor & 0xFF);
}
