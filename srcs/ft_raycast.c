/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edessain <edessain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 14:07:36 by edessain          #+#    #+#             */
/*   Updated: 2020/06/12 12:00:24 by evrard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		ft_keyboard(int keycode, t_data *data)
{
	if (keycode == 53)
		exit(1);
	if (keycode == 126 || keycode == 13)
	{
		if (data->parse.map[(int)(data->rec.posX + data->rec.dirX * data->rec.speed)][(int)data->rec.posY] != '1')
			data->rec.posX += data->rec.dirX * data->rec.speed;
		if (data->parse.map[(int)data->rec.posX][(int)(data->rec.posY + data->rec.dirY * data->rec.speed)] != '1')
			data->rec.posY += data->rec.dirY * data->rec.speed;
	}
	if (keycode == 125 || keycode == 1)
	{
		if (data->parse.map[(int)(data->rec.posX - data->rec.dirX * data->rec.speed)][(int)data->rec.posY] != '1')
			data->rec.posX -= data->rec.dirX * data->rec.speed;
		if (data->parse.map[(int)data->rec.posX][(int)(data->rec.posY - data->rec.dirY * data->rec.speed)] != '1')
			data->rec.posY -= data->rec.dirY * data->rec.speed;
	}
	if (keycode == 123 || keycode == 0)
	{
		data->rec.olddirX = data->rec.dirX;
		data->rec.dirX = data->rec.dirX * cos(-data->rec.rotation) - data->rec.dirY * sin(-data->rec.rotation);
		data->rec.dirY = data->rec.olddirX * sin(-data->rec.rotation) + data->rec.dirY * cos(-data->rec.rotation);
		data->rec.oldplaneX = data->rec.planeX;
		data->rec.planeX = data->rec.planeX * cos(-data->rec.rotation) - data->rec.planeY * sin(-data->rec.rotation);
		data->rec.planeY = data->rec. oldplaneX * sin(-data->rec.rotation) + data->rec.planeY * cos(-data->rec.rotation);
	}
	if (keycode == 124 || keycode == 2)
	{
		data->rec.olddirX = data->rec.dirX;
		data->rec.dirX = data->rec.dirX * cos(data->rec.rotation) - data->rec.dirY * sin(data->rec.rotation);
		data->rec.dirY = data->rec.olddirX * sin(data->rec.rotation) + data->rec.dirY * cos(data->rec.rotation);
		data->rec.oldplaneX = data->rec.planeX;
		data->rec.planeX = data->rec.planeX *  cos(data->rec.rotation) - data->rec.planeY * sin(data->rec.rotation);
		data->rec.planeY = data->rec.oldplaneX * sin(data->rec.rotation) + data->rec.planeY * cos(data->rec.rotation);
	}
	mlx_clear_window(data->mlx.mlx_ptr, data->mlx.mlx_win);
	ft_start_algo(data);
	mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.mlx_win, data->dis.img, 0, 0);
	return (0);
}

void	ft_start_algo(t_data *data)
{
//	data->rec.dirX = -1;
//	data->rec.dirY = 0;
//	data->rec.planeX = 0;
//	data->rec.planeY = 0.66;
	start_raycasting(data);
}

void	*start_raycasting(t_data *data)
{
	//data->dis.color_sky = 65536 * 200 + 256 * 200 + 25;
	//data->dis.color_n = 65536 * 200 + 256 * 50 + 25;
	//data->dis.color_s = 65536 * 150 + 256 * 100 + 25;
	//data->dis.color_e = 65536 * 100 + 256 * 150 + 25;
	//data->dis.color_w = 65536 * 50 + + 256 * 200 + 25;
	//data->dis.color_floor = 65536 * 200 + 256 * 175 + 150;

	int		x;
	x = 0;
	while (x < data->parse.r1)
	{
		data->rec.hit = 0;
		ray_and_deltadist(x, data);
		step_and_sidedist(data);
		perform_dda(data);
		calculate_dist(data);
		calculate_height(data);
		calculate_textures(data);
		calculate_colors(data);
		ft_verline(x, data);
		x++;
	}
	mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.mlx_win, data->dis.img, 0, 0);
	return (NULL);
}

void	ft_verline(int x, t_data *data)
{
	int y;
	y = 0;
	while (y < data->rec.drawstart)
	{
		data->dis.addr[y * data->parse.r1 + x] = data->parse.c;
		y++;
	}
	while (y < data->rec.drawend)
	{
		data->dis.texy = (int)data->dis.texpos & (data->dis.texheight - 1);
		data->dis.texpos += data->dis.step;
		data->dis.addr[y * data->parse.r1 + x] =
			data->dis.color[data->dis.texy * data->dis.texheight + data->dis.texx];
		y++;
	}
	while (y < data->parse.r2)
	{
		data->dis.addr[y * data->parse.r1 + x] = data->parse.f;
		y++;
	}
}
