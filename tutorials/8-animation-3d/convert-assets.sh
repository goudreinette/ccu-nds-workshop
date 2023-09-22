#!/bin/sh


for background in assets/*.png; do
    grit $background -ftb -fh! -gT000000 -gt -gB8 -mR8 -mLs
done

for sprite in assets/sprites/*.png; do
    echo "converting $sprite"
    grit $sprite  -ftb -fh! -gTFF00FF -gb -gB8 -m! # bitmap this time
done

for file in *.bin; do
    mv -- "$file" "${file%.bin}"
done

mv *.pal *.img *.map ./nitrofiles/
