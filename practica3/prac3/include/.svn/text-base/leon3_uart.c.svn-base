//! LEON3 UART A Transmit FIFO is FULL
#define LEON3_UART_TFF (0x200)
#define LEON3_UART_TFE (0x4)


#include "leon3_uart.h"
//Estructura de datos que permite acceder a los registros de la
//UART de LEON3
struct UART_regs
{
/** \brief UART Data Register */
volatile uint32_t Data; /* 0x80000100 */
/** \brief UART Status Register */
volatile uint32_t Status; /* 0x80000104 */
/** \brief UART Control Register */
volatile uint32_t Ctrl; /* 0x80000108 */
/** \brief UART Scaler Register */
volatile uint32_t Scaler; /* 0x8000010C */
};

struct UART_regs * pLEON3_UART_REGS= (struct UART_regs *) 0x80000100UL;//COMPLETAR

#define leon3_UART_TF_IS_FULL() !(pLEON3_UART_REGS->Status & LEON3_UART_TFE)

//PARA EL LLENO (pLEON3_UART_REGS->Status & LEON3_UART_TFF)


int8_t leon3_putchar(char c){
	uint32_t write_timeout=0;
	while(leon3_UART_TF_IS_FULL()&&(write_timeout < 0xAAAAA))
		{
			write_timeout++;
		} //Espera mientras la cola de transmisión esté llena
		if(write_timeout < 0xAAAAA){
			pLEON3_UART_REGS->Data=c;
		}
		return (write_timeout == 0xAAAAA);
	}


