/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthammat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:41:55 by rthammat          #+#    #+#             */
/*   Updated: 2022/06/13 23:07:34 by rthammat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	error_handle(pid_t cli_pid, char *msg)
{
	if (msg)
		free(msg);
	kill(cli_pid, SIGUSR2);
	exit(1);
}

char	*print_msg(char *msg)
{
	ft_putstr_fd(msg, 1);
	free(msg);
	return (NULL);
}

static	void	handler_sigusr(int signum, siginfo_t *info, void *context)
{
	static char	c = 0xFF;
	static int	bit_shift = 0;
	static char	*msg = NULL;

	(void)info;
	(void)context;
	if (signum == SIGUSR1)
		c |= (0x80 >> bit_shift);
	else if (signum == SIGUSR2)
		c ^= (0x80 >> bit_shift);
	++bit_shift;
	if (bit_shift == 8)
	{
		ft_putchar_fd(c, 1);
		bit_shift = 0;
		c = 0xFF;
	}
	if (kill(info->si_pid, SIGUSR1) == -1)
		error_handle(info->si_pid, msg);
}

int	main(void)
{
	struct sigaction	sa;
	pid_t				server_pid;

	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &handler_sigusr;
	server_pid = getpid();
	ft_putstr_fd("server pid is ", 1);
	ft_putnbr_fd(server_pid, 1);
	ft_putchar_fd('\n', 1);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		usleep(1);
	return (0);
}
