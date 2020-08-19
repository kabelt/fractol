# Fractol
![Aug-19-2020 15-49-35](https://user-images.githubusercontent.com/49394144/90613514-ac4a9580-e233-11ea-9b93-63ff9bdbe764.gif)
<img width="1312" alt="Screen Shot 2020-08-19 at 15 25 04" src="https://user-images.githubusercontent.com/49394144/90610840-31cc4680-e230-11ea-8024-a8b049d013a2.png">
### Requirements
This project relies on MiniLibX and can be run only on MacOS.
### Installations
Run the following command in your terminal. You should see the window similar to the above screenshot.
```shell
cd ~/Downloads && git clone https://github.com/kabelt/fractol.git fractol && cd fractol && make && ./fractol Mandelbrot
```
### Features
- [x] Collision detection
- [x] [Sprites](https://en.wikipedia.org/wiki/Sprite_(computer_graphics))
- [x] Different wall texturing based on directions
- [x] Customizable wall/ceiling colors
- [x] Shadow effect based on distance
- [x] Minimap
### Want to explore other types of fractal?
You can find the details about how .cub files works [here](subject/en.subject.pdf) on page 6-9.\
Then relaunch 2Dto3D with your map;
```shell
./2Dto3D <your_map>
```
### Acknowledgements
I found this [wikipage](https://github.com/VBrazhnik/FdF/wiki) super useful in implementing this project.
This project is part of 42 pedagogy.
