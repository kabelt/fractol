# Fractol
Explore one of the most magnificent mysteries of the universe, [fractals](https://en.wikipedia.org/wiki/Fractal), with ease from your own computer.\
\
![Aug-19-2020 15-49-35](https://user-images.githubusercontent.com/49394144/90613514-ac4a9580-e233-11ea-9b93-63ff9bdbe764.gif)\
\
All of the features were implemented from scratch without any help from external libraries. :star:
### Requirements
This project relies on MiniLibX and can be run only on MacOS.
### Installations
Run the following command in your terminal. You should see the window similar to the above screenshot.
```shell
cd ~/Downloads && git clone https://github.com/kabelt/fractol.git fractol && cd fractol && make && ./fractol Julia
```
### Features
- [x] Four available fractols; Mandelbrot, Julia, Burning_ship, Mandelbar
- [x] Multithreading implementation for smooth rendering
- [x] Interactive mode available for Julia set as shown above
- [x] Interative zooming in/out relative to the mouse position including iteration adjustment
- [x] Four available color themes

### Want to explore other types of fractal?
Relaunch the program using the name of the other fractals. For example, inserting this into your terminal
```shell
./fractol Mandelbrot
```
allows you to appreciate the beauty of the Mandelbrot set like this\
<img width="1312" alt="Screen Shot 2020-08-19 at 15 25 04" src="https://user-images.githubusercontent.com/49394144/90610840-31cc4680-e230-11ea-8024-a8b049d013a2.png">
### Acknowledgements
I found this [wikipage](https://github.com/VBrazhnik/FdF/wiki) super useful in implementing this project.
This project is part of 42 pedagogy.
