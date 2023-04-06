#!/bin/bash

bits=10000000

while [ $bits -le 100000000 ]
do
  /tmp/build/bloom/bloomfilter -b $bits -l hamlet.txt -f 2
  ((bits += 5000000))
done  

bits=10000000

while [ $bits -le 100000000 ]
do
  /tmp/build/bloom/bloomfilter -b $bits -l hamlet.txt -f 3
  ((bits += 5000000))
done 
