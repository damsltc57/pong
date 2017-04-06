/*
** tek.h for tek.h in /home/dams/delivery/Igraph/Tekadventure/
**
** Made by Damien Laurent
** Login   <damien.laurent@epitech.eu@epitech.eu>
**
** Started on  Tue Mar 21 10:03:53 2017 Damien Laurent
** Last update Thu Apr  6 02:35:57 2017 John Doe
*/
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#ifndef TEK_H
#define TEK_H
#define	FRAMEBUFFER_WIDTH 800
#define FRAMEBUFFER_HEIGHT 900
#define SPEED 0.4
#define IA_SPEED 0.4

typedef struct s_score
{
  int         player;
  int         ia;
  int         level;
}              t_score;
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
int		process_game_loop(sfRenderWindow *window, t_score *score);
sfVector2f	move_player(sfVector2f player);
void         move_ball(sfVector2f *balle, sfVector2f *balle_dir);
void         rebondir(sfVector2f *balle, sfVector2f *balle_dir, sfVector2f *player, sfVector2f *ia, t_score *score);
void     ia_play(sfVector2f balle, sfVector2f *ia, t_score *score);
void          draw_score(t_score *score, sfRenderWindow *window, sfFont *font, sfText *text);
void    increase_level(t_score *score);

#endif /*TEK_H*/
