awk '{print}' file.txt
awk '{print $1}' file.txt
awk '$2 > 100' file.txt
awk 'END {print NR}' file.txt
awk '{sum += $1} END {print sum}' file.txt