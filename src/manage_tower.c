/*
** EPITECH PROJECT, 2021
** manage tower
** File description:
** .
*/

#include "../include/defender.h"
tower_t *create_tower(const char *path, sfVector2f pos, int a);
tower_t *add_tower(tower_t *towers, const char *path, sfVector2f pos, int a);
tower_t *put_my_tower(sfVector2i p, input_t *input, tower_t *towers);

tower_t *check_pos_click(sfRenderWindow *window, input_t *input,
tower_t *towers)
{
    sfVector2i p = sfMouse_getPosition((sfWindow *)window);

    if (p.y >= 21 && p.y <= 130) {
        if (p.x >= 805 && p.x <= 890 && input->gold_tmp >= 30)
            input->gold_tmp -= 30, input->click = 1, input->tower = 1;
        if (p.x >= 895 && p.x <= 980 && input->gold_tmp >= 40)
            input->gold_tmp -= 30, input->click = 1, input->tower = 2;
        if (p.x >= 985 && p.x <= 1075 && input->gold_tmp >= 50)
            input->gold_tmp -= 30, input->click = 1, input->tower = 3;
        if (p.x >= 1080 && p.x <= 1165 && input->gold_tmp >= 60)
            input->gold_tmp -= 30, input->click = 1, input->tower = 4;
    }
    else if (input->click == 1) {
        input->click = 0;
        towers = put_my_tower(p, input, towers);
    }
    return towers;
}

tower_t *put_my_tower(sfVector2i p, input_t *input, tower_t *towers)
{
    float x = input->place[0][0];
    float y = input->place[0][1];
    //sfVector2f po_bis = {x, y};

    for (int i = 0; i <= 109; i++) {
        x = input->place[i][0];
        y = input->place[i][1];
        sfVector2f po_bis = {x, y};
        if (p.x <= (x + 72) && p.x >= (x) && p.y <= (y + 72) && p.y >= (y)) {
            if (input->tower == 1)
                towers = add_tower(towers, "pictures/volcan_red.png", po_bis, 1);
            else if (input->tower == 2)
                towers = add_tower(towers, "pictures/volcan_green.png", po_bis, 2);
            else if (input->tower == 3)
                towers = add_tower(towers, "pictures/volcan_blue.png", po_bis, 3);
            else if (input->tower == 4)
                towers = add_tower(towers, "pictures/volcan_black.png", po_bis, 4);
        }
    }
    return towers;
}

int **fill_places(void)
{
    int nbr = 110;
    int x = 0;
    int y = 432;
    int flag = 1;

    int **new = malloc(sizeof(int *) * (nbr + 2));
    for (int i = 0; i < nbr; i++) {

        new[i] = malloc(sizeof(int) * 20);

        new[i][0] = 0 + x;
        new[i][1] = 0 + y;
        if (flag == 1) {
            if (x <= 360)
                x += 72;
            else if (x == 432 && y >= 360)
                y -= 72;
            else if (x <= 792 && y == 288)
                x += 72;
            else if (x == 864 && y >= 288)
                y -= 72;
            else if (x <= 1296 && y == 216)
                x += 72;
            else if (x == 1368 && y <= 360)
                y += 72;
            else if (x <= 1728 && y == 432)
                x += 72;
            else if (x == 1800 && y == 432)
                flag = 2;
        }
        else if (flag == 2) {
            if (x == 1800 && y == 432)
                y += 144;
            else if (x >= 1656 && y == 576)
                x -= 72;
            else if (x == 1584 && y <= 720)
                y += 72;
            else if (x >= 1440 && y == 792)
                x -= 72;
            else if (x == 1368 && y <= 792)
                y += 72;
            else if (x >= 1008 && y == 864)
                x -= 72;
            else if (x == 936 && y >= 864)
                y -= 72;
            else if (x >= 432 && y == 792)
                x -= 72;
            else if (x == 360 && y >= 648)
                y -= 72;
            else if (x >= 72 && y == 576)
                x -= 72;
            else if (x == 0 && y == 576)
                flag = 3;
        }
        if (flag == 3)
        {
            if (x == 0 && y == 576)
                x += 504;
            else if (x == 504  && y <= 576)
                y += 72;
            else if (x <= 504 && y == 648)
                x += 72;
            else if (x == 576 && y >= 504)
                y -= 72;
            else if (x <= 576 && y == 432)
                x += 72;
            else if (x == 648 && y <= 432)
                y += 72;
            else if (x <= 936 && y == 504)
                x += 72;
            else if (x == 1008 && y >= 432 && y <= 576)
                y -= 72;
            else if (x <= 1152 && y == 360)
                x += 72;
            else if (x == 1224 && y <= 504)
                y += 72;
            else if (x <= 1368 && y == 576)
                x += 72;
            else if (x == 1440 && y == 576)
                y += 72;
            else if (x >= 1296 && y == 648)
                x -= 72;
            else if (x == 1224 && y == 648)
                y += 72;
            else if (x >= 1152 && y == 720)
                x -= 72;
            else if (x == 1080 && y >= 720)
                y -= 72;
            else if (x >= 720 && y == 648)
                x -= 72;
            else if (x == 648 && y == 648)
                flag = 4;
            }
        if (flag == 4) {
            if (x == 648 && y == 648)
                x = 792, y = 360;
            else if (x == 792 && y == 360)
                x += 72;
        }
    }

    new[nbr + 1] = NULL;

    return new;
}

