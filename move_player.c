/*
** move_player.c for move_player.c in /home/dams/delivery/perso/pong/
**
** Made by Damien Laurent
** Login   <damien.laurent@epitech.eu@epitech.eu>
**
** Started on  Wed Apr  5 19:32:55 2017 Damien Laurent
** Last update Wed Apr  5 20:09:57 2017 Damien Laurent
*/
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <unistd.h>
#include <stdio.h>
#include "pong.h"

// void		draw_player(sfVector2i)

sfVector2f	move_player(sfVector2f player)
{
  if (sfKeyboard_isKeyPressed(sfKeyRight) && player.x < FRAMEBUFFER_HEIGHT - 150)
    player.x += SPEED;
  if (sfKeyboard_isKeyPressed(sfKeyLeft) && player.x > 0)
    player.x -= SPEED;
  return (player);
}
