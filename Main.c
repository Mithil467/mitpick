#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    FILE *fp;

    int window_dimensions[4], i = 0;
    int x, y, w, h;

    // Most screens have width less than 1000
    // +1 for safety
    char op[6];

    fp = popen("bash /usr/local/share/mitpick/win_details.sh", "r");
    
    // fp = popen("xwininfo -id $(xdotool getactivewindow) |    sed -n -e \"s/^ \\+Absolute upper-left X: \\+\\([0-9]\\+\\).*/x=\\1/p\" \\        -e \"s/^ \\+Absolute upper-left Y: \\+\\([0-9]\\+\\).*/y=\\1/p\" \\        -e \"s/^ \\+Width: \\+\\([0-9]\\+\\).*/w=\\1/p\" \\        -e \"s/^ \\+Height: \\+\\([0-9]\\+\\).*/h=\\1/p\"", "r");

    while (fgets(op, sizeof(op), fp) != NULL)
        window_dimensions[i++] = atoi(op);

    // initialize gtk
    gtk_init(&argc, &argv);

    GdkWindow *root = gdk_get_default_root_window();

    x = window_dimensions[0];
    y = window_dimensions[1];
    w = window_dimensions[2];
    h = window_dimensions[3];

    // Take screenshot
    GdkPixbuf *screenshot = gdk_pixbuf_get_from_window(root, x, y, w, h);

    // Save screenshot
    gdk_pixbuf_save(screenshot, "/tmp/MitPick", "jpeg", NULL, "quality", "100", NULL);

    // Copy image to clipboard
    system("xclip -selection clipboard -t image/png -i /tmp/MitPick");

    return 0;
}