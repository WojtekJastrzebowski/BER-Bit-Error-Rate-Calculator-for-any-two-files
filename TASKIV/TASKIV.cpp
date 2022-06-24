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
        std::cout << "Nie mozna otworzyÄ‡ pliku log" << "log.txt" << std::endl;
    }
    saveLog("Plik log otwarty");
}

void closeLog(void)
{
    saveLog("Plik log zamkniety");
    logFile.close();
}