/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghanquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 14:40:59 by ghanquer          #+#    #+#             */
/*   Updated: 2022/09/05 16:15:15 by nflan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

int	hook(int keycode, t_info *info)
{
	if (keycode == 65361)
		info->hook.cam_left = 1;
	if (keycode == 65363)
		info->hook.cam_right = 1;
	if (keycode == 65362)
		info->hook.forward = 1;
	if (keycode == 65364)
		info->hook.backward = 1;
	if (keycode == 97)
		info->hook.left = 1;
	if (keycode == 100)
		info->hook.right = 1;
	if (keycode == 119)
		info->hook.forward = 1;
	if (keycode == 115)
		info->hook.backward = 1;
	if (keycode == 109)
		ft_map(info);
	if (keycode == 65307)
		ft_closewin(info, 0);
	if (keycode == 101)
		open_door(info);
	return (0);
}

int	hook_release(int keycode, t_info *info)
{
	if (keycode == 65361)
		info->hook.cam_left = 0;
	if (keycode == 65363)
		info->hook.cam_right = 0;
	if (keycode == 65362)
		info->hook.forward = 0;
	if (keycode == 65364)
		info->hook.backward = 0;
	if (keycode == 97)
		info->hook.left = 0;
	if (keycode == 100)
		info->hook.right = 0;
	if (keycode == 119)
		info->hook.forward = 0;
	if (keycode == 115)
		info->hook.backward = 0;
	return (0);
}

void	mouse_move(t_info *info)
{
	if (info->hook.mouse_hold == 1)
	{
		if (info->hook.mouse_prev_pos != info->hook.mouse_pos)
		{
			info->player.angle -= ((double)(info->hook.mouse_prev_pos
						- info->hook.mouse_pos) * ((double)M_PI / 2))
				/ (double)info->w;
			if (info->player.angle - (2 * M_PI) < 0.001
				&& info->player.angle - (2 * M_PI) > -0.001)
				info->player.angle = 0;
			info->hook.mouse_prev_pos = info->hook.mouse_pos;
		}
	}
}

int	looping_hook(t_info *info)
{
	mouse_move(info);
	if (info->map[(int)info->player.y][(int)info->player.x] == 'X')
		ft_closewin(info, 0);
	if (info->hook.cam_left && !info->hook.cam_right)
		turn_left(info);
	if (info->hook.cam_right && !info->hook.cam_left)
		turn_right(info);
	if ((info->hook.forward) && (!info->hook.backward))
		mv_for(info);
	if ((info->hook.backward) && (!info->hook.forward))
		mv_back(info);
	if (info->hook.left && !info->hook.right)
		mv_left(info);
	if (info->hook.right && !info->hook.left)
		mv_right(info);
	tracing_again(info);
	return (0);
}
