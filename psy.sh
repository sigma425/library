#!/bin/bash

# 使い方
# ./psy.sh A.cpp name
#		- A.cpp をコンパイルして、name という名前で結果を保存
# ./psy.sh A.cpp
#		- A.cpp をコンパイルして、結果は保存せずにテスト

g++ -std=c++20 -O3 -Wall -Wextra -Wshadow $1
psytester run $2 -t 0-9 -p