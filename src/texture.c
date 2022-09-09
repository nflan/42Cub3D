/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghanquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 11:10:49 by ghanquer          #+#    #+#             */
/*   Updated: 2022/09/01 12:10:46 by nflan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	get_address(t_info *info)
{
	info->texture_n.img.addr = mlx_get_data_addr(info->texture_n.img.img,
			&info->texture_n.img.bits_per_pixel,
			&info->texture_n.img.line_length, &info->texture_n.img.endian);
	info->texture_s.img.addr = mlx_get_data_addr(info->texture_s.img.img,
			&info->texture_s.img.bits_per_pixel,
			&info->texture_s.img.line_length, &info->texture_s.img.endian);
	info->texture_e.img.addr = mlx_get_data_addr(info->texture_e.img.img,
			&info->texture_e.img.bits_per_pixel,
			&info->texture_e.img.line_length, &info->texture_e.img.endian);
	info->texture_w.img.addr = mlx_get_data_addr(info->texture_w.img.img,
			&info->texture_w.img.bits_per_pixel,
			&info->texture_w.img.line_length, &info->texture_w.img.endian);
}

int	get_texture(t_info *info)
{
	info->texture_n.img.img = mlx_xpm_file_to_image(info->mlx,
			info->texture_n.path, &info->texture_n.width,
			&info->texture_n.height);
	info->texture_s.img.img = mlx_xpm_file_to_image(info->mlx,
			info->texture_s.path, &info->texture_s.width,
			&info->texture_s.height);
	info->texture_e.img.img = mlx_xpm_file_to_image(info->mlx,
			info->texture_e.path, &info->texture_e.width,
			&info->texture_e.height);
	info->texture_w.img.img = mlx_xpm_file_to_image(info->mlx,
			info->texture_w.path, &info->texture_w.width,
			&info->texture_w.height);
	if (!info->texture_n.img.img || !info->texture_s.img.img
		|| !info->texture_e.img.img || !info->texture_w.img.img)
		return (ft_putstr_error("Error\nError while opening a texture\n"));
	get_address(info);
	if (!info->texture_n.img.addr || !info->texture_s.img.addr
		|| !info->texture_e.img.addr || !info->texture_w.img.addr)
		return (ft_putstr_error("Error\nError while opening a texture\n"));
	return (0);
}
