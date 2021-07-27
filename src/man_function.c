/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** man_function
*/

#include "defender.h"

void man(my_game_t *str)
{
    sfFont *f_font;
    sfText *t_text;
    sfVector2f p_text;

    p_text.x = 500;
    p_text.y = 540;

    f_font = sfFont_createFromFile("pictures/my_font.ttf");
    t_text = sfText_create();

    sfText_setString(t_text, "You have to kill ennemies\nbefore the take your,castel and destroy it\n");
    sfText_setFont(t_text, f_font);
    sfText_setCharacterSize(t_text, 50);
    sfRenderWindow_drawSprite(str->window, str->s_bcg2, NULL);
    sfText_setPosition(t_text, p_text);
    sfRenderWindow_drawText(str->window, t_text, NULL);
}

void man_exit_button(orga_t *all, my_game_t *str)
{
    sfVector2i mouse = sfMouse_getPosition(NULL);
    all->m_exit->pos_string.x = 1650;
    all->m_exit->pos_string.y = 50;

    sfRenderWindow_drawSprite(str->window, all->m_exit->s_string, NULL);
    if (all->m_exit->pos_string.x < mouse.x && mouse.x < (all->m_exit->pos_string.x + 200) &&
        (all->m_exit->pos_string.y + 50 < mouse.y && mouse.y < (all->m_exit->pos_string.y + 250))) {
        sfRenderWindow_drawSprite(str->window, all->m_exit->s_string_2, NULL);
    }
    if (str->event.type == sfEvtMouseButtonPressed) {
        if (all->m_exit->pos_string.x < mouse.x && mouse.x < (all->m_exit->pos_string.x + 200) &&
            (all->m_exit->pos_string.y < mouse.y + 50 && mouse.y < (all->m_exit->pos_string.y + 250)))
            str->a = 0;
    }
}