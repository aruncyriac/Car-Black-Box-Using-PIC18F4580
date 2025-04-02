/*
 * File:   adc.c
 * Author: arunc
 *
 * Created on 30 December, 2024, 4:47 PM
 * File:   adc.c
 * Author: arunc
 *
 * Created on 28 December, 2024, 12:01 PM
 */


#include <xc.h>

void init_adc() {
    //channel selection for potentometer
    CHS3 = 0;
    CHS2 = 1;
    CHS1 = 0;
    CHS0= 0;

    GO = 0;//no conversion
    ADON = 1;//adc enable

    //no referance voltage
    VCFG1 = 0;
    VCFG1 = 0;
    
    //make channel 4 as analog
    PCFG3 = 1;
    PCFG2 = 0;
    PCFG1 = 1;
    PCFG0 = 0;
    
    //0.625 mHZ OF CLOCK
    ADCS2 = 0;
    ADCS1 = 1;
    ADCS0 = 0;

    //Aquisition time 8TAD(1286 micro sec)
    ACQT2 = 1;
    ACQT1 = 0;
    ACQT0 = 0;
    
    ADFM = 1; //right justified
    ADRESH = 0X00;
}  
unsigned short read_adc()
{
   //initiate conversion
    GO = 1;
    //wait till conversion completes
    while(GO);
    //fetch value from reg
    return ADRESL|(ADRESH << 8);
}
    