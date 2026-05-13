#!/bin/bash

for i in $(seq 3 12);
do
    ./katamino3 $i &
done
