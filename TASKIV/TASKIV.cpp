#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>  
#include <stdio.h>



struct berResults
{
    double tot;
    double err;
    float ber;
    clock_t t1;
    clock_t t2;
};

std::fstream logFile;

void saveLog(std::string msg)
{
    std::string ss;
    time_t currentTime = time(NULL);
    std::string txttime = (std::string)asctime(localtime(&currentTime));
    txttime = txttime.substr(0, txttime.length() - 1);
    ss = (std::string)"T: " + txttime + " M: " + msg + "\n";
    logFile << ss.c_str();
    logFile.flush();
    std::cout << ss.c_str();
    std::cout.flush();
}

void openLog(std::string fileName)
{
    logFile.open(fileName.c_str(), std::ios_base::app);
    if (!logFile.good() == true)
    {
        std::cout << "Unable to open log file" << "log.txt" << std::endl;
    }
    saveLog("Open log file");
}

void closeLog(void)
{
    saveLog("Log file closed");
    logFile.close();
}

uint8_t hammingDistance(uint8_t n1, uint8_t n2);
void createFile1(const std::string name, const int count, const char value);
berResults calculateBer(std::string fpath1, std::string fpath2);
void printResult(berResults results);

int main(int argc, char** argv)
{
    std::string fpath1;
    std::string fpath2;

    berResults results;

    openLog("log.log");
    if (argc != 3)  //incorrect arguments
    {

        saveLog("No file paths provided");
        saveLog("Creating test files");
        //test 1
        createFile1("test1_file1.bin", 100, 0x55);
        createFile1("test1_file2.bin", 100, 0x55);
        //test 1

        //test 2
        createFile1("test2_file1.bin", 100, 0x55);
        createFile1("test2_file2.bin", 98, 0x55);
        //test 2
        //test 2

        //test 3
        createFile1("test3_file1.bin", 400000000, 0x55);
        createFile1("test3_file2.bin", 400000000, 0x50);
        //test 3

        saveLog("The files were created");
    }
    else //arguments correct
    {
        fpath1 = argv[1];
        fpath2 = argv[2];

        saveLog("File processing");
        results = calculateBer(fpath1, fpath2);
        printResult(results);
    }

    closeLog();
    return 0;
}

uint8_t hammingDistance(uint8_t n1, uint8_t n2)
{
    uint8_t x = n1 ^ n2; // XOR
    uint8_t setBits = 0;
    while (x > 0)
    {
        setBits += x & 1;
        x >>= 1;
    }
    return setBits;
}

void createFile1(const std::string name, const int count, const char value)
{
    std::fstream f;
    f.open(name.c_str(), std::ios::binary | std::ios::out);
    unsigned char num1(0xEE);
    unsigned char num2(0x1E);

    if (count == 98)
    {
        for (int i = 0; i < count; i++)
        {
            f.write((char*)&value, 1);
        }
        f.write((char*)&num1, 1);
        f.write((char*)&num2, 1);
    }
    else
    {
        for (int i = 0; i < count; i++)
        {
            f.write((char*)&value, 1);
        }
    };
    
    f.close();
}

berResults calculateBer(std::string fpath1, std::string fpath2)
{
    std::fstream f1, f2;
    berResults results;
    results.t1 = 0;
    results.t2 = 0;
    results.ber = 0;
    results.err = 0;
    results.tot = 0;

    saveLog("Calculating BER");

    f1.open(fpath1.c_str(), std::ios::binary | std::ios::in);
    f2.open(fpath2.c_str(), std::ios::binary | std::ios::in);

    char a = 0x00;
    char b = 0x00;
    results.t1 = clock();

    if (!f1) {
        saveLog("File one error");
    }
    if (!f2) {
        saveLog("File two error");
    }
    while (!f1.eof())
    {
        f1 >> a;
        f2 >> b;
        if (f1.eof()) { break; }
        results.err += hammingDistance(a, b);
        results.tot += 8;

    }

    results.ber = (float)results.err / results.tot; // calculating ber
    results.t2 = clock();
    saveLog("BER calculations concluded");
    return results; //return results
}

void printResult(berResults results)
{
    std::stringstream message;
    message << "Results: " << std::endl;
    message << "BER: " << results.ber << std::endl;
    message << "Tot: " << results.tot << std::endl;
    message << "Err: " << results.err << std::endl;
    message << "Calculation Time: " << ((float)results.t2 - results.t1) / CLOCKS_PER_SEC << " sec ";
    saveLog(message.str());
}
