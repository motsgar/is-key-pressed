# keypress detector

To find out the keycode to use, look at [keysymdef.h](https://github.com/D-Programming-Deimos/libX11/blob/master/c/X11/keysymdef.h), output of "xmodmap -pm" and the source isPressed.c

with the defines from [keysymdef.h](https://github.com/D-Programming-Deimos/libX11/blob/master/c/X11/keysymdef.h) remove the XK_ from the name before passing it to isPressed

***

Examples:

```
isPressed Button1   # left mouse button
isPressed Control   # control button
isPressed Shift_R   # Right shift button
```
