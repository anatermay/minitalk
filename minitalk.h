/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 18:26:25 by aternero          #+#    #+#             */
/*   Updated: 2024/11/24 20:53:39 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

/*LIBRARIES*/
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <sys/types.h>
	// My Libraries
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

/*FUNCTIONS*/
void	binary_conversion(char *message, int pid);
void	char_to_binary(char *str);

#endif