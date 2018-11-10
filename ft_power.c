/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okryzhan <okryzhan@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 16:49:05 by okryzhan          #+#    #+#             */
/*   Updated: 2018/10/27 16:49:06 by okryzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_power(int n, int p)
{
	long long res;

	res = 1;
	while (p > 0)
	{
		res *= n;
		p--;
	}
	return (res);
}
