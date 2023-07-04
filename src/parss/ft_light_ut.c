/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_light_ut.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 19:12:59 by nbouljih          #+#    #+#             */
/*   Updated: 2023/06/11 05:39:54 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	ft_light_cordcheck(char **ptr, t_rt *rt)
{
	float	x;
	float	y;
	float	z;

	if (ptr != NULL && mtx_len(ptr) == 3)
	{
		x = ft_atof(ptr[0]);
		y = ft_atof(ptr[1]);
		z = ft_atof(ptr[2]);
		if (x == 1337 || y == 1337 || z == 1337)
		{
			ft_exit("Error: atof\n", 2);
		}
		rt->lt->crd.x = x;
		rt->lt->crd.y = y;
		rt->lt->crd.z = z;
	}
}

void	ft_light_coordination(char *string, t_rt *rt)
{
	char	**ptr;

	ptr = ft_split(string, ',');
	if (ptr != NULL && mtx_len(ptr) == 3)
	{
		ft_light_cordcheck(ptr, rt);
		rt->lt->crd.x = ft_atof(ptr[0]);
		rt->lt->crd.y = ft_atof(ptr[1]);
		rt->lt->crd.z = ft_atof(ptr[2]);
		deallocate(ptr);
	}
	else
		ft_exit("Error: Invalid light coordinates\n", 1);
}
