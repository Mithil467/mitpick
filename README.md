<h1 align="center"> MitPick </h1>
<p align="center">
    Capture the terminal, from the terminal
    <br />
  <br />
  <a href="https://lgtm.com/projects/g/Mithil467/mitpick/context:cpp"><img alt="Language grade: C/C++" src="https://img.shields.io/lgtm/grade/cpp/g/Mithil467/mitpick.svg?logo=lgtm&logoWidth=18"/></a>
  <a href="https://lgtm.com/projects/g/Mithil467/mitpick/alerts/"><img alt="Total alerts" src="https://img.shields.io/lgtm/alerts/g/Mithil467/mitpick.svg?logo=lgtm&logoWidth=18"/></a>
</p>

### What is it?
**MitPick** is a program for linux based systems to capture a screenshot of the terminal without leaving the terminal.

### Features:
📷 Take a screenshot of the terminal
📝 Copies it to clipboard
⚙️ Easy installation

### Where to get it?

Download the debian package from [releases](https://github.com/Mithil467/mitpick/releases/latest).  
Execute the following from the directory where the package is downloaded (e.g. /home/mithil/Downloads)

```sudo apt install ./mitpick_1.0-1.deb```

### Dependencies

- [xdotool](https://github.com/jordansissel/xdotool)
- [xclip](https://github.com/astrand/xclip)

Dependencies are resolved automatically when installing the MitPick debian package.

### How to install using meson and ninja?

Clone the repo and from within the repo execute the following commands.

```
meson builddir
cd builddir
ninja install
```

### How to compile from source code?

You would need gtk3 development libraries for compiling the source.

```
gcc Main.c `pkg-config --cflags --libs gtk+-3.0` -o mitpick
```

This will generate the executable binary ``mitpick`` in the same folder.

### License
[GPL](LICENSE)
