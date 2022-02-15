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

int	ft_argv_is_num(char	**argv)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (argv[j])
	{
		i = 0;
		while (argv[j][i] != '\0')
		{
			if (argv[j][i] < '0' || argv[j][i] > '9' || ft_atoi(argv[j]) == -1)
				return (-1);
			i++;
		}
		j++;
	}
	return (1);
}

void	ft_init_all(t_all *all, char **argv)
{
	all->nop = ft_atoi(argv[1]);
	all->ttd = ft_atoi(argv[2]);
	all->tte = ft_atoi(argv[3]);
	all->tts = ft_atoi(argv[4]);
	if (argv[5] != NULL)
		all->pme = ft_atoi(argv[5]);
	else
		all->pme = -1;
	all->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * all->nop);
	if (!all->forks)
		ft_error(2);
	all->f = 1;
}

void	create_philos(t_p *philos, t_all *all)
{
	int		i;

	i = -1;
	while (++i < all->nop)
	{
		philos[i].pid = i + 1;
		philos[i].pe = 0;
		philos[i].all = all;
		philos[i].lf = i;
		philos[i].rf = (i + 1) % all->nop;
		pthread_mutex_init(&all->forks[i], NULL);
	}
	pthread_mutex_init(&all->print, NULL);
	pthread_mutex_init(&all->dead, NULL);
}

int	ft_printf(t_all *all, long long time, int pid, char *str)
{
	pthread_mutex_lock(&all->print);
	if (all->f)
		printf("%lli %i %s\n", time, pid, str);
	pthread_mutex_unlock(&all->print);
	return (0);
}
