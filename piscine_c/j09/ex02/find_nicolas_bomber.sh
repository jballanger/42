cat $1 | grep -i bomber | grep -i nicolas | cut -d $'\t' -f3 | awk -F '[^0-9]*' '$1'
