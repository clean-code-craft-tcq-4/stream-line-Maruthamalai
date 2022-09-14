#include <cstring>
//#include <cstdio>
//#include <cstdlib>
#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

using namespace std;

int readDataFromConsole(int pip[], char readBuffer[])
{
    //char writeBuffer[1000];
    memset(readBuffer, 0, 500);
    read(pip[0], readBuffer, 450);
    //cout<<writeBuffer;
    //cout<<strlen(readBuffer);
    return strlen(readBuffer);
}
