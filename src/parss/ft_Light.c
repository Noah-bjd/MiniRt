/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_Light.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 09:14:09 by nbouljih          #+#    #+#             */
/*   Updated: 2023/06/11 05:44:09 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int	valid_rgb(char **rgb_values, int *r, int *g, int *b)
{
	if (ft_strlen(rgb_values[0]) <= 3 && ft_strlen(rgb_values[1]) <= 3
		&& ft_strlen(rgb_values[2]) <= 3)
	{
		*r = m_ft_atoi(rgb_values[0]);
		*g = m_ft_atoi(rgb_values[1]);
		*b = m_ft_atoi(rgb_values[2]);
		if (*r >= 0 && *r <= 255 && *g >= 0 && *g <= 255 && *b >= 0
			&& *b <= 255)
		{
			return (1);
		}
		else
		{
			ft_exit("Error: In light's values of RGB\n", 1);
		}
	}
	else
	{
		ft_exit("Error: Problem with the RGB len in L\n", 1);
	}
	return (0);
}

static void	assign_rgb(t_rt *rt, int r, int g, int b)
{
	rt->lt->clr.r = r;
	rt->lt->clr.g = g;
	rt->lt->clr.b = b;
}

void	ft_rgb_l(char *string, t_rt *rt)
{
	int		r;
	int		g;
	int		b;
	char	**ptr;

	r = 0;
	g = 0;
	b = 0;
	ptr = ft_split(string, ',');
	if (ptr != NULL && mtx_len(ptr) == 3)
	{
		if (valid_rgb(ptr, &r, &g, &b))
			assign_rgb(rt, r, g, b);
		deallocate(ptr);
	}
	else
		ft_exit("Error: RGB problem in light\n", 1);
}

void	ft_light(char *tmp, t_rt *rt)
{
	char	**ptr;

	rt->lt = malloc(sizeof(t_light));
	if (!rt->lt)
		ft_exit("Error: Failed to allocate memory for light\n", 1);
	if (rt->lt != NULL)
	{
		ptr = ft_split2(tmp);
		if (mtx_len(ptr) != 4)
			return (deallocate(ptr), ft_printf("Error : L\n", 2), exit(1));
		ft_light_coordination(ptr[1], rt);
		if (ft_atof(ptr[2]) == 1337)
			ft_exit("Error: check  brightness of the light\n", 2);
		rt->lt->bright = ft_atof(ptr[2]);
		if (rt->lt->bright < 0.0 || rt->lt->bright > 1.0)
			ft_exit("Error:light brightness'ratio range [0.0,1.0]\n", 1);
		ft_rgb_l(ptr[3], rt);
		deallocate(ptr);
	}
}
