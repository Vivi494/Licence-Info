#!/bin/bash

function square {
for (( k=$1;k<=$2;k++ )); do
    carre=$(($k*$k));
    echo $carre;
done
}

square $1 $2
