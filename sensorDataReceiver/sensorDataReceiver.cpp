#include <cstring>
#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

using namespace std;

int readDataFromConsole(int pip[], char readBuffer[])
{
    memset(readBuffer, 0, 500);
    read(pip[0], readBuffer, 450);
    cout<<readBuffer;
    return strlen(readBuffer);
}
