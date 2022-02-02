/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 14:36:23 by mbarra            #+#    #+#             */
/*   Updated: 2022/02/02 15:49:29 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>

typedef struct s_p
{
	int		left_fork;
	int		right_fork;
}				t_p;


typedef struct s_all
{
	int		nop;
	int		ttd;
	int		tte;
	int		tts;
	int		pme;

	t_p		**philos;
}				t_all;

int		ft_error(int err);
long	ft_atoi(const char *nptr);
int		ft_argv_is_num(char	**argv);


#endif