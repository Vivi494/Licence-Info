#!/bin/bash

function chperm {
    if [[ -z $2 ]]; then
        chmod u+rx $1
    else
        chmod a+rx $1
    fi
}

chperm $1 $2
