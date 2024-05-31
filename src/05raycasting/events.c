/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogalio <rmouchel@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 09:13:51 by lannur-s          #+#    #+#             */
/*   Updated: 2024/05/31 15:30:56 by rogalio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"



void move_up(t_data *data, double move_speed)
{
    if (data->world_map[(int)(data->game.pos_x + data->game.dir_x * move_speed)][(int)data->game.pos_y] == 0)
        data->game.pos_x += data->game.dir_x * move_speed;
    if (data->world_map[(int)data->game.pos_x][(int)(data->game.pos_y + data->game.dir_y * move_speed)] == 0)
        data->game.pos_y += data->game.dir_y * move_speed;
}

void move_down(t_data *data, double move_speed)
{
    if (data->world_map[(int)(data->game.pos_x - data->game.dir_x * move_speed)][(int)data->game.pos_y] == 0)
        data->game.pos_x -= data->game.dir_x * move_speed;
    if (data->world_map[(int)data->game.pos_x][(int)(data->game.pos_y - data->game.dir_y * move_speed)] == 0)
        data->game.pos_y -= data->game.dir_y * move_speed;
}

void rotate_left(t_data *data, double rot_speed)
{
    double oldDirX = data->game.dir_x;
    data->game.dir_x = data->game.dir_x * cos(rot_speed) - data->game.dir_y * sin(rot_speed);
    data->game.dir_y = oldDirX * sin(rot_speed) + data->game.dir_y * cos(rot_speed);
    double oldPlaneX = data->game.plane_x;
    data->game.plane_x = data->game.plane_x * cos(rot_speed) - data->game.plane_y * sin(rot_speed);
    data->game.plane_y = oldPlaneX * sin(rot_speed) + data->game.plane_y * cos(rot_speed);
}

void rotate_right(t_data *data, double rot_speed)
{
    double oldDirX = data->game.dir_x;
    data->game.dir_x = data->game.dir_x * cos(-rot_speed) - data->game.dir_y * sin(-rot_speed);
    data->game.dir_y = oldDirX * sin(-rot_speed) + data->game.dir_y * cos(-rot_speed);
    double oldPlaneX = data->game.plane_x;
    data->game.plane_x = data->game.plane_x * cos(-rot_speed) - data->game.plane_y * sin(-rot_speed);
    data->game.plane_y = oldPlaneX * sin(-rot_speed) + data->game.plane_y * cos(-rot_speed);
}

int on_keypress(int key, t_data *data)
{
    double moveSpeed = 0.6; // Vitesse de déplacement
    double rotSpeed = 0.3;  // Vitesse de rotation

    if (key == 65307) // Touche Échap
        exit(0);
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

int	render(t_data *data)
{
    // Creer une nouvelle image
    void *img = mlx_new_image(data->mlx_ptr, data->win_width, data->win_height);
    int *img_data = (int *)mlx_get_data_addr(img, &data->textures.no_count, &data->textures.ea_count, &data->textures.so_count);

    for (int x = 0; x < data->win_width; x++) {
        // Calcul de lapositio  du rayon
        double cameraX = 2 * x / (double)data->win_width - 1;
        double rayDirX = data->game.dir_x + data->game.plane_x * cameraX;
        double rayDirY = data->game.dir_y + data->game.plane_y * cameraX;

        // Position de la carte
        int mapX = (int)data->game.pos_x;
        int mapY = (int)data->game.pos_y;

        // Longueur du rayon
        double sideDistX;
        double sideDistY;

        // Longueur du rayon jusqu'à la prochaine case
        double deltaDistX = fabs(1 / rayDirX);
        double deltaDistY = fabs(1 / rayDirY);
        double perpWallDist;

        // Direction du rayon
        int stepX;
        int stepY;

        int hit = 0; // SI le rayon a toucher un mur
        int side;  // Quel cote du mur a ete touche

        // Calcul de la direction du rayon
        if (rayDirX < 0) {
            stepX = -1;
            sideDistX = (data->game.pos_x - mapX) * deltaDistX;
        } else {
            stepX = 1;
            sideDistX = (mapX + 1.0 - data->game.pos_x) * deltaDistX;
        }
        if (rayDirY < 0) {
            stepY = -1;
            sideDistY = (data->game.pos_y - mapY) * deltaDistY;
        } else {
            stepY = 1;
            sideDistY = (mapY + 1.0 - data->game.pos_y) * deltaDistY;
        }

        // Détecter les murs
        while (hit == 0) {
            if (sideDistX < sideDistY) {
                sideDistX += deltaDistX;
                mapX += stepX;
                side = 0;
            } else {
                sideDistY += deltaDistY;
                mapY += stepY;
                side = 1;
            }
            if (data->world_map[mapX][mapY] > 0) hit = 1;
        }

        // Calcul de la distance du mur
        if (side == 0) {
            perpWallDist = (mapX - data->game.pos_x + (1 - stepX) / 2) / rayDirX;
        } else {
            perpWallDist = (mapY - data->game.pos_y + (1 - stepY) / 2) / rayDirY;
        }

        // Calcul de la hauteur du mur
        int lineHeight = (int)(data->win_height / perpWallDist);

        // Calcul des limites du mur
        int drawStart = -lineHeight / 2 + data->win_height / 2;
        if (drawStart < 0) drawStart = 0;
        int drawEnd = lineHeight / 2 + data->win_height / 2;
        if (drawEnd >= data->win_height) drawEnd = data->win_height - 1;

        double wallX;
        if (side == 0) {
            wallX = data->game.pos_y + perpWallDist * rayDirY;
        } else {
            wallX = data->game.pos_x + perpWallDist * rayDirX;
        }
        wallX -= floor(wallX);

        // Calcul de la position de la tecture
        int texX = (int)(wallX * (double)(data->textures.east_width));
        if (side == 0 && rayDirX > 0) texX = data->textures.east_width - texX - 1;
        if (side == 1 && rayDirY < 0) texX = data->textures.east_width - texX - 1;

        // Dessiner le mur
        for (int y = drawStart; y < drawEnd; y++) {
            int d = y * 256 - data->win_height * 128 + lineHeight * 128;
            int texY = ((d * data->textures.east_height) / lineHeight) / 256;
            int color;
            if (side == 0 && rayDirX < 0) {
                color = data->textures.north_data[texY * data->textures.north_width + texX];
            } else if (side == 0 && rayDirX > 0) {
                color = data->textures.south_data[texY * data->textures.south_width + texX];
            } else if (side == 1 && rayDirY < 0) {
                color = data->textures.west_data[texY * data->textures.west_width + texX];
            } else {
                color = data->textures.east_data[texY * data->textures.east_width + texX];
            }
            if (side == 1) color = (color >> 1) & 8355711; // Couleur plus sombre pour les côtés

            img_data[y * data->win_width + x] = color;
        }
    }

    // Afficher l' image
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img, 0, 0);
    mlx_destroy_image(data->mlx_ptr, img);

    return 0;
}

