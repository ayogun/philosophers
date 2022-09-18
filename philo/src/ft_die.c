/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_die.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 13:40:00 by yogun             #+#    #+#             */
/*   Updated: 2022/09/18 10:36:02 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_die(t_data *data)
{
	t_data				*tmp;
	int					j;
	long unsigned int	i;

	tmp = data;
	while (*data->done < data->total_philo)
	{
		j = ft_time(data->last_eat);
		if (j >= data->dieTime)
		{
			*data->die = 1;
			pthread_mutex_lock(data->funeral);
			i = ft_time(data->time);
			printf("%lums - The philosopher number %i,  \033[31;1mdied!\033[0m 💀💀💀  \n", i, data->index_philo);
			return ;
		}
		data = data->next;
		if (data == NULL)
			data = tmp;
	}
}