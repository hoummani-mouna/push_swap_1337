#include "push_swap.h"
static int	count_words(char const *s, char c)
{
	int	count;
	int	i;
	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}
static char	*get_next_word(char const *s, char c, int *cursor)
{
	char	*word;
	int		len;
	int		start;
	int		i;
	len = 0;
	while (s[*cursor] == c)
		(*cursor)++;
	start = *cursor;
	while (s[*cursor] && s[*cursor] != c)
	{
		len++;
		(*cursor)++;
	}
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
		word[i++] = s[start++];
	word[i] = '\0';
	return (word);
}
static void	free_all(char **strs, int j)
{
	while (j > 0)
		free(strs[--j]);
	free(strs);
}
char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		word_count;
	int		i;
	int		cursor;
	if (!s)
		return (NULL);
	word_count = count_words(s, c);
	strs = malloc(sizeof(char *) * (word_count + 1));
	if (!strs)
		return (NULL);
	i = 0;
	cursor = 0;
	while (i < word_count)
	{
		strs[i] = get_next_word(s, c, &cursor);
		if (!strs[i])
		{
			free_all(strs, i);
			return (NULL);
		}
		i++;
	}
	strs[i] = NULL;
	return (strs);
}
