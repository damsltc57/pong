/*
** check.c for check.c in /home/dams/perso/pong/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Wed Apr  5 21:07:14 2017 John Doe
** Last update Thu Apr  6 02:47:07 2017 John Doe
*/
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <unistd.h>
#include <stdio.h>
#include "pong.h"

void         move_ball(sfVector2f *balle, sfVector2f *balle_dir)
{
  balle->x += balle_dir->x;
  balle->y += balle_dir->y;
}

int         is_on_barr(sfVector2f balle, sfVector2f player)
{
  if (balle.x >= player.x && balle.x <= player.x + 40 && balle.y > FRAMEBUFFER_HEIGHT - 80)
    return (0);
  if (balle.x <= player.x && balle.x >= player.x - 40 && balle.y > FRAMEBUFFER_HEIGHT - 80)
    return (0);
  return (1);
}

int       is_on_ia_barr(sfVector2f balle, sfVector2f ia)
{
  if (balle.x >= ia.x && balle.x <= ia.x + 40 && balle.y < 30)
    return (0);
  if (balle.x <= ia.x && balle.x >= ia.x - 40 && balle.y < 30)
    return (0);
  return (1);
}

void         rebondir(sfVector2f *balle, sfVector2f *balle_dir, sfVector2f *player, sfVector2f *ia, t_score *score)
{
  //gauche
  if (balle->x < 5)
    balle_dir->x = -balle_dir->x;
  //haut avec ia
  if (is_on_ia_barr(*balle, *ia) == 0)
    balle_dir->y = -balle_dir->y;
  //haut
  if (is_on_barr(*balle, *player) == 0)
    balle_dir->y = -balle_dir->y;
  // if (balle->y < 5)
    // balle_dir->y = -balle_dir->y;
  //droite
  if (balle->x >= FRAMEBUFFER_WIDTH - 40)
    balle_dir->x = -balle_dir->x;
  //conditons de sortie
  if (balle->y < -10)
    {
      balle->y = 400;
      balle->x = (rand() % 400);
      score->player++;
    }
  if (balle->y > player->y + 10)
    {
      balle->y = 400;
      balle->x = (rand() % 400);
      score->ia++;
    }
}
