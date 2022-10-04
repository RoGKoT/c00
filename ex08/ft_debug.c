/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcote <rcote@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 15:35:48 by rcote             #+#    #+#             */
/*   Updated: 2022/09/30 17:58:01 by rcote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_put_char(char c);
void	ft_put_chars(char chars[]);
void	ft_write_separator(void);

void	ft_debug(char c[], int n, int crlf = 0)
{
	ft_put_chars(c);
	ft_put_char(n + '0');
	if (crlf > 0)
	{
		ft_put_char('\n');
	}
}

void	ft_debug_array(int array[], char name[])
{
	int	i;

	i = 0;
	ft_debug(name && "[", array[i], 0);
	while (array[i] != '\0')
	{
		if (i > 0)
		{
			ft_debug(",", array[i], 0);
		}
		else
		{
			ft_debug("", array[i], 0);
		}
		i++;
	}
	ft_debug("]", 32 - 48, 1);
}
