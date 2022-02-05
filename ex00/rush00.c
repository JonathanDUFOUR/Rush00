/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 11:13:34 by jodufour          #+#    #+#             */
/*   Updated: 2022/02/05 13:32:23 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#ifndef BUFF_SIZE
# define BUFF_SIZE	4096
#endif

/*
	CHARS[0]: corner top-left
	CHARS[1]: corner top-right
	CHARS[2]: corner bottom-left
	CHARS[3]: corner bottom-right
	CHARS[4]: border top
	CHARS[5]: border bottom
	CHARS[6]: border left
	CHARS[7]: border right
	CHARS[8]: middle
*/
#ifndef CHARS
# define CHARS	"oooo--|| "
#endif

static int	__flush(char const *buff, size_t *const j)
{
	if (write(STDOUT_FILENO, buff, *j) == -1)
		return (EXIT_FAILURE);
	*j = 0;
	return (EXIT_SUCCESS);
}

static char	__filler(unsigned int const width, unsigned int const height,
	size_t const i)
{
	if (i % (width + 1) == width)
		return ('\n');
	if (!i)
		return (CHARS[0]);
	if (i == width - 1)
		return (CHARS[1]);
	if (i == (width + 1) * (height - 1))
		return (CHARS[2]);
	if (i == (width + 1) * height - 2)
		return (CHARS[3]);
	if (i < width)
		return (CHARS[4]);
	if (i > (width + 1) * (height - 1) && i < (width + 1) * height - 2)
		return (CHARS[5]);
	if (!(i % (width + 1)))
		return (CHARS[6]);
	if (i % (width + 1) == width - 1)
		return (CHARS[7]);
	return (CHARS[8]);
}

int	rush(unsigned int const width, unsigned int const height)
{
	char			buff[BUFF_SIZE];
	size_t const	size = width * height + height;
	size_t			i;
	size_t			j;

	i = 0;
	j = 0;
	while (i < size)
	{
		if (j == BUFF_SIZE && __flush(buff, &j))
			return (EXIT_FAILURE);
		buff[j] = __filler(width, height, i);
		++i;
		++j;
	}
	if (__flush(buff, &j))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
