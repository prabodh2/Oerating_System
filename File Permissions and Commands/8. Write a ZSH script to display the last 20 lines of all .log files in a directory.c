for log in *.log; do
    echo "==> $log <=="
    tail -n 20 "$log"
done
