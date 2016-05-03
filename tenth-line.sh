#!/bin/bash


# Read from the file file.txt and output the tenth line to stdout
cat file.txt | awk '{ if(NR==10) print $0 }'
