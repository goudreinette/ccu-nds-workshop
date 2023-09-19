#!/bin/sh

grit_args="-ftb -fh! -gTFF00FF -gt -gB8 -mR8 -mLs"


# Backgrounds
for background in assets/*.png; do
    grit $background $grit_args
done

for file in *.bin; do
    mv -- "$file" "${file%.bin}"
done

mv *.pal *.img *.map ./nitrofiles/
