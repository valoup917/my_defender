/*
** EPITECH PROJECT, 2021
** move my rect
** File description:
** .
*/

#include "../include/defender.h"

void move_rect(enemie_t *enemies)
{
    sfTime time = sfClock_getElapsedTime(enemies->rect_clock);
    float seconds = time.microseconds / 100000.0;

    if (seconds > 0.5) {
        move_rect2(enemies);
        sfSprite_setTextureRect(enemies->sprite_enemie, enemies->rect_enemie);
        sfClock_restart(enemies->rect_clock);
    }
}

void move_rect2(enemie_t *enemies)
{
    if (enemies->pos.x == 505 && enemies->pos.y != 370)
        move_up(enemies);
    else if (enemies->pos.x == 720 && enemies->pos.y != 442)
        move_down(enemies);
    else if (enemies->pos.x == 936 && enemies->pos.y != 298)
        move_up(enemies);
    else if (enemies->pos.x == 1297 && enemies->pos.y != 730)
        move_up(enemies);
    else if (enemies->pos.x == 1513 && enemies->pos.y != 515)
        move_up(enemies);
    else if (enemies->pos.x == 1298 && enemies->pos.y != 515)
        move_down(enemies);
    else if (enemies->pos.x == 432 && enemies->pos.y != 730)
        move_down(enemies);
    else if (enemies->pos.x == 1008 && enemies->pos.y != 802)
        move_down(enemies);
    else
        move_right(enemies);
}

void move_right(enemie_t *enemies)
{
    sfTexture_destroy(enemies->texture_enemie);
    if (enemies->lvl == 1)
        enemies->texture_enemie =
        sfTexture_createFromFile("pictures/right_1.png", NULL);
    else if (enemies->lvl == 2)
        enemies->texture_enemie =
        sfTexture_createFromFile("pictures/right_2.png", NULL);
    else
        enemies->texture_enemie =
        sfTexture_createFromFile("pictures/right.png", NULL);
    sfSprite_setTexture(enemies->sprite_enemie,
    enemies->texture_enemie, sfFalse);
    enemies->rect_enemie.left += 64;
    if (enemies->rect_enemie.left >= 512)
        enemies->rect_enemie.left = 0;
}

void move_up(enemie_t *enemies)
{
    sfTexture_destroy(enemies->texture_enemie);
    if (enemies->lvl == 1)
        enemies->texture_enemie =
        sfTexture_createFromFile("pictures/up_1.png", NULL);
    else if (enemies->lvl == 2)
        enemies->texture_enemie =
        sfTexture_createFromFile("pictures/up_2.png", NULL);
    else
        enemies->texture_enemie =
        sfTexture_createFromFile("pictures/up.png", NULL);
    sfSprite_setTexture(enemies->sprite_enemie,
    enemies->texture_enemie, sfFalse);
    enemies->rect_enemie.left += 64;
    if (enemies->rect_enemie.left >= 512)
        enemies->rect_enemie.left = 0;
}

void move_down(enemie_t *enemies)
{
    sfTexture_destroy(enemies->texture_enemie);
    if (enemies->lvl == 1)
        enemies->texture_enemie =
        sfTexture_createFromFile("pictures/down_1.png", NULL);
    else if (enemies->lvl == 2)
        enemies->texture_enemie =
        sfTexture_createFromFile("pictures/down_2.png", NULL);
    else
        enemies->texture_enemie =
        sfTexture_createFromFile("pictures/down.png", NULL);
    sfSprite_setTexture(enemies->sprite_enemie,
    enemies->texture_enemie, sfFalse);
    enemies->rect_enemie.left += 64;
    if (enemies->rect_enemie.left >= 512)
        enemies->rect_enemie.left = 0;
}