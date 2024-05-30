if [ "$#" -ne 2 ]; then
    echo "Usage: $0 source_directory backup_directory"
    exit 1
fi

src_dir="$1"
backup_dir="$2"

if [ -d "$src_dir" ]; then
    cp -r "$src_dir" "$backup_dir"
    echo "Backup of $src_dir completed in $backup_dir"
else
    echo "Source directory $src_dir does not exist"
    exit 1
fi