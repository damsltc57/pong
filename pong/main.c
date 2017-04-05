/*
** main.c for main.c in /home/dams/delivery/Igraph/raytracer1/
**
** Made by Damien Laurent
** Login   <damien.laurent@epitech.eu@epitech.eu>
**
** Started on  Fri Feb 17 11:24:17 2017 Damien Laurent
** Last update Wed Apr  5 20:06:59 2017 Damien Laurent
*/
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <unistd.h>
#include <stdio.h>
#include "pong.h"

int	sec(t_my_framebuffer *framebuffer)
{
  sfRenderWindow*	window;
  sfTexture*		texture;
  sfSprite*		sprite;

  window = create_window("Tekadventure", framebuffer);
  sprite = sfSprite_create();
  texture = sfTexture_create(FRAMEBUFFER_WIDTH, FRAMEBUFFER_HEIGHT);
  sfSprite_setTexture(sprite, texture, sfTrue);
  framebuffer->pixels = my_framebuffer_create(FRAMEBUFFER_WIDTH,
	 FRAMEBUFFER_HEIGHT, framebuffer);
  process_game_loop(window, sprite, framebuffer, texture);
  sfRenderWindow_destroy(window);
  return (0);
}

int	main(int ac, char **av)
{
  t_my_framebuffer framebuffer;
  init_framebuffer(&framebuffer, av[1]);
  sec(&framebuffer);
  return (0);
}


int		process_game_loop(sfRenderWindow *window, sfSprite *sprite,
				  t_my_framebuffer *framebuffer, sfTexture *texture)
{
  sfEvent	event;
  sfVector2f	player;
  sfTexture	*texture_bar;
  sfSprite	*sprite_bar;

  player.x = 700;
  player.y = 850;
  texture_bar = sfTexture_createFromFile("barre.png", NULL);
  sprite_bar = sfSprite_create();
  sfSprite_setTexture(sprite_bar, texture_bar, sfTrue);
  sfSprite_setPosition(sprite_bar, player);
  while (sfRenderWindow_isOpen(window))
    {
      while (sfRenderWindow_pollEvent(window, &event))
	{
	  if (event.type == sfEvtClosed)
	    sfRenderWindow_close(window);
	}
      sfRenderWindow_clear(window, sfWhite);
      // sfRenderWindow_drawSprite(window, sprite, NULL);
      player = move_player(player);
      sfSprite_setPosition(sprite_bar, player);
      // printf("%f\n", player.y);
      sfRenderWindow_drawSprite(window, sprite_bar, NULL);
      sfRenderWindow_display(window);
      // sfTexture_updateFromPixels(texture, framebuffer->pixels,
				//  FRAMEBUFFER_WIDTH, FRAMEBUFFER_HEIGHT, 0, 0);
    }
  return (0);
}
