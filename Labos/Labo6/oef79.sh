#!/bin/bash

var=/a/b/c/d/e.txt

file=${var##*/}
echo $file

dir=${var%$file}
echo $dir
