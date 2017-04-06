/*
** draw_info.c for draw_info.c in /home/dams/perso/pong/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Thu Apr  6 01:51:43 2017 John Doe
** Last update Thu Apr  6 02:29:45 2017 John Doe
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <unistd.h>
#include <stdio.h>
#include "pong.h"
#include <string.h>

void          draw_score(t_score *score, sfRenderWindow *window, sfFont *font, sfText *text)
{
  sfVector2f pos;
  char       *tmp;
  char       *fine;

  fine = malloc(sizeof(char) * 10);
  tmp = malloc(sizeof(char) * 10);
  strcpy(fine, "Player ");
  sprintf(tmp, "%d", score->player);
  strcat(fine, tmp);
  pos.x = 20;
  pos.y = 150;
  sfText_setString(text, fine);
  sfText_setColor(text, sfBlack);
  sfText_setPosition(text, pos);
  sfText_setFont(text, font);
  sfText_setCharacterSize(text, 30);
  sfRenderWindow_drawText(window, text, NULL);

  fine[0] = '\0';
  strcpy(fine, "IA ");
  sprintf(tmp, "%d", score->ia);
  strcat(fine, tmp);
  sfText_setString(text, fine);
  pos.y += 50;
  sfText_setPosition(text, pos);
  sfRenderWindow_drawText(window, text, NULL);

  fine[0] = '\0';
  strcpy(fine, "level ");
  sprintf(tmp, "%d", score->level);
  strcat(fine, tmp);
  sfText_setString(text, fine);
  pos.y -= 100;
  sfText_setPosition(text, pos);
  sfRenderWindow_drawText(window, text, NULL);

}
