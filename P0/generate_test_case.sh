#!/bin/bash

END=$1

for i in $(seq 1 $END); do  tr -cd '[:lower:]' < /dev/urandom | fold -w10 | head -n1 ; done

exit 0

