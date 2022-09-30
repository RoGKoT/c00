/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcote <rcote@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 16:46:14 by rcote             #+#    #+#             */
/*   Updated: 2022/09/30 10:37:01 by rcote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_put_char(char c)
{
	write(1, &c, 1);
}

void	ft_debug(char c[], int n, int crlf)
{
	int	i;

	i = 0;
	while (c[i] != '\0')
	{
		ft_put_char(c[i]);
		i++;
	}
	ft_put_char(n + '0');
	if (crlf > 0){ft_put_char('\n');}
}

void	ft_debug_comb(int comb[], int n)
{
	int	i;

	i = 0;
	ft_debug("comb", 91 - 48, 0);
	while (i <= n)
	{
		if (i > 0 )
		{
			ft_debug(",", comb[i], 0);
		}
		else
		{
			ft_debug("", comb[i], 0);
		}
		i++;
	}
	ft_debug("", 93 - 48, 1);
}

void	ft_write_separator(void)
{
	ft_put_char(',');
	ft_put_char(' ');
}

void	ft_write_comb(int comb[],int n)
{
	int	i;

	i = 0;
	while (i <= n)
	{
		ft_put_char(comb[i] + '0');
		i++;
	}
}

void	ft_init_comb(int comb[], int n)
{
	while (n >= 0)
	{
		comb[n] = n;
		n--;
	}
}

void	ft_build_comb(int comb[], int n, int col)
{
	int	i;

	ft_debug("ft_build_comb::col = ", col, 0);
	comb[col]++;
	i = col + 1;
	while (i <= n)
	{
		comb[i] = comb[i - 1] + 1;
		i++;
	}
	ft_debug_comb(comb,n);
}

void	ft_comb(int comb[], int n, int col)
{
	if (comb[n] <= 9)
	{	

		ft_debug("last digit++", 32 - 48, 0);
		ft_debug("if comb[",n, 0);
		ft_debug("] --> ", comb[n], 0);
		ft_debug(" <= ", 9, 0);
		ft_debug(" then ", 32 - 48, 0);
		ft_debug_comb(comb,n);

		//ft_write_comb(comb, n);
		//ft_write_separator();
		comb[n]++;
		ft_comb(comb, n, col);
	}
	else if (comb[col - 1] <= (9 - n + col - 1))
	{
		ft_debug("middle digits++", 32 - 48, 0);
		ft_debug("if comb[", col - 1, 0);
		ft_debug("] --> ", comb[col - 1], 0);
		ft_debug(" <= ", 9 - n + col - 1, 0);
		ft_debug(" then ", 32 - 48,0);
		ft_build_comb(comb, n, col - 1);
		ft_comb(comb, n, col);
	}
	else if (col > 0)
	{

		ft_debug("else if col", 32 - 48, 0);
		ft_debug(" --> ", col, 0);
		ft_debug(" > ", 0, 0);
		ft_debug(" *** col-- *** ", 32 - 48, 0);

		col--;
		ft_build_comb(comb, n, col);
		ft_comb(comb, n, col);
	}
	else if (comb[0] <= (9 - n + col))
	{

		ft_debug("first digits++", 32 - 48, 0);
		ft_debug("else if comb[0]", 32 - 48 , 0);
		ft_debug("--> ", comb[0], 0);
		ft_debug(" <= ", 9 - n + col, 0);

		//comb[0]++;
		ft_build_comb(comb, n, col);
		ft_comb(comb, n, col);
	}
}

void	ft_print_combn(int n)
{
	int	comb[10];

	if ((n >= 0) && (n <= 9))
	{
		ft_init_comb(comb, 9);
		ft_comb(comb, n - 1, n - 1);
	}
}
