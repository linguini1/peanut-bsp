# Peanut Altimeter Board Support Package

This repository contains the board support package for the [Peanut
altimeter][peanut] to hook into the [Nuttx][nuttx-web] build system. This
package sets up peripherals on the board so they can be manipulated by firmware
(i.e. barometer, buzzer, pyro channels, etc.).

## Usage

Clone this repository in your NuttX space folder, as a sibling directory to the
`nuttx` and `nuttx-apps` directories.

Then, you should be able to use the NuttX `tools/configure.sh` script to
configure the altimeter firmware build by providing a path to the desired
configuration you want to use:

```console
$ cd nuttx
$ ./tools/configure.sh ../peanut-bsb/configs/<config>
```
where `<config>` is the name of the configuration you want to flash.

## Flashing Firmware

Just plug in Peanut using the USB-C connector. On most systems, it will appear
under `/dev/ttyACM0`. You can then use the NuttX build system to build and flash
the firmware simultaneously:

```console
$ make flash ESPTOOL_PORT=/dev/ttyACM0
```

[peanut]: github.com/linguini1/peanut
[nuttx-web]: https://nuttx.apache.org/
