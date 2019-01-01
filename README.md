# DankBSD Ports

![dank meme pic](https://unrelentingtech.s3.dualstack.eu-west-1.amazonaws.com/dankbsd.jpg?1)

Welcome!

This fork of the FreeBSD Ports Collection adds more bleeding edge desktop-related patches.

**NOTE**: this is the new `lite` branch, which is always rebased on top of `master` and has some cherry-picks from `ports-gnome`.

This is now part of a whole system fork/distro thing.. binaries and images "coming" "soon".

## Usage

- Clone this repo into `/usr/ports` (if it's already managed by git, add this repo as a remote, fetch and checkout/merge)
- Build any ports you want :)

## Highlights

- `ldconfig` post-(de)install scripts support `runit-faster`
- most GNOME/GTK apps are updated
- `X11` optionalized in lots of things, allowing for a pure-Wayland system with no Xlib installed at all
- `devel/consolekit2`: drm/evdev support [D18754](https://reviews.freebsd.org/D18754)
- `graphics/mesa-dev`: alternative mesa port! Development version ([little fork](https://github.com/myfreeweb/mesa) with my BSD patches), everything built together, using Meson! Always includes GL, GLES, Vulkan (RADV, ANV), Gallium Nine, OpenCL (Clover), VDPAU, VAAPI.
	- `graphics/libglvnd`: allows using desktop GL when everything is built w/o X11, allows swapping Mesa ports (well GL drivers in general) without rebuilding everything
- `audio/pulseaudio`: [upstream MR](https://gitlab.freedesktop.org/pulseaudio/pulseaudio/-/merge_requests/277) with devd hotplug and stuff
- `audio/jack`: jack2 [jack2/pull/400](https://github.com/jackaudio/jack2/pull/400)
- `devel/libgusb`: GObject libusb wrapper (w/ [PR #10](https://github.com/hughsie/libgusb/pull/10))
- `graphics/simple-scan`: GNOME scanning app (requires `libgusb`)
- `graphics/inkscape`: GTK3-powered (Wayland-compatible) Inkscape 1.0alpha
- `graphics/gimp30`: GTK3-powered (Wayland-compatible) GIMP 2.99.whatever
- `editors/libreoffice`: updates from [freebsd-ports-libreoffice](https://github.com/lwhsu/freebsd-ports-libreoffice)

For all changes, just look at the commits :)

## Other FreeBSD desktop resources

- [My dotfiles](https://github.com/myfreeweb/dotfiles)
- [kb/FirefoxSettings](https://unrelenting.technology/kb/FirefoxSettings)
- [kb/FreeBSDDesktop](https://unrelenting.technology/kb/FreeBSDDesktop)
- [A FreeBSD 11 Desktop How-to](https://cooltrainer.org/a-freebsd-desktop-howto/), not up to date with modern GPU stuff but very good for general desktop setup (printing, networking, etc.)
- [FreeBSD on the ThinkPad X240](https://unrelenting.technology/articles/freebsd-on-the-thinkpad-x240), my post that's mostly updated but still contains old stuff

## Other resources

- [1.5 Hour Spicy SUPER EUROBEAT Mix](https://www.youtube.com/watch?v=6ftCIfHwqtg)
