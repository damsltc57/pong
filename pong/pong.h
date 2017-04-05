/*
** tek.h for tek.h in /home/dams/delivery/Igraph/Tekadventure/
**
** Made by Damien Laurent
** Login   <damien.laurent@epitech.eu@epitech.eu>
**
** Started on  Tue Mar 21 10:03:53 2017 Damien Laurent
** Last update Wed Apr  5 20:09:49 2017 Damien Laurent
*/
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#ifndef TEK_H
#define TEK_H
#define	FRAMEBUFFER_WIDTH 800
#define FRAMEBUFFER_HEIGHT 900
#define SPEED 0.4

typedef struct		s_my_framebuffer
{
  sfUint8*		pixels;
  int			width;
  int			height;
  char			*name;
}			t_my_framebuffer;

sfRenderWindow*		create_window(char *name, t_my_framebuffer *framebuffer);
sfUint8*		my_framebuffer_create(int width, int height, t_my_framebuffer *framebuffer);
void			init_framebuffer(t_my_framebuffer *framebuffer, char *name);
int		process_game_loop(sfRenderWindow *window, sfSprite *sprite,
				  t_my_framebuffer *framebuffer, sfTexture *texture);
sfVector2f	move_player(sfVector2f player);

#endif /*TEK_H*/
