/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthammat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 17:12:12 by rthammat          #+#    #+#             */
/*   Updated: 2022/06/13 23:05:31 by rthammat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_null(pid_t server_pid)
{
	static int	i = -1;

	if (++i < 8)
	{
		if (kill(server_pid, SIGUSR2) == -1)
			cli_error_handle();
		usleep(110);
	}
	if (i == 8)
	{
		ft_putstr_fd("\nSending successfully\n", 1);
		exit(0);
	}
}

void	send_char(pid_t server_pid, char c)
{
	static int	bit = -1;

	if (++bit == 8)
		bit = 0;
	if (c & (0x80 >> bit))
	{
		if (kill(server_pid, SIGUSR1) == -1)
			cli_error_handle();
	}
	else if (kill(server_pid, SIGUSR2) == -1)
		cli_error_handle();
	usleep(110);
}

void	send_str(pid_t pid, char *argv2)
{
	static char		*str = NULL;
	static pid_t	server_pid = 0;
	static int		i = 0;
	static int		bit_count = -1;

	if (pid)
		server_pid = pid;
	if (argv2)
		str = argv2;
	if (++bit_count == 8)
	{
		++i;
		bit_count = 0;
	}
	if (str[i])
	{
		send_char(server_pid, str[i]);
		return ;
	}
	ft_putstr_fd("sending successfully\n", 1);
	exit(0);
	send_null(server_pid);
}

static void	handler_sigusr(int signum, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	if (signum == SIGUSR1)
		send_str(0, 0);
	if (signum == SIGUSR2)
	{
		ft_putstr_fd("client: server end unexpectedly\n", 1);
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	pid_t				server_pid;

	sigemptyset(&sa.sa_mask);
	server_pid = ft_atoi(argv[1]);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &handler_sigusr;
	if (argc == 3)
	{
		if (!argv[2])
			exit(1);
		sigaction(SIGUSR1, &sa, 0);
		sigaction(SIGUSR2, &sa, 0);
		send_str(server_pid, argv[2]);
		while (1)
			pause();
	}
	else
		return (1);
	return (0);
}
