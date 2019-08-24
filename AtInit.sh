# Atinit.sh abc128 6
root='/mnt/c/Users/sigma/Documents/Cprogram/'
python3 $root'sample_collector.py' $1
bash $root'init.sh' $2
cp $root'judge.sh' .