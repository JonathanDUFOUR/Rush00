/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 10:38:20 by jodufour          #+#    #+#             */
/*   Updated: 2022/02/05 11:15:36 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef RED
# define RED	"\e[31m"
#endif
#ifndef RESET
# define RESET	"\e[0m"
#endif

int	rush(unsigned int const width, unsigned int const height);

static int	__usage_err(void)
{
	write(STDERR_FILENO, RED "Error: wrong usage\n" RESET, 28);
	write(STDERR_FILENO, "Usage: ./rush00 <width> <height>\n", 33);
	return (EXIT_FAILURE);
}

static bool	__isspace(char const c)
{
	return (c == '\f'
		|| c == '\t'
		|| c == '\n'
		|| c == '\r'
		|| c == '\v'
		|| c == ' ');
}

static bool	__isdigit(char const c)
{
	return (c >= '0' && c <= '9');
}

static unsigned int	__atou(char const *str)
{
	unsigned int	output;

	output = 0;
	while (__isspace(*str))
		++str;
	if (*str == '+')
		++str;
	while (__isdigit(*str))
		output = output * 10 + *str++ - '0';
	return (output);
}

int	main(int const ac, char const **av)
{
	if (ac != 3)
		return (__usage_err());
	if (rush(__atou(av[1]), __atou(av[2])))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
