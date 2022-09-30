/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcote <rcote@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 16:46:14 by rcote             #+#    #+#             */
/*   Updated: 2022/09/30 17:57:04 by rcote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_put_char(char c);
void	ft_put_chars(char chars[]);
void	ft_write_separator(void);

void	ft_write_comb(int comb[], int n)
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

	comb[col]++;
	i = col + 1;
	while (i <= n)
	{
		comb[i] = comb[i - 1] + 1;
		i++;
	}
}

void	ft_comb(int comb[], int n, int col)
{
	if (comb[n] <= 9)
	{	
		ft_write_comb(comb, n);
		if (comb[0] < (9 - n))
		{
			ft_write_separator();
		}
		comb[n]++;
		ft_comb(comb, n, col);
	}
}

void	ft_print_combn(int n)
{
	int	comb[10];
	int	i;

	n--;
	i = n;
	if ((n >= 0) && (n <= 9))
	{
		ft_init_comb(comb, 9);
		ft_comb(comb, n, n);
		while (i >= 0)
		{
			if (comb[i] <= (9 - n))
			{
				ft_build_comb(comb, n, i);
				ft_comb(comb, n, i);
			}
			else
			{
				i--;
			}
		}
	}
}
