#!/bin/sh


# for background in assets/backgrounds/*.png; do
#     grit $background -ftb -fh! -gT000000 -gt -gB8 -mR8 -mLs
# done

for sprite in assets/sprites/*.png; do
    grit $sprite -ftb -fh! -gT000000 -gt -gB8 -m!
done

for file in *.bin; do
    mv -- "$file" "${file%.bin}"
done

mv *.pal *.img ./nitrofiles/
