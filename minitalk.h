/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthammat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 13:03:14 by rthammat          #+#    #+#             */
/*   Updated: 2022/06/13 21:56:06 by rthammat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <limits.h>

typedef struct mini_t
{
	pid_t	server_pid;
	int		bit;
}	t_cli;

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlen(const char *s);

int		ft_atoi(const char *str);
void	*ft_memmove(void *dst, const void *src, size_t len);

char	*ft_strdup(const char *s1);
char	*ft_addalloc_c(char *msg, char c);
void	cli_error_handle(void);

#endif
