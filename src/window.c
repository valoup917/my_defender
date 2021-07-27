/*
** EPITECH PROJECT, 2021
** window
** File description:
** .
*/

#include "../include/defender.h"

void damage_enemies(enemie_t *enemies);
int check_end(text_t *score);
int my_print_organisation(map_t *background, enemie_t *enemies,
text_t *score, sfRenderWindow *window);
void take_tower(sfRenderWindow *window, input_t *input);
tower_t *check_pos_click(sfRenderWindow *window, input_t *input,
tower_t *towers);
void print_tower(sfRenderWindow *window, tower_t *towers);
input_t *create_input(void);
int **fill_places(void);
sfClock *check_hit_tower(tower_t *towers, enemie_t *enemies, sfClock *clock, sfRenderWindow *window);

text_t *create_all_text(void);

int main(int ac, char **argv, char **env)
{
    (void)ac;
    (void)argv;
    my_organisation(env);
    return 0;
}

int my_organisation(char **env)
{

    map_t *background = create_background();
    enemie_t *enemies = create_enemies(5);
    text_t *score = create_all_text();

    if (my_window(background, enemies, score, env) == 1)
        return 1;
    return 0;
}

int my_window(map_t *background, enemie_t *enemies, text_t *score, char **env)
{
    my_game_t *str = backround_img(str);
    str->my_env = env;
    tower_t *towers = NULL;
    sfVideoMode video_mode = {1920, 1080, 32};
    str->window = sfRenderWindow_create(video_mode,
    "my defender", sfClose | sfResize, NULL);
    input_t *input = create_input();
    orga_t *all = organisation();
    input->gold_tmp = score->gold_tmp;
    sfEvent event;

    while (sfRenderWindow_isOpen(str->window)) {
        sfRenderWindow_display(str->window);
        while (sfRenderWindow_pollEvent(str->window, &event)) {
            str->event = event;
            towers = analyse_events(str->window, event, input, towers);
        }
        menu_pages(str, background, enemies, score, all);
    }
    all_dest(str);
    return 0;
}

int game_start(my_game_t *str, map_t *background, enemie_t *enemies, text_t *score)
{
    sfRenderWindow_close(str->window);
    pid_t pid = fork();
    int status;

    if (pid == -1) {
        return;
    }
    if (pid == 0)
        execve("include/my_defender", NULL, str->my_env);
    else
        waitpid(pid, &status, 0);
}

int check_end(text_t *score)
{
    score = score->next;
    if (score->life_tmp <= 0)
        return 1;
    return 0;
}

tower_t *analyse_events(sfRenderWindow *window, sfEvent event,
input_t *input, tower_t *towers)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
    if (sfKeyboard_isKeyPressed(sfKeyEscape))
        sfRenderWindow_close(window);
    if (event.type == sfEvtMouseButtonPressed &&
        sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
        towers = check_pos_click(window, input, towers);
    return towers;
}

void damage_enemies(enemie_t *enemies)
{
    while (enemies) {
        enemies->life_struct->life -= 0.000001;
        enemies = enemies->next;
    }
}

input_t *create_input(void)
{
    input_t *input = malloc(sizeof(input_t));

    input->click = 0;
    input->tower = 0;
    input->place = fill_places();
    input->sprite = sfSprite_create();
    input->texture = sfTexture_createFromFile("pictures/volcan_red.png", NULL);
    sfSprite_setTexture(input->sprite, input->texture, sfFalse);
    return input;
}