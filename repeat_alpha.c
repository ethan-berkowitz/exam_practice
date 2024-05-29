/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 10:10:11 by eberkowi          #+#    #+#             */
/*   Updated: 2024/05/29 10:19:45 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	repeat_alpha(char arg)
{
	int i = 0;

	i = arg - 96;
	while (i)
	{
		write(1, &arg, 1);
		i--;
	}
}

void	repeat_alpha_upper(char arg)
{
	int i = 0;

	i = arg - 64;
	while (i)
	{
		write(1, &arg, 1);
		i--;
	}
}

int	main(int argc, char *argv[])
{
	int i = 0;
	
	if (argc == 2)
	{
		while (argv[1][i])
		{
			if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
				repeat_alpha(argv[1][i]);
			else if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
				repeat_alpha_upper(argv[1][i]);
			else
				write(1, &argv[1][i], 1);
			i++;
		}
	}
}