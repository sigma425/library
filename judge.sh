#!/usr/bin/env bash
g++ -std=c++20 -O2 -g -Wall -Wshadow -Wextra -D_GLIBCZZ_DEBUG -fsanitize=undefined,address $1.cpp -o $1
for f in tests/*$1*.in; do
    echo '#### Start ' $f
    of=${f%.in}.out
    af=${f%.in}.ans
    ./$1 < $f | tee $af
    echo " --- dif mode ---"
    diff -y --ignore-trailing-space --ignore-blank-lines $af $of
#    diff -y $af $of
    if [[ $? = 1 ]] ; then
        echo -e "\e[33mWA\e[m"
    fi
done
