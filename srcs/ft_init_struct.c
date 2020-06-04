/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edessain <edessain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 10:23:04 by edessain          #+#    #+#             */
/*   Updated: 2020/06/04 17:26:46 by evrard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void		init_raycasting(t_data *data)
{
	data->rec.posX = 0.0;
	data->rec.posY = 0;
	data->rec.dirX = 0;
	data->rec.dirY = 0;
	data->rec.planeX = 0;
	data->rec.planeY = 0;
	data->rec.oldplaneX = 0;
	data->rec.cameraX = 0;
	data->rec.raydirX = 0;
	data->rec.raydirY = 0;
	data->rec.mapX = 0;
	data->rec.mapY = 0;
	data->rec.sidedistX = 0;
	data->rec.sidedistY = 0;
	data->rec.perpwalldist = 0;
	data->rec.stepX = 0;
	data->rec.stepY = 0;
	data->rec.hit = 0;
	data->rec.side = 0;
	data->rec.lineheight = 0;
	data->rec.drawstart = 0;
	data->rec.drawend = 0;
	data->rec.wallheight = 0;
}

void		init_parse(t_data *data)
{
	data->parse.info = NULL;
	data->parse.map_str = NULL;
	data->parse.map = NULL;
	data->parse.dir = 0;
	data->parse.nb_sprites = 0;
	data->parse.r1 = 0;
	data->parse.r2 = 0;
	data->parse.n_path = 0;
	data->parse.s_path = 0;
	data->parse.w_path = 0;
	data->parse.e_path = 0;
	data->parse.s = 0;
	data->parse.f = 0;
	data->parse.c = 0;
	data->parse.map_h = 0;
	data->parse.map_w = 0;
}

void		init_mlx(t_data *data)
{
	data->mlx.mlx_ptr = 0;
	data->mlx.mlx_win = 0;
}

void		init_dis(t_data *data)
{
	data->dis.addr = 0;
	data->dis.img = 0;
	data->dis.line_length = 0;
	data->dis.endian = 0;
	data->dis.bits_per_pixel = 0;
	data->dis.color_sky = 0;
	data->dis.color_floor = 0;
	data->dis.color_n = 0;
	data->dis.color_s = 0;
	data->dis.color_w = 0;
	data->dis.color_e = 0;
	data->dis.texx = 0;
	data->dis.texy = 0;
	data->dis.texwidth = 0;
	data->dis.texheight = 0;
	data->dis.texpos = 0;
	data->dis.color = 0;
	data->dis.step = 0;
}

void		ft_init_struct(t_data *data)
{
	init_raycasting(data);
	init_dis(data);
	init_mlx(data);
	init_parse(data);
}
