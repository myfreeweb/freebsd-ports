# freebsd-ports-dank

![dank meme pic](https://unrelentingtech.s3.dualstack.eu-west-1.amazonaws.com/dankbsd.jpg?1)

Welcome!

This fork of the FreeBSD Ports Collection merges the [KDE](https://github.com/freebsd/freebsd-ports-kde) and [GNOME](https://github.com/freebsd/freebsd-ports-gnome) branches together with the upstream and adds more bleeding edge desktop-related patches.

## Usage

- Make sure you have an up-to-date FreeBSD 12-CURRENT kernel and base
- Clone this repo into `/usr/ports` (if it's already managed by git, add this repo as a remote, fetch and checkout/merge)
- Build any ports you want :)

## Current status

### Graphics stack

- `graphics/mesa-dev`: alternative mesa port! Development version ([little fork](https://github.com/myfreeweb/mesa) with my BSD patches), everything built together, using Meson! Always includes GL, GLES, Vulkan (RADV, ANV), Gallium Nine, OpenCL (Clover), VAAPI, VDPAU.
	- to install and keep pkg happy without rebuilding everything, just `pkg add -f` over existing `mesa-libs/dri`
- `graphics/mesa-dri` and `graphics/mesa-libs`:
	- updated to 18.0.0.rc4 [225415](https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=225415)
	- enabled VK_KHR_wayland_surface [221540](https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=221540)
	- (included upstream) fix device name detection [223030](https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=223030)
- `graphics/vulkan-sdk`: [Vulkan SDK](https://github.com/KhronosGroup/Vulkan-LoaderAndValidationLayers) (headers, ICD loader, validation layers) [222175](https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=222175)
- `graphics/libdrm`: 2.4.91

NOTE: ANV (Intel Vulkan) requires running the apps as root and might not work for complex applications.
RADV (Radeon Vulkan) with the `amdgpu` KMS/DRM driver works very well!
Tested on an AMD Polaris (RX 480) GPU.

### Desktop stack

- `www/webkit2-gtk3`: updated to 2.19.91, Wayland support added (stable version: [223733](https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=223733))
- `devel/sdl20`: Wayland and udev options added [223018](https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=223018)
- `x11/libinput`: [222905](https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=222905)
	- update to 1.9.901
	- fix [touchpad dropping out](https://blog.grem.de/pages/t470s.html)
	- fix device rejection when running without /dev/input access
- `devel/libepoll-shim`: update version ~~[223530](https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=223530)~~ included in 222905
- `x11-servers/xorg-server`:
	- add `UDEV` option to support evdev devices autodetection [222609](https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=222609)
	- fix terminal handling without 'keyboard' driver [220562](https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=220562)

### Games

- `games/vkquake`: [a Vulkan-powered Quake engine](https://github.com/Novum/vkQuake) [222182](https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=222182)
- `emulators/dolphin-emu`: [Dolphin Emulator](https://dolphin-emu.org) (GameCube/Wii) updated to a recent git revision (Vulkan just works, dynamically loaded)
- `games/vcmi`: open source reimplementation of Heroes of Might and Magic III! [221885](https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=221885)

### Misc

- `multimedia/mpv`: 0.28.2
- `multimedia/ffmpeg`: git master (because mpv 0.28.x requires it)
- `devel/boehm-gc*`: [225560](https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=225560)
- `mail/geary`: 0.12.1
- `www/woff2`: [226165](https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=226165)
- `sysutils/u-boot-rpi3`: update to 2018.01, with netboot support [225355](https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=225355)
- `lang/luajit`: update to 2.1.0-beta3 (works on arm64) [225342](https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=225342)
- `multimedia/gnome-twitch`: Twitch livestream player [224980](https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=224980)
- `archivers/maxcso`: ISO to CSO compressor for PSP/PS2 emulators [224638](https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=224638)
- `editors/neovim-qt`: nvim GUI [224427](https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=224427)
- `devel/gnome-builder`: 3.27 (XXX: crashes)
- `graphics/mypaint` and `graphics/libmypaint`: git master version, works on Wayland natively
- `graphics/inkscape`: git master version with GTK3, works on Wayland natively
- `editors/libreoffice`: **6.0.1** with GTK3 by default, works on Wayland natively [224288](https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=224288) || further work [by lwhsu@ over there](https://github.com/lwhsu/freebsd-ports-libreoffice)
- `www/firefox`: (no extra updates here currently) See [FirefoxSettings](https://unrelenting.technology/kb/FirefoxSettings) for, well, settings (force enable GPU acceleration!)
- `java/jamvm`: update to 2.0.0 [192305](https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=192305)
- `audio/rhythmbox-plugin-{alternative-toolbar,coverart-browser,coverart-search-providers}`: Some nice Rhythmbox plugins [223137](https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=223137)

## Kernel patches

- [222375](https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=222375) linsysfs(5): Add support for recent libdrm [LANDED!](https://github.com/freebsd/freebsd/commit/09ad0b962f3029e47b3f430948933b6fe066ccdf)
- [222504](https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=222504) Add support for 32-bit compatibility IOCTLs in the LinuxKPI [LANDED!](https://github.com/freebsd/freebsd/commit/10ef676c4bbe7379de1f3687444e4311a7d872e2)
- [222646](https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=222646) ukbd(4): support Consumer Control based multimedia keys

## Recommended kernel config

`/usr/src/sys/amd64/conf/DESKTOP`:

```
include GENERIC-NODEBUG
ident   DESKTOP
device		evdev
options		EVDEV_SUPPORT
options 	KDTRACE_HOOKS
options 	VIMAGE
```

(the important part is the `EVDEV_SUPPORT`, which is still disabled by default for some reason!)

## Recommended /etc/make.conf

```
DEFAULT_VERSIONS+=ssl=libressl
CPUTYPE?=znver1 # Replace with your CPU
RUST_PORT=lang/rust-nightly
```

## Other FreeBSD desktop resources

- [kb/FreeBSDDesktop](https://unrelenting.technology/kb/FreeBSDDesktop)
- [My dotfiles](https://github.com/myfreeweb/dotfiles) (mostly the `x11` folder)
- [A FreeBSD 11 Desktop How-to](https://cooltrainer.org/a-freebsd-desktop-howto/), not up to date with modern GPU stuff but very good for general desktop setup (printing, networking, etc.)
- [FreeBSD on the ThinkPad X240](https://unrelenting.technology/articles/freebsd-on-the-thinkpad-x240), my post that's mostly updated but still contains old stuff

## Other resources

- [1.5 Hour Spicy SUPER EUROBEAT Mix](https://www.youtube.com/watch?v=6ftCIfHwqtg)
