/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 21:05:09 by yogun             #+#    #+#             */
/*   Updated: 2022/09/14 13:29:04 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>

typedef struct s_info
{
	struct s_info	*next;
	int				total_philo;
	int				*die;
	int				*done;
	int				philo_N;
	int				t2d;
	int				t2e;
	int				t2s;
	int				t2em;
	pthread_mutex_t	*done_eat;
	pthread_mutex_t	*fork_l;
	pthread_mutex_t	*fork_r;
	pthread_mutex_t	*in;
	struct timeval	*last_eat;
	struct timeval	*time;

}				t_info;

void wrong_input();
t_info *ft_start(int argc, char **argv);
int	ft_initialize_sub(t_info *data);
int	ft_atoi(char *str);
int	ft_check(int argc, char **argv);

#endif