/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_initialization_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 13:08:01 by mbarra            #+#    #+#             */
/*   Updated: 2022/02/21 17:17:55 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

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
	all->f = 1;
	sem_unlink(SEM_FORKS);
	all->forks  = sem_open(SEM_FORKS, O_CREAT, 0660, all->nop);
	if (all->forks == SEM_FAILED)
		return(ft_error(4));
	sem_unlink(SEM_PRINT);
	all->print  = sem_open(SEM_PRINT, O_CREAT, 0660, 1);
	if (all->print == SEM_FAILED)
		return (ft_error(4));
	sem_unlink(SEM_DEAD);
	all->dead  = sem_open(SEM_DEAD, O_CREAT, 0660, 1);
	if (all->dead == SEM_FAILED)
		return(ft_error(4));
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
	}
	return (1);
}
