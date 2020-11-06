#!/bin/bash

for x in {1..30}
do
    time ./a.out <input/E_$x >out_$x && diff out_$x output/E_$x
    echo $x
done