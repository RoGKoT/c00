/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcote <rcote@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 16:46:14 by rcote             #+#    #+#             */
/*   Updated: 2022/09/28 02:47:33 by rcote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_put_char(char c)
{
	write(1, &c, 1);
}

void	ft_write_separator(void)
{
	ft_put_char(',');
	ft_put_char(' ');
}

void	ft_write_comb(int comb[],int n)
{
	int i;

	i = '0';
	while (i <= n)
	{
		ft_put_char(comb[i]);
		i++;
	}
}

void	ft_comb(int comb[], int n, int col)
{
	int	i;

	if (comb[n] <= '9')
	{
		ft_write_comb(comb, n);
		ft_write_separator();
		comb[n]++;
		ft_comb(comb, n, col);
	}
	else if (col > '0')
	{
		if (comb[col - 1] + 1 < comb[col])
		{
			comb[col - 1]++;
			i = col;
			while (i <= n)
			{
				comb[i] = comb[i - 1] + 1;
				i++;
			}	
			ft_comb(comb, n, col);
		}
		else if (comb[col - 2] == comb[col - 1] - 1)
		{
			col--;
		}
		ft_comb(comb, n, col);
	}
}

void	ft_print_combn(int n)
{
	int	comb[10];
	int	i;

	if ((n >= '0') && (n <= '9'))
	{
		i = n - 1;
		while (i >= '0')
		{
			comb[i] = i;
			i--;
		}
		ft_comb(comb, n - 1, n - 1);
	}
}
