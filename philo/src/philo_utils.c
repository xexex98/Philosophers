/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 15:29:58 by mbarra            #+#    #+#             */
/*   Updated: 2022/02/07 18:48:57 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	ft_error(int err)
{
	if (err == 1)
		printf("Run as: NOP, TTD(ms), TTE(ms), TTS(ms), PME(optional)\n");
	if (err == 2)
		printf("Malloc error!\n");
	if (err == 3)
		printf("Incorrect args!\n");
	return (-1);
}

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
}

int	create_philos(t_all	*all)
{
	int		i;
	
	all->philos = (t_p *)malloc(sizeof(t_p) * all->nop);
	if (!all->philos)
		ft_error(2);
	i = -1;
	while (++i < all->nop)
	{
		all->philos[i].pid = i + 1;
	}
	return (0);
}

long long	ft_time(void)
{
	struct timeval time;
	
	gettimeofday(&time, NULL);
	
	return ((long long)time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	ft_philo_is_thread(t_all *all)
{
	int	i;
	long long	start;

	i = -1;
	all->start = ft_time();
	while (++i < all->nop)
		pthread_mutex_init(&all->forks[i], NULL);
	i = -1;
	while (++i < all->nop)
		pthread_create(&all->philos[i].tid, NULL, philo, all);
	i = -1;
	while (++i < all->nop)
		pthread_join(all->philos[i].tid, NULL);
}
