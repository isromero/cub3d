/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 08:57:02 by isromero          #+#    #+#             */
/*   Updated: 2023/12/06 14:09:41 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_map *map, int x, int y, int color)
{
	char	*dst;

	dst = map->img->addr + (y * map->img->line_length + x * (map->img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
/* void	draw_slice(t_map *map, int x, int projected_slice_height)
{
	int ceiling_height = (map->screen_height - projected_slice_height) / 2;
    int floor_height = map->screen_height - ceiling_height;

    // Dibuja el techo
    for (int y = 0; y < ceiling_height; y++)
        mlx_pixel_put(map->mlx_ptr, map->win_ptr, x, y, 0x003333);

    // Dibuja el muro
    for (int y = ceiling_height; y < floor_height; y++)
        mlx_pixel_put(map->mlx_ptr, map->win_ptr, x, y, 0x00FFFFFF);

    // Dibuja el suelo
    for (int y = floor_height; y < map->screen_height; y++)
        mlx_pixel_put(map->mlx_ptr, map->win_ptr, x, y, 0x00FF00);
} */

// void load_texture(t_map *map, char *path)
// {
//     map->texture->img = mlx_xpm_file_to_image(map->mlx_ptr, path, &map->texture->width, &map->texture->height);
//     if (!map->texture->img)
//     {
//         // Manejar el error al cargar la textura
//         perror("Error cargando la textura");
//         exit(EXIT_FAILURE);
//     }

//     map->texture->addr = mlx_get_data_addr(map->texture->img, &map->texture->bits_per_pixel, &map->texture->line_length, &map->texture->endian);
// }

// int get_texture_pixel_color(t_map *map, int x, int y)
// {
//     char *color = map->texture->addr + (y * map->texture->line_length + x * (map->texture->bits_per_pixel / 8));

//     // Utilizamos máscaras para extraer los componentes RGBA
//     unsigned char red = (unsigned char)color[0];
//     unsigned char green = (unsigned char)color[1];
//     unsigned char blue = (unsigned char)color[2];
//     unsigned char alpha = (unsigned char)color[3];

//     // Combinamos los componentes para obtener el color en formato RGBA
//     return (alpha << 24) | (red << 16) | (green << 8) | blue;
// }


// void draw_vertical_line_with_texture(t_map *map, int x, int start_y, int end_y, int texture_y)
// {
//     for (int y = start_y; y < end_y; y++)
//     {
//         int pixel = (y * map->img->line_length) + (x * 4);

//         // Asegurarse de que la coordenada de textura esté en el rango de la imagen de textura
//         int texture_x = (int)((double)x / (double)map->screen_width * map->texture->width);
//         if (texture_x >= map->texture->width)
//             texture_x = map->texture->width - 1;

//         int texture_color = get_texture_pixel_color(map, texture_x, texture_y);

//         map->img->addr[pixel + 0] = (texture_color >> 24);
//         map->img->addr[pixel + 1] = (texture_color >> 16) & 0xFF;
//         map->img->addr[pixel + 2] = (texture_color >> 8) & 0xFF;
//         map->img->addr[pixel + 3] = (texture_color) & 0xFF;
//     }
// }


// void draw_image(t_map *map, int x, int projected_slice_height)
// {
//     int color_sky = 0xABCDEF;

//     if (map->img->bits_per_pixel != 32)
//         color_sky = mlx_get_color_value(map->mlx_ptr, color_sky);

//     int color_floor = 0x00FF00;

//     if (map->img->bits_per_pixel != 32)
//         color_floor = mlx_get_color_value(map->mlx_ptr, color_floor);

//     int ceiling_height = (map->screen_height - projected_slice_height) / 2;
//     int floor_height = map->screen_height - ceiling_height;
// 	load_texture(map, map->no);
//     for (int y = 0; y < ceiling_height; y++)
//     {
//         int pixel = (y * map->img->line_length) + (x * 4);

//         if (map->img->endian == 1)
//         {
//             map->img->addr[pixel + 0] = (color_sky >> 24);
//             map->img->addr[pixel + 1] = (color_sky >> 16) & 0xFF;
//             map->img->addr[pixel + 2] = (color_sky >> 8) & 0xFF;
//             map->img->addr[pixel + 3] = (color_sky) & 0xFF;
//         }
//         else if (map->img->endian == 0)
//         {
//             map->img->addr[pixel + 0] = (color_sky) & 0xFF;
//             map->img->addr[pixel + 1] = (color_sky >> 8) & 0xFF;
//             map->img->addr[pixel + 2] = (color_sky >> 16) & 0xFF;
//             map->img->addr[pixel + 3] = (color_sky >> 24);
//         }
//     }

//     for (int y = ceiling_height; y < floor_height; y++)
//     {
//         // Calcular las coordenadas de textura en función de la altura de la pared proyectada
//         double texture_scale = (double)(y - ceiling_height) / (double)(floor_height - ceiling_height);
//         int texture_y = (int)(texture_scale * map->texture->height);

