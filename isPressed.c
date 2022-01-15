#include <X11/Xlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char **argv)
{
    unsigned int buttonMask;
    KeySym keysym;
    bool isKeySym = false;

    if (argc == 2)
    {
        if (strcmp(argv[1], "Shift") == 0)
            buttonMask = ShiftMask;
        else if (strcmp(argv[1], "Lock") == 0)
            buttonMask = LockMask;
        else if (strcmp(argv[1], "Control") == 0)
            buttonMask = ControlMask;
        else if (strcmp(argv[1], "Mod1") == 0)
            buttonMask = Mod1Mask;
        else if (strcmp(argv[1], "Mod2") == 0)
            buttonMask = Mod2Mask;
        else if (strcmp(argv[1], "Mod3") == 0)
            buttonMask = Mod3Mask;
        else if (strcmp(argv[1], "Mod4") == 0)
            buttonMask = Mod4Mask;
        else if (strcmp(argv[1], "Mod5") == 0)
            buttonMask = Mod5Mask;
        else if (strcmp(argv[1], "Button1") == 0)
            buttonMask = Button1Mask;
        else if (strcmp(argv[1], "Button2") == 0)
            buttonMask = Button2Mask;
        else if (strcmp(argv[1], "Button3") == 0)
            buttonMask = Button3Mask;
        else if (strcmp(argv[1], "Button4") == 0)
            buttonMask = Button4Mask;
        else if (strcmp(argv[1], "Button5") == 0)
            buttonMask = Button5Mask;
        else
        {
            isKeySym = true;
            keysym = XStringToKeysym(argv[1]);
            if (keysym == NoSymbol)
            {
                fprintf(stderr, "The string '%s' is not a valid button.\n", argv[1]);
                return 1;
            }
        }
    }
    else
    {
        fprintf(stderr, "No button specified.\n", argv[1]);
        return 1;
    }

    Display *display = XOpenDisplay(NULL);
    if (display == NULL)
    {
        fprintf(stderr, "Failed connecting to X server.\n");
        return 1;
    }
    if (isKeySym)
    {
        char keymap[32];
        XQueryKeymap(display, keymap);

        KeyCode keycode = XKeysymToKeycode(display, keysym);

        if (keymap[keycode / 8] & (1 << (keycode % 8)))
            printf("1\n");
        else
            printf("0\n");
    }
    else
    {
        int x, y, rx, ry;
        Window r, c;
        unsigned int m;
        XQueryPointer(display, RootWindow(display, DefaultScreen(display)), &r, &c, &x, &y, &rx, &ry, &m);
        if (buttonMask & m)
            printf("1\n");
        else
            printf("0\n");
    }

    XCloseDisplay(display);
    return 0;
}