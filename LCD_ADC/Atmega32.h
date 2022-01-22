/*
 * Atmega32.h
 *
 * Author : Ahmed
 */ 


#ifndef MCU_H_
#define MCU_H_

#include "Typedef.h"

// DIO REGISTERS //

#define    PORTA   (*(volatile uint8_t*)0x3B)
#define    DDRA    (*(volatile uint8_t*)0x3A)
#define    PINA    (*(volatile uint8_t*)0x39)

#define    PORTB    (*(volatile uint8_t*)0x38)
#define    DDRB     (*(volatile uint8_t*)0x37)
#define    PINB     (*(volatile uint8_t*)0x36)

#define    PORTC    (*(volatile uint8_t*)0x35)
#define    DDRC     (*(volatile uint8_t*)0x34)
#define    PINC     (*(volatile uint8_t*)0x33)

#define    PORTD    (*(volatile uint8_t*)0x32)
#define    DDRD     (*(volatile uint8_t*)0x31)
#define    PIND     (*(volatile uint8_t*)0x30)


// EXTERNAL INTERRUPTS REGISTERS //


#define SREG   (*(volatile uint8_t*)(0x5F))

#define GICR   (*(volatile uint8_t*)(0x5B))

#define GIFR   (*(volatile uint8_t*)(0x5A))

#define MCUCR  (*(volatile uint8_t*)(0x55))

#define MCUCSR (*(volatile uint8_t*)(0x54))


// ADC REGISTERS //

#define ADMUX           (*(volatile uint8_t *)(0x27))
#define ADCSRA          (*(volatile uint8_t *)(0x26))
#define ADCH            (*(volatile uint8_t *)(0x25))
#define ADCL            (*(volatile uint8_t *)(0x24))
#define ADC_VALUE      (*(volatile uint16 *)(0x24))






#endif /* MCU_H_ */