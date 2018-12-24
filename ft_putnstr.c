/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okryzhan <okryzhan@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 17:29:04 by okryzhan          #+#    #+#             */
/*   Updated: 2018/11/14 17:29:05 by okryzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putnstr(char *s, size_t n)
{
	size_t len;

	if (!(len = ft_strlen(s)))
		return (0);
	write(1, s, n < len ? n : len);
	return (n < len ? n : len);
}
