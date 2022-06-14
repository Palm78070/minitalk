/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthammat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 18:37:30 by rthammat          #+#    #+#             */
/*   Updated: 2022/06/14 19:06:24 by rthammat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*ft_strdup(const char *s1)
{
	char	*p;
	size_t	len;

	len = ft_strlen(s1) + 1;
	if (len == 0)
		return ("\0");
	p = (char *)malloc(len);
	if (!p)
		return (NULL);
	ft_memmove(p, s1, len);
	return (p);
}

char	*add_first_c(char c)
{
	char	*new_msg;

	new_msg = (char *)malloc(2 * sizeof(char));
	if (!new_msg)
		return (NULL);
	new_msg[0] = c;
	new_msg[1] = '\0';
	return (new_msg);
}

char	*ft_addalloc_c(char *msg, char c)
{
	int		i;
	char	*new_msg;

	i = -1;
	if (!c)
		return (NULL);
	if (msg == NULL)
		return (add_first_c(c));
	new_msg = (char *)malloc((ft_strlen(msg) + 2) * sizeof(char));
	if (!new_msg)
	{
		free(msg);
		return (NULL);
	}
	while (msg[++i])
		new_msg[i] = msg[i];
	new_msg[i] = c;
	new_msg[++i] = '\0';
	free(msg);
	return (new_msg);
}

void	cli_error_handle(void)
{
	ft_putstr_fd("client: error\n", 1);
	exit(1);
}

int	ft_str_isnum(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (!(s[i] >= '0' && s[i] <= '9'))
			return (0);
	}
	return (1);
}
