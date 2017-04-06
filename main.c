/*
** main.c for main.c in /home/dams/delivery/Igraph/raytracer1/
**
** Made by Damien Laurent
** Login   <damien.laurent@epitech.eu@epitech.eu>
**
** Started on  Fri Feb 17 11:24:17 2017 Damien Laurent
** Last update Thu Apr  6 02:35:50 2017 John Doe
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
  t_score               score;

  score.player = 0;
  score.ia = 0;
  score.level = 1;
  window = create_window("Tekadventure", framebuffer);
  sprite = sfSprite_create();
  texture = sfTexture_create(FRAMEBUFFER_WIDTH, FRAMEBUFFER_HEIGHT);
  sfSprite_setTexture(sprite, texture, sfTrue);
  framebuffer->pixels = my_framebuffer_create(FRAMEBUFFER_WIDTH,
	 FRAMEBUFFER_HEIGHT, framebuffer);
  process_game_loop(window, &score);
  sfRenderWindow_destroy(window);
  return (0);
}

int	main(int ac, char **av)
{
  (void)ac;
  t_my_framebuffer framebuffer;
  init_framebuffer(&framebuffer, av[1]);
  sec(&framebuffer);
  return (0);
}



int		process_game_loop(sfRenderWindow *window, t_score *score)
{
  sfEvent	event;
  sfVector2f	player;
  sfTexture	*texture_bar;
  sfSprite	*sprite_bar;
  sfTexture	*texture_balle;
  sfSprite	*sprite_balle;
  sfVector2f     balle;
  sfVector2f     balle_dir;
  sfVector2f     ia;
  sfSprite       *sprite_ia;
  sfFont          *font;
  sfText          *text;

  balle_dir.x = 0.2;
  balle_dir.y = 0.3;
  player.x = 700;
  player.y = 850;
  balle.x = 200;
  balle.y = 200;
  ia.x = 200;
  ia.y = 20;
  font = sfFont_createFromFile("FunSized.ttf");
  text = sfText_create();
  texture_bar = sfTexture_createFromFile("barre.png", NULL);
  sprite_bar = sfSprite_create();
  sfSprite_setTexture(sprite_bar, texture_bar, sfTrue);
  sfSprite_setPosition(sprite_bar, player);
  sprite_ia = sfSprite_create();
  sfSprite_setTexture(sprite_ia, texture_bar, sfTrue);
  texture_balle = sfTexture_createFromFile("balle.png", NULL);
  sprite_balle = sfSprite_create();
  sfSprite_setTexture(sprite_balle, texture_balle, sfTrue);
  sfSprite_setPosition(sprite_balle, balle);
  sfSprite_setPosition(sprite_ia, ia);
  while (sfRenderWindow_isOpen(window))
    {
      while (sfRenderWindow_pollEvent(window, &event))
	{
	  if (event.type == sfEvtClosed)
	    sfRenderWindow_close(window);
	}
      sfRenderWindow_clear(window, sfWhite);
      // sfRenderWindow_drawSprite(window, sprite, NULL);
      rebondir(&balle, &balle_dir, &player, &ia, score);
      move_ball(&balle, &balle_dir);
      increase_level(score);
      ia_play(balle, &ia, score);
      player = move_player(player);
      sfSprite_setPosition(sprite_bar, player);
      sfSprite_setPosition(sprite_balle, balle);
      sfSprite_setPosition(sprite_ia, ia);
      draw_score(score, window, font, text);
      sfRenderWindow_drawSprite(window, sprite_ia, NULL);
      sfRenderWindow_drawSprite(window, sprite_balle, NULL);
      sfRenderWindow_drawSprite(window, sprite_bar, NULL);
      sfRenderWindow_display(window);
      // sfTexture_updateFromPixels(texture, framebuffer->pixels,
				//  FRAMEBUFFER_WIDTH, FRAMEBUFFER_HEIGHT, 0, 0);
    }
  return (0);
}
