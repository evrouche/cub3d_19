/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_sprt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edessain <edessain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 17:14:21 by edessain          #+#    #+#             */
/*   Updated: 2020/10/12 17:35:59 by edessain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		ft_malloc_sprt(t_data *data)
{
	if (!(data->spr.sprites_x =
		malloc(sizeof(int *) * data->spr.nbsprites + 2)))
	{
		write(1, "Error\n", 6);
		write(1, "Can't malloc the sprite", 23);
		exit_all(data);
		return (-1);
	}
	if (!(data->spr.sprites_y =
		malloc(sizeof(int *) * data->spr.nbsprites + 2)))
	{
		write(1, "Error\n", 6);
		write(1, "Can't malloc the sprite", 23);
		exit_all(data);
		return (-1);
	}
	return (0);
}

void	ft_get_sprites(t_data *data)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (data->parse.map[i] != 0)
	{
		j = 0;
		while (data->parse.map[i][j] != 0)
		{
			if (data->parse.map[i][j] == '2')
			{
				data->spr.sprites_x[k] = j + 0.5;
				data->spr.sprites_y[k] = i + 0.5;
				k++;
			}
			j++;
		}
		i++;
	}
	data->spr.sprites_x[k] = '\0';
	data->spr.sprites_y[k] = '\0';
}

int		ft_get_sprt(t_data *data)
{
	int		i;

	i = 0;
	if (ft_malloc_sprt(data) == -1)
		return (-1);
	ft_get_sprites(data);
	return (0);
}
