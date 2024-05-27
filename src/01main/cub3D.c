/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogalio <rmouchel@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 12:36:05 by lannur-s          #+#    #+#             */
/*   Updated: 2024/05/27 15:27:12 by rogalio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "cub3D.h"
#include <math.h>
#include <stdlib.h>


#define mapWidth 24
#define mapHeight 24
#define screenWidth 640
#define screenHeight 480

int worldMap[mapWidth][mapHeight] = {
    // Carte avec des murs (1) et des espaces vides (0)
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
     {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
};

double posX = 22, posY = 12;  // Position de la caméra
double dirX = -1, dirY = 0;   // Direction de la caméra
double planeX = 0, planeY = 0.66; // Plan de la caméra pour le FOV

int handleInput(int key, void *param);
int handleMouse(int x, int y, void *param);
int render(t_data *data);

void	init_images(t_data *data)
{
	data->textures.east_texture = mlx_xpm_file_to_image(data->mlx_ptr,"./textures/wolfenstein/blue_stone.xpm", &data->win_width, &data->win_height);
	data->textures.north_texture = mlx_xpm_file_to_image(data->mlx_ptr,"./textures/wolfenstein/blue_stone.xpm", &data->win_width, &data->win_height);
	data->textures.south_texture = mlx_xpm_file_to_image(data->mlx_ptr,"./textures/wolfenstein/blue_stone.xpm", &data->win_width, &data->win_height);
	data->textures.west_texture = mlx_xpm_file_to_image(data->mlx_ptr,"./textures/wolfenstein/blue_stone.xpm", &data->win_width, &data->win_height);
	data->player_ptr = mlx_xpm_file_to_image(data->mlx_ptr,"./textures/wolfenstein/mossy.xpm", &data->win_width, &data->win_height);
	}

int main() {
    t_data data;

    data.mlx_ptr = mlx_init();
    data.win_ptr = mlx_new_window(data.mlx_ptr, screenWidth, screenHeight, "Raycaster");
    data.win_height = screenHeight;
    data.win_width = screenWidth;

    init_images(&data);

    mlx_key_hook(data.win_ptr, handleInput, &data);
    mlx_hook(data.win_ptr, 6, 0, handleMouse, &data); // 6 est l'événement de mouvement de la souris
    mlx_loop_hook(data.mlx_ptr, (int (*)())render, &data);
    mlx_loop(data.mlx_ptr);

    return 0;
}


int handleInput(int key, void *param) {
    (void)param;
    double moveSpeed = 0.3; // Vitesse de déplacement
    double rotSpeed = 0.3;  // Vitesse de rotation

    if (key == 65307) { // Touche Échap
        exit(0);
    }
    if (key == 119) { // Touche W
        if(worldMap[(int)(posX + dirX * moveSpeed)][(int)posY] == 0) posX += dirX * moveSpeed;
        if(worldMap[(int)posX][(int)(posY + dirY * moveSpeed)] == 0) posY += dirY * moveSpeed;
    }
    if (key == 115) { // Touche S
        if(worldMap[(int)(posX - dirX * moveSpeed)][(int)posY] == 0) posX -= dirX * moveSpeed;
        if(worldMap[(int)posX][(int)(posY - dirY * moveSpeed)] == 0) posY -= dirY * moveSpeed;
    }
    if (key == 97) { // Touche A
        double oldDirX = dirX;
        dirX = dirX * cos(rotSpeed) - dirY * sin(rotSpeed);
        dirY = oldDirX * sin(rotSpeed) + dirY * cos(rotSpeed);
        double oldPlaneX = planeX;
        planeX = planeX * cos(rotSpeed) - planeY * sin(rotSpeed);
        planeY = oldPlaneX * sin(rotSpeed) + planeY * cos(rotSpeed);
    }
    if (key == 100) { // Touche D
        double oldDirX = dirX;
        dirX = dirX * cos(-rotSpeed) - dirY * sin(-rotSpeed);
        dirY = oldDirX * sin(-rotSpeed) + dirY * cos(-rotSpeed);
        double oldPlaneX = planeX;
        planeX = planeX * cos(-rotSpeed) - planeY * sin(-rotSpeed);
        planeY = oldPlaneX * sin(-rotSpeed) + planeY * cos(-rotSpeed);
    }
    return 0;
}

int handleMouse(int x, int y, void *param) {
    static int lastX = screenWidth / 2; // Position précédente de la souris
    int diffX = x - lastX;
    double rotSpeed = 0.005 * diffX; // Ajuster la vitesse de rotation
    (void)param;
    (void)y;
    double oldDirX = dirX;
    dirX = dirX * cos(-rotSpeed) - dirY * sin(-rotSpeed);
    dirY = oldDirX * sin(-rotSpeed) + dirY * cos(-rotSpeed);
    double oldPlaneX = planeX;
    planeX = planeX * cos(-rotSpeed) - planeY * sin(-rotSpeed);
    planeY = oldPlaneX * sin(-rotSpeed) + planeY * cos(-rotSpeed);

    lastX = x;
    return 0;
}

int render(t_data *data) {
    // Créer un nouvel image
    void *img = mlx_new_image(data->mlx_ptr, data->win_width, data->win_height);
    int *img_data = (int *)mlx_get_data_addr(img, &data->textures.no_count, &data->textures.ea_count, &data->textures.so_count);

    for (int x = 0; x < data->win_width; x++) {
        // Calcul de la position du rayon
        double cameraX = 2 * x / (double)data->win_width - 1;
        double rayDirX = dirX + planeX * cameraX;
        double rayDirY = dirY + planeY * cameraX;

        // Position de la carte
        int mapX = (int)posX;
        int mapY = (int)posY;

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

        int hit = 0; // Si le rayon a touché un mur
        int side;   // Quel côté du mur a été touché

        // Calcul de la direction du rayon
        if (rayDirX < 0) {
            stepX = -1;
            sideDistX = (posX - mapX) * deltaDistX;
        } else {
            stepX = 1;
            sideDistX = (mapX + 1.0 - posX) * deltaDistX;
        }
        if (rayDirY < 0) {
            stepY = -1;
            sideDistY = (posY - mapY) * deltaDistY;
        } else {
            stepY = 1;
            sideDistY = (mapY + 1.0 - posY) * deltaDistY;
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
            if (worldMap[mapX][mapY] > 0) hit = 1;
        }

        // Calcul de la distance du mur
        if (side == 0) {
            perpWallDist = (mapX - posX + (1 - stepX) / 2) / rayDirX;
        } else {
            perpWallDist = (mapY - posY + (1 - stepY) / 2) / rayDirY;
        }

        // Calcul de la hauteur du mur
        int lineHeight = (int)(data->win_height / perpWallDist);

        // Calcul des limites du mur
        int drawStart = -lineHeight / 2 + data->win_height / 2;
        if (drawStart < 0) drawStart = 0;
        int drawEnd = lineHeight / 2 + data->win_height / 2;
        if (drawEnd >= data->win_height) drawEnd = data->win_height - 1;

        // Couleur du mur
        int color = 0x00FF00;
        if (side == 1) {
            color = color / 2;
        }

        // Dessiner le mur
        for (int y = 0; y < data->win_height; y++) {
            if (y < drawStart) {
                img_data[y * data->win_width + x] = 0x0000FF;
            } else if (y > drawEnd) {
                img_data[y * data->win_width + x] = 0xFF0000;
            } else {
                img_data[y * data->win_width + x] = color;
            }
        }
    }

    // Afficher l'image
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img, 0, 0);
    mlx_destroy_image(data->mlx_ptr, img);

    return 0;
}




/*
int	main(int ac, char **av)
{
 	t_data	data;

	if (!check_args(ac))
		return (0);
	init_data(&data);
	if (!check_cub_extension(av[1]))
		on_destroy(&data);
	parse_scene_file(&data, av[1]);



	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		on_destroy(&data);



	if (!set_up(&data))
	{
		on_destroy(&data);
	}

	 mlx_key_hook(data.win_ptr, handleInput, &data);
    mlx_hook(data.win_ptr, 6, 1L<<6, handleMouse, &data);
    mlx_loop_hook(data.mlx_ptr, render, &data);
	mlx_loop(data.mlx_ptr);



	if (!validate_map(&data))
		on_destroy(&data);
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		on_destroy(&data);
	if (!set_up(&data))
	{
		on_destroy(&data);
	}
	mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, &data);
	mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask,
		&on_destroy, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
*/



