/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcote <rcote@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 16:45:21 by rcote             #+#    #+#             */
/*   Updated: 2022/09/30 17:56:42 by rcote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_put_char(char c)
{
	write(1, &c, 1);
}

void	ft_put_chars(char chars[])
{
	int	i;

	i = 0;
	while (chars[i] != '\0')
	{
		ft_put_char(chars[i]);
		i++;
	}	
}

void	ft_write_separator(void)
{
	ft_put_chars(", ");
}
