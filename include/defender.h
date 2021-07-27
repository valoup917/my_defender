/*
** EPITECH PROJECT, 2021
** include
** File description:
** .
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

typedef struct map_s
{
    sfSprite *sprite_map;
    sfTexture *texture_map;
    sfVector2f pos;
    struct map_s *next;
} map_t;

typedef struct life_s
{
    int life;
    sfVector2f pos;
    sfSprite *life_sprite;
    sfTexture *life_full;
    sfTexture *life_1;
    sfTexture *life_2;
    sfTexture *life_3;
    sfTexture *life_4;
    sfTexture *life_5;
} life_t;

typedef struct enemie_s
{
    sfSprite *sprite_enemie;
    sfTexture *texture_enemie;
    sfIntRect rect_enemie;
    sfVector2f pos;
    sfClock *clock;
    sfClock *rect_clock;
    int lvl;
    int randome;
    int gold;
    life_t *life_struct;
    struct enemie_s *next;
} enemie_t;

typedef struct text_s
{
    sfVector2f pos;
    sfText *text;
    sfFont *font;
    char *string;
    struct text_s *next;
    int gold_tmp;
    int life_tmp;
} text_t;

typedef struct input_s
{
    int **place;
    int click;
    int tower;
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    int fill;
    int gold_tmp;
} input_t;

typedef struct tower_s
{
    sfSprite *sprite;
    sfSprite *s_degats;
    sfTexture *texture;
    sfTexture *t_degats;
    sfVector2f pos;
    sfVector2f p_degats;
    int lvl;
    struct tower_s *next;
} tower_t;

typedef struct my_game_s
{
    sfRenderWindow *window;
    sfEvent event;
    sfMusic *music;
    sfMusic *effect1;
    sfTexture *t_bcg1;
    sfSprite *s_bcg1;
    sfTexture *t_bcg2;
    sfSprite *s_bcg2;
    sfVector2f poscursor;
    sfTexture *t_string;
    sfSprite *s_string;
    sfVector2f pos_string;
    sfTexture *t_string_2;
    sfSprite *s_string_2;
    int a;
    int b;
    char **my_env
} my_game_t;

typedef struct orga_s
{
    my_game_t *start;
    my_game_t *exit;
    my_game_t *m_exit;
    my_game_t *pause_exit;
    my_game_t *man;
    my_game_t *home;
    my_game_t *resume;
} orga_t;

typedef struct music_s
{
    sfMusic *music;
    sfSoundBuffer *buffer2;
    sfSound *sound2;
    sfSoundBuffer *buffer1;
    sfSound *sound1;
} music_t;

//My Functions

int menu_pages(my_game_t *str, map_t *background, enemie_t *enemies, text_t *score, orga_t *all);
int game_start(my_game_t *str, map_t *background, enemie_t *enemies, text_t *score);
void all_dest(my_game_t *str);

//Main Menu

void startButton(my_game_t *str);
void exitButton(my_game_t *str);
void smallButton(my_game_t *str);
my_game_t *backround_img();
void manButton(my_game_t *str);
void mouse(orga_t *all, my_game_t *str);
void main_menu_poz(my_game_t *str);
void draw_main_menu(my_game_t *str);

//Man Menu

void man(my_game_t *str);
void man_exit_button(orga_t *all, my_game_t *str);
void my_game_t_man(void);

//Pause Menu

void my_pause(my_game_t *str);
void pause_menu(orga_t *all, my_game_t *str);

//Loose Menu

void loose_menu(orga_t *all, my_game_t *str);

my_game_t *tButton(char *string, char *string_2, int i, int x);
orga_t *organisation();

/*lib*/
char *my_revstr(char *str);
char *my_strcat(char *dest, char *src);
int my_strlen(char const *str);
int my_strcmp(const char *str_o, const char *str_c);

/*life_texture.c*/
void degat1(enemie_t *enemies);
void degat2(enemie_t *enemies);
void degat3(enemie_t *enemies);
void degat4(enemie_t *enemies);
void degat5(enemie_t *enemies);

/*move_rect.c*/
void move_rect(enemie_t *enemies);
void move_rect2(enemie_t *enemies);
void move_right(enemie_t *enemies);
void move_down(enemie_t *enemies);
void move_up(enemie_t *enemies);

/*free_all.c*/
enemie_t *freelist(enemie_t *enemies);
enemie_t *free_enemies(enemie_t *enemies);
life_t *freelife(life_t *life_struct);

/*move_pos_enemiesnlife.c*/
void move_pos_enemies(enemie_t *enemies);
void move_life(enemie_t *enemies);
void move_by_part_up(enemie_t *enemies);
void move_by_part_down(enemie_t *enemies);


/*window.c*/
int my_organisation(char **env);
int my_window(map_t *background, enemie_t *enemies, text_t *score, char **env);
tower_t *analyse_events(sfRenderWindow *window, sfEvent event, input_t *input, tower_t *towers);

/*enemies.c*/
enemie_t *create_enemies(int a);
void print_enemies(sfRenderWindow *window, enemie_t *enemies);
int count_enemies(enemie_t *enemies);
int check_dead(enemie_t *enemies);

/*background.c*/
map_t *create_background(void);
map_t *add_background(map_t *map, char *path, sfVector2f pos);
map_t *fill_background(char *path, sfVector2f pos);
void print_background(sfRenderWindow *window, map_t *background);

/*score*/
int print_text(text_t *score, sfRenderWindow *window, int wave, enemie_t *enemies);
text_t *create_score(sfVector2f position, const char *str);
int len_nbr(int x);
char *my_itc(int nbr);

/*struct creation*/
enemie_t *add_object(enemie_t *enemies, const char *path_to_spritesheet,
sfVector2f pos, sfIntRect rect);
enemie_t *create_object(const char *path_to_spritesheet,
sfVector2f pos, sfIntRect rect);
life_t *create_life(void);
void fill_texture(life_t *life_struct);