#!/bin/sh

convert icon-1024.png -gamma 0.454545 -resize 36x36 -gamma 2.2 project/res/drawable-ldpi/icon.png
convert icon-1024.png -gamma 0.454545 -resize 48x48 -gamma 2.2 project/res/drawable-mdpi/icon.png
convert icon-1024.png -gamma 0.454545 -resize 72x72 -gamma 2.2 project/res/drawable-hdpi/icon.png
convert icon-1024.png -gamma 0.454545 -resize 96x96 -gamma 2.2 project/res/drawable-xhdpi/icon.png
convert icon-1024.png -gamma 0.454545 -resize 144x144 -gamma 2.2 project/res/drawable-xxhdpi/icon.png
convert icon-1024.png -gamma 0.454545 -resize 192x192 -gamma 2.2 project/res/drawable-xxxhdpi/icon.png