void count_tower(tower_t *towers)
{
    int i = 0;
    for (;towers; i++) {
        towers = towers->next;
    }
}

void print_tower(sfRenderWindow *window, tower_t *towers)
{
    //count_tower(towers);
    if (!towers)
        return;
    while (towers) {
        sfRenderWindow_drawSprite(window, towers->sprite, NULL);
        towers = towers->next;
    }
}

void fill_mouse(input_t *input, char *path)
{
    if (input->fill == input->tower)
        return;
    input->sprite = sfSprite_create();
    input->texture = sfTexture_createFromFile(path, NULL);
    sfSprite_setTexture(input->sprite, input->texture, sfFalse);
    input->fill = input->tower;
}

void print_mouse(sfRenderWindow *window, input_t *input)
{
    sfVector2i mouse = sfMouse_getPosition((sfWindow *)window);
    input->pos.x = mouse.x;
    input->pos.y = mouse.y;
    sfSprite_setPosition(input->sprite, input->pos);
    sfRenderWindow_drawSprite(window, input->sprite, NULL);
}

void take_tower(sfRenderWindow *window, input_t *input)
{
    if (input->click == 1) {
        if (input->tower == 1)
            fill_mouse(input, "pictures/volcan_red.png");
        if (input->tower == 2)
            fill_mouse(input, "pictures/volcan_green.png");
        if (input->tower == 3)
            fill_mouse(input, "pictures/volcan_blue.png");
        if (input->tower == 4)
            fill_mouse(input, "pictures/volcan_black.png");
        print_mouse(window, input);
    }
}

tower_t *add_tower(tower_t *towers, const char *path, sfVector2f pos, int a)
{
    tower_t *new_towers = create_tower(path, pos, a);

    if (!towers)
        return new_towers;

    new_towers->next = towers;
    return new_towers;
}

tower_t *create_tower(const char *path, sfVector2f pos, int a)
{
    tower_t *towers = malloc(sizeof(tower_t));
    if (!towers)
        return NULL;
    towers->lvl = a;
    towers->sprite = sfSprite_create();
    towers->s_degats = sfSprite_create();
    towers->pos = pos;
    towers->p_degats = pos;
    towers->texture = sfTexture_createFromFile(path, NULL);
    towers->t_degats = sfTexture_createFromFile("pictures/volcan_red.png", NULL);
    towers->next = NULL;

    sfSprite_setTexture(towers->sprite, towers->texture, sfFalse);
    sfSprite_setPosition(towers->sprite, pos);
    sfSprite_setTexture(towers->s_degats, towers->t_degats, sfFalse);
    sfSprite_setPosition(towers->s_degats, towers->p_degats);

    return towers;
}

void wich_tower(tower_t *towers, enemie_t *enemies)
{
    if (towers->lvl == 1)
        enemies->life_struct->life -= 7;
    if (towers->lvl == 2)
        enemies->life_struct->life -= 9;
    if (towers->lvl == 3)
        enemies->life_struct->life -= 11;
    if (towers->lvl == 4)
        enemies->life_struct->life -= 15;
}

void find_pos_tower(tower_t *towers, enemie_t *enemies, sfRenderWindow *window)
{
    sfVector2f p_n = enemies->pos;
    sfVector2f e = {0,0};

    for (int i = 0; towers; i++) {
        if (((p_n.x <= (towers->pos.x + 72) && p_n.x >= (towers->pos.x - 72))
        || (p_n.x >= towers->pos.x && p_n.x <= (towers->pos.x + 72)))
        && ((p_n.y >= (towers->pos.y) && p_n.y <= (towers->pos.y + 144))
        || (p_n.y <= (towers->pos.y + 72) && p_n.y >= (towers->pos.y - 72)))) {
            wich_tower(towers, enemies);
            sfSprite_setPosition(towers->s_degats, e);
            sfRenderWindow_drawSprite(window, towers->s_degats, NULL);
        }
        towers = towers->next;
    }
}

void hit_box(tower_t *towers, enemie_t *enemies, sfRenderWindow *window)
{
    for (int i = 0; enemies; i++) {
        find_pos_tower(towers, enemies, window);
        enemies = enemies->next;
    }
}

sfClock *check_hit_tower(tower_t *towers, enemie_t *enemies, sfClock *clock, sfRenderWindow *window)
{
    sfTime time = sfClock_getElapsedTime(clock);
    float seconds = time.microseconds / 1000000;

    if (seconds > 0.01)
    {
        hit_box(towers, enemies, window);
        sfClock_restart(clock);
    }
    return clock;
}