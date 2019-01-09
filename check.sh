g++ -std=c++17 -O3 -Wall -Wextra -D_GLIBCZZ_DEBUG -fsanitize=undefined $1.cpp -o $1
for f in *$1*.in; do
    echo '#### Start ' $f
    ./$1 < $f
done