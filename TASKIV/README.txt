Write a program that calculates the BER (Bit Error Rate) for any two files.

Requirements for the program :


1. Console program. Takes as two arguments the paths to the files for which it calculates the BER value.

2. The result of the calculation is printed in the console (As the result you specify: Number of bits compared, number of different bits, BER result, calculation time).

3.The program creates a log.txt file in which it saves its logs. Each message starts with a timestamp.

4. Test 1: Prepare two identical files containing the binary stored value 0x55. Each file of 100 Bytes. 

5. Test 2: Prepare two files each of 100 bytes. The first contains the binary stored value 0x55. The second file differs from the first by any 10 bits.

6. Test 3: Prepare two files each of 400 MB. The first contains the binary stored value 0x55. The second file contains the binary stored value 0x50.


Give the result of the BER program for the given test files (Results stored in the log file) 

After the program has created the necessary files, the initialization of the BER counting program is as follows:

./"TASKIV.exe" test2_file1.bin test2_file2.bin

Note that the selected test files must be in the program directory in this case.

