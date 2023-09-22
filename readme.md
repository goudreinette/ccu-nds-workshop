# CCU Nintendo DS Workshop


![CCU Nintendo DS Workshop](./cover.png)


## Installation

Requirements:
- [devkitPro](https://devkitpro.org/wiki/Getting_Started) with `nds-dev` package installed
    - [Mac and Linux](https://github.com/devkitPro/pacman/releases/tag/v6.0.2)
    - [Windows](https://github.com/devkitPro/installer/releases/tag/v3.0.3)
- [Aseprite](https://www.aseprite.org/) to edit sprites and backgrounds
- [DeSmuME](https://github.com/TASEmulators/desmume/releases) or another NDS emulator
    - For Linux look [here](https://www.maketecheasier.com/desmume-play-nintendo-ds-games-linux/)
- [nflib](https://github.com/knightfox75/nds_nflib) library


### (Mac/Linux) Add these lines to your `.zshrc` or `.bashrc` file 
```zsh
export DEVKITARM=/opt/devkitpro/devkitARM
export DEVKITPRO=/opt/devkitpro
```


## Clone the repository somewhere in your computer

```bash
git clone 
```


## Building a program
Go to the folder of the program you want to build.

```bash
cd demos/buttons
```


### Convert images to the format used by the DS
Do this before compiling the program.

```bash
sh ./convert-assets.sh
```

### Compiling 

```bash
make
```

### Running the program on the emulator

```bash
open buttons.nds
```



## Graphics
We're using the PICO-8 color palette.