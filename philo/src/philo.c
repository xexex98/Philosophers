/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 19:50:05 by mbarra            #+#    #+#             */
/*   Updated: 2022/02/09 14:07:45 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
# define FORK "has taken a fork\n"
# define FORKT "put the forks on the table\n"
# define EAT "is eating\n"
# define SLEEP "is sleeping\n"
# define THINK "is thinking\n"
# define DIED "died\n"


pthread_mutex_t	print;
pthread_mutex_t	queue;

void	ft_printf(t_all *all, long long time, int pid, char *str)
{
	pthread_mutex_lock(&all->print);
	printf("%lli %i %s\n", time, pid, str);
	pthread_mutex_unlock(&all->print);
}

void	ft_forks_in_hand(t_p *philos)
{
	pthread_mutex_lock(&philos->all->forks[philos->lf]);
	ft_printf(philos->all, ft_timestamp(philos->all), philos->pid, FORK);
	pthread_mutex_lock(&philos->all->forks[philos->rf]);
	ft_printf(philos->all, ft_timestamp(philos->all), philos->pid, FORK);
	return ;
}

void	ft_forks_on_the_table(t_p *philos)
{
	pthread_mutex_unlock(&philos->all->forks[philos->lf]);
	// ft_printf(philos->all, ft_timestamp(philos->all), philos->pid, FORKT);
	pthread_mutex_unlock(&philos->all->forks[philos->rf]);
	// ft_printf(philos->all, ft_timestamp(philos->all), philos->pid, FORKT);
	return ;
}

void	ft_think(t_p *philos)
{
	ft_printf(philos->all, ft_timestamp(philos->all), philos->pid, THINK);
	return ;
}

void	ft_eat(t_p *philos)
{
	ft_forks_in_hand(philos);
	ft_printf(philos->all, ft_timestamp(philos->all), philos->pid, EAT);
	philos->lm = ft_time();
	usleep(philos->all->tte * 1000);
	ft_forks_on_the_table(philos);
	return ;
}

void	ft_sleep(t_p *philos)
{
	ft_printf(philos->all, ft_timestamp(philos->all), philos->pid, SLEEP);
	usleep(philos->all->tts * 1000);
	return	;
}

void	*ft_meal(void *arg)
{
	t_p	*philos;

	philos = (t_p *)arg;
	unsigned int i = 5;
	// while (i--)
	while (1)
	{
		ft_think(philos);
		ft_eat(philos);
		ft_sleep(philos);
		usleep(100);
	}
	return (NULL);
}

int main(int argc, char **argv)
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
	return (0);
}
