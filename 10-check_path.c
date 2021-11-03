#include "main.h"

/**
*  * checkPath - searches $PATH for directory of command
*   *
*    * Description: checks the path of a given command
*     * @build: input build
*      * Return: the state of the path values
*/
int check_path(config *build)
{
register int len;
static char buffer[BUFSIZE];
struct stat st;
char *token, *copy, *delim = ":", *tmp;
int inLoop = 0;

if (validate_constraints(build))
return (1);
copy = _strdup(build->path);
token = _strtok(copy, delim);
while (token)
{
tmp = inLoop ? token - 2 : token;
if (*tmp == 0 && stat(build->args[0], &st) == 0)
{
build->full_path = build->args[0];
return (1);
}
len = _strlen(token) + _strlen(build->args[0]) + 2;
_strcat(buffer, token);
_strcat(buffer, "/");
_strcat(buffer, build->args[0]);
get_null_bytes(buffer, len - 1);
if (stat(buffer, &st) == 0)
{
build->full_path = buffer;
free(copy);
return (1);
}
get_null_bytes(buffer, 0);
token = _strtok(NULL, delim);
inLoop = 1;
}
build->full_path = build->args[0];
return (0);
}

/**
*  * checkEdgeCases - helper func for check path to check edge cases
*   * @build: input build
*    * Return: 1 if found, 0 if not
*/
int validate_constraints(config *build)
{
char *copy;
struct stat st;

copy = _strdup(build->path);
if (!copy)
{
build->full_path = build->args[0];
return (1);
}
if (*copy == ':' && stat(build->args[0], &st) == 0)
{
build->full_path = build->args[0];
return (1);
}
free(copy);
return (0);
}
