# cube3D

# Description

This project is exploring the raycasting technique that allows to create a 3D perspective from a 2D map. Back when computers were slower, it wasn't possible to run real 3D engines in realtime, and raycasting was the first solution. Raycasting can go very fast, because only a calculation has to be done for every vertical line of the screen. The most well known game that used this technique was Wolfenstein 3D.

In this project was implemented:
- the raycasting technique rendering in 3D a 2D map
- moving around the map
- sprites
- wall collisions

The project is run as follows:
- run `make` in the main folder to build the executable
- to launch the project, write in the command line:
  > `./cub3D maps/map01.cub`

- you can move around with the WASD keys to move back and forth, left and right, with the left and right arrow keys to rotate left or right.

![image](https://github.com/E33aS42/cube3D/assets/66993020/849213d3-011c-449b-a50e-2bb8a59df403)
