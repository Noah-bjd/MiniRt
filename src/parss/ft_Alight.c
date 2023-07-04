/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_Alight.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 13:56:33 by nbouljih          #+#    #+#             */
/*   Updated: 2023/06/11 05:37:10 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	ft_alight(char *line, t_rt *rt)
{
	double	ratio;
	char	**ptr;

	rt->al = malloc(sizeof(t_abt_lt));
	if (rt->al == NULL)
		ft_exit("Error: Failed to allocate memory for ambient light\n", 1);
	if (rt->al != NULL)
	{
		ptr = ft_split2(line);
		if (mtx_len(ptr) != 3)
			return (deallocate(ptr), ft_printf("Error : A\n", 2), exit(1));
		ratio = ft_atof(ptr[1]);
		if (ratio < 0.0 || ratio > 1.0)
			ft_exit("Error: AL's Ratio range should be btw [0.0,1.0]\n", 2);
		rt->al->brightness = ratio;
		if (rt->al->brightness == 1337)
			ft_exit("Error: ratio in AL\n", 1);
		ft_rgb_al(ptr[2], rt);
		deallocate(ptr);
	}
	else
		ft_exit("Error: Failed to allocate memory for ambient light\n", 1);
}
