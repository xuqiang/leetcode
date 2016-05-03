#!/bin/bash

# Read from the file words.txt and output the word frequency list to stdout.
cat words.txt | awk -F' ' '{ for(i=1;i<=NF;++i) print $i }' | sort | uniq -c | sort -k1nr | awk '{ print $2" "$1 }'
