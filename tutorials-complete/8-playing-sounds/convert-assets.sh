#!/bin/sh


for background in assets/backgrounds/*.png; do
    grit $background -ftb -fh! -gb -gB16
done

for sprite in assets/sprites/*.png; do
    grit $sprite -ftb -fh! -gT000000 -gt -gB8 -m!
done

for file in *.bin; do
    mv -- "$file" "${file%.bin}"
done

mv *.pal *.img ./nitrofiles/
