/*
** EPITECH PROJECT, 2021
** score
** File description:
** .
*/

#include "../include/defender.h"

text_t *add_text(text_t *text, sfVector2f p, const char *str);

void move_wave_text(text_t *score, int wave)
{
    char *new = my_strcat("Wave : ", my_itc(wave));
    sfText_setString(score->text, new);
}

int check_gold_enemies_dead(enemie_t *enemies)
{
    int pessos = 0;

    while (enemies) {
        if (enemies->life_struct->life <= 0 && enemies->gold != 0 && enemies->life_struct->life != -2) {
            pessos += enemies->gold;
            enemies->gold = 0;
        }
        enemies = enemies->next;
    }
    return pessos;
}

void count_my_gold(enemie_t *enemies, text_t *score)
{
    score->gold_tmp += 0;
    score->gold_tmp += check_gold_enemies_dead(enemies);
}

void move_gold(text_t *score)
{
    char *str = my_itc(score->gold_tmp);
    str = my_strcat("Gold : ", str);
    sfText_setString(score->text, str);
}

void check_life_end(enemie_t *enemies, text_t *score)
{
    while (enemies) {
        if (enemies->life_struct->life == -1) {
            score->life_tmp -= 1;
            enemies->life_struct->life = -2;
            char *str = my_itc(score->life_tmp);
            str = my_strcat("Life : ", str);
            sfText_setString(score->text, str);
        }
        enemies = enemies->next;
    }
}

int print_text(text_t *score, sfRenderWindow *window,
int wave, enemie_t *enemies)
{
    int gold = score->gold_tmp;

    move_wave_text(score, wave);
    sfRenderWindow_drawText(window, score->text, NULL);
    score = score->next;
    check_life_end(enemies, score);
    sfRenderWindow_drawText(window, score->text, NULL);
    score = score->next;
    gold += check_gold_enemies_dead(enemies);
    score->gold_tmp = gold;
    move_gold(score);
    gold = score->gold_tmp;
    sfRenderWindow_drawText(window, score->text, NULL);
    score = score->next;
    sfText_setColor(score->text, sfYellow);
    sfText_setCharacterSize(score->text, 27);
    sfRenderWindow_drawText(window, score->text, NULL);
    score = score->next;
    sfText_setColor(score->text, sfGreen);
    sfText_setCharacterSize(score->text, 27);
    sfRenderWindow_drawText(window, score->text, NULL);
    score = score->next;
    sfText_setColor(score->text, sfBlue);
    sfText_setCharacterSize(score->text, 27);
    sfRenderWindow_drawText(window, score->text, NULL);
    score = score->next;
    sfText_setColor(score->text, sfRed);
    sfText_setCharacterSize(score->text, 27);
    sfRenderWindow_drawText(window, score->text, NULL);

    return gold;
}

text_t *create_all_text(void)
{
    text_t *text = NULL;
    sfVector2f coin_p = {70, 30};
    sfVector2f life_p = {1750, 30};
    sfVector2f vague_p = {50, 940};
    sfVector2f t1_p = {820, 88};
    sfVector2f t2_p = {915, 88};
    sfVector2f t3_p = {1010, 88};
    sfVector2f t4_p = {1105, 88};
    char *coin_str = my_strcat("Gold : ", my_itc(0));
    char *life_str = my_strcat("Life : ", my_itc(20));
    char *vague_str = my_strcat("Wave : ", my_itc(0));
    char *t_4 = my_itc(60);
    char *t_3 = my_itc(50);
    char *t_2 = my_itc(40);
    char *t_1 = my_itc(30);
    text = add_text(text, t4_p, t_4);
    text = add_text(text, t3_p, t_3);
    text = add_text(text, t2_p, t_2);
    text = add_text(text, t1_p, t_1);
    text = add_text(text, coin_p, coin_str);
    text = add_text(text, life_p, life_str);
    text = add_text(text, vague_p, vague_str);
    return text;
}

text_t *add_text(text_t *text, sfVector2f p, const char *str)
{
    text_t *new_text = create_score(p, str);
    if (text == NULL) {
        return new_text;
    }
    new_text->next = text;
    return new_text;
}

text_t *create_score(sfVector2f position, const char *str)
{
    text_t *score = malloc(sizeof(text_t));
    if (!score)
        return NULL;
    score->pos = position;
    score->life_tmp = 20;
    score->gold_tmp = 160;
    score->text = sfText_create();
    score->font = sfFont_createFromFile("font/3d.ttf");
    sfText_setString(score->text, str);
    sfText_setFont(score->text, score->font);
    sfText_setColor(score->text, sfWhite);
    sfText_setPosition(score->text, score->pos);
    score->gold_tmp = 160;
    return score;
}

int len_nbr(int x)
{
    if (x >= 100000)
        return 6;
    if (x >= 10000)
        return 5;
    if (x >= 1000)
        return 4;
    if (x >= 100)
        return 3;
    if (x >= 10)
        return 2;
    return 1;
}

char *my_itc(int nbr)
{
    int len = len_nbr(nbr);
    char *result = malloc(sizeof(char) * len + 1);
    for (int i = 0; i != len; i++) {
    	result[i] = nbr % 10 + '0';
    	nbr /= 10;
    }
    result[len] = '\0';
    my_revstr(result);
    return result;
}