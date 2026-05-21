#!/bin/bash

for i in $(seq 4 12);
do
    ./katamino2 $i &
done
