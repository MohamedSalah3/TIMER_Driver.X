#include "DIO.h"

static uint8_t is_init = 0;
/*
*Input: DIO_Cfg_s -> to get PORT name, pins to be initiated and the required direction
*Output: No output
*InOut:
*Description: This function can set the direction of a full port, a nibble
* 			  or even one pin.
*/
ERROR_STATUS DIO_init (DIO_Cfg_s *DIO_info)
{
uint8_t ret_error=E_OK;
static uint8_t first_powerup_init = 0;
is_init=1;
 if (first_powerup_init == 0) {
    switch (DIO_info -> port)
    {
      case GPIOA:
  PORTA_DIR=0x00;
      break;
      case GPIOB:
  PORTB_DIR=0x00;
      break;
      case GPIOC:
  PORTC_DIR=0x00;
      break;
      case GPIOD:
  PORTD_DIR=0x00;
      break;
      case GPIOE:
  PORTE_DIR=0x00;
      break;
  }
  first_powerup_init++;
  }
if((DIO_info -> port)== GPIOA)
 ADCON1 |=( DIO_info -> operation_mode) ;
if(DIO_info != NULL){
    switch (DIO_info -> dir)
    {
      case INPUT:
        switch (DIO_info -> port)
        {
            case GPIOA:
              /*make the PORTA INPUT*/
          
           PORTA_DIR |=(DIO_info-> pin) ;
            break;
            case GPIOB:
            /*make the PORTB INPUT*/
                PORTB_DIR |=(DIO_info->pin) ;
            break;
            case GPIOC:
            /*make the PORTC INPUT*/
                PORTC_DIR |=(DIO_info->pin) ;
            break;
            case GPIOD:
            /*make the PORTD INPUT*/
                PORTD_DIR |=(DIO_info->pin) ;
            break;
            case GPIOE:
            /*make the PORTE INPUT*/
            PORTE_DIR |=(DIO_info->pin) ;
            break;
            default:
            ret_error += E_NOK+INVALID_PORT;
            break;
    }
  break;
  case OUTPUT:
    switch (DIO_info -> port)
    {
      case GPIOA:
        PORTA_DIR &=(~(DIO_info->pin))	;
      break;
      case GPIOB:
        PORTB_DIR &=(~(DIO_info->pin))	;
      break;
      case GPIOC:
        PORTC_DIR &=(~(DIO_info->pin))	;
      break;
      case GPIOD:
        PORTD_DIR &=(~(DIO_info->pin))	;
      break;
      case GPIOE:
        PORTE_DIR &=(~(DIO_info->pin))	;
      break;
      default:
      ret_error += E_NOK+INVALID_PORT;
      break;
  }
  break;
default:
ret_error +=E_NOK + INVALID_DIR;
break;
}
}else
{
ret_error +=E_NOK+NULL_PTR;
}
return ret_error;
}


