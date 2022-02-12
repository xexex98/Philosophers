/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 19:50:05 by mbarra            #+#    #+#             */
/*   Updated: 2022/02/12 16:28:19 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	*ft_dead(void *arg)
{
	t_p	*philos;

	philos = (t_p *)arg;
	while (philos->all->f != TIME_TO_DIE)
	{
		if (philos->all->ttd < ft_time() - philos->lm)
		{
			ft_printf(philos->all, ft_timestamp(philos->all),
				philos->pid, DIED);
			philos->all->f = TIME_TO_DIE;
		}
		if (philos->pe == philos->all->pme + 1)
			philos->all->f = TIME_TO_DIE;
		usleep(100);
	}
	return (NULL);
}

void	*ft_meal(void *arg)
{
	t_p	*philos;

	philos = (t_p *)arg;
	philos->lm = ft_time();
	pthread_create(&philos->death, NULL, ft_dead, (void *)philos); //errros
	usleep(10);
	while (philos->all->f != TIME_TO_DIE)
	{
		ft_eat(philos);
		ft_sleep(philos);
		ft_think(philos);
		usleep(10);
	}
	return (NULL);
}

int	ft_philo_is_thread(t_all *all)
{
	int	i;
	int	check;

	i = -1;
	while (++i < all->nop)
	{
		check = pthread_mutex_init(&all->forks[i], NULL);
		if (check != 0)
			return (ft_error(6));
	}
	all->start = ft_time();
	i = -1;
	while (++i < all->nop)
	{
		check = pthread_create(&all->philos[i].tid, NULL,
				ft_meal, (void *)&all->philos[i]);
		if (check != 0)
			return (ft_error(7));
		usleep(100);
	}
	check = pthread_join(all->philos->death, NULL);
	if (check != 0)
		return (ft_error(8));
	return (0);
}

int	main(int argc, char **argv)
{
	t_all	all;

	if (argc < 5 || argc > 6)
		return (ft_error(1));
	if (ft_argv_is_num(argv) < 0)
		return (ft_error(3));
	ft_init_all(&all, argv);
	if (create_philos(&all) < 0)
		return (ft_error(2));
	ft_philo_is_thread(&all);
	if (ft_philo_is_thread(&all) == -1)
		return (ft_error(4));
	return (0);
}
