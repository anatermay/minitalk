/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 14:42:48 by aternero          #+#    #+#             */
/*   Updated: 2024/11/29 14:47:27 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_pid(int pid, bool bonus)
{
	ft_printf("* * * *   WELLCOME TO MINITALK SERVER   * * * *\n");
	ft_printf("*                 by AnaTerMay                *\n");
	ft_printf("*        aternero from 42 Málaga (2024)       *\n");
	if (bonus)
		ft_printf("*       >>>·>>>·>>>· BONUS ·<<<·<<<·<<<       *\n");
	ft_printf("* * * * * * * * * * * * * * * * * * * * * * * *\n");
	ft_printf("\n>>>           PID number: %d         <<<\n", pid);
	ft_printf("\n>>> Please, wait. Waiting for messages... <<<\n");
}
