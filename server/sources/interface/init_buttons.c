/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_buttons.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 12:29:58 by itonoli-          #+#    #+#             */
/*   Updated: 2017/12/06 18:34:18 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static void init_topin_rect(t_env *e)
{
	int i;

	i = -1;
	while (++i < 3)
	{
		e->topin_rect[i].x = 269 + (i * 98);
		e->topin_rect[i].y = 16;
		e->topin_rect[i].w = 86;
		e->topin_rect[i].h = 42;
	}
}

static void init_bt_rect(t_env *e)
{
	int i;

	i = -1;
	while (++i < 8)
	{
			e->bt_rect[i].x = (i < 5) ? 582 + (66 * i) : 587 + (66 * i);
			e->bt_rect[i].y = 16;
			e->bt_rect[i].w = 44;
			e->bt_rect[i].h = 42;

	}
	e->bt_rect[i].x = 1135;
	e->bt_rect[i].y = 16;
	e->bt_rect[i].w = 142;
	e->bt_rect[i].h = 42;
}

static void init_b_rect(t_env *e)
{
	int i;

	i = -1;
	while (++i < 8)
	{
			e->b_rect[i].x = 15;
			e->b_rect[i].y = (i < 5) ? 116 + (59 * i) : 128 + (59 * i);
			e->b_rect[i].w = 50;
			e->b_rect[i].h = 47;
	}
	e->b_rect[i].x = 23;
	e->b_rect[i].y = 670;
	e->b_rect[i].w = 35;
	e->b_rect[i].h = 35;
}

static void init_i_rect(t_env *e)
{
	int i;

	i = -1;
	while (++i < 10)
	{
		e->i_rect[i].x = 1134;
		e->i_rect[i].w = 145;
		if (i < 6)
		{
			e->i_rect[i].y = 120 + (37 * i);
			e->i_rect[i].h = 25;
		}
		else
		{
			e->i_rect[i].y = 349 + (66 * (i - 6));
			e->i_rect[i].h = 46;
		}
	}
}

static void init_it_rect(t_env *e)
{
	e->it_rect[1].x = 1137;
	e->it_rect[1].y = 370;
	e->it_rect[1].w = 43;
	e->it_rect[1].h = 21;
}


void init_rects(t_env *e)
{
	init_b_rect(e);
	init_bt_rect(e);
	init_i_rect(e);
	init_topin_rect(e);
	e->help_rect = (SDL_Rect){707, 294, 350, 400};
}
