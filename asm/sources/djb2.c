
unsigned int		djb2(char *str)
{
	unsigned int	hash;
	unsigned int	i;

	hash = 5381;
	i = 0;
	if (str == 0x00 || str[0] == '\0')
		return (0);
	while (str[i])
	{
		hash = ((hash << 5) + hash) + str[i];
		++i;
	}
	return (hash);
}
