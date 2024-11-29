/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:47:38 by aternero          #+#    #+#             */
/*   Updated: 2024/11/29 18:59:36 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	client_error_handling_bonus(int i)
{
	if (i == 0)
	{
		ft_printf("ERROR:\n   Kill failed\n");
		exit(1);
	}
	if (i == 1)
	{
		ft_printf("Error:\n   Sigaction failed\n");
		exit(1);
	}
}

void	client_null_message_bonus(int pid)
{
	static int	i = 0;

	if (i <= 8)
		if (kill(pid, SIGUSR1) == -1)
			client_error_handling_bonus(0);
	i++;
}

void	client_messenger_bonus(int pid, char *str)
{
	static int	bit = 0;
	static char	*str_bis = 0;

	if (str)
		str_bis = str;
	if (*str_bis)
	{
		if ((((unsigned char)*str_bis >> bit) % 2) == 0)
			if (kill(pid, SIGUSR1) == -1)
				client_error_handling_bonus(0);
		if ((((unsigned char)*str_bis >> bit) % 2) == 1)
			if (kill(pid, SIGUSR2) == -1)
				client_error_handling_bonus(0);
		bit++;
		if (bit == 8)
		{
			str_bis++;
			bit = 0;
		}
	}
	if (!(*str_bis))
		client_null_message_bonus(pid);
}

void	client_checker_bonus(int sig, siginfo_t *info, void *context)
{
	static int	id;

	if (info->si_pid != 0)
		id = info->si_pid;
	(void)context ;
	if (sig == SIGUSR1)
		client_messenger_bonus(id, NULL);
	if (sig == SIGUSR2)
	{
		ft_printf("Server >> \"The message came through\"\n");
		exit(EXIT_SUCCESS);
	}
}

int	main(int ac, char **av)
{
	struct sigaction	action;

	action.sa_flags = SA_SIGINFO;
	action.sa_sigaction = client_checker_bonus;
	sigemptyset(&action.sa_mask);
	if (sigaction(SIGUSR1, &action, NULL) == -1
		|| sigaction(SIGUSR2, &action, NULL) == -1)
		client_error_handling_bonus(1);
	if (ac != 3)
	{
		ft_printf("ERROR:\n	Use the format: ./client <PID> <String>\n");
		exit(EXIT_FAILURE);
	}
	client_messenger_bonus(ft_atoi(av[1]), av[2]);
	while (1)
		pause();
	return (0);
}
