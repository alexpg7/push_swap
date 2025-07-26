/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpascua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:13:25 by alpascua          #+#    #+#             */
/*   Updated: 2025/01/27 15:43:55 by alpascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

int long long	ft_maxatoi(const char *nptr);

static int	ft_nummlen(char *str)
{
	int long long	num;
	int				cont;

	num = ft_maxatoi(str);
	if (num < 0)
		num = -num;
	cont = 1;
	while (num / 10 > 0)
	{
		cont++;
		num = num / 10;
	}
	return (cont);
}

static int	checkint(char **argv, int narg)
{
	int	i;

	while (narg >= 0)
	{
		i = 0;
		while (argv[narg][i] == ' ')
			i++;
		if (argv[narg][i] == '-')
			i++;
		if ((int)ft_strlen(argv[narg] + i) != ft_nummlen(argv[narg] + i))
			return (-1);
		narg--;
	}
	return (0);
}

static int	checkintmax(char **argv, int narg)
{
	int	i;
	int	con1;
	int	con2;

	while (narg >= 0)
	{
		i = 0;
		if (argv[narg][i] == '-')
			i++;
		con1 = ft_maxatoi(argv[narg] + i) > 2147483647 && i != 1;
		con2 = ft_maxatoi(argv[narg] + i) > 2147483648;
		if ((con1) || (con2))
			return (-1);
		narg--;
	}
	return (0);
}

static int	checkdup(char **argv, int narg)
{
	int	i;
	int	j;

	i = 0;
	while (i <= narg - 1)
	{
		j = i + 1;
		while (j <= narg)
		{
			if (ft_atoi(argv[j]) == ft_atoi(argv[i]))
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	checkerror(char **argv, int narg)
{
	int	integer;
	int	intmax;
	int	dup;

	integer = checkint(argv, narg);
	intmax = checkintmax(argv, narg);
	dup = checkdup(argv, narg);
	if (integer == -1 || intmax == -1 || dup == -1)
		return (-1);
	return (0);
}
