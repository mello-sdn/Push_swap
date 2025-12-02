#include "../../include/push_swap.h"

static int	count_words(char *s, char c)
{
	int		count;
	bool	in_word;

	count = 0;
	in_word = false;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			count++;
			in_word = true;
		}
		else if (*s == c)
			in_word = false;
		s++;
	}
	return (count);
}

static char	*get_next_word(char *s, char c, int *cursor)
{
	int		len;
	int		i;
	char	*word;

    len = 0;
    i = 0;
    while (s[*cursor] == c)
        (*cursor)++;
    while (s[*cursor + len] && s[*cursor + len] != c)
        len++;
    word = malloc(len + 1);
    if (!word)
        return (NULL);
    while (s[*cursor] && s[*cursor] != c)
        word[i++] = s[(*cursor)++];
    word[i] = '\0';
    return (word);
}

static void	free_split_partial(char **tab, int filled)
{
	while (filled > 0)
		free(tab[--filled]);
	free(tab);
}

char	**split(char *s, char c)
{
    int		words;
    char	**res;
    int		i;
    int		cursor;

    if (!s)
    	return (NULL);
    words = count_words(s, c);
    res = malloc(sizeof(char *) * (words + 1));
    if (!res)
    	return (NULL);
    cursor = 0;
    i = 0;
    while (i < words)
	{
		res[i] = get_next_word(s, c, &cursor);
		if (!res[i])
		{
			free_split_partial(res, i);
			return (NULL);
		}
		i++;
	}
	res[i] = NULL;
	return (res);
}
