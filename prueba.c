#include "so_long.h"

void key_hook(mlx_key_data_t keydata, void *param)
{
    mlx_t *mlx = param;
    if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
        mlx_close_window(mlx);
}

int main(void)
{
    mlx_set_setting(MLX_STRETCH_IMAGE, true);
    
    mlx_t *mlx = mlx_init(512, 512, "prueba", true);
    if (!mlx)
    {
        printf("Error al inicializar MLX\n");
        return (1);
    }
    
    mlx_texture_t *texture = mlx_load_png("textures/cloud.png");
    if (!texture)
    {
        printf("Error cargando textures/cloud.png\n");
        mlx_terminate(mlx);
        return (1);
    }
    
    mlx_image_t *img = mlx_texture_to_image(mlx, texture);
    mlx_image_to_window(mlx, img, 0, 0);
    
    mlx_key_hook(mlx, &key_hook, mlx);
    mlx_loop(mlx);
    mlx_delete_texture(texture);
    // mlx_delete_image(mlx, img);
    mlx_terminate(mlx);
    return (0);
}
