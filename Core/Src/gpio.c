/**

  ******************************************************************************

  * @file    Lab-Libraries/gpio.c

  * @author  CSF Team

  * @mail    formation@csf.tn

  * @Tel     (+216)92.039.433

  * @version V1.0.0

  * @date    19-06-2019

  *****************************************************************************/

/* Includes ------------------------------------------------------------------*/

#include "gpio.h"

# define RCC      0x40023800

# define AHB1ENR 0x30

# define AHB1RSTR 0x10



volatile unsigned short int *RCC_GPIO_Clock = (unsigned short int *)(RCC + AHB1ENR) ;

volatile unsigned short int *RCC_GPIO_Reset = (unsigned short int *)(RCC + AHB1RSTR) ;





/**

* @brief Enable clock for the gpio_x peripheral.

* @param gpio_x: where x can be (A..G) to select the GPIO peripheral.

* @retval None

*/

void GPIO_ClockEnable (unsigned int * gpio_x){



	 if (gpio_x == GPIO_A)

	    {

	        *RCC_GPIO_Clock |= (1 << 0);

	    }

	    else if (gpio_x == GPIO_B)

	    {

	        *RCC_GPIO_Clock |= (1 << 1);

	    }

	    else if (gpio_x == GPIO_C)

	    {

	        *RCC_GPIO_Clock |= (1 << 2);

	    }

	    else if (gpio_x == GPIO_D)

	    {

	        *RCC_GPIO_Clock |= (1 << 3);

	    }

	    else if (gpio_x == GPIO_E)

	    {

	        *RCC_GPIO_Clock |= (1 << 4);

	    }

	    else if (gpio_x == GPIO_F)

	    {

	        *RCC_GPIO_Clock |= (1 << 5);

	    }

	    else if (gpio_x == GPIO_G)

	    {

	        *RCC_GPIO_Clock |= (1 << 6);

	    }

	    else if (gpio_x == GPIO_H)

	    {

	        *RCC_GPIO_Clock |= (1 << 7);

	    }

	    else if (gpio_x == GPIO_I)

	    {

	        *RCC_GPIO_Clock |= (1 << 8);

	    }

}



/**

* @brief Deinitializes the gpio_x peripheral registers to their default reset values.

* @param gpio_x: where x can be (A..G) to select the GPIO peripheral.

* @retval None

*/

void GPIO_DeInit(unsigned int * gpio_x){

	 if (gpio_x == GPIO_A)

	    {

	       *RCC_GPIO_Reset |= (1 << 0);

	       *RCC_GPIO_Reset &= ~(1 << 0);

	    }

	    else if (gpio_x == GPIO_B)

	    {

	        *RCC_GPIO_Reset |= (1 << 1);

	        *RCC_GPIO_Reset &= ~(1 << 1);

	    }

	    else if (gpio_x == GPIO_C)

	    {

	        *RCC_GPIO_Reset |= (1 << 2);

	        *RCC_GPIO_Reset &= ~(1 << 2);

	    }

	    else if (gpio_x == GPIO_D)

	    {

	        *RCC_GPIO_Reset |= (1 << 3);

	        *RCC_GPIO_Reset &= ~(1 << 3);

	    }

	    else if (gpio_x == GPIO_E)

	    {

	        *RCC_GPIO_Reset |= (1 << 4);

	        *RCC_GPIO_Reset &= ~(1 << 4);

	    }

	    else if (gpio_x == GPIO_F)

	    {

	        *RCC_GPIO_Reset |= (1 << 5);

	        *RCC_GPIO_Reset &= ~(1 << 5);

	    }

	    else if (gpio_x == GPIO_G)

	    {

	        *RCC_GPIO_Reset |= (1 << 6);

	        *RCC_GPIO_Reset &= ~(1 << 6);

	    }



}



/**

* @brief Configure the gpio_x

* @param gpio_x: where x can be (A..G) to select the GPIO peripheral.

* @param Mode: can be INPUT, OUTPUT, AF or AN

* @param typeOutput: can be PP or OD

* @param pin: can be 0...15

* @retval None

*/

void GPIO_Init(unsigned int * gpio_x, char Mode, char typeOutput, short int pin)

{

	    *(gpio_x + MODER) &=  ~(0x3 << (pin * 2));

	    *(gpio_x + MODER) |=  (Mode << (pin * 2));





	    if (Mode == OUTPUT)

	    {

	        *(gpio_x + OTYPER) &= ~(1 << pin);

	        *(gpio_x + OTYPER) |=  (typeOutput << pin);

	    }



//	        *(gpio_x + OSPEEDR) &= ~(0x3 << (pin * 2));

//	        *(gpio_x +OSPEEDR ) |=  (0x2 << (pin * 2));

//

//	        *(gpio_x +PUPDR) &= ~(0x3 << (pin * 2));

}



/**

* @brief Reads the specified input port pin.

* @param gpio_x: where x can be (A..G) to select the GPIO peripheral.

* @param GPIO_Pin: specifies the port bit to read.

* This parameter can be GPIO_Pin_x where x can be (0..15).

* @retval The input port pin value.

*/

unsigned char GPIO_ReadInputDataBit(unsigned int * gpio_x, unsigned short int GPIO_Pin)



{

	char bit_val ;

	if (*(gpio_x + IDR) & GPIO_Pin != 0)

	{

      bit_val=1;

	}

	else

	{

      bit_val=0;

	}

	return bit_val;

}



/**

* @brief Reads the specified GPIO input data port.

* @param gpio_x: where x can be (A..G) to select the GPIO peripheral.

* @retval GPIO input data port value.

*/

unsigned short int GPIO_ReadInputData(unsigned int * gpio_x)

  {

        return (unsigned short)(*(gpio_x+IDR));

	}



/**

* @brief Sets or clears the selected data port bit.

* @param gpio_x: where x can be (A..G) to select the GPIO peripheral.

* @param GPIO_Pin: specifies the port bit to be written.

* This parameter can be one of GPIO_Pin_x where x can be (0..15).

* @param BitVal: specifies the value to be written to the selected bit.

* This parameter can be one of the BitAction enum values:

* @arg Bit_RESET: to clear the port pin

* @arg Bit_SET: to set the port pin

* @retval None

*/

void GPIO_WriteBit(unsigned int * gpio_x, unsigned short int GPIO_Pin, char BitVal)

{

	  if (BitVal == 1)

	    {

	        *(gpio_x + ODR/4) |= GPIO_Pin;

	    }

	    else

	    {

	    	*(gpio_x + ODR/4) &= ~ GPIO_Pin;

	    }

}



/**

* @brief Writes data to the specified GPIO data port.

* @param gpio_x: where x can be (A..G) to select the GPIO peripheral.

* @param PortVal: specifies the value to be written to the port output data register.

* @retval None

*/

void GPIO_Write(unsigned int * gpio_x, unsigned short int PortVal)

{

	*(gpio_x + ODR) = PortVal;

}



