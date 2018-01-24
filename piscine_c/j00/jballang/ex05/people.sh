#!bin/sh
ldapsearch -LLL 'uid=z*' cn | grep "^cn" -i | sort -r | sed "s/cn: //"
