/*
 * seven_segment.c
 *
 * Created: 8/6/2018 10:31:18 PM
 *  Author: Mohamed Zaghlol
 */ 

#include "DIO.h"
void seven_seg_vinit(unsigned char port_name)
{
	DIO_set_port_direction(port_name,0x0F);
}

void seven_seg_write(unsigned char portname,unsigned char number)
{
unsigned char arr[]={ 0,1,2,3,4,5,6,7,8,9};

write_low_nibble(portname,arr[number]);
}