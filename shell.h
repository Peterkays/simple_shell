#ifndef _SHELL_H_
#define _SHELL_H_

/* Required libraries */
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>

/* Environmental variables */
extern char **enviro;

/* Function declarations (prototypes) for main functions*/
void _looper(void);
char *_lyn_read(void);
char **_lyn_split(char *lyn);
int _executing(char **arrgz, char *nputt);
int _begin(char **arrgz);
void signl_hadler(int sg);

/* Function declarations (prototypes for for builtin shell commands */
int star_exit(char **arrgz, char *nputt);
int _cdir(char **arrgz, __attribute__((unused)) char *nputt);
/**
  * _hellp - Help function
  * @arrgz: List of arguments passed from parsing.
  * @nputt: Nputt line for free.
  * Return: 1 if works.
  */
int _hellp(__attribute__((unused)) char **arrgz,
		__attribute__((unused)) char *nputt);

/**
  * _envyr - Env function
  * @arrgz: List of arguments passed from parsing.
  * @nputt: Nputt line for free.
  * Return: 1 if works.
  */
int _envyr(__attribute__((unused)) char **arrgz,
	__attribute__((unused)) char *nputt);
int _set_envi(char *the_nme, char *its_valu);

/* Function declarations (prototypes) for auxiliary funtions */
ssize_t _gt_lyn(char **b, size_t *size_ofbaffa, FILE *strim);
int _ridchar(void);

char *_stritknz(char *s, const char *delimie);
char *_stritknz_r(char *s, const char *delimie, char **accept_stri);
int _stri_ptn(char *sy, const char *delimie);
int _strieq_ptn(char *ss, const char *delimie);

void *_smart_alloc(void *pntr, unsigned int foma_size, unsigned int curnt_size);

char *_get_envir(const char *the_nme);
char **_way(char *way);
char **_split_way(char *lyn, char *copy_lyn);
char **_check_way(char **arrgz, int *sine);

int _stri_size(char *s);
char *_stri_cat(char *destin, char *stg);
int _stri_comp(char *st1, char *st2);
char *_stri_dupl(char *destin, char *stg);
int _stri_compa(const char *st1, const char *st2, size_t n);
int _putchar(char c);
void _puts(char *str);
int _atoi(char *q);

#endif

