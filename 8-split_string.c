#include "main.h"

/**
*  * splitString - splits string into an array of strings
*   * separated by spaces
*    * @build: input build
*     *
*      * Description: Gets the input string,
*       * then breaks it into individual tokens and
*        * store it in an array ans separately to implement them
*         * Return: 1 if able to split, 0 if not
*/
int split_string(config *build)
{
register unsigned int i = 0;
char *tok, *cpy;

cpy = _strdup(build->buffer);
tok = _strtok(cpy, " ");
if (count_words(build->buffer) == 0)
{
build->args = NULL;
free(build->buffer);
return (0);
}
build->args = malloc((count_words(build->buffer) + 1) * sizeof(char *));
while (tok)
{
build->args[i] = _strdup(tok);
tok = _strtok(NULL, " ");
i++;
}
build->args[i] = NULL;
free(cpy);

return (1);
}

/**
*  * count_words - count number of words in a string
*   * @str: input string
*    *
*     * Description: gets letters in ever word, checks for
*      * empty spaces constraints and returns the word's total count
*       * Return: number of words
*/
unsigned int count_words(char *str)
{
register int words = 0;
int word_on = 0;

while (*str)
{
if (is_space(*str) && word_on)
{
word_on = 0;
}
else if (!is_space(*str) && !word_on)
{
word_on = 1;
words++;
}
str++;
}
return (words);
}

/**
*  * is_space - determines if char is a space
*   * @c: input char
*    * Return: 1 or 0
*/
int is_space(char c)
{
return (c == ' ');
}
