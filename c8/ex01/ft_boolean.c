/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 11:06:48 by gschwart          #+#    #+#             */
/*   Updated: 2023/08/30 11:08:06 by gschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_boolean.h"

int main(int argc, char *argv[])
{
    if (EVEN(argc - 1)) {
        write(1, EVEN_MSG, sizeof(EVEN_MSG) - 1);
    } else {
        write(1, ODD_MSG, sizeof(ODD_MSG) - 1);
    }
    
    return SUCCESS;
}

