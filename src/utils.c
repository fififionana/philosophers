/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frushiti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:35:39 by frushiti          #+#    #+#             */
/*   Updated: 2023/10/04 15:36:02 by frushiti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

uint64_t	get_time_ms(void)
{
	static struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * (uint64_t)1000) + (tv.tv_usec / 1000));
}

void	m_sleep(uint64_t sleep_ms, t_philo *p)
{
	uint64_t	end_time;

	end_time = get_time_ms() + sleep_ms;
	while (get_time_ms() < end_time && p->env->is_running > 0)
		usleep(50);
}

void	print_state(t_philo *philo, t_state state, uint64_t timestamp)
{
	const char	*states[6] = {STR_THINKING, STR_EATING, STR_SLEEPING,
		STR_TOOK_FORK, STR_DEAD, NULL};

	if (!philo->env->is_running)
		return ;
	pthread_mutex_lock(&philo->env->write);
	printf("%lu %d %s\n", timestamp, philo->id, states[state]);
	pthread_mutex_unlock(&philo->env->write);
}
