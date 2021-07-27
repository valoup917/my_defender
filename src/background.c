/*
** EPITECH PROJECT, 2021
** background
** File description:
** .
*/

#include "../include/defender.h"

map_t *create_background(void)
{
    sfVector2f pos0 = {0, 0};
    sfVector2f p1 = {812, 23};
    sfVector2f p2 = {904, 23};
    sfVector2f p3 = {996, 23};
    sfVector2f p4 = {1088, 23};
    sfVector2f p5 = {788, 15};
    map_t *background = NULL;
    background = add_background(background, "pictures/volcan_red.png", p1);
    background = add_background(background, "pictures/volcan_green.png", p2);
    background = add_background(background, "pictures/volcan_blue.png", p3);
    background = add_background(background, "pictures/volcan_black.png", p4);
    background = add_background(background, "pictures/pannel.png", p5);
    background = add_background(background, "pictures/map3.png", pos0);
    return background;
}

map_t *add_background(map_t *map, char *path, sfVector2f pos)
{
    map_t *new_map = fill_background(path, pos);
    if (!map)
        return new_map;
    new_map->next = map;
    return new_map;
}

map_t *fill_background(char *path, sfVector2f position)
{
    map_t *backgrd = malloc(sizeof(map_t));
    backgrd->pos = position;
    backgrd->sprite_map = sfSprite_create();
    backgrd->texture_map = sfTexture_createFromFile(path, NULL);
    sfSprite_setTexture(backgrd->sprite_map, backgrd->texture_map, sfFalse);
    sfSprite_setPosition(backgrd->sprite_map, backgrd->pos);
    backgrd->next = NULL;
    return backgrd;
}

void print_background(sfRenderWindow *window, map_t *background)
{
    while (background) {
        sfRenderWindow_drawSprite(window, background->sprite_map, NULL);
        background = background->next;
    }
}