﻿#define _CRT_SECURE_NO_DEPRECATE
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
        std::cout << "Nie mozna otworzyÄ‡ pliku log" << "log.txt" << std::endl;
    }
    saveLog("Plik log otwarty");
}

void closeLog(void)
{
    saveLog("Plik log zamkniety");
    logFile.close();
}

int main(int argc, char** argv)
{
    std::string fpath1;
    std::string fpath2;

    berResults results;

    openLog("log.log");
    if (argc != 3)  //argumenty niepoprawne
    {

        saveLog("Nie podano ścieżek plików");
        saveLog("Tworzę pliki testowe");
        //test 1
        createFile1("test1_file1.bin", 100, 0xFF); //1111 1111
        createFile1("test1_file2.bin", 100, 0xFE); //1111 1110
        //test 1

        //test 2

        //test 2
        //test 2

        //test 3
        createFile1("test3_file1.bin", 400000000, 0x55);
        createFile1("test3_file2.bin", 400000000, 0x50);
        //test 3

        saveLog("Pliki zostały stworzone");
    }
    else //argumenty poprawne
    {
        fpath1 = argv[1];
        fpath2 = argv[2];

        saveLog("Przetwarzanie plików");
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
    for (int i = 0; i < count; i++)
    {
        f.write((char*)&value, 1);
    }
    f.close();
}