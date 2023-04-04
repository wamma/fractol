/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:37:11 by hyungjup          #+#    #+#             */
/*   Updated: 2023/04/04 16:59:58 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_check_equal(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	if (s1[i] != s2[i])
		return (0);
	else
		return (1);
}

static long	ft_atol(char *str)
{
	size_t	i;
	long	ret;
	int		flag;

	i = 0;
	flag = 0;
	ret = 0;
	while (str[i] == 9 || str[i] == 10 || str[i] == 11 || \
	str[i] == 12 || str[i] == 13 || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
		flag = str[i++] - '+';
	while ('0' <= str[i] && str[i] <= '9')
	{
		ret *= 10;
		ret += str[i] - '0';
		i++;
	}
	if (flag != 0)
		ret *= -1;
	return (ret);
}

double	ft_atof(char *str)
{
	int		len;
	int		flag;
	int		i;
	double	ret;
	double	tmp;

	i = 0;
	flag = 1;
	len = ft_strlen(str);
	if (str[0] == '-')
	{
		flag = -1;
		i++;
	}
	ret = ft_atol(str);
	i = 0;
	while (str[i] && str[i] != '.')
		i++;
	if (str[i] == '.')
		i++;
	tmp = ft_atol(str + i);
	i = len - i;
	while (i--)
		tmp /= 10;
	return (flag * (ret + tmp));
}
