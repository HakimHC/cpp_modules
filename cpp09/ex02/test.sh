#! /bin/bash

GREEN='\033[0;32m'
RED='\033[0;31m'
END='\033[0m'

OK="${GREEN}OK${END}"
KO="${RED}KO${END}"

logfile=test.log

errlog=0

function test {
  original=$(./PmergeMe $(shuf -i 1-200000 -n $1 | tr "\n" " ") | grep -i after | tr -d "After:" | tr -d "\t")

  sorted=$(echo "$original" | tr " " "\n" | sort -n - | tr "\n" " " | rev | cut -c 2- | rev)
  # echo "$sorted"
  # echo "$original"
  echo -n $original >> $logfile
  diff -q <(echo "$original") <(echo "$sorted") 2>&1 >/dev/null
  if [ $? -ne 0 ]; then
    echo -e "$KO"
    echo " KO" >> $logfile
  else
    echo -e "$OK"
    if [ $errlog -ne 0 ]; then
      echo " OK" >> $logfile
    fi
  fi
}

function test_loop {
  echo "10 tests for $1 random numbers (between 1 and 200000)"
  echo "========= $1 NUMBERS ==========" >> $logfile
  for ((i = 1; i <= 10; i++))
  do
    test $1
  done

}

echo "======== WELCOME TO MY MERGE-INSERTION SORT TESTER ==========="
rm -f $logfile
if [[ "$1" = "-e" ]]; then
  errlog=1
fi
test_loop "10"
test_loop "100"
test_loop "3000"
