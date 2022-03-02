/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 16:04:42 by mbarra            #+#    #+#             */
/*   Updated: 2022/02/12 16:04:42 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

long	ft_atoi(const char *nptr)
{
	int		i;
	long	num;

	i = -1;
	num = 0;
	if (!nptr)
		return (0);
	while (nptr[++i])
	{
		num = num * 10 + nptr[i] - '0';
		if (num > 2147483647 || num < 1)
			return (-1);
	}
	return (num);
}

int	ft_argv_is_num(int argc, char	**argv)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	if (argc < 5 || argc > 6)
		return (ft_error(1));
	while (argv[j])
	{
		i = 0;
		while (argv[j][i] != '\0')
		{
			if (argv[j][i] < '0' || argv[j][i] > '9' || ft_atoi(argv[j]) == -1)
				return (ft_error(3));
			i++;
		}
		j++;
	}
	if (ft_atoi(argv[1]) > 200 || ft_atoi(argv[2]) < 60
		|| ft_atoi(argv[3]) < 60 || ft_atoi(argv[4]) < 60)
		return (ft_error(1));
	return (1);
}

int	ft_error(int err)
{
	if (err == 1)
		printf(START);
	else if (err == 2)
		printf("Malloc error!\n");
	else if (err == 3)
		printf("Incorrect args!\n");
	return (-1);
}
