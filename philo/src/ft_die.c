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

/*
	This function loop thorough all the philosophers infinitely
	unless fifth parameter has given. In this case it will loop
	thorough untill philosophers complete their total mustEat times.
	Whenever a philosopher's last_eat time become bigger than dieTime,
	it means our philosopher died out of starving. In this case,
	we lock our funeral mutex for other philosophers not to race to die.
	We lock the funeral mutex in printf function.
*/
void	ft_die(philoData *data)
{
	philoData				*tmp;
	int					j;
	long unsigned int	i;

	tmp = data;
	while (*data->done < data->total_philo)
	{
		j = ft_time(data->last_eat);
		if (j >= data->dieTime)
		{
			*data->did_die = 1;
			i = ft_time(data->time);
			printf("%lums - The philosopher number %i,  \033[31;1mdid_died!\033[0m 💀💀💀  \n", i, data->index_philo);
			return ;
		}
		data = data->next;
		if (data == NULL)
			data = tmp;
	}
}
