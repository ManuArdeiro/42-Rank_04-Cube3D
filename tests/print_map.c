/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ardeiro <Ardeiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:22:08 by Ardeiro           #+#    #+#             */
/*   Updated: 2024/05/06 21:17:38 by Ardeiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void    ft_print_map(t_list *map)
{
    t_list  *temp;

    temp = map;
    while (temp->next)
    {
        printf("%s\n", (char *)temp->content);
        temp = temp->next;

    }
    printf("%s\n", (char *)temp->content);
    return ;
}