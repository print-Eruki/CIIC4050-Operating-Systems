Make a simple terminal program. This program must handle at least 
the following commands:

ls
cp
mv
ifconfig
make
cat

Execute a custom program by naming the executable file.
Use the fork() function to create a new process and exec() to launch
the command. In the parent process, use the wait()
function to wait for its son to end before receiving a new command. 
The terminal program must be able to accept parameters for each of the 
commands.

Hint: use the execvp() function to launch the commands.

If the user’s input contains multiple commands, e.g., “ifconfig; ls -l; ./program1,” each command will be executed sequentially.

Upload a compressed file with the project's folder, including the "src" and "include" 
directories and the cmakelists.txt file. The program will not be evaluated 
if it does not compile correctly with the cmakelists.txt file.