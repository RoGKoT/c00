/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcote <rcote@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 01:41:02 by rcote             #+#    #+#             */
/*   Updated: 2022/09/22 02:06:06 by rcote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_alphabet(void)
{
	char	c;
	int	i;

	i = 1;
	while (i <= 26)
	{
		c = i + 96;
		write(1, &c, 1);
		i++;
	}
}
