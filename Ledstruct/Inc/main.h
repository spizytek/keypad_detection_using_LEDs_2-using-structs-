/*
 * main.h
 *
 *  Created on: Dec 1, 2020
 *      Author: spizyteck
 */

#ifndef MAIN_H_
#define MAIN_H_

#define ENABLECLOCK (1)

//DEFINING FOR PD11 AND PD12 AS OUTPUTS
#define CLEAR_PD11          (~(3))      //For clearing the bit positions for PD11 in the mode register
#define SET_PD11_AS_OUTPUT	(1)		    //enabling PD11 as output

#define CLEAR_PD12          (~(3))      //For clearing the bit positions for PD11 in the mode register
#define SET_PD12_AS_OUTPUT	(1)		    //enabling PD11 as output

//DEFINING FOR PC0 AND PC1 AS OUTPUTS
#define CLEAR_PC0           (~(3))      //For clearing the bit positions for PD11 in the mode register
#define SET_PC0_AS_OUTPUT	(1)		    //enabling PD11 as output

#define CLEAR_PC1           (~(3))      //For clearing the bit positions for PD11 in the mode register
#define SET_PC1_AS_OUTPUT	(1)		    //enabling PD11 as output

//DEFINING FOR PC2 AND PC3 AS INPUTS
#define SET_PC2_AS_INPUT	(~(3))
#define SET_PC3_AS_INPUT    (~(3))

//DEFINING FOR PC2 AND PC3 AS PUPDR
#define CLEAR_PC2_PUPDR     (~(3))
#define SET_PC2_AS_PUPDR	(1)

#define CLEAR_PC3_PUPDR     (~(3))
#define SET_PC3_AS_PUPDR	(1)


#include <stdint.h>
#include <stdio.h>

//DEFINING STRUCTS
typedef struct {
 uint32_t	gpioa_en       :1;
 uint32_t	gpiob_en       :1;
 uint32_t	gpioc_en       :1;
 uint32_t	gpiod_en       :1;
 uint32_t	gpioe_en       :1;
 uint32_t	gpiof_en       :1;
 uint32_t	gpiog_en       :1;
 uint32_t	gpioh_en       :1;
 uint32_t	gpioi_en       :1;
 uint32_t	gpioj_en       :1;
 uint32_t	gpiok_en       :1;
 uint32_t	res            :1;
 uint32_t	crc_en         :1;
 uint32_t	res1           :5;
 uint32_t	bkpsram        :1;
 uint32_t	res2           :1;
 uint32_t	ccmdataram_en  :1;
 uint32_t	dma1_en        :1;
 uint32_t	dma2_en        :1;
 uint32_t	dma2d_en       :1;
 uint32_t	res3           :1;
 uint32_t	ethmac_en      :1;
 uint32_t	ethmactx_en    :1;
 uint32_t	ethmacrx_en    :1;
 uint32_t	ethmacptp_en   :1;
 uint32_t	otghs_en       :1;
 uint32_t	otghsulpi_en   :1;
 uint32_t	res4           :1;


} GPIOX_RCC_AHB1ENR_t;

typedef struct {
	uint32_t	moder0       :2;
	uint32_t	moder1       :2;
	uint32_t	moder2       :2;
	uint32_t	moder3       :2;
	uint32_t	moder4       :2;
	uint32_t	moder5       :2;
	uint32_t	moder6       :2;
	uint32_t	moder7       :2;
	uint32_t	moder8       :2;
	uint32_t	moder9       :2;
	uint32_t	moder10      :2;
	uint32_t	moder11      :2;
	uint32_t	moder12      :2;
	uint32_t	moder13      :2;
	uint32_t	moder14      :2;
	uint32_t	moder15      :2;
}GPIOX_MODER_t;

typedef struct{
	uint32_t	odr0         :1;
	uint32_t	odr1         :1;
	uint32_t	odr2         :1;
	uint32_t	odr3         :1;
	uint32_t	odr4         :1;
	uint32_t	odr5         :1;
	uint32_t	odr6         :1;
	uint32_t	odr7         :1;
	uint32_t	odr8         :1;
	uint32_t	odr9         :1;
	uint32_t	odr10        :1;
	uint32_t	odr11        :1;
	uint32_t	odr12        :1;
	uint32_t	odr13        :1;
	uint32_t	odr14        :1;
	uint32_t	odr15        :1;
	uint32_t	res         :16;
} GPIOX_ODR_t;

