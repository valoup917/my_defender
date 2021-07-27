/*
** EPITECH PROJECT, 2021
** enemies
** File description:
** .
*/

#include "../include/defender.h"

enemie_t *create_enemies(int a)
{
    sfVector2f p = {0, 515};
    sfIntRect rect = {0, 0, 64, 47};

    enemie_t *enemies = NULL;
    for (int i = 0; i != a; i++) {
        if (i == a - 1)
            enemies = add_object(enemies, "pictures/right_2.png", p, rect);
        else if (i >= a - 3 && i != a - 1)
            enemies = add_object(enemies, "pictures/right_1.png", p, rect);
        else
            enemies = add_object(enemies, "pictures/right.png", p, rect);
        p.x -= 150;
    }
    return enemies;
}

void print_enemies(sfRenderWindow *window, enemie_t *enemies)
{
    int nbr = count_enemies(enemies);
    for (int i = 0; i != nbr; i++) {
        if (enemies->life_struct->life > 0) {
            move_pos_enemies(enemies);
            move_rect(enemies);
            sfRenderWindow_drawSprite(window,
            enemies->life_struct->life_sprite, NULL);
            sfRenderWindow_drawSprite(window, enemies->sprite_enemie, NULL);
        }
        enemies = enemies->next;
    }
}

int count_enemies(enemie_t *enemies)
{
    int n = 0;
    for (;enemies; enemies = enemies->next)
        n++;
    return n;
}

int check_dead(enemie_t *enemies)
{
    int nbr = count_enemies(enemies);
    int i = 0;

    for (int k = 0; k < nbr; k++) {
        if (enemies->life_struct->life < 1)
            i++;
        enemies = enemies->next;
    }
    if (i == nbr)
        return 1;
    return 0;
}