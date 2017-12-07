/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 11:35:45 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/07 16:08:55 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	init_render_env(t_env *e)
{
	e->avoid = NULL;
	perlin_generate(e);
	perlin_generate_perm((int *)&e->perm_x);
	perlin_generate_perm((int *)&e->perm_y);
	perlin_generate_perm((int *)&e->perm_z);
	e->increment = 4;
	e->recursion = 1;
	e->rot_speed = ROT_SPEED;
	e->move_speed = MOVE_SPEED;
	e->rebond = 0.8;
	e->sum = 1;
	e->live = 1;
	e->threads = 32;
	e->magic = MAGIC;
	e->skybox_total = TOTAL_SKYBOX;
	e->obj_tx_total = TOTAL_TX;
	e->tsp_tx_total = TOTAL_TSP;
}
