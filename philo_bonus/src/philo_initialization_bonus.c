/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_initialization_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 13:08:01 by mbarra            #+#    #+#             */
/*   Updated: 2022/02/24 17:45:27 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

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
	all->f = 1;
	sem_unlink(SEM_FORKS);
	all->forks  = sem_open(SEM_FORKS, O_CREAT, 0660, all->nop);
	if (all->forks == SEM_FAILED)
		ft_error(4);
	sem_unlink(SEM_PRINT);
	all->print  = sem_open(SEM_PRINT, O_CREAT, 0660, 1);
	if (all->print == SEM_FAILED)
		ft_error(4);
	sem_unlink(SEM_DEAD);
	all->dead  = sem_open(SEM_DEAD, O_CREAT, 0660, 1);
	if (all->dead == SEM_FAILED)
		ft_error(4);
	all->f_philo = malloc(sizeof(pid_t) * all->nop);
	if (!all->f_philo)
		ft_error(2);
}
