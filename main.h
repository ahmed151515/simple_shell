#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
char *StrCopy(char *s1);
char **SetCmd(char *s);
char *StrCon(char *s1, char *s2);
char *Find_Path(char *s);
int combar(char *s1, char *s2);
void free_cmd(char **cmd);
int is_spase_line(char *s);
#endif
