// @File		MAIN.C		 		
// @Author		JOSIMAR PEREIRA LEITE
// @country		BRAZIL
// @Date		01/05/23
//
//
// Copyright (C) 2023 JOSIMAR PEREIRA LEITE
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
#include "utils.h"
#include "ks0066.h"
#include "wire.h"
#include "ds1621.h"

void main(void)
{
    __delay_ms(500);
    
    PIC18F2520();
    
    Wire_Init();
    
    KS0066_Init();
    
    KS0066_Clear(0);
    
    KS0066_Clear(1);
    
    KS0066_Goto(0, 0);
    
    unsigned int data = 0;
    
    while(1)
    {
        DS1621_Start();
        __delay_ms(1000);
        DS1621_Stop();
        
        data = DS1621_Temp();
    
        KS0066_Clear(0);
    
        KS0066_Goto(0, 0);
        
        KS0066_Int( data );
    }
    
    return;
}