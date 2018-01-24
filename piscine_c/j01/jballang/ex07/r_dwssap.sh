cat /etc/passwd | sed /^#/d | sed '1d; n; d'  | rev | cut -d : -f 7 | sort -dr  | sed -n "${FT_LINE1},${FT_LINE2} p"  | tr '\n' ',' | sed "s/,/, /"g | sed "s/, $/./" | tr -d "\n"
