/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** pause_menu
*/

#include "defender.h"

void resume_button(orga_t *all, my_game_t *str)
{
    sfVector2i mouse = sfMouse_getPosition(NULL);
    all->resume->pos_string.x = 680;
    all->resume->pos_string.y = 540;

    sfRenderWindow_drawSprite(str->window, all->resume->s_string, NULL);
    if (all->resume->pos_string.x < mouse.x && mouse.x < (all->resume->pos_string.x + 600) &&
        (all->resume->pos_string.y + 50 < mouse.y && mouse.y < (all->resume->pos_string.y + 250)))
        sfRenderWindow_drawSprite(str->window, all->resume->s_string_2, NULL);
    if (str->event.type == sfEvtMouseButtonPressed) {
        if (all->resume->pos_string.x < mouse.x && mouse.x < (all->resume->pos_string.x + 600) &&
            (all->resume->pos_string.y + 50 < mouse.y && mouse.y < (all->resume->pos_string.y + 250)))
            str->a = 1;
    }
}

void exit_button(orga_t *all, my_game_t *str)
{
    sfVector2i mouse = sfMouse_getPosition(NULL);
    all->pause_exit->pos_string.x = 1650;
    all->pause_exit->pos_string.y = 800;

    sfRenderWindow_drawSprite(str->window, all->pause_exit->s_string, NULL);
    if (all->pause_exit->pos_string.x < mouse.x && mouse.x < (all->pause_exit->pos_string.x + 200) &&
        (all->pause_exit->pos_string.y + 50 < mouse.y && mouse.y < (all->pause_exit->pos_string.y + 250))) {
            sfRenderWindow_drawSprite(str->window, all->pause_exit->s_string_2, NULL);
    }
    if (str->event.type == sfEvtMouseButtonPressed) {
        if (all->pause_exit->pos_string.x < mouse.x && mouse.x < (all->pause_exit->pos_string.x + 200) &&
            (all->pause_exit->pos_string.y + 50 < mouse.y && mouse.y < (all->pause_exit->pos_string.y + 250)))
                sfRenderWindow_close(str->window);
    }
}

void home_button(orga_t *all, my_game_t *str)
{
    sfVector2i mouse = sfMouse_getPosition(NULL);
    all->home->pos_string.x = 680;
    all->home->pos_string.y = 140;

    sfRenderWindow_drawSprite(str->window, all->home->s_string, NULL);
    if (all->home->pos_string.x < mouse.x && mouse.x < (all->home->pos_string.x + 600) &&
        (all->home->pos_string.y + 50 < mouse.y && mouse.y < (all->home->pos_string.y + 250)))
        sfRenderWindow_drawSprite(str->window, all->home->s_string_2, NULL);
    if (str->event.type == sfEvtMouseButtonPressed) {
        if (all->home->pos_string.x + 50 < mouse.x && mouse.x < (all->home->pos_string.x + 650) &&
            (all->home->pos_string.y + 50 < mouse.y && mouse.y < (all->home->pos_string.y + 250)))
            str->a = 0;
    }
}

void my_pause(my_game_t *str)
{
    if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
        str->a = 3;
    }
}

void pause_menu(orga_t *all, my_game_t *str)
{
    exit_button(all, str);
    home_button(all, str);
    resume_button(all, str);
}