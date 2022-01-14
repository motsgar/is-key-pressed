#include <X11/Xlib.h>
#include <X11/keysym.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    KeySym keysym;
    if (argc == 2)
    {
        keysym = XStringToKeysym(argv[1]);
        if (keysym == NoSymbol)
        {
            fprintf(stderr, "The string '%s' is not a valid keysym.\n", argv[1]);
            return 1;
        }
    }
    else
    {
        fprintf(stderr, "No keysym specified.\n", argv[1]);
        return 1;
    }

    char keymap[32];
    Display *display = XOpenDisplay(NULL);
    if (display == NULL)
    {
        fprintf(stderr, "Failed connecting to X server.\n");
        return 1;
    }
    XQueryKeymap(display, keymap);

    KeyCode keycode = XKeysymToKeycode(display, keysym);

    if (keymap[keycode / 8] & (1 << (keycode % 8)))
        printf("1\n");
    else
        printf("0\n");
    XCloseDisplay(display);
    return 0;
}