//         draw_vertical_line_with_texture(map, x, y, floor_height, texture_y);
//     }

//     for (int y = floor_height; y < map->screen_height; y++)
//     {
//         int pixel = (y * map->img->line_length) + (x * 4);

//         if (map->img->endian == 1)
//         {
//             map->img->addr[pixel + 0] = (color_floor >> 24);
//             map->img->addr[pixel + 1] = (color_floor >> 16) & 0xFF;
//             map->img->addr[pixel + 2] = (color_floor >> 8) & 0xFF;
//             map->img->addr[pixel + 3] = (color_floor) & 0xFF;
//         }
//         else if (map->img->endian == 0)
//         {
//             map->img->addr[pixel + 0] = (color_floor) & 0xFF;
//             map->img->addr[pixel + 1] = (color_floor >> 8) & 0xFF;
//             map->img->addr[pixel + 2] = (color_floor >> 16) & 0xFF;
//             map->img->addr[pixel + 3] = (color_floor >> 24);
//         }
//     }
// }



void	draw_image(t_map *map, int x, int projected_slice_height)
{
	int color_sky = 0xABCDEF;

	if (map->img->bits_per_pixel != 32)
		color_sky = mlx_get_color_value(map->mlx_ptr, color_sky);

	int color_wall = 0x00AA0000;

	if (map->img->bits_per_pixel != 32)
		color_wall = mlx_get_color_value(map->mlx_ptr, color_wall);

	int color_floor = 0x00FF00;

	if (map->img->bits_per_pixel != 32)
		color_floor = mlx_get_color_value(map->mlx_ptr, color_floor);
	int ceiling_height = (map->screen_height - projected_slice_height) / 2;
	int floor_height = map->screen_height - ceiling_height;
	
	for (int y = 0; y < ceiling_height; y++)
	{
		int pixel = (y * map->img->line_length) + (x * 4);
		

		if (map->img->endian == 1)
		{
			map->img->addr[pixel + 0] = (color_sky >> 24);
			map->img->addr[pixel + 1] = (color_sky >> 16) & 0xFF;
			map->img->addr[pixel + 2] = (color_sky >> 8) & 0xFF;
			map->img->addr[pixel + 3] = (color_sky) & 0xFF;
		}
		else if (map->img->endian == 0)
		{
			map->img->addr[pixel + 0] = (color_sky) & 0xFF;
			map->img->addr[pixel + 1] = (color_sky >> 8) & 0xFF;
			map->img->addr[pixel + 2] = (color_sky >> 16) & 0xFF;
			map->img->addr[pixel + 3] = (color_sky >> 24);
		}
	}

	for (int y = ceiling_height; y < floor_height; y++)
	{
		int pixel = (y * map->img->line_length) + (x * 4);
		
		if (map->img->endian == 1)
		{
			map->img->addr[pixel + 0] = (color_wall >> 24);
			map->img->addr[pixel + 1] = (color_wall >> 16) & 0xFF;
			map->img->addr[pixel + 2] = (color_wall >> 8) & 0xFF;
			map->img->addr[pixel + 3] = (color_wall) & 0xFF;
		}
		else if (map->img->endian == 0)
		{
			map->img->addr[pixel + 0] = (color_wall) & 0xFF;
			map->img->addr[pixel + 1] = (color_wall >> 8) & 0xFF;
			map->img->addr[pixel + 2] = (color_wall >> 16) & 0xFF;
			map->img->addr[pixel + 3] = (color_wall >> 24);
		}
	}

	for (int y = floor_height; y < map->screen_height; y++)
	{
		int pixel = (y * map->img->line_length) + (x * 4);
		
		if (map->img->endian == 1)
		{
			map->img->addr[pixel + 0] = (color_floor >> 24);
			map->img->addr[pixel + 1] = (color_floor >> 16) & 0xFF;
			map->img->addr[pixel + 2] = (color_floor >> 8) & 0xFF;
			map->img->addr[pixel + 3] = (color_floor) & 0xFF;
		}
		else if (map->img->endian == 0)
		{
			map->img->addr[pixel + 0] = (color_floor) & 0xFF;
			map->img->addr[pixel + 1] = (color_floor >> 8) & 0xFF;
			map->img->addr[pixel + 2] = (color_floor >> 16) & 0xFF;
			map->img->addr[pixel + 3] = (color_floor >> 24);
		}
	}
}

