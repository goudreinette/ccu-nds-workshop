#!/bin/sh

grit_args="-ftb -fh! -gTFF00FF -gt -gB8 -mR8 -mLs"

# Backgrounds
grit red.png $grit_args
grit yellow.png $grit_args
grit green.png $grit_args
grit blue.png $grit_args

for file in *.bin; do
    mv -- "$file" "${file%.bin}"
done

mv *.pal *.img *.map ../nitrofiles/
