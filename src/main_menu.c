/*
** EPITECH PROJECT, 2021
** my_defender2
** File description:
** mouse_evt
*/

#include "defender.h"

void start_evt(orga_t *all, my_game_t *str)
{
    sfVector2i mouse = sfMouse_getPosition(NULL);
    all->start->pos_string.x = 1220;
    all->start->pos_string.y = 300;

    sfRenderWindow_drawSprite(str->window, all->start->s_string, NULL);
    if (all->start->pos_string.x < mouse.x && mouse.x < (all->start->pos_string.x + 600) &&
        (all->start->pos_string.y + 50 < mouse.y && mouse.y < (all->start->pos_string.y + 250)))
        sfRenderWindow_drawSprite(str->window, all->start->s_string_2, NULL);
    if (str->event.type == sfEvtMouseButtonPressed) {
        if (all->start->pos_string.x < mouse.x && mouse.x < (all->start->pos_string.x + 600) &&
            (all->start->pos_string.y < mouse.y && mouse.y < (all->start->pos_string.y + 200)))
            str->a = 1;
    }
}

void exit_evt(orga_t *all, my_game_t *str)
{
    sfVector2i mouse = sfMouse_getPosition(NULL);
    all->exit->pos_string.x = 100;
    all->exit->pos_string.y = 300;

    sfRenderWindow_drawSprite(str->window, all->exit->s_string, NULL);
    if (all->exit->pos_string.x < mouse.x && mouse.x < (all->exit->pos_string.x + 600) &&
        (all->exit->pos_string.y + 50 < mouse.y && mouse.y < (all->exit->pos_string.y + 250)))
        sfRenderWindow_drawSprite(str->window, all->exit->s_string_2, NULL);
    if (str->event.type == sfEvtMouseButtonPressed) {
        if (all->exit->pos_string.x < mouse.x && mouse.x < (all->exit->pos_string.x + 600) &&
            (all->exit->pos_string.y < mouse.y && mouse.y < (all->exit->pos_string.y + 200)))
            sfRenderWindow_close(str->window);
    }
}

void man_evt(orga_t *all, my_game_t *str)
{
    sfVector2i mouse = sfMouse_getPosition(NULL);
    all->man->pos_string.x = 1650;
    all->man->pos_string.y = 800;

    sfRenderWindow_drawSprite(str->window, all->man->s_string, NULL);
    if (all->man->pos_string.x < mouse.x && mouse.x < (all->man->pos_string.x + 200) &&
        (all->man->pos_string.y + 50 < mouse.y && mouse.y < (all->man->pos_string.y + 250)))
        sfRenderWindow_drawSprite(str->window, all->man->s_string_2, NULL);
    if (str->event.type == sfEvtMouseButtonPressed) {
        if (all->man->pos_string.x < mouse.x && mouse.x < (all->man->pos_string.x + 600) &&
            (all->man->pos_string.y < mouse.y && mouse.y < (all->man->pos_string.y + 200)))
            str->a = 2;
    }
}

void mouse(orga_t *all, my_game_t *str)
{
    start_evt(all, str);
    exit_evt(all, str);
    man_evt(all, str);
}