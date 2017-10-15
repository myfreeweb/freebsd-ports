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

- `graphics/mesa-dri` and `graphics/mesa-libs`: Vulkan drivers enabled [221540](https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=221540)
- `graphics/vulkan-sdk`: [Vulkan SDK](https://github.com/KhronosGroup/Vulkan-LoaderAndValidationLayers) (headers, ICD loader, validation layers) [222175](https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=222175)

NOTE: ANV (Intel Vulkan) doesn't really work yet.
RADV (Radeon Vulkan) with the `amdgpu` KMS/DRM driver works very well!
Tested on an AMD Polaris (RX 480) GPU.

### Xorg and Wayland

- `x11-toolkits/wlc`: updated to 0.0.10 (for sway)
- `x11-wm/sway`: [sway, the i3-like Wayland compositor](https://github.com/SirCmpwn/sway)
- `www/webkit2-gtk3`: Wayland option added (for GNOME Web aka Epiphany browser)
- `devel/sdl20`: Wayland option added [223018](https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=223018) (also, audio crash fixes imported)
- `x11/libinput`: Update to 1.8.0 [222905](https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=222905)
- `x11-servers/xorg-server`: added `UDEV` option to support evdev devices autodetection [222609](https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=222609)
- `x11/xcape`: [Useful X11 keyboard utility](https://github.com/alols/xcape) [222602](https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=222602)
- `multimedia/mpv`: Wayland option added [223029](https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=223029)
- `graphics/mesa-libs`: Fix device name detection [223030](https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=223030)

NOTE: [Wayland kernel panic issue and workaround](https://github.com/FreeBSDDesktop/kms-drm/issues/11)

### Games

- `x11-toolkits/mygui-devel`: current git version doesn't have weird C++ problems anymore, see [220189](https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=220189)
- `games/openmw-devel`: current git version uses the current `mygui` version 
- `games/vkquake`: [a Vulkan-powered Quake engine](https://github.com/Novum/vkQuake) [222182](https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=222182)
- `emulators/dolphin-emu`: [Dolphin Emulator](https://dolphin-emu.org) (GameCube/Wii) updated to a recent git revision (Vulkan just works, dynamically loaded)
- `devel/fuzzylite`: used for AI in VCMI [222052](https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=222052)
- `games/vcmi`: open source reimplementation of Heroes of Might and Magic III! [221885](https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=221885)

### Misc

- `www/firefox-beta`: Firefox 57! As always, don't forget `layers.acceleration.force-enabled` in `about:config`.
- `graphics/instant-meshes`: Interactive field-aligned mesh generator [222711](https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=222711)
- `graphics/goxel`: 3D voxel editor [222729](https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=222729)
- `java/jamvm`: update to 2.0.0 [192305](https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=192305)
- `lang/rust-nightly`: revived port by copy-pasting from `lang/rust` and updating version numbers. Here's the resulting toolchain tarballs: [rustc](https://unrelentingtech.s3.dualstack.eu-west-1.amazonaws.com/rust4current/rustc-nightly-x86_64-unknown-freebsd.tar.xz) [std](https://unrelentingtech.s3.dualstack.eu-west-1.amazonaws.com/rust4current/rust-std-nightly-x86_64-unknown-freebsd.tar.xz) [cargo](https://unrelentingtech.s3.dualstack.eu-west-1.amazonaws.com/rust4current/cargo-nightly-x86_64-unknown-freebsd.tar.xz) [rls](https://unrelentingtech.s3.dualstack.eu-west-1.amazonaws.com/rust4current/rls-nightly-x86_64-unknown-freebsd.tar.xz) [analysis](https://unrelentingtech.s3.dualstack.eu-west-1.amazonaws.com/rust4current/rust-analysis-nightly-x86_64-unknown-freebsd.tar.xz) [docs](https://unrelentingtech.s3.dualstack.eu-west-1.amazonaws.com/rust4current/rust-docs-nightly-x86_64-unknown-freebsd.tar.xz). Use [libc from here](https://github.com/myfreeweb/libc) and [mio from there](https://github.com/FreeBSDRust/mio) via `[patch.crates-io]` sections in `Cargo.toml` files.
- `mail/geary`: update to 0.12.0 [210718](https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=210718)
- `devel/apitrace`: OpenGL tracing tools [223002](https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=223002)

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

## Other FreeBSD desktop resources

- [My dotfiles](https://github.com/myfreeweb/dotfiles) (mostly the `x11` folder)
- [Building the awesome Alacritty terminal emulator on -CURRENT](https://github.com/jwilm/alacritty/issues/618#issuecomment-331983715) (also relevant for other Rust applications)
- [A FreeBSD 11 Desktop How-to](https://cooltrainer.org/a-freebsd-desktop-howto/), not up to date with modern GPU stuff but very good for general desktop setup (printing, networking, etc.)
- [FreeBSD on the ThinkPad X240](https://unrelenting.technology/articles/freebsd-on-the-thinkpad-x240), my post that's mostly updated but still contains old stuff

## Other resources

- [1.5 Hour Spicy SUPER EUROBEAT Mix](https://www.youtube.com/watch?v=6ftCIfHwqtg)
