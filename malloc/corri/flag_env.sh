#!/bin/sh
export LD_LIBRARY_PATH=.
export LD_PRELOAD=libft_malloc.so
export MALLOC_VERBOSE=0
export MALLOC_NO_DEFRAGMENT=0
$@