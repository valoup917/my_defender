/*
** EPITECH PROJECT, 2021
** all_sprite
** File description:
** sprite
*/

#include "defender.h"

my_game_t *backround_img()
{
    my_game_t *str = malloc(sizeof(my_game_t));
    str->a = 0;
    str->t_bcg1 = sfTexture_createFromFile("pictures/map3.png", NULL);
    str->s_bcg1 = sfSprite_create();
    sfSprite_setTexture(str->s_bcg1, str->t_bcg1, sfTrue);
    str->t_bcg2 = sfTexture_createFromFile("pictures/index.png", NULL);
    str->s_bcg2 = sfSprite_create();
    sfSprite_setTexture(str->s_bcg2, str->t_bcg2, sfTrue);
    return (str);
}

my_game_t *tButton(char *string, char *string_2, int i, int x)
{
    my_game_t *str = malloc(sizeof(my_game_t));
    str->pos_string.x = i;
    str->pos_string.y = x;

    str->t_string = sfTexture_createFromFile(string, NULL);
    str->s_string = sfSprite_create();
    sfSprite_setTexture(str->s_string, str->t_string, sfTrue);
    sfSprite_setPosition(str->s_string, str->pos_string);
    str->t_string_2 = sfTexture_createFromFile(string_2, NULL);
    str->s_string_2 = sfSprite_create();
    sfSprite_setTexture(str->s_string_2, str->t_string_2, sfTrue);
    sfSprite_setPosition(str->s_string_2, str->pos_string);
    return str;
}

orga_t *organisation()
{
    orga_t *all = malloc(sizeof(orga_t));

    all->start = tButton("pictures/Start1.png", "pictures/Start2.png", 1220, 300);
    all->exit = tButton("pictures/exit1.png", "pictures/exit2.png", 100, 300);
    all->man = tButton("pictures/man1.png", "pictures/man2.png", 1650, 800);
    all->m_exit = tButton("pictures/m_exit1.png", "pictures/m_exit2.png", 1650, 50);
    all->home = tButton("pictures/home1.png", "pictures/home2.png", 680, 140);
    all->pause_exit = tButton("pictures/close1.png", "pictures/close2.png", 1650, 800);
    all->resume = tButton("pictures/resume1.png", "pictures/resume2.png", 680, 540);
    return all;
}