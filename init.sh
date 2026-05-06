ABC=`echo {A..Z}`
for ((i=0;i<$1;i++))
do
    cp `dirname "$0"`/0.cpp ${ABC:$i*2:1}.cpp
done