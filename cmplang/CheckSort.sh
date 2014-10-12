#!/bin/bash

function printSorted() {
    prog_commands=( ./QsortC ./Qsort "java Qsort" ./Qsort.py "pypy Qsort.py" ./Qsort.php "jython -J-Xmx8000m Qsort.py" )
    PRINTLN="--print"
    for cmd in "${prog_commands[@]}"
    do
        j="2"
        while [ $j -lt 9 ]
        do
            eval $"$cmd" $"$j" $"--print"
            ((j++))
        done
    done
}

cd bin

if [ $1 == 'print' ]; then
        printSorted
        files=($(ls *sorted*.txt))
        for file in "${files[@]}"
        do
            ./CheckSort "$file"
        done
elif [ $1 == 'run' ]; then
    files=($(ls *sorted*.txt))
    for file in "${files[@]}"
    do
        ./CheckSort "$file"
    done
else
    echo "Usage: ./CheckSort.sh {\"print\" or \"run\"}"
fi

cd ..
