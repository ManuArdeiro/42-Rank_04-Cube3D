/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ardeiro <Ardeiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 00:53:42 by Ardeiro           #+#    #+#             */
/*   Updated: 2024/05/07 02:06:59 by Ardeiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char    *ft_north_texture(char *str)
{
    int     i;
    int     j;
    char    *path;

    i = 0;
    j = 0;
    path = malloc(ft_strlen(str));
    while (ft_is_space(str[i]))
        i++;
    if (!(str[i] == 'N' && str[i + 1] == 'O' && ft_is_space(str[i + 2])))
        return (NULL);
    while (ft_is_space(str[i]))
        i++;
    while (str[i])
    {
        path[j] = str[i];
        i++;
        j++;
    }
    path[j] = '\0';
    return (path);
}

char    *ft_south_texture(char *str)
{
    int     i;
    int     j;
    char    *path;

    i = 0;
    j = 0;
    path = malloc(ft_strlen(str));
    while (ft_is_space(str[i]))
        i++;
    if (!(str[i] == 'S' && str[i + 1] == 'O' && ft_is_space(str[i + 2])))
        return (NULL);
    while (ft_is_space(str[i]))
        i++;
    while (str[i])
    {
        path[j] = str[i];
        i++;
        j++;
    }
    path[j] = '\0';
    return (path);
}

char    *ft_east_texture(char *str)
{
    int     i;
    int     j;
    char    *path;

    i = 0;
    j = 0;
    path = malloc(ft_strlen(str));
    while (ft_is_space(str[i]))
        i++;
    if (!(str[i] == 'E' && str[i + 1] == 'A' && ft_is_space(str[i + 2])))
        return (NULL);
    while (ft_is_space(str[i]))
        i++;
    while (str[i])
    {
        path[j] = str[i];
        i++;
        j++;
    }
    path[j] = '\0';
    return (path);
}

char    *ft_west_texture(char *str)
{
    int     i;
    int     j;
    char    *path;

    i = 0;
    j = 0;
    path = malloc(ft_strlen(str));
    while (ft_is_space(str[i]))
        i++;
    if (!(str[i] == 'W' && str[i + 1] == 'E' && ft_is_space(str[i + 2])))
        return (NULL);
    while (ft_is_space(str[i]))
        i++;
    while (str[i])
    {
        path[j] = str[i];
        i++;
        j++;
    }
    path[j] = '\0';
    return (path);
}
