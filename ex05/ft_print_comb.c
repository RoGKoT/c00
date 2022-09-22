/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcote <rcote@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 10:22:37 by rcote             #+#    #+#             */
/*   Updated: 2022/09/22 13:51:54 by rcote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_write_comb(int h, int d, int u)
{
	ft_putchar(h);
	ft_putchar(d);
	ft_putchar(u);
}

void	ft_write_separator(void)
{
	ft_putchar(',');
	ft_putchar(' ');
}

void	ft_comb(int h, int d, int u)
{
	ft_write_comb(h, d, u);
	if (u < '9')
	{
		ft_write_separator();
		u++;
		ft_comb(h, d, u);
	}
	else if (d < '8')
	{
		ft_write_separator();
		d++;
		u = d + 1;
		ft_comb(h, d, u);
	}
	else if (h < '7')
	{
		ft_write_separator();
		h++;
		d = h + 1;
		u = d + 1;
		ft_comb(h, d, u);
	}
}

void	ft_print_comb(void)
{
	ft_comb('0', '1', '2');
}
