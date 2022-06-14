/*
** EPITECH PROJECT, 2021
** Unix System Programming2
** File description:
** prototypes.h
*/

#include <stdio.h>
#include "struct.h"

#ifndef __PROTOTYPES__
    #define __PROTOTYPES__

void show_type(void);
void my_putchar(char c);
void free_tab(char **env);
void show_env(char **env);
void show_error(int errnum);
void ctrl_d(stocker_t *stock);
void not_a_directory(char *str);
void too_many_args(char **args);
void my_cd(char **env, char **args);
void detect_error(int error, char *name);
void my_setenv(stocker_t *stock, char **args);
void my_unsetenv(stocker_t *stock, char **args);
void replace_by_name(stocker_t *stock, int index, char *name);
void fill_tab(char *str, char *dest, char sep, stocker_t *stock);
void commandexecution(char **program, char **list, stocker_t *stock);
void replace_by_name_args(stocker_t *stock, int index, char *name, char *args);
int my_strlen(char *str);
int find_null(char **env);
int args_cmpt(char **args);
int find_len_lane(char *str);
int my_putstr(char const *str);
int my_getnbr(char const *str);
int alphanum_detect(char *str);
int command_not_found(char *str);
int find_nb_args(char **program);
int find_step(char *str, char sep);
int my_move(char **oldpwd, char **args);
int access_denied(char *str, int checker);
int my_back(char **oldpwd, char **oldpwd2);
int pathfinding(char *str, const char *name);
int my_strcmp(char const *str1, char const *str2);
int place_name_to_env(stocker_t *stock, char **args);
int execvecommand(char *path, char **args, char **env);
int find_len_elem(char *str, char sep, stocker_t *stock);
int place_name_args_to_env(stocker_t *stock, char **args);
int my_builtin(const char *program, char **args, stocker_t *stock);
char *my_strcy(char *str);
char *copy_str(char *name);
char *my_getpwd(char *pwd, char *name);
char *check_program_exist(char *program);
char **get_path(char **env, stocker_t *stock);
char **copy_paste_env(int *i, int *j, char **env);
char **copy_env2(char **env, char *name, char *args);
char **copy_paste_name(char **env2, char *name, int *i);
char **str_to_str_array(char *str, char sep, stocker_t *stock);
char **array_command(stocker_t *stock, char *program, ssize_t nread);

#endif