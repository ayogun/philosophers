#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_data
{
	int				index_philo;
	int				total_philo;
	int				dieTime;
	int				eatTime;
	int				sleepTime;
	int				mustEat;
	int				*die;
	int				*done;
	pthread_t		*tid;
	pthread_mutex_t	*done_eat;
	pthread_mutex_t	*fork_l;
	pthread_mutex_t	*fork_r;
	pthread_mutex_t	*in;
	struct timeval	*last_eat;
	struct timeval	*time;
	struct s_data	*next;
}					t_data;

void				ft_thread(t_data *data);
void				ft_free(t_data *data);
void				ft_printf(char *s, t_data *data);
void				ft_sleep(int i);
int					ft_atoi(char *str);
t_data				*ft_initialize(int argc, char **argv, int *die);
long unsigned int	ft_time(struct timeval *time);
void				wrong_input();
void				ft_die(t_data *data);
void				ft_thread_create(t_data *data, int	*done);


#endif