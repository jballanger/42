# 21sh
## Unix shell

##### Builtins
- echo
- cd
- setenv
- unsetenv
- env
- exit

##### Capabilities
- A line edition feature using the termcaps library.
    - Edit the line where the cursor is located.
    - Move the cursor left and right to be able to edit the line at a specific location.
    - Use up and down arrows to navigate through the command history.
    - Copy, and paste all part of a line using alt+c/alt+v.
    - Move directly by word towards the left or the right using alt+left and alt+right.
    - Go directly to the beginning or the end of a line by pressing home and end.
    - Write AND edit a command over a few lines. alt+up and alt+down allow to go from one line to another in the command while remaining in the same column.
    - Completely manage quotes and double quotes, even on several lines (expansions excluded).
- The ctrl+D and ctrl+C keys combination features in line edition and process execution.
- The “;” command line separator.
- Pipes “|”.
- The 4 following redirections “<”, “>”, “<<” and “>>”.
- File descriptor aggregation. (`rm doesntexist 2>&-`)
