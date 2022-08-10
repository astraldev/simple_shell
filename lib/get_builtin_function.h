
#include "types.h"
#include "print_working_directory.h"
#include "change_directory.h"
#include "echo.h"
#include "help.h"
#include "env_variables.h"

int (*get_builtin_function(char *))(char **, char *, list_t **);
