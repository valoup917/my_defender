/*
** EPITECH PROJECT, 2021
** all_sprite
** File description:
** sprite
*/

#include "my.h"
#include "defender.h"

void backround_img(game *str)
{
    str->t_bcg1 = sfTexture_createFromFile("pictures/bcg1.jpg", NULL);
    str->s_bcg1 = sfSprite_create();
    sfSprite_setTexture(str->s_bcg1, str->t_bcg1, sfTrue);
    str->t_bcg2 = sfTexture_createFromFile("pictures/bcg4.jpg", NULL);
    str->s_bcg2 = sfSprite_create();
    sfSprite_setTexture(str->s_bcg2, str->t_bcg2, sfTrue);
}

void smallButton(game *str)
{
    str->t_btn7 = sfTexture_createFromFile("pictures/m_exit1.png", NULL);
    str->s_btn7 = sfSprite_create();
    sfSprite_setTexture(str->s_btn7, str->t_btn7, sfTrue);
    str->t_btn8 = sfTexture_createFromFile("pictures/m_exit2.png", NULL);
    str->s_btn8 = sfSprite_create();
    sfSprite_setTexture(str->s_btn8, str->t_btn8, sfTrue);
}

int tButton(game *str, char *string, int i, int x)
{
    i = str->pos_string.x;
    x = str->pos_string.y;

    str->t_string = sfTexture_createFromFile(string, NULL);
    str->s_string = sfSprite_create();
    sfSprite_setTexture(str->s_string, str->t_string, sfTrue);

    sfSprite_setPosition(str->s_string, str->pos_string);
    sfRenderWindow_drawSprite(str->window, str->s_string, NULL);
    return 0;
}