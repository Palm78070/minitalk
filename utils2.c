/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthammat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 17:20:54 by rthammat          #+#    #+#             */
/*   Updated: 2022/06/12 17:44:22 by rthammat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	is_instr(char c, char *s)
{
	while (*s)
	{
		if (c == *s)
			return (1);
		++s;
	}
	return (0);
}

static int	ft_isspace(char c)
{
	return (is_instr(c, " \t\r\n\v\f"));
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	unsigned long long	result;
	int					sign;

	result = 0;
	sign = 1;
	while (*str && ft_isspace(*str))
		++str;
	if (*str != '\0' && (*str == '+' || *str == '-'))
	{
		if (*str == '-')
			sign = -1;
		++str;
	}
	while (*str && ft_isdigit(*str))
	{
		result = (result * 10) + (*str - '0');
		if (result > LLONG_MAX && sign > 0)
			return (-1);
		else if (result > LLONG_MAX)
			return (0);
		++str;
	}
	return ((int)(result * sign));
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = -1;
	if (dst == src || len == 0)
		return (dst);
	if ((unsigned char *)dst > (unsigned char *)src)
	{
		while (len-- > 0)
			((unsigned char *)dst)[len] = ((unsigned char *)src)[len];
	}
	else
	{
		while (++i < len)
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
	}
	return (dst);
}
