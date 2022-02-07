/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 19:50:05 by mbarra            #+#    #+#             */
/*   Updated: 2022/02/07 18:46:34 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
// memset, 
// usleep, 
// gettimeofday, 
// pthread_create,
// pthread_detach, 
// pthread_join, 
// pthread_mutex_init,
// pthread_mutex_destroy,
// pthread_mutex_lock,
// pthread_mutex_unlock,
# define FORK "has taken a fork\n"
# define EAT "is eating\n"
# define SLEEP "is sleeping\n"
# define THINK "is thinking\n"
# define DIED "died\n"


pthread_mutex_t	print;
void	ft_printf(long long time, int philosophernum, char *str)
{
	pthread_mutex_lock(&print);
	printf("%lli %i %s\n", time, philosophernum, str);
	pthread_mutex_unlock(&print);
}

void	ft_eat(int	philosophernum, t_all *all)
{
	int	left;
	int	right;

	left = (philosophernum + all->nop) % all->nop;
	right = (philosophernum + 1) % all->nop;
	if (all->philos[philosophernum].pid == all->nop)
		right = 0;
	// printf("left %i\n", left);
	// printf("right %i\n", right);

	pthread_mutex_lock(&all->forks[left]);
	ft_printf(ft_time(), philosophernum, FORK);
	pthread_mutex_lock(&all->forks[right]);
	ft_printf(ft_time(), philosophernum, FORK);
	ft_printf(ft_time(), philosophernum, EAT);
	while (all->tte > )
	pthread_mutex_unlock(&all->forks[left]);
	pthread_mutex_unlock(&all->forks[right]);
	ft_printf(ft_time(), philosophernum, SLEEP);
}

// void	ft_sleep(t_all *all)
// {
	
// }

void *philo(void *arg)
{
	t_all	*all;
	int		i;

	all = (t_all *)arg;
	i = 0;
	while (1)
	{
		if (i == all->nop)
			i = 0;
		ft_eat(i, all);
		i++;
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
