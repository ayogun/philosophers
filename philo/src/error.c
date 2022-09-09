/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:04:25 by yogun             #+#    #+#             */
/*   Updated: 2022/09/09 14:04:46 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void wrong_input()
{
	printf("\n\n__________________________________________________________________________________________________________________________________________\n"
	"\033[0;31mWrong input has given!\033[0m                                                                 						          |\n"
"\033[0;32mCorrect use: \033[0m															    	  |\n"
"$ ./philo <number_of_philosophers>  <time_to_die>  <time_to_eat>  <time_to_sleep> <number_of_times_each_philosopher_must_eat>(optional)   |\n"
"															    		  |\n"
"\033[0;32mExample use: \033[0m																  |\n"
"$ ./philo 4 500 200 200															  |\n"
"																	  |\n"
"\033[0;32mInput parameters: \033[0m															  |\n"
"<number_of_philosophers> 													 	  |\n"
"<time_to_die> 																  |\n"
"<time_to_eat> 																  |\n"
"<time_to_sleep>																  |\n"
"<number_of_times_each_philosopher_must_eat> (optional)											  |\n"
"																	  |\n"
"__________________________________________________________________________________________________________________________________________|\n\n\n");
}