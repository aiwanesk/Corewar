/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   djb2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 13:30:40 by aiwanesk          #+#    #+#             */
/*   Updated: 2017/03/17 13:31:56 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
