/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 12:29:23 by nbouljih          #+#    #+#             */
/*   Updated: 2023/06/11 05:42:35 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

char	*search_string(char **array, const char *needle)
{
	int	i;
	int	num_str;

	i = 0;
	num_str = mtx_len(array);
	while (i < num_str)
	{
		if (!ft_strncmp(array[i], needle, ft_strlen(needle)))
			return (array[i]);
		i++;
	}
	return (NULL);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}
