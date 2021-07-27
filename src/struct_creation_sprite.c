/*
** EPITECH PROJECT, 2021
** struct creationns sprite
** File description:
** ..
*/

#include "../include/defender.h"

enemie_t *add_object(enemie_t *enemies, const char
*path_to_spritesheet, sfVector2f pos, sfIntRect rect)
{
    enemie_t *new_enemie = create_object(path_to_spritesheet, pos, rect);
    if (!enemies)
        return new_enemie;

    new_enemie->next = enemies;

    return new_enemie;
}

enemie_t *create_object(const char *path,
sfVector2f pos, sfIntRect rect)
{
    enemie_t *enemies = malloc(sizeof(enemie_t));
    if (my_strcmp(path, "pictures/right_2.png") == 0) {
        enemies->lvl = 2;
        enemies->gold = 20;
    }
    else if (my_strcmp(path, "pictures/right_1.png") == 0) {
        enemies->lvl = 1;
        enemies->gold = 10;
    }
    else {
        enemies->lvl = 0;
        enemies->gold = 3;
    }
    enemies->life_struct = create_life();
    if (!enemies)
        return NULL;
    enemies->clock = sfClock_create();
    enemies->rect_clock = sfClock_create();
    sfTime time;
    enemies->sprite_enemie = sfSprite_create();
    enemies->pos = pos;
    enemies->rect_enemie = rect;
    time = sfClock_getElapsedTime(enemies->clock);
    int seconds = time.microseconds;
    if (seconds % 2 == 0)
        enemies->randome = 1;
    else
        enemies->randome = 0;
    enemies->texture_enemie = sfTexture_createFromFile(path, NULL);
    sfSprite_setTexture(enemies->sprite_enemie, enemies->texture_enemie,
    sfFalse);
    sfSprite_setTextureRect(enemies->sprite_enemie, rect);
    sfSprite_setPosition(enemies->sprite_enemie, pos);
    enemies->next = NULL;
    return enemies;
}

void fill_texture(life_t *life_struct);

life_t *create_life(void)
{
    sfVector2f pos = {0, 0};
    life_t *life_struct = malloc(sizeof(life_t));
    life_struct->life = 100;
    life_struct->life_sprite = sfSprite_create();
    fill_texture(life_struct);
    sfSprite_setTexture(life_struct->life_sprite,
    life_struct->life_full, sfFalse);
    sfSprite_setPosition(life_struct->life_sprite, pos);
    return life_struct;
}

void fill_texture(life_t *life_struct)
{
    life_struct->life_1 =
    sfTexture_createFromFile("pictures/life_degat1.png", NULL);
    life_struct->life_2 =
    sfTexture_createFromFile("pictures/life_degat2.png", NULL);
    life_struct->life_3 =
    sfTexture_createFromFile("pictures/life_degat3.png", NULL);
    life_struct->life_4 =
    sfTexture_createFromFile("pictures/life_degat4.png", NULL);
    life_struct->life_5 =
    sfTexture_createFromFile("pictures/life_degat5.png", NULL);
    life_struct->life_full =
    sfTexture_createFromFile("pictures/life_full.png", NULL);
}