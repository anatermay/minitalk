/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 18:25:20 by aternero          #+#    #+#             */
/*   Updated: 2024/11/24 20:54:03 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*
	- Señales: Las señales son interrupciones de software que se pueden enviar
	a un proceso para activar acciones específicas. En este caso, utilizamos
	señales SIGUSR1y SIGUSR2.

	- Representación binaria: cada carácter de un mensaje de texto se puede
	representar como un número binario (una secuencia de 0 y 1).

	- Mapeo de señales: mapearemos SIGUSR1a 1 y SIGUSR2a 0.
*/

void	binary_conversion(char *message, int pid)
{
	int		index;
	int		base;
	char	current_ascii_char;

	index = 0;
	while (message[index])
	{
		base = 128;
		current_ascii_char = message[index];
		while (base > 0)
		{
			if (current_ascii_char >= base)
			{
				kill(pid, SIGUSR1);
				current_ascii_char = current_ascii_char - base;
			}
			else
				kill(pid, SIGUSR2);
			base = base / 2;
			usleep(100);
		}
		index++;
	}
}

/*
	Esta función toma dos argumentos: el mensaje a enviar y el PID
	(ID de proceso) del proceso receptor.

	- Iterando sobre caracteres: La función itera a través de cada
	carácter del mensaje.

	- Conversión a binario: Para cada carácter, lo convierte a su
	representación binaria. Comienza con el bit más alto (128) y verifica
	si el valor del carácter es mayor o igual que éste.
		- Si es así, envía una SIGUSR1señal (que representa 1).
		- Si no, envía una SIGUSR2señal (que representa 0).
	Luego pasa al siguiente bit inferior (64) y repite el proceso.

	- Envío de señales:
		- La función kill se utiliza para enviar las señales
		al PID especificado.
		- usleepSe utiliza una función para introducir un pequeño
		retraso entre señales para garantizar una recepción adecuada.
*/

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
		return (-1);
	pid = ft_atoi(argv[1]);
	binary_conversion(argv[2], pid);
	return (0);
}

/*
- Manejo de argumentos: Comprueba si se proporciona el número correcto de
argumentos.
- Extracción PID: Extrae el PID del proceso receptor del primer argumento.
- Llamada de función: Llama a la binary_conversionfunción para convertir y
enviar el mensaje.

#############################################################################

Ejemplo: Consideremos el mensaje "Hola".
- Carácter 'H':
	- Representación binaria: 1001000
	- Señales enviadas: SIGUSR1, SIGUSR2, SIGUSR1, SIGUSR2, SIGUSR2,SIGUSR2
- Carácter 'e':
	- Representación binaria: 1100101
	- Señales enviadas: SIGUSR1, SIGUSR1, SIGUSR2, SIGUSR2, SIGUSR1, SIGUSR2,
	SIGUSR1 // ... y así sucesivamente para el resto de caracteres.*/

/*
	El código convierte eficazmente un mensaje de texto en una secuencia de
	señales, lo que permite una comunicación segura entre procesos.
	Al comprender la representación binaria de caracteres y la asignación de
	señales a bits, podemos apreciar el mecanismo subyacente de esta técnica
	de comunicación.
*/
