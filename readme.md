# CCU Nintendo DS Workshop


![CCU Nintendo DS Workshop](./cover.png)


## Prerequisites

- [devkitPro](https://devkitpro.org/wiki/Getting_Started)
- [Aseprite](https://www.aseprite.org/)
- [Desmume](https://desmume.org/)
    - Mac: `brew install --cask desmume`



## Getting started



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
