/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 18:26:05 by aternero          #+#    #+#             */
/*   Updated: 2024/11/24 20:46:34 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	char_to_binary(char *str)
{
	int	index[2];
	int	length;
	int	result;

	index[0] = 0;
	result = 0;
	length = 0;
	while (str[length])
		length++;
	while (index[0] <= length)
	{
		index[1] = 8;
		while (index[1] <= 8)
		{
			result = result + (str[index[0]] * (2 ^ index[1]));
			index[1]--;
		}
		index[0]++;
	}
	ft_printf("The binary result is: %d\n", result);
}

/*
Esta función toma una cadena como entrada y convierte cada carácter a su
representación binaria. Así es como funciona:

Inicialización:

index[0]:Mantiene un registro del carácter actual en la cadena.
result:Almacena el valor binario del carácter actual.
length:Almacena la longitud de la cadena.
Calcular la longitud de la cadena:

El primer whilebucle itera a través de la cadena para determinar su longitud.
Conversión de caracteres a binarios:

El segundo whilebucle itera sobre cada carácter de la cadena.
El bucle interno whileitera sobre cada bit del carácter actual.
Se resultcalcula multiplicando el valor ASCII del carácter por la potencia de 
2 apropiada (2^7, 2^6, ..., 2^0) y sumando los resultados.
Una vez que se procesa un carácter, resultse imprime en la consola.
Ejemplo:

Si la cadena de entrada es "A", el valor ASCII de 'A' es 65. La representación 
binaria de 65 es 1000001. La función calculará el valor binario de la siguiente 
manera:

result = 65 * 2^7 + 0 * 2^6 + 0 * 2^5 + 0 * 2^4 + 0 * 2^3 +
*/

void	i(int signum)
{
	static int	position;
	static char	binary_char[8];

	if (signum == SIGUSR1)
		binary_char[position] = '1';
	else if (signum == SIGUSR2)
		binary_char[position] = '0';
	position++;
	if (position == 8)
	{
		position = 0;
		char_to_binary(binary_char);
	}
}

/*
Esta función maneja las señales recibidas (SIGUSR1 y SIGUSR2) y las almacena en 
una cadena binaria. Así es como funciona:

Manejo de señales:

La función se llama siempre que se recibe una señal SIGUSR1 o SIGUSR2.
El signumargumento indica qué señal se recibió.
Almacenamiento de bits:

La positionvariable realiza un seguimiento de la posición del bit actual en la 
cadena binaria.
Si se recibe SIGUSR1, se almacena un '1' en la posición actual.
Si se recibe SIGUSR2, se almacena un '0' en la posición actual.
El positionse incrementa.
Procesando un byte:

Cuando se han recibido 8 bits, positionse restablece a 0 y char_to_binaryse 
llama a la función para procesar el byte completado.
*/
int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("* * * *   WELLCOME TO MINITALK SERVER   * * * *\n");
	ft_printf("*                 by AnaTerMay                *\n");
	ft_printf("*        aternero from 42 Málaga (2024)       *\n");
	ft_printf("* * * * * * * * * * * * * * * * * * * * * * * *\n");
	ft_printf("\n>>>           PID number: %d         <<<\n", pid);
	ft_printf("\n>>> Please, wait. Waiting for messages... <<<\n");
	signal(SIGUSR1, i);
	signal(SIGUSR2, i);
	while (1)
		pause();
	return (0);
}

/*
Esta es la función principal del programa. Esto es lo que hace:

Obtener ID de proceso:

La getpid()función recupera el ID del proceso actual y lo imprime en 
la consola.

Manejo de señales:

La signal()función se utiliza para registrar la ifunción como 
manejador de señales para las señales SIGUSR1 y SIGUSR2.

Esperando señales:

El whilebucle llama continuamente a la pause()función, lo que hace que 
el proceso se duerma hasta que se recibe una señal.
*/

/*
Funcionalidad general:

El código configura un proceso de servidor que escucha las señales SIGUSR1 
y SIGUSR2. Cuando recibe estas señales, almacena los bits correspondientes 
en una cadena binaria. Una vez que recibe un byte completo, convierte la 
cadena binaria en un carácter y lo imprime en la consola.
*/
