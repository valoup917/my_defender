/*
** EPITECH PROJECT, 2021
** my_defender2
** File description:
** mouse_evt
*/

#include "defender.h"

void start_evt(my_game_t *str)
{
    sfVector2i mouse = sfMouse_getPosition(NULL);
    int mouse_x = str->event.mouseButton.x;
    int mouse_y = str->event.mouseButton.y;
    str->pos_string.x = 1220;
    str->pos_string.y = 300;

    tButton(str, "pictures/Start1.png", 1120, 300);
    if (str->pos_string.x < mouse.x && mouse.x < (str->pos_string.x + 600) &&
        (str->pos_string.y + 50 < mouse.y && mouse.y < (str->pos_string.y + 250)))
            tButton(str, "pictures/Start2.png", 1220, 300);
    if (str->event.type == sfEvtMouseButtonPressed) {
        if (str->pos_string.x < mouse_x && mouse_x < (str->pos_string.x + 600) &&
            (str->pos_string.y < mouse_y && mouse_y < (str->pos_string.y + 200)))
            str->a = 1;
    }
}

void exit_evt(my_game_t *str)
{
    sfVector2i mouse = sfMouse_getPosition(NULL);
    int mouse_x = str->event.mouseButton.x;
    int mouse_y = str->event.mouseButton.y;
    str->pos_string.x = 100;
    str->pos_string.y = 300;

    tButton(str, "pictures/exit1.png", 100, 300);
    if (str->pos_string.x < mouse.x && mouse.x < (str->pos_string.x + 600) &&
        (str->pos_string.y + 50 < mouse.y && mouse.y < (str->pos_string.y + 250)))
        tButton(str, "pictures/exit2.png", 100, 300);
    if (str->event.type == sfEvtMouseButtonPressed) {
        if (str->pos_string.x < mouse_x && mouse_x < (str->pos_string.x + 600) &&
            (str->pos_string.y < mouse_y && mouse_y < (str->pos_string.y + 200)))
            sfRenderWindow_close(str->window);
    }
}

void man_evt(my_game_t *str)
{
    sfVector2i mouse = sfMouse_getPosition(NULL);
    int mouse_x = str->event.mouseButton.x;
    int mouse_y = str->event.mouseButton.y;
    str->pos_string.x = 1650;
    str->pos_string.y = 800;

    tButton(str, "pictures/man1.png", 1650, 800);
    if (str->pos_string.x < mouse.x && mouse.x < (str->pos_string.x + 200) &&
        (str->pos_string.y + 50 < mouse.y && mouse.y < (str->pos_string.y + 250)))
        tButton(str, "pictures/man2.png", 1650, 800);
    if (str->event.type == sfEvtMouseButtonPressed) {
        if (str->pos_string.x < mouse_x && mouse_x < (str->pos_string.x + 600) &&
            (str->pos_string.y < mouse_y && mouse_y < (str->pos_string.y + 200)))
            str->a = 2;
    }
}

void mouse(my_game_t *str)
{
    start_evt(str);
    exit_evt(str);
    man_evt(str);
}
void game_start(my_game_t *str, map_t *background, enemie_t *enemies)
{
    printf("passe\n");
    all_dest(str);
    sfRenderWindow_close(str->window);
    if (access("../../B-MUL-200-PAR-2-1-mydefender-sheroz-ahmed.saroya/my_defender", X_OK) == 0)
        printf("ca va\n");
    else
        printf("erreur\n");
    pid_t pid = fork();
    int status;

    if (pid == -1) {
        printf("ca marche pas\n");
        return;
    }
    if (pid == 0)
        printf("ca passe\n"), execve("../../B-MUL-200-PAR-2-1-mydefender-sheroz-ahmed.saroya/my_defender", NULL, str->my_env);
    else
        waitpid(pid, &status, 0);
}
/*
void game_start(my_game_t *str, map_t *background, enemie_t *enemies)
{
    int i = 5;

    print_background(str->window, background);
    if (check_dead(enemies) == 0) {
            print_enemies(str->window, enemies);
    }
    else {
            i += 2;
            enemies = freeList(enemies);
            enemies = create_enemies(i);
    }
}
*/