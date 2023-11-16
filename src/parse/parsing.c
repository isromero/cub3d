/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adgutier <adgutier@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 18:33:50 by adgutier          #+#    #+#             */
/*   Updated: 2023/10/07 18:33:50 by adgutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	default_error(void)
{
	perror("\033[1;31mERROR\033[0m");
	exit(1);
}

char	**read_map(char *fmap)
{
	int		fd;
	char	*line;
	char	*joined_lines;

	line = "";
	joined_lines = ft_strdup("");
	fd = open(fmap, O_RDONLY);
	if (fd < 0)
		default_error();
	while (line)
	{
		line = get_next_line(fd);
		if (line == NULL || line[0] == '\n')
			break ;
		joined_lines = ft_strjoin(joined_lines, line);
	}
	close(fd);
	if (joined_lines[0] == '\0')
		default_error();
	return (ft_split(joined_lines, '\n'));
}

void	fill_dir(t_map *map)
{
	int		i;
	int		aux;
	int		j;
	int		len;

	i = 1;
	j = 0;
	aux = map->y - 1;
	len = ft_strlen(map->map[i]);
	while (i < aux)
	{
		j = 0;
		len = ft_strlen(map->map[i]);
		while(j < len)
		{
			if (map->map[(int)i][(int)j] == 'N')
			{
				map->player->dir = 'N';
				map->player->x = j + 0.5;
				map->player->y = i + 0.5;
				map->ray->angle = 3 * M_PI / 2.0; // 270º(90º 2d) pero mira al norte -> eje coordenadas Y disminuye según subes
				return ;
			}
			else if (map->map[(int)i][(int)j] == 'S')
			{
				map->player->dir = 'S';
				map->player->x = j + 0.5;
				map->player->y = i + 0.5;
				map->ray->angle = M_PI / 2.0; // 90º(270º 2d) pero mira al sur -> eje coordenadas Y aumenta según bajas
				return ;
			}
        	else if (map->map[(int)i][(int)j] == 'E')
			{
				map->player->dir = 'E';
				map->player->x = j + 0.5;
				map->player->y = i + 0.5;
				map->ray->angle = 0.0; // 0º
				return ;
			}
			else if (map->map[(int)i][(int)j] == 'W')
			{
				map->player->dir = 'W';
				map->player->x = j + 0.5;
				map->player->y = i + 0.5;
				map->ray->angle = M_PI; // 180º
				return ;
			}
			j++;
		}
		i++;
	}
}