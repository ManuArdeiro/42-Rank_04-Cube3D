Minilib:

https://github.com/42Paris/minilibx-linux

Raycasting:

https://lodev.org/cgtutor/raycasting.html

The general outline of the program is as follows:

1. Arguments are checked.

2. Parsing is done:

   -> All files are in the parsing folder.

   -> There is one and only one texture for each cardinal direction.

   -> The texture files exist and are valid.

   -> There are no duplicate textures.

   -> There are correct RGB values for floor and ceiling.

   -> There is only one map, and it only contains 0, 1, and a cardinal point (N, E, S, W).

   -> There is only one initial cardinal point in the map.

   -> The map walls are closed.

3. Then ft_game() function is called, where the game is runned:

   a) The initial dir and plane vectors are set depending on the initial direction of the player.

   b) ft_mlx_start() opens a new window with the dimensions specified in cube.h for the game.

   c) Through the function ft_texture_start(), the files containing the textures for the four directions are read, and their information (if correct) is stored in the main data structure char **data->texture.texture[cardinal]. This way, the four textures are stored in the main structure so they can be accessed whenever necessary.

   d) 
