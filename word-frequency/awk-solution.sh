cat words.txt | awk '{ for (i = 1; i <= NF; ++i) ++a[$i] } END { for (i in a) print i, a[i] }' | sort -k 2 -nr
