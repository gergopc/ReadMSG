#include <iostream>
#include <fstream>
#include <string.h>

#define START 0x10
#define STOP 0xFF
#define STARTUSERNAME 0x11
#define STOPUSERNAME 0x12
#define STARTMESSAGE 0x13
#define STOPMESSAGE 0x14


using namespace std;

int main()
{
ifstream fin("in.msg");
string a;
fin>>a;
while(fin.eof()==false){
    cout<<a;
    fin>>a;

}
}
