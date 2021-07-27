/*
** EPITECH PROJECT, 2021
** life texture assignation
** File description:
** .
*/

#include "../include/defender.h"

void degat1(enemie_t *enemies)
{
    sfSprite *sprite = enemies->life_struct->life_sprite;
    sfTexture *texture = enemies->life_struct->life_1;
    sfSprite_setTexture(sprite, texture, sfFalse);
}

void degat2(enemie_t *enemies)
{
    sfSprite *sprite = enemies->life_struct->life_sprite;
    sfTexture *texture = enemies->life_struct->life_2;
    sfSprite_setTexture(sprite, texture, sfFalse);
}

void degat3(enemie_t *enemies)
{
    sfSprite *sprite = enemies->life_struct->life_sprite;
    sfTexture *texture = enemies->life_struct->life_3;
    sfSprite_setTexture(sprite, texture, sfFalse);
}

void degat4(enemie_t *enemies)
{
    sfSprite *sprite = enemies->life_struct->life_sprite;
    sfTexture *texture = enemies->life_struct->life_4;
    sfSprite_setTexture(sprite, texture, sfFalse);
}

void degat5(enemie_t *enemies)
{
    sfSprite *sprite = enemies->life_struct->life_sprite;
    sfTexture *texture = enemies->life_struct->life_5;
    sfSprite_setTexture(sprite, texture, sfFalse);
}