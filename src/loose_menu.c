/*
** EPITECH PROJECT, 2021
** my_defender3
** File description:
** loose_menu
*/

#include "defender.h"

void loose_msg(my_game_t *str)
{
    sfFont *f_font;
    sfText *t_text;
    sfVector2f p_text;

    p_text.x = 500;
    p_text.y = 540;

    f_font = sfFont_createFromFile("pictures/my_font.ttf");
    t_text = sfText_create();

    sfText_setString(t_text, "YOU LOOSE NOOB\n");
    sfText_setFont(t_text, f_font);
    sfText_setCharacterSize(t_text, 100);
    sfText_setPosition(t_text, p_text);
    sfRenderWindow_drawText(str->window, t_text, NULL);
}

void l_exit_button(orga_t *all, my_game_t *str)
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

void l_home_button(orga_t *all, my_game_t *str)
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

void loose_menu(orga_t *all, my_game_t *str)
{
    loose_msg(str);
    l_exit_button(all, str);
    l_home_button(all, str);
}