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
	int				index_philo;
	int				total_philo;
	int				dieTime;
	int				eatTime;
	int				sleepTime;
	int				mustEat;
	int				*die;
	int				*done;
}					philoData;

void				ft_thread(philoData *data);
void				ft_free(philoData *data);
void				ft_printf(char *s, philoData *data);
void				ft_sleep(int i);
int					ft_atoi(char *str);
philoData				*ft_initialize(int argc, char **argv, int *die);
long unsigned int	ft_time(struct timeval *time);
void				wrong_input();
void				ft_die(philoData *data);
void				ft_thread_create(philoData *data, int	*done);


#endif