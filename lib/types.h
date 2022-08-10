#ifndef TYPES_H
#define TYPES_H

#define STR_TO_INT(val) (val - 48)
#define INT_TO_STR(val) (val + 48)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

typedef struct list_s
{
	int value;
	struct list_s *next;
} list_t;

typedef struct
{
	char *keyword;
	int (*op)(char **, char *, list_t **);
} execute_functions;

#endif