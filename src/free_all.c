/*
** EPITECH PROJECT, 2021
** free all
** File description:
** .
*/

#include "../include/defender.h"

enemie_t *freelist(enemie_t *enemies)
{
    if (!enemies)
        return NULL;
    enemie_t *tmp = NULL;
    while (enemies) {
        tmp = enemies->next;
        enemies = free_enemies(enemies);
        free(enemies);
        enemies = tmp;
    }
    return enemies;
}

enemie_t *free_enemies(enemie_t *enemies)
{
    sfSprite_destroy(enemies->sprite_enemie);
    sfTexture_destroy(enemies->texture_enemie);
    sfClock_destroy(enemies->clock);
    sfClock_destroy(enemies->rect_clock);
    enemies->life_struct = freelife(enemies->life_struct);
    return enemies;
}

life_t *freelife(life_t *life_struct)
{
    free(life_struct->life_1);
    free(life_struct->life_2);
    free(life_struct->life_3);
    free(life_struct->life_4);
    free(life_struct->life_5);
    free(life_struct->life_full);
    sfSprite_destroy(life_struct->life_sprite);
    free(life_struct);
    return life_struct;
}