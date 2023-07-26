#! /bin/bash

original=$(./PmergeMe $(shuf -i 1-200000 -n $1 | tr "\n" " ")|grep -i after|tr -d "After:"|tr -d "\t")

sorted=$(echo "$original" | tr " " "\n" | sort -n - | tr "\n" " " | rev | cut -c 2- | rev)

# echo "Test: $original"
# echo "Sorted: $sorted"
diff <(echo "$original") <(echo "$sorted")
