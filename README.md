# freebsd-ports-dank

![dank meme pic](https://unrelentingtech.s3.dualstack.eu-west-1.amazonaws.com/dankbsd.jpg?1)

Welcome!

This fork of the FreeBSD Ports Collection merges the [KDE](https://github.com/freebsd/freebsd-ports-kde) and [GNOME](https://github.com/freebsd/freebsd-ports-gnome) branches together with the upstream and adds more bleeding edge desktop-related patches.

## Usage

- Make sure you have an up-to-date FreeBSD 12-CURRENT kernel and base
- Clone this repo into `/usr/ports` (if it's already managed by git, add this repo as a remote, fetch and checkout)
- Build any ports you want :)

## Current status

### Vulkan

- `graphics/mesa-dri` and `graphics/mesa-libs`: updated to 17.3.0, enabled Vulkan drivers and VK_KHR_wayland_surface [221540](https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=221540) [223195](https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=223195)
	- + enabled SWR software renderer, run like this: `LIBGL_ALWAYS_SOFTWARE=true GALLIUM_DRIVER=llvmpipe LD_PRELOAD=/usr/local/lib/libtinyxml2.so glxgears`
- `graphics/vulkan-sdk`: [Vulkan SDK](https://github.com/KhronosGroup/Vulkan-LoaderAndValidationLayers) (headers, ICD loader, validation layers) [222175](https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=222175)

NOTE: ANV (Intel Vulkan) requires running the apps as root and might not work for complex applications.
RADV (Radeon Vulkan) with the `amdgpu` KMS/DRM driver works very well!
Tested on an AMD Polaris (RX 480) GPU.

### Xorg and Wayland

- `x11-toolkits/wlc`: updated to 0.0.10 (for sway)
- `x11-wm/sway`: [sway, the i3-like Wayland compositor](https://github.com/SirCmpwn/sway)
- `www/webkit2-gtk3`: updated to 2.18.3, Wayland support added [223733](https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=223733)
- `devel/sdl20`: Wayland and udev options added [223018](https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=223018)
- `x11/libinput`: Update to 1.9.2, remove unnecessary/unused patches [222905](https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=222905)
- `x11-servers/xorg-server`: added `UDEV` option to support evdev devices autodetection [222609](https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=222609)
- `graphics/mesa-libs`: Fix device name detection [223030](https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=223030)
- `devel/libepoll-shim`: Update version [223530](https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=223530)
- `x11-wm/weston`: reference Wayland compositor and some apps
- `net/freerdp`: wlfreerdp Wayland client enabled [223913](https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=223913)
- `x11-toolkits/qt5-gui` and `graphics/qt5-wayland`: Wayland-EGL enabled (and some extra stuff like evdev and eglfs)
- `multimedia/libva`: install to lib/dri instead of lib/va [224424](https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=224424)
- `multimedia/mpv`: add VAAPI on Wayland support [224425](https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=224425)
- `x11-toolkits/qt5-gtkplatform`: Qt-on-GTK, better Wayland support than `wayland-egl` [224453](https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=224453)

### Games

- `x11-toolkits/mygui`: current git version that doesn't have weird C++ problems anymore, see [220189](https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=220189)
- `games/vkquake`: [a Vulkan-powered Quake engine](https://github.com/Novum/vkQuake) [222182](https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=222182)
- `emulators/dolphin-emu`: [Dolphin Emulator](https://dolphin-emu.org) (GameCube/Wii) updated to a recent git revision (Vulkan just works, dynamically loaded)
- `games/vcmi`: open source reimplementation of Heroes of Might and Magic III! [221885](https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=221885)

### Misc

- `multimedia/gnome-twitch`: Twitch livestream player [224980](https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=224980)
- `archivers/maxcso`: ISO to CSO compressor for PSP/PS2 emulators [224638](https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=224638)
- `devel/llvm50`, `devel/llvm-devel`, `devel/cmake`: workarounds for LLVM linking / `llvm-config`!!! [223191](https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=223191)
- `editors/neovim-qt`: nvim GUI [224427](https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=224427)
- `devel/gitg`: 3.26
- `devel/gnome-builder`: 3.27 (XXX: crashes)
- `graphics/mypaint` and `graphics/libmypaint`: git master version, works on Wayland natively
- `graphics/inkscape`: git master version with GTK3, works on Wayland natively
- `editors/libreoffice`: **6.0.0.beta2** with GTK3 by default, works on Wayland natively [224288](https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=224288)
- `lang/crystal`: The Crystal programming language! [224459](https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=224459)
- `lang/ponyc`: The Pony programming language! [205444](https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=205444)
- `www/firefox`: [58 beta](https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=223425). See [FirefoxSettings](https://unrelenting.technology/kb/FirefoxSettings) for, well, settings (force enable GPU acceleration!)
- `graphics/instant-meshes`: Interactive field-aligned mesh generator [222711](https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=222711)
- `java/jamvm`: update to 2.0.0 [192305](https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=192305)
- `lang/rust-nightly`: revived port by copy-pasting from `lang/rust` and updating version numbers. Might need to use [libc from here](https://github.com/myfreeweb/libc) and [mio from there](https://github.com/FreeBSDRust/mio) via `[patch.crates-io]` sections in `Cargo.toml` files.
- `mail/geary`: update to 0.12.0 [210718](https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=210718)
- `audio/rhythmbox-plugin-{alternative-toolbar,coverart-browser,coverart-search-providers}`: Some nice Rhythmbox plugins [223137](https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=223137)
- `audio/picard`: 1.4.2 [223354](https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=223354)

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
CC=clang-devel
CXX=clang++-devel
CFLAGS+=-flto=thin
LDFLAGS+=-fuse-ld=gold
LDFLAGS+=-fuse-ld=lld
LD=ld.lld-devel
RUST_PORT=lang/rust-nightly
```

(but for some ports you'll have to turn some of these off!!! especially ThinLTO)

## Other FreeBSD desktop resources

- [kb/FreeBSDDesktop](https://unrelenting.technology/kb/FreeBSDDesktop)
- [My dotfiles](https://github.com/myfreeweb/dotfiles) (mostly the `x11` folder)
- [A FreeBSD 11 Desktop How-to](https://cooltrainer.org/a-freebsd-desktop-howto/), not up to date with modern GPU stuff but very good for general desktop setup (printing, networking, etc.)
- [FreeBSD on the ThinkPad X240](https://unrelenting.technology/articles/freebsd-on-the-thinkpad-x240), my post that's mostly updated but still contains old stuff

## Other resources

- [1.5 Hour Spicy SUPER EUROBEAT Mix](https://www.youtube.com/watch?v=6ftCIfHwqtg)
