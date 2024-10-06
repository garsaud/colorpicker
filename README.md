# colorpicker
Command line tool to get the color of a pixel from the screen, written in C, and using the X11 lib.

## building
```bash
make
```

## installing
```bash
make install
```
(Install dir is `/usr/local/bin` by default)

## usage
```bash
colorpicker x y
```
The arguments x and y refer to the pixel coordinates.

To retrieve the first pixel on the top-left corner of the screen:
```bash
colorpicker 0 0
# outputs something like #ff9912
```
