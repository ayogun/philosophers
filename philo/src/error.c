/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:04:25 by yogun             #+#    #+#             */
/*   Updated: 2022/09/19 18:42:11 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	wrong_input(void)
{
	printf("\033[0;31mWrong input has given!\033[0m \n");
	printf("\033[0;32mCorrect use: \033[0m \n");
	printf("$ ./philo <number_of_philosophers>  <time_to_did_die>");
	printf("<time_to_eat>  <time_to_sleep>");
	printf("<number_of_times_each_philosopher_must_eat>");
	printf("(optional) \n\n");
}