typedef struct{
	uint32_t	idr0         :1;
	uint32_t	idr1         :1;
	uint32_t	idr2         :1;
	uint32_t	idr3         :1;
	uint32_t	idr4         :1;
	uint32_t	idr5         :1;
	uint32_t	idr6         :1;
	uint32_t	idr7         :1;
	uint32_t	idr8         :1;
	uint32_t	idr9         :1;
	uint32_t	idr10        :1;
	uint32_t	idr11        :1;
	uint32_t	idr12        :1;
	uint32_t	idr13        :1;
	uint32_t	idr14        :1;
	uint32_t	idr15        :1;
	uint32_t	res         :16;
} GPIOX_IDR_t;

typedef struct{
	uint32_t	pupdr0       :2;
	uint32_t	pupdr1       :2;
	uint32_t	pupdr2       :2;
	uint32_t	pupdr3       :2;
	uint32_t	pupdr4       :2;
	uint32_t	pupdr5       :2;
	uint32_t	pupdr6       :2;
	uint32_t	pupdr7       :2;
	uint32_t	pupdr8       :2;
	uint32_t	pupdr9       :2;
	uint32_t	pupdr10      :2;
	uint32_t	pupdr11      :2;
	uint32_t	pupdr12      :2;
	uint32_t	pupdr13      :2;
	uint32_t	pupdr14      :2;
	uint32_t	pupdr15      :2;
}GPIOX_PUPDR_t;




//DEFINING THE REGISTER ADDRESS OF EACH STRUCT
#define AHB1ENR_REG      ((GPIOX_RCC_AHB1ENR_t*)(0x40023800 + 0x30))// GPIOX_RCC_AHB1ENR memory address + offset
#define ADDR_MODEREG_D   ((GPIOX_MODER_t*)(0x40020C00))
#define ADDR_ODREG_D     ((GPIOX_ODR_t*)(0x40020C00 + 0x14))
#define ADDR_MODEREG_C   ((GPIOX_MODER_t*)(0x40020800))
#define ADDR_ODREG_C     ((GPIOX_ODR_t*)(0x40020800 + 0x14))    //
#define ADDR_PUPDREG_C   ((GPIOX_PUPDR_t*)(0x40020800 + 0x0C))  // PORT C PUSHUP/DOWN RESISTOR REGISTER ADDRESS
#define ADDR_IDREG_C     ((GPIOX_IDR_t*)(0x40020800 + 0x10))      //PORT C INPUT REGISTER ADDRESS


GPIOX_RCC_AHB1ENR_t volatile *const GPIOX_AHB1ENR = AHB1ENR_REG ;
GPIOX_MODER_t  volatile * const GPIOX_MODEREG_D = ADDR_MODEREG_D; //assigning port D to the mode register address to the structs's pointer
GPIOX_ODR_t    volatile * const GPIOX_ODREG_D   = ADDR_ODREG_D  ;
GPIOX_MODER_t  volatile * const GPIOX_MODEREG_C = ADDR_MODEREG_C;
GPIOX_ODR_t    volatile * const GPIOX_ODREG_C   = ADDR_ODREG_C  ;
GPIOX_PUPDR_t  volatile * const GPIOX_PUPDR_C   = ADDR_PUPDREG_C; //enabling push up/down resistor for port
GPIOX_IDR_t    volatile * const GPIOX_IDR_C = ADDR_IDREG_C  ;

//KEY DETECT DEFINITION
#define COLUMN_1_ENABLE (!(GPIOX_IDR_C->idr2 &= (1)))
#define COLUMN_2_ENABLE (!(GPIOX_IDR_C->idr3 &= (1)))

#define SET_ROW1_LOW    (GPIOX_ODREG_C->odr0 &= (~(1)))
#define SET_ROW2_LOW    (GPIOX_ODREG_C->odr1 &= (~(1)))

//TURN ON/OFF LED1 ON PD11
#define TURN_ON_LED_1    (GPIOX_ODREG_D->odr11 |= (1))
#define TURN_OFF_LED_1   (GPIOX_ODREG_D->odr11 &= (~(1)))

//TURN ON/OFF LED2 ON PD12
#define TURN_ON_LED_2    (GPIOX_ODREG_D->odr12 |= (1))
#define TURN_OFF_LED_2   (GPIOX_ODREG_D->odr12 &= (~(1)))

#endif /* MAIN_H_ */
