#include "main.h"

char
	*ft_strjoin_free(char *s1, char *s2)
{
	size_t		len_s1;
	size_t		len_s2;
	char		*str;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!str)
		return (NULL);
	ft_memcpy(str, s1, len_s1);
	free(s1);
	ft_memcpy(str + len_s1, s2, len_s2);
	str[len_s1 + len_s2] = 0;
	return (str);
}
