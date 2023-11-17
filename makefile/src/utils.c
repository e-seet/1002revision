
#include "../include/utils.h"

int total(int x)
{
	return x * 2;
}

// DO NOT NEED TO KNOW HOW TO DO IT. JUST UNDERSTAND THE CONCEPT
// For ft_split
int	numofwords(const char *s, char c)
{
	int		count;
	char	*str;

	str = (char *) s;
	count = 0;
	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (*str)
		{
			count = count + 1;
			str++;
		}
		while (*str && *str != c)
			str++;
	}
	return (count);
}

int	wordlen(const char *s, char c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (s[i] == c)
		i++;
	while (s[i] && s[i] != c)
	{
		len++;
		i++;
	}
	return (len);
}

char	*copycontent(const char *s, char c)
{
	int		i;
	int		len;
	char	*str;

	if (!s)
		return (0);
	i = 0;
	len = wordlen(s, c);
	str = malloc((len + 1) * sizeof(char)); 
	if (!str)
		return (NULL);
	while (len > i)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	*list_free(char **strs, int i)
{
	while (--i >= 0)
		free(strs[i]);
	free(strs);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int		num;
	int		i;
	char	*str;
	char	**strs;

	i = 0;
	str = (char *) s;
	num = numofwords(str, c);
	strs = malloc(sizeof(char *) * (num + 1));
	if (!strs)
		return (0);
	while (num > i)
	{
		while (*str && *str == c)
			str++;
		strs[i] = copycontent(str, c);
		if (!strs[i])
			return (list_free(strs, i));
		str = str + wordlen(str, c);
		i++;
	}
	strs[i] = NULL;
	return (strs);
}
