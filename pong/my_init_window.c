/*
** my_init_window.c for my_init_window.c in /home/dams/delivery/Igraph/raytracer1/
**
** Made by Damien Laurent
** Login   <damien.laurent@epitech.eu@epitech.eu>
**
** Started on  Sat Mar 18 15:23:55 2017 Damien Laurent
** Last update Wed Apr  5 19:31:18 2017 Damien Laurent
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <unistd.h>
#include "pong.h"

sfRenderWindow*		create_window(char *name, t_my_framebuffer *framebuffer)
{
  sfRenderWindow	*window;
  sfVideoMode		mode;

  mode.width = framebuffer->width;
  mode.height = framebuffer->height;
  mode.bitsPerPixel = 32;
  window = sfRenderWindow_create(mode, name, sfResize | sfClose, NULL);
  if (window == NULL)
    return (0);
  return (window);
}

sfUint8*		my_framebuffer_create(int width, int height,
					      t_my_framebuffer *framebuffer)
{
  int			i;

  i = 0;
  framebuffer->pixels = malloc(width * height * 4 *
			       sizeof(framebuffer->pixels));
  if (framebuffer->pixels == NULL)
    return (0);
  while (i < width * height * 4)
    {
      framebuffer->pixels[i] = 0;
      i++;
    }
  return (framebuffer->pixels);
}

void			init_framebuffer(t_my_framebuffer *framebuffer, char *name)
{
  framebuffer->width = FRAMEBUFFER_WIDTH;
  framebuffer->height = FRAMEBUFFER_HEIGHT;
  framebuffer->name = name;
}
