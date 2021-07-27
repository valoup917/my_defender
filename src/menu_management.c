/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** menu_management
*/

#include "defender.h"

int menu_pages(my_game_t *str, map_t *background, enemie_t *enemies, text_t *score, orga_t *all)
{
    if (str->a == 0) {
        sfRenderWindow_clear(str->window, sfBlack);
        sfRenderWindow_drawSprite(str->window, str->s_bcg1, NULL);
        mouse(all, str);
    }
    if (str->a == 1) {
        game_start(str, background, enemies, score);
        //my_pause(str);
    }
    if (str->a == 2) {
        man(str);
        man_exit_button(all, str);
    }
    if (str->a == 3) {
        pause_menu(all, str);
    }
    if (str->a == 4)
        loose_menu(all, str);
    return 0;
}

void all_dest(my_game_t *str)
{
    sfRenderWindow_destroy(str->window);
    sfTexture_destroy(str->t_bcg1);
    sfSprite_destroy(str->s_bcg1);
    sfTexture_destroy(str->t_bcg2);
    sfSprite_destroy(str->s_bcg2);
}

void music(music_t *sound)
{
    float volume =  0.5;

    sound->music = sfMusic_createFromFile("pictures/song.ogg");
    sfMusic_setLoop(sound->music, sfTrue);
    sfMusic_setVolume(sound->music, volume);
    sfMusic_play(sound->music);
    sound->buffer1 = sfSoundBuffer_createFromFile("pictures/hit_effect.ogg");
    sound->sound1 = sfSound_create();
    sfSound_setBuffer(sound->sound1, sound->buffer2);
    sound->buffer2 = sfSoundBuffer_createFromFile("pictures/hit_effect.ogg");
    sound->sound1 = sfSound_create();
    sfSound_setBuffer(sound->sound2, sound->buffer2);
}