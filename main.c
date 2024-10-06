#include <stdio.h>
#include <stdlib.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>

int main(int argc, char * argv[])
{
    if (argc < 3) {
        printf("Usage: %s x y\nRetrieve pixel color at given coordinates.\n", argv[0]);
        return 0;
    }

    int x = atoi(argv[1]);
    int y = atoi(argv[2]);

    // find the color at coordinates
    Display *display = XOpenDisplay(XDisplayName(NULL));
    XImage *image = XGetImage(display, XRootWindow(display, XDefaultScreen(display)), x, y, 1, 1, AllPlanes, XYPixmap);
    XColor color = {pixel: (*((image)->f.get_pixel))(image, 0, 0)};
    XQueryColor(display, XDefaultColormap(display, XDefaultScreen(display)), &color);
    
    printf("#%02x%02x%02x\n", color.red/257, color.green/257, color.blue/257);

    return 0;
}
