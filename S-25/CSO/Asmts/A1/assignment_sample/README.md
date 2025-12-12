# CSO Assignment boilerplate

## Compilation Example

Compilation of a C file along with the corresponding assembly `.s` file can be done with a single GCC command:

`gcc [path to C file here] [path to S file here] -o [output file path]`

For instance, for `q1` in the current directory structure, the command would look like

`gcc src/q1/q1.c src/q1/q1.s -o q1`

## Compilation of all problems in the assignment

Just run `make` to compile all 5 questions into their respective executables (uses the provided `Makefile`).
The files `q1`, `q2`, `q3`, `q4` and `q5` generated are executables corresponding to each problem of the assignment.
You can also run `make clean` to delete all the executables and do a fresh build, if needed.

## Submission

Rename the src folder to your roll number, ZIP the folder and submit.
