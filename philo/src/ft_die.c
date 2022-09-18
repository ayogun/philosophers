/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_did_die.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 13:40:00 by yogun             #+#    #+#             */
/*   Updated: 2022/09/18 10:45:44 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_did_die(philoData *data)
{
	philoData				*tmp;
	int					j;
	long unsigned int	i;

	tmp = data;
	while (*data->done < data->total_philo)
	{
		j = ft_time(data->last_eat);
		if (j >= data->did_dieTime)
		{
			*data->did_die = 1;
			pthread_mutex_lock(data->funeral);
			i = ft_time(data->time);
			printf("%lums - The philosopher number %i,  \033[31;1mdid_died!\033[0m 💀💀💀  \n", i, data->index_philo);
			return ;
		}
		data = data->next;
		if (data == NULL)
			data = tmp;
	}
}