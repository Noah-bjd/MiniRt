/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sp_ut.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 18:31:00 by nbouljih          #+#    #+#             */
/*   Updated: 2023/06/11 05:41:17 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	parse_rgb(char *rgb_string, int *r, int *g, int *b)
{
	char	**rgb_values;

	rgb_values = ft_split(rgb_string, ',');
	if (rgb_values != NULL && mtx_len(rgb_values) == 3)
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
				deallocate(rgb_values);
			}
			else
				ft_exit("Error: Invalid RGB values in sp\n", 2);
		}
		else
			ft_exit("Error: Problem with the RGB length in sp\n", 2);
	}
	else
		ft_exit("Error: RGB problem in sp\n", 2);
}

void	asign_rgb(t_sphere *sp, int r, int g, int b)
{
	sp->clr.r = r;
	sp->clr.g = g;
	sp->clr.b = b;
}

void	ft_sp_rgb(char *rgb_string, t_sphere *sp)
{
	int	r;
	int	g;
	int	b;

	r = 0;
	g = 0;
	b = 0;
	parse_rgb(rgb_string, &r, &g, &b);
	asign_rgb(sp, r, g, b);
}

void	ft_sp_cord(char *string, t_sphere *rt)
{
	char	**ptr;

	ptr = ft_split(string, ',');
	if (ptr != NULL && mtx_len(ptr) == 3)
	{
		if (ft_atof(ptr[0]) != 1337 && ft_atof(ptr[1]) != 1337
			&& ft_atof(ptr[2]) != 1337)
		{
			rt->crd.x = ft_atof(ptr[0]);
			rt->crd.y = ft_atof(ptr[1]);
			rt->crd.z = ft_atof(ptr[2]);
		}
		else
		{
			ft_printf("Error: Invalid sp coordinates\n", 1);
			exit(EXIT_FAILURE);
		}
		deallocate(ptr);
	}
	else
	{
		ft_printf("Error: allocation comming form : [ft_sp_vec]\n", 2);
		exit(1);
	}
}
