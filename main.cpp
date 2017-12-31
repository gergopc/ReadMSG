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
    bool read;
    bool un_mode;
    bool msg_mode;
    cout<<a;
    int p=0;
    int sector=999;
    string sec;
    while(sector>0){
    sec.clear();
    sec=a.substr(p, 3);
    p+=3;
    sector=atoi(sec.c_str());
    if(sector==START) read=true;
    if(sector==STOP){
            read=false;
            sector=0;
    }
    if(sector==STARTUSERNAME) un_mode=true;
    if(sector==STOPUSERNAME) un_mode=false;
    if(sector==STARTMESSAGE) msg_mode=true;
    if(sector==STOPMESSAGE) msg_mode=false;
    if(read==true){


    }
    }
cout<<username<<": "<<message;
fin>>a;
}
}
