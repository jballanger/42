#!/bin/sh

clear
echo "========================================================="
echo "Compile, norminette et ls"
echo "========================================================="
cc -Wall -Wextra -Werror -o sudoku *.c
echo "========================================================="
echo "Norminette"
echo "========================================================="
norminette -R CheckForbiddenSourceHeader *.c
echo "========================================================="
echo "ls"
echo "========================================================="
ls -l
echo "========================================================="
./sudoku "9...7...." "2...9..53" ".6..124.." "84...1.9." "5.....8.." ".31..4..." "..37..68." ".9..5.741" "47......."
echo "========================================================="
./sudoku "..9.86.41" "52...3.7." "4...2.3.." "6.2831795" "..52746.." "8376951.4" "..4.6...2" ".5.9...63" "16.45.9.."
echo "========================================================="
./sudoku "9.6.7.4.3" "0..4..2.." ".7..23.1." "5.....1.." ".4.2.8.6." "..3.....5" ".3.7...5." "..7..5..." "4.5.1.7.8"
echo "========================================================="
./sudoku "........." "........." "........." "........." "........." "........." "........." "........." "........."
echo "========================================================="
echo "Press ENTER to restart"
read
sh compile.sh