int find_vertical_intersection(t_map *map, double ray_x, double ray_y, double angle)
{
	double tan_value = (tan(angle));
	double face = ray_x + (100.0 * cos(angle));
	int grid_y = 0;
	int grid_x = 0;
	map->line->line_v.intersection_x = 0;
	map->line->line_v.intersection_y = 0;

	if (face <= ray_x) // El rayo mira hacia la derecha
	{
		map->line->line_v.intersection_x = floor(ray_x / 64) * (64) - 1;
		map->line->line_v.xa = -64;
		map->line->line_v.ya = (64 * tan_value) * -1;
	}
	else// el rayo mira hacia izquierda
	{
		map->line->line_v.intersection_x = floor(ray_x / 64) * (64) + 64;
		map->line->line_v.xa = 64;
		map->line->line_v.ya = 64 * tan_value;
	}
	/* if (tan_value != 0 && angle !=  4.712389) */
		map->line->line_v.intersection_y = ray_y - (ray_x - map->line->line_v.intersection_x) * tan_value;
	/* else
		return 0; */
	int i = -1;
	while (++i <= map->x)
	{
		grid_y = floor(map->line->line_v.intersection_y) / 64;
		grid_x = floor(map->line->line_v.intersection_x) / 64;

		if (grid_y >= 0 && grid_y < map->y && grid_x >= 0 && grid_x < (int)ft_strlen(map->map[grid_y]))
		{
			if (map->map[grid_y][grid_x] == '1')
			{
				map->line->line_v.perp_dist = fabs(sqrt(pow(ray_x - map->line->line_v.intersection_x, 2) + pow(ray_y - map->line->line_v.intersection_y, 2)));
				// Para el fish eye
				//map->line->line_v.correct_dist = map->line->line_v.perp_dist * cos(angle); 
				return 1;
			}
		}
		// Actualizar coordenadas solo si no hay colisión
		map->line->line_v.intersection_x += map->line->line_v.xa;
		map->line->line_v.intersection_y += map->line->line_v.ya;
	
    }
	return 0; // Nunca debería llegar aquí, ya que la función siempre debería salir con una colisión
}



//SE VE MAS O MENOS IGUL CON EL FABS EN LA SQRT , NO SE SI DEJARLO

int find_horizontal_intersection(t_map *map, double ray_x, double ray_y, double angle)
{
	double tan_value = (tan(angle));
	double face = ray_y + (100 * sin(angle));
	//printf("path textura: %s\n", map->no);
	int grid_y = 0;
	int grid_x = 0;
	map->line->line_h.intersection_y = 0;
	map->line->line_h.intersection_x = 0;
	if (face <= ray_y) // El rayo mira hacia arriba
	{	
		map->line->line_h.intersection_y = floor(ray_y / 64) * (64) - 1;
		map->line->line_h.ya = -64;
		map->line->line_h.xa = (64 / tan_value) * -1;
	}
	else// El rayo mira hacia abajo
	{
		map->line->line_h.intersection_y = floor(ray_y / 64) * (64) + 64;
		map->line->line_h.ya = 64;
		map->line->line_h.xa = 64 / tan_value;
	}
	/* if (tan_value != 0 && angle !=  4.712389) */
		map->line->line_h.intersection_x = ray_x - (ray_y - map->line->line_h.intersection_y) / tan_value;
	/* else
		return 0; */
	
	int i = -1;
	while (++i <= map->y)
	{
		grid_y = floor(map->line->line_h.intersection_y) / 64;
		grid_x = floor(map->line->line_h.intersection_x) / 64;
		if (grid_y >= 0 && grid_y < map->y && grid_x >= 0 && grid_x < (int)ft_strlen(map->map[grid_y]))
		{
			if (map->map[grid_y][grid_x] == '1')
			{
				map->line->line_h.perp_dist = fabs(sqrt(pow(ray_x - map->line->line_h.intersection_x, 2) + pow(ray_y - map->line->line_h.intersection_y, 2)));
				// Para el fish eye
				//map->line->line_h.correct_dist = map->line->line_h.perp_dist * cos(angle);
				return 1;
			}
		}
		// Actualizar coordenadas solo si no hay colisión
		map->line->line_h.intersection_x += map->line->line_h.xa;
		map->line->line_h.intersection_y += map->line->line_h.ya;
    }
	return 0;
}

int	raycast(t_map *map)
{
	int		projected_slice_height;
	double 	angle;
	double 	initial_angle;
	
	map->ray->current_col = -1;
	projected_slice_height = 0;
	initial_angle = map->ray->angle - (30.0 * M_PI / 180.0);
	angle = initial_angle;
	if (angle < 0.0 && angle >= -M_PI * 2.0)
		angle += M_PI * 2.0;
	
	while(++map->ray->current_col < map->screen_width)
	{
		find_horizontal_intersection(map, (map->player->x) * 64.0, (map->player->y) * 64.0, angle);
		find_vertical_intersection(map, (map->player->x) * 64.0, (map->player->y) * 64.0, angle);
		if (map->line->line_h.perp_dist <= map->line->line_v.perp_dist)
			projected_slice_height = floor((64.0 / map->line->line_h.perp_dist) * map->ray->dist_player_projection_plane);
		else if (map->line->line_h.perp_dist > map->line->line_v.perp_dist)
			projected_slice_height = floor((64.0 / map->line->line_v.perp_dist) * map->ray->dist_player_projection_plane);
        if (projected_slice_height > map->screen_height)
            projected_slice_height = map->screen_height;
		draw_image(map, map->ray->current_col, projected_slice_height);
		angle += map->ray->angle_between_rays;
		
	}
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img->img, 0, 0);
	return 0;
}
