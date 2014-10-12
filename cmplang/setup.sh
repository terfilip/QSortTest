chmod +x div.py TestTime.sh CheckSort.sh
mkdir -p bin
mkdir -p result
cp src/Qsort.php bin
cp src/Qsort.py bin
chmod +x bin/Qsort.php bin/Qsort.py 

make
java -classpath bin GenRandFile
