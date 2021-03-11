#!/usr/bin/env bash

g++ main.cpp -lncursesw -o SeventyFivePercent
gnome-terminal --geometry=132x43 -- ./SeventyFivePercent
