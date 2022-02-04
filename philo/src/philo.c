/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 19:50:05 by mbarra            #+#    #+#             */
/*   Updated: 2022/02/04 13:04:50 by mbarra           ###   ########.fr       */
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

void	*ft_eat(void *arg)
{
	t_all	*all;
	
	all = (t_all *)arg;

	// if 
	// pthread_mutex_lock(&all->forks[id]);
	// pthread_mutex_lock(&all->forks[id + 1]);
	// printf("|sleep|\n");
	// pthread_mutex_unlock(&all->forks[0]);
	// pthread_mutex_unlock(&all->forks[1]);

	return NULL;
}


void	ft_philo_is_thread(t_all *all)
{
	int	i;

	i = -1;
	while (++i < all->nop)
		pthread_mutex_init(&all->forks[i], NULL);
	i = -1;
	while (++i < all->nop)
		pthread_create(&all->philos[i].tid, NULL, ft_eat, &all);
	i = -1;
	while (++i < all->nop)
		pthread_join(all->philos[i].tid, NULL);

}

int	ft_time(void)
{
	struct timeval time;

	int	i;
	i = gettimeofday(&time, NULL);
	printf("%i\n", i);
	i = gettimeofday(&time, NULL);

	return 0;
}
int main(int argc, char **argv)
{
	t_all	all;


	ft_time();
// 	if (argc < 5 || argc > 6)
// 		return (ft_error(1));
// 	if (ft_argv_is_num(argv) < 0)
// 		return (ft_error(3));
// 	ft_init_all(&all, argv);
// 	if (create_philos(&all) < 0)
// 		return (ft_error(2));
// 	ft_philo_is_thread(&all);
// 	return (0);
}
