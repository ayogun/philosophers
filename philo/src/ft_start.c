/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 22:49:38 by yogun             #+#    #+#             */
/*   Updated: 2022/09/11 23:02:01 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_initialize_sub(t_info *data)
{
	t_info				*tmp;
	int					i;

	i = 0;
	while (data->total_philo > i++)
	{
		data->die = 0;
		data->philo_N = i;
		data->next = NULL;
		data->fork_r = malloc(sizeof(pthread_mutex_t) * 1);
		if (!data->fork_r || pthread_mutex_init(data->fork_r, 0))
			return (1);
		if (data->total_philo == i)
			break ;
		tmp = malloc(sizeof(t_info) * 1);
		if (!tmp)
			return (1);
		data->next = tmp;
		data = tmp;
	}
	return (0);
}

t_info *ft_start(int argc, char **argv)
{
		t_info	*info;

		ft_start(argc,argv);
		info = malloc(sizeof(t_info) * 1);
		if (!info)
			return (NULL);
		info->total_philo = ft_check(argc, argv);
		if (info->total_philo < 1)
			return (NULL);
		if (ft_initialize_sub(info))
		{
			free(info);
			return (NULL);
		}
		return (info);
}