/*
*Input: GPIO -> to get PORT name
*					- GPIOA
*					- GPIOB
*					- GPIOC
*					- GPIOD
*		pins -> pins to be written at.
*					- PIN0
*					- PIN1
*					- PIN2
*					- PIN3
*					- PIN4
*					- PIN5
*					- PIN6
*					- PIN7
*					- UPPER_NIBBLE
*					- LOWER_NIBBLE
*					- FULL_PORT
*		value 	-> The desired value
*					- HIGH
*					- LOW
*Output: No output
*In/Out: No In/Out
*Description: This function can set the value of a full port, a nibble
* 			  or even one pin.
*/
ERROR_STATUS DIO_Write (uint8_t GPIO, uint8_t pins, uint8_t value)
{ uint8_t ret_error=E_OK;
  /*As PORTX when first_powerup default value =0xFF we need to clear it once */
  static uint8_t first_powerup = 0;
if (first_powerup == 0) {
switch (GPIO) {
  case GPIOA:
  PORTA_DATA=INPUT;
  break;
  case GPIOB:
  PORTB_DATA=INPUT;
  break;
  case GPIOC:
  PORTC_DATA=INPUT;
  break;
  case GPIOD:
  PORTD_DATA=INPUT;
  break;
  case GPIOE:
  PORTE_DATA=INPUT;
  break;
}
  first_powerup++;
}
switch (value) {
  case HIGH:
    switch (GPIO) {
      case GPIOA:
      PORTA_DATA |= pins;
      break;
      case GPIOB:
      PORTB_DATA |= pins;
      break;
      case GPIOC:
      PORTC_DATA |= pins;
      break;
      case GPIOD:
      PORTD_DATA |= pins;
      break;
      case GPIOE:
      PORTE_DATA |= pins;
      break;
      default:
      ret_error +=E_NOK+INVALID_PORT;
      break;

    }
  break;
  case LOW:
    switch (GPIO) {
      case GPIOA:
      PORTA_DATA &= (~pins);
      break;
      case GPIOB:
      PORTB_DATA &= (~pins);
      break;
      case GPIOC:
      PORTC_DATA &= (~pins);
      break;
      case GPIOD:
      PORTD_DATA &= (~pins);
      break;
      case GPIOE:
      PORTE_DATA &= (~pins);
      break;
      default:
      ret_error +=E_NOK+INVALID_PORT;
      break;

    }
  break;
  default:
ret_error +=E_NOK+INVALID_DIR;
  break;
}
return ret_error;
}

/*
*Input: GPIO -> to get PORT name
*					- GPIOA
*					- GPIOB
*					- GPIOC
*					- GPIOD
*		pins -> pins to be written at.
*					- PIN0
*					- PIN1
*					- PIN2
*					- PIN3
*					- PIN4
*					- PIN5
*					- PIN6
*					- PIN7
*					- UPPER_NIBBLE
*					- LOWER_NIBBLE
*					- FULL_PORT
*		value 	-> The desired value
*					- HIGH
*					- LOW
*Output: data -> the acquired data wether it was PORT data or pins data
*In/Out:
*Description: This function gets the value of a full port, a nibble
* 			  or even one pin.
*/
ERROR_STATUS DIO_Read (uint8_t GPIO,uint8_t pins, uint8_t *data)
{
  uint8_t ret_error=E_OK;
  switch (GPIO)
  	{	case GPIOA:
  		*data=(PORTA_DATA & pins);
  		break;
  	case GPIOB:
  		*data=(PORTB_DATA & pins);
  		break;
  	case GPIOC:
  		*data=(PORTC_DATA & pins);
  		break;
  	case GPIOD:
  		*data=(PORTD_DATA & pins);
                break;
        case GPIOE:
  		*data=(PORTE_DATA & pins);
  		break;
  		default:
  		ret_error += INVALID_PORT;
  		break;
  	}
  	if(*data > 0)
  	{
  		*data = 1;
  	}

  return ret_error;
}

/*
*Input: GPIO -> to get PORT name
*					- GPIOA
*					- GPIOB
*					- GPIOC
*					- GPIOD
*		pins -> pins to be written at.
*					- PIN0
*					- PIN1
*					- PIN2
*					- PIN3
*					- PIN4
*					- PIN5
*					- PIN6
*					- PIN7
*					- UPPER_NIBBLE
*					- LOWER_NIBBLE
*					- FULL_PORT
*Output: data -> No output
*In/Out:
*Description: This function toggles the value of a full port, a nibble
* 			  or even one pin.
*/
ERROR_STATUS DIO_Toggle (uint8_t GPIO, uint8_t pins)
{
    uint8_t ret_error=E_OK;
    switch (GPIO)
    	{	case GPIOA:
    		PORTA_DATA ^=(pins);
    		break;
    	case GPIOB:
    		PORTB_DATA ^=(pins);
    		break;
    	case GPIOC:
    		PORTC_DATA ^=(pins);
    		break;
    	case GPIOD:
    		PORTD_DATA ^=(pins);
    		break;
    	default:
    		ret_error +=INVALID_PORT+E_NOK;
    		break;
    	}
    return ret_error;
}


