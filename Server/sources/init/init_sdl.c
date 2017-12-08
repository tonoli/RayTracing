/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sdl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 04:08:09 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/07 11:50:47 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void		init_sdl_modules(t_env *e)
{
	if (TTF_Init() == -1)
	{
		ft_printf("TTF_Init: %s\n", TTF_GetError());
		exit(EXIT_FAILURE);
	}
	if (SDL_Init(SDL_INIT_VIDEO) == -1)
		fatal_quit("SDL_Init");
}

void		init_sdl_env(t_env *e)
{
	e->win_w = WIN_W;
	e->win_h = WIN_H;
	e->run = 1;
	e->b_actif = -1;
	e->i_actif = -1;
	e->it_actif = -1;
	e->bt_actif = -1;
	e->help_actif = -1;
	e->topin_actif = -1;
	e->loader = 1;
	e->render = 0;
	e->font = (TTF_Font **)ft_memalloc(sizeof(TTF_Font *) * 3);
}

SDL_Surface	*load_img(char *addr)
{
	SDL_Surface *s;

	s = IMG_Load(addr);
	if (!s)
		fatal_quit("IMG_Load");
	return (s);
}

TTF_Font	*load_ttf(char *addr, int size)
{
	TTF_Font *t;

	t = TTF_OpenFont(addr, size);
	if (!t)
		fatal_quit("TTF_OpenFont");
	return (t);
}

void		init_sdl_interface(t_env *e)
{
	if (!(e->win = SDL_CreateWindow("RayTracer", SDL_WINDOWPOS_CENTERED,
								SDL_WINDOWPOS_CENTERED, e->win_w, e->win_h, 0)))
		fatal_quit("SDL_CreateWindow");
	if (!(e->w_icon = IMG_Load("./assets/images/icon.png")))
		fatal_quit("Error Load icon");
	SDL_SetWindowIcon(e->win, e->w_icon);
	e->s_loader = load_img("./assets/images/loader.png");
	e->s_ui = load_img("./assets/images/ui.png");
	e->font[0] = load_ttf("./assets/font/RobotoCondensed-Light.ttf", 15);
	e->font[1] = load_ttf("./assets/font/RobotoCondensed-Regular.ttf", 15);
	e->font[2] = load_ttf("./assets/font/RobotoCondensed-Bold.ttf", 12);
	e->s_background = SDL_GetWindowSurface(e->win);
	e->s_raytracer = SDL_CreateRGBSurface(0, F_WIDTH, F_HEIGHT, 32,
										_R, _G, _B, _A);
	if (!e->s_background || !e->s_raytracer)
		fatal_quit("SDL_GetWindowSurface");
}