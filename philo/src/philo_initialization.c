/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_initialization.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 13:08:01 by mbarra            #+#    #+#             */
/*   Updated: 2022/02/20 15:09:48 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	ft_init_all(t_all *all, char **argv)
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
		return (ft_error(2));
	all->f = 1;
	return (1);
}

int	create_philos(t_p *philos, t_all *all)
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
		pthread_mutex_init(&all->dead, NULL);
	}
	pthread_mutex_init(&all->print, NULL);
	return (1);
}
