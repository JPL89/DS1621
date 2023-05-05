// @File		DS1621.H		 		
// @Author		JOSIMAR PEREIRA LEITE
// @country		BRAZIL
// @Date		04/05/23
//
//
// Copyright (C) 2023 JOSIMAR PEREIRA LEITE
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
#ifndef DS1621_H
#define DS1621_H

// SLAVE, MASTER ADDRESS
#define DS1621_SLA_W					0x90
#define DS1621_SLA_R					0x91

// ADDRESS MAP
#define DS1621_READ_TEMP				0xAA
#define DS1621_ACCESS_TH				0xA1
#define DS1621_ACCESS_TL				0xA2
#define DS1621_ACCESS_CONFIG			0xAC
#define DS1621_READ_COUNTER				0xA8
#define DS1621_READ_SLOPE				0xA9
#define DS1621_START_CONVET				0xEE
#define DS1621_STOP_CONVET				0x22

void DS1621_Start()
{
	Wire_Start();
	Wire_Write(DS1621_SLA_W);
	Wire_Write(DS1621_START_CONVET);
	Wire_Stop();
}

void DS1621_Stop()
{
	Wire_Start();
	Wire_Write(DS1621_SLA_W);
	Wire_Write(DS1621_STOP_CONVET);
	Wire_Stop();
}

void DS1621_Write(unsigned char address, unsigned char data)
{
	Wire_Start();
	Wire_Write(DS1621_SLA_W);
	Wire_Write(address);
	Wire_Write(data);
	Wire_Stop();
}

unsigned int DS1621_Read(unsigned char address)
{
	unsigned char msb = 0;
	unsigned char lsb = 0;
	
	Wire_Start();
	Wire_Write(DS1621_SLA_W);
	Wire_Write(address);
	Wire_Start();
	Wire_Write(DS1621_SLA_R);
	msb = Wire_Ack();
	lsb = Wire_Nack();
	Wire_Stop();
	
	unsigned int data = (unsigned int) ((msb << 8 | lsb));
	
	return ( data );
}

unsigned int DS1621_Temp(void)
{
	unsigned char msb = 0;
	unsigned char lsb = 0;
	
	Wire_Start();
	Wire_Write(DS1621_SLA_W);
	Wire_Write(DS1621_READ_TEMP);
	Wire_Start();
	Wire_Write(DS1621_SLA_R);
	msb = Wire_Ack();
	lsb = Wire_Nack();
	Wire_Stop();
	
	unsigned int data = (unsigned int) ((msb << 8 | lsb));

	data >>= 8;
	
	return ( data );
}

#endif
