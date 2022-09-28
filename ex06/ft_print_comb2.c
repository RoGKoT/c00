/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcote <rcote@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 19:34:51 by rcote             #+#    #+#             */
/*   Updated: 2022/09/26 16:12:26 by rcote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_write_comb(int d, int u, int d1, int u1)
{
	ft_putchar(d);
	ft_putchar(u);
	ft_putchar(' ');
	ft_putchar(d1);
	ft_putchar(u1);
}

void	ft_write_separator(void)
{
	ft_putchar(',');
	ft_putchar(' ');
}

void	ft_comb(int d, int u, int d1, int u1)
{
	ft_write_comb(d, u, d1, u1);
	if ((d != '9') || (u != '8') || (d1 != '9') || (u1 != '9'))
	{
		ft_write_separator();
		if (u1 < '9')
		{
			u1++;
		}
		else if (d1 < '9')
		{
			u1 = '0';
			d1++;
		}	
		else if (u <= '9')
		{		
			//ft_putchar ('\n');
			u++;
			if (u == '9') // case of 08 99, 18 99, 28 99 ... 98 99
			{
				d1 = d + 1;
				u1 = '0';
			}
			else if (u == ':') // case of 09 99, 19 99, 29 99 ... 89 99
			{
				d++;
				u = '0';
				d1 = d;
				u1 = u + 1;
			}
			else
			{
				d1 = d;
				u1 = u + 1;
			}
		}
		else if (d < '9')
		{
			d++;
			u1 = u;
			d1 = d + 1;
		}
		ft_comb(d, u, d1, u1);
	}
}

void	ft_print_comb2(void)
{
	ft_comb('0', '0', '0', '1');
}
