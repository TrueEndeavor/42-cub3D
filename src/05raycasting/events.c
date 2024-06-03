/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogalio <rmouchel@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 09:13:51 by lannur-s          #+#    #+#             */
/*   Updated: 2024/06/03 16:01:50 by rogalio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void free_dup_map(t_data *data)
{
    int i;

    i = 0;
    while (i < data->map_height)
    {
        free(data->dup_map[i]);
        i++;
    }
    free(data->dup_map);
}

int on_keypress(int key, t_data *data)
{
    double moveSpeed = 0.6; // Vitesse de déplacement
    double rotSpeed = 0.3;  // Vitesse de rotation

    if (key == 65307) // Touche Échap
    {

        exit(0);
    }
    if (key == 119) // Touche W
        move_up(data, moveSpeed);
    if (key == 115) // Touche S
        move_down(data, moveSpeed);
    if (key == 97) // Touche A
        rotate_left(data, rotSpeed);
    if (key == 100) // Touche D
        rotate_right(data, rotSpeed);
    return 0;
}

int	on_mouse(int x, int y, t_data *data)
{
    static int lastX = screenWidth / 2; // Position précédente de la souris
    int diffX = x - lastX;
    double rotSpeed = 0.005 * diffX; // Ajuster la vitesse de rotation
    (void)data;
    (void)y;
    double oldDirX =  data->game.dir_x;
     data->game.dir_x =  data->game.dir_x * cos(-rotSpeed) - data->game.dir_y * sin(-rotSpeed);
    data->game.dir_y = oldDirX * sin(-rotSpeed) + data->game.dir_y * cos(-rotSpeed);
    double oldPlaneX = data->game.plane_x;
    data->game.plane_x = data->game.plane_x * cos(-rotSpeed) - data->game.plane_y * sin(-rotSpeed);
    data->game.plane_y = oldPlaneX * sin(-rotSpeed) + data->game.plane_y * cos(-rotSpeed);

    lastX = x;
    return 0;
}

















