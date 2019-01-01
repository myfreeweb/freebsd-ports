# freebsd-ports-dank

![dank meme pic](https://unrelentingtech.s3.dualstack.eu-west-1.amazonaws.com/dankbsd.jpg?1)

Welcome!

This fork of the FreeBSD Ports Collection adds more bleeding edge desktop-related patches.

**NOTE**: this is the new `lite` branch, which is always rebased on top of `master` and has some cherry-picks from `ports-gnome`.

## Usage

- Clone this repo into `/usr/ports` (if it's already managed by git, add this repo as a remote, fetch and checkout/merge)
- Build any ports you want :)

## Highlights

- `devel/llvm80`: OpenMP and Sanitizers on aarch64 (read the patch files)
- `devel/consolekit2`: drm/evdev support [D18754](https://reviews.freebsd.org/D18754)
- `graphics/mesa-dev`: alternative mesa port! Development version ([little fork](https://github.com/myfreeweb/mesa) with my BSD patches), everything built together, using Meson! Always includes GL, GLES, Vulkan (RADV, ANV), Gallium Nine, OpenCL (Clover), VDPAU, VAAPI.
	- to install and keep pkg happy without rebuilding everything, ~~just `pkg add -f` over existing `mesa-libs/dri`~~ install dummy replacements from `dummy/` (there's also a dummy for using `graphics/librsvg2-rust`)
	- but if you want to do it properly, define `MESA_DRI_PORT=graphics/mesa-dev` and `MESA_LIBS_PORT=graphics/mesa-dev` in `make.conf` and rebuild dependent ports
		- [synth](https://github.com/jrmarino/synth) is the recommended port upgrade tool, it does try to fetch binary packages when a rebuild is not necessary
- `x11/libinput`: fix [touchpad dropping out](https://blog.grem.de/pages/t470s.html)
- `devel/libudev-devd`: my patches applied: [connector hotplug](https://github.com/FreeBSDDesktop/libudev-devd/pull/7) and [device enumeration w/o `/dev/input/*` access rights](https://github.com/FreeBSDDesktop/libudev-devd/pull/8) (both landed, everything this needs is landed in kms-drm and base as well)
- `audio/jack`: jack2 [jack2/pull/400](https://github.com/jackaudio/jack2/pull/400)
- `lang/luajit`: 2.1.0-beta3 (works on aarch64) [225342](https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=225342)
- `devel/libgusb`: GObject libusb wrapper (w/ [PR #10](https://github.com/hughsie/libgusb/pull/10))
- `graphics/simple-scan`: GNOME scanning app (requires `libgusb`)
- `multimedia/gstreamer1-plugins`: backport xdg-shell support (prevents GL sink crash on Wayland compositors w/o wl-shell, i.e. prevents Pitivi crash on wlroots based compositors)
- `graphics/mypaint` and `graphics/libmypaint`: 2.0.0alpha, works on Wayland natively [235805](https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=235805)
- `graphics/inkscape`: 1.0alpha
- `graphics/rawtherapee`: workaround for OpenMP idle threads' CPU consumption [#5105](https://github.com/Beep6581/RawTherapee/issues/5105), disable mmap (to make performance over NFS not terrible), enable LTO
- `accessibility/redshift-wlr`: fork of redshift with wlr-gamma-control based Wayland backend

For all changes, just look at the commits :)

## Other FreeBSD desktop resources

- [My dotfiles](https://github.com/myfreeweb/dotfiles)
- [kb/FirefoxSettings](https://unrelenting.technology/kb/FirefoxSettings)
- [kb/FreeBSDDesktop](https://unrelenting.technology/kb/FreeBSDDesktop)
- [A FreeBSD 11 Desktop How-to](https://cooltrainer.org/a-freebsd-desktop-howto/), not up to date with modern GPU stuff but very good for general desktop setup (printing, networking, etc.)
- [FreeBSD on the ThinkPad X240](https://unrelenting.technology/articles/freebsd-on-the-thinkpad-x240), my post that's mostly updated but still contains old stuff

## Other resources

- [1.5 Hour Spicy SUPER EUROBEAT Mix](https://www.youtube.com/watch?v=6ftCIfHwqtg)
