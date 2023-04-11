#!/bin/bash

bits=10000000

while [ $bits -le 10000000000 ]
do
  /home/u189940/wordCloud/build/bloom/bloomfilter -b $bits -l hamlet.txt -f 1 -d "/home/u189940/wordCloud/dictionaryinput.txt"
  ((bits += 5000000))
done  

