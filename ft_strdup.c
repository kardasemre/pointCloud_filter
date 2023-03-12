#include "main.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	len;
	char	*str;

	len = ft_strlen(s1);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

size_t
	ft_strlen(const char *s)
{
	size_t		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void
	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (!dst && !src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}

char    **ft_split(char *str)
{
    int i;
    int k;
    int j;
    char **split;

    i = 0;
    k = 0;
    if(!(split = (char **)malloc(sizeof(char) * 256)))
        return(NULL);
    while(str[i] <= 32)
        i++;
    while(str[i])
    {
        j = 0;
        if(!(split[k] = (char *)malloc(sizeof(char) * 4096)))
            return(NULL);
        while(str[i] > 32 && str[i])
            split[k][j++] = str[i++];
        while(str[i] <= 32 && str[i])
            i++;
        split[k][j] = '\0';
        k++;
    }
    split[k] = NULL;
    return(split);
}