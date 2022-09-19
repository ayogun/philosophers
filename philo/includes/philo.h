/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 18:46:02 by yogun             #+#    #+#             */
/*   Updated: 2022/09/19 18:49:30 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_data
{
	pthread_t		*tid;
	pthread_mutex_t	*done_eat;
	pthread_mutex_t	*fork_l;
	pthread_mutex_t	*fork_r;
	pthread_mutex_t	*funeral;
	struct timeval	*last_eat;
	struct timeval	*time;
	struct s_data	*next;
	int				index;
	int				total_philo;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				must_eat;
	int				*did_die;
	int				*done;
}					t_phi_data;

void				ft_thread(t_phi_data *data);
void				ft_free(t_phi_data *data);
void				ft_printf(char *s, t_phi_data *data);
void				ft_sleep(int i);
int					ft_atoi(char *str);
t_phi_data			*ft_start(int argc, char **argv, int *did_die);
long unsigned int	ft_time(struct timeval *time);
void				wrong_input(void);
void				ft_die(t_phi_data *data);
void				ft_thread_create(t_phi_data *data, int	*done);

#endif