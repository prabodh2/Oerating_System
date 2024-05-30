//!/bin/zsh
for file in *; do;
    if [ -f "$file" ]; then
        echo "$file - $(stat -c%s "$file") bytes"
    fi
done