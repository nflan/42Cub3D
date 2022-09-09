/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghanquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 14:40:59 by ghanquer          #+#    #+#             */
/*   Updated: 2022/09/05 12:19:38 by ghanquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

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
	if (keycode == 65307)
		ft_closewin(info, 0);
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

int	looping_hook(t_info *info)
{
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
