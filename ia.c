/*
** ia.c for ia.c in /home/dams/perso/pong/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Thu Apr  6 01:22:57 2017 John Doe
** Last update Thu Apr  6 02:44:35 2017 John Doe
*/
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <unistd.h>
#include <stdio.h>
#include "pong.h"

void     ia_play(sfVector2f balle, sfVector2f *ia, t_score *score)
{
  if (balle.x > ia->x)
    ia->x += 0.1 * score->level;
  if (balle.x < ia->x)
    ia->x -= 0.1 * score->level;
}

void    increase_level(t_score *score)
{
  if (sfKeyboard_isKeyPressed(sfKeyPageUp))
    {
      usleep(300000);
      score->level++;
    }
  if (sfKeyboard_isKeyPressed(sfKeyPageDown))
    {
      usleep(300000);
      score->level--;
    }
}
