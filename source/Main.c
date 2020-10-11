#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv) {
  FILE *fp;

  int window_dimensions[4], i = 0;
  int x, y, w, h;

  // Most screens have width less than 1000
  // +1 for safety, +1 for \0
  char op[6];

  if (access("get_window_details.sh", F_OK) != -1)
    fp = popen("bash get_window_details.sh", "r");
  else
    fp = popen("bash /usr/local/bin/get_window_details.sh", "r");

  while (fgets(op, sizeof(op), fp) != NULL) window_dimensions[i++] = atoi(op);

  gtk_init(&argc, &argv);

  GdkWindow *root = gdk_get_default_root_window();

  x = window_dimensions[0];
  y = window_dimensions[1];
  w = window_dimensions[2];
  h = window_dimensions[3];

  // Take screenshot
  GdkPixbuf *screenshot = gdk_pixbuf_get_from_window(root, x, y, w, h);

  // Save screenshot
  gdk_pixbuf_save(screenshot, "/tmp/MitPick.png", "png", NULL, NULL);

  // Copy image to clipboard
  system("xclip -selection clipboard -t image/png -i /tmp/MitPick.png");

  return 0;
}