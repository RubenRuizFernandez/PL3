


#include "leon3_uart.h"
//transmite a través del puerto serie la cadena de caracteres
//pasada por parámetro.
//Funcionamiento. Recorremos el string hasta que encuentre \0 y paramos
int8_t leon3_print_string(char* str){
	int i=0;
	int8_t error=0;
	while(str[i]!='\0'&&(!error))//Lo hace hasta que pasa \0 como dice en el enunciado.

	{
		leon3_putchar(str[i]);
		i++;
	}
	leon3_putchar('\n');
	return i;
}
//transmite a través del puerto serie el entero transformado en
//cadena de caracteres.
//FUNCIONAMIENTO: Primero comprueba si es mayor que 100, las centenas, imprime la centena y hace el resto y se lo pasa a i
//Ejemplo: 123. Pasar a putchar un 1, que es el valor de la centena y queda 23. Lo mismo con las decenas, como es mayor de 10
//entonces se queda con el 2 y pasa el 3. Como solo queda el 3, pasa el 3 y en total hemos pasado 123 caracter a caracter.
//Le sumamos siempre 48 ya que es como se realiza la conversion de int a char
int8_t leon3_print_uint8(uint8_t i){
	int c; //Centenas
	int d; //Decenas

	if(i>99){
		c=i/100;
		//Nos quedamos con el valor de la centena
		i=i%100;
		//Nos quedamos con el resto
		if(c>0){
			leon3_putchar((char)c + 48);

		}
		if(i<=9){
			leon3_putchar((char)48);
		}
	}
	if (i>9){
		d=i/10;
		i=i%10;
		leon3_putchar((char)d+48);
	}
	if (i>=0){

		leon3_putchar((char)i+48);
	}
	return 0;
}

int8_t leon3_print_uint32( uint32_t i) {

	int c; //Centenas
	int d; //Decenas

	if(i>99){
		c=i/100;
		//Nos quedamos con el valor de la centena
		i=i%100;
		//Nos quedamos con el resto
		if(c>0){
			leon3_putchar((char)c + 48);

		}
		if(i<=9){
			leon3_putchar((char)48);
		}
	}
	if (i>9){
		d=i/10;
		i=i%10;
		leon3_putchar((char)d+48);
	}
	if (i>=0){

		leon3_putchar((char)i+48);
	}
	return 0;
}

