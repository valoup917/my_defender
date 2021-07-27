/*
** EPITECH PROJECT, 2021
** move pos enemies & life
** File description:
** .
*/

#include "../include/defender.h"

void move_pos_enemies(enemie_t *enemies)
{
    sfTime time = sfClock_getElapsedTime(enemies->clock);
    float seconds = time.microseconds / 100000.0;

    if (seconds > 0.14) {
        if (enemies->randome == 0)
            move_by_part_up(enemies);
        else if (enemies->randome == 1)
            move_by_part_down(enemies);
        move_life(enemies);
        sfSprite_setPosition(enemies->sprite_enemie, enemies->pos);
        sfClock_restart(enemies->clock);
    }
}

void move_life(enemie_t *enemies)
{
    int life_i = enemies->life_struct->life;
    sfVector2f pos = enemies->pos;
    pos.y -= 18;
    pos.x += 14;
    if (life_i < 84 && life_i >= 68)
        degat1(enemies);
    if (life_i < 68 && life_i >= 52)
        degat2(enemies);
    if (life_i < 52 && life_i >= 36)
        degat3(enemies);
    if (life_i < 36 && life_i >= 20)
        degat4(enemies);
    if (life_i < 20 && life_i >= 0)
        degat5(enemies);
    sfSprite_setPosition(enemies->life_struct->life_sprite, pos);
}

void move_by_part_up(enemie_t *enemies)
{
    if (enemies->pos.x != 505 && enemies->pos.y == 515)
        enemies->pos.x += 1;
    if (enemies->pos.x == 505 && enemies->pos.y != 370)
        enemies->pos.y -= 1;
    if (enemies->pos.x != 720 && enemies->pos.y == 370 && enemies->pos.x < 900)
        enemies->pos.x += 1;
    if (enemies->pos.x == 720 && enemies->pos.y != 442)
        enemies->pos.y += 1;
    if (enemies->pos.x >= 720 && enemies->pos.x <= 1297
        && enemies->pos.x != 936 && enemies->pos.y == 442)
        enemies->pos.x += 1;
    if (enemies->pos.x == 936 && enemies->pos.y != 298)
        enemies->pos.y -= 1;
    if (enemies->pos.x != 1298 && enemies->pos.y == 298)
        enemies->pos.x += 1;
    if (enemies->pos.x == 1298 && enemies->pos.y != 515)
        enemies->pos.y += 1;
    if (enemies->pos.x > 1920)
        enemies->life_struct->life = -1;
}

void move_by_part_down(enemie_t *enemies)
{
    if (enemies->pos.x != 432 && enemies->pos.y <= 515)
        enemies->pos.x += 1;
    if (enemies->pos.x == 432 && enemies->pos.y != 730)
        enemies->pos.y += 1;
    if (enemies->pos.x != 1008 && enemies->pos.y == 730
        && enemies->pos.x <= 1018)
        enemies->pos.x += 1;
    if (enemies->pos.x == 1008 && enemies->pos.y != 802)
        enemies->pos.y += 1;
    if (enemies->pos.x != 1297 && enemies->pos.y == 802)
        enemies->pos.x += 1;
    if (enemies->pos.x == 1297 && enemies->pos.y != 730)
        enemies->pos.y -= 1;
    if (enemies->pos.x != 1513 && enemies->pos.y == 730
        && enemies->pos.x > 1200)
        enemies->pos.x += 1;
    if (enemies->pos.x == 1513 && enemies->pos.y != 515)
        enemies->pos.y -= 1;
    if (enemies->pos.x > 1920)
        enemies->life_struct->life = -1;
}