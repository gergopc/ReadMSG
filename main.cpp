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

char decode(int num){
int sum=0;
 int rem;
 int i=1;
 int szr=10;
 while(num>0)
 {
 rem=num%szr;
 sum=sum+(rem*i);
 i*=5;
 num=num/szr;
 }
 return (char)sum;
}
int main()
{
ifstream fin("in.msg");
string a;
fin>>a;
while(fin.eof()==false){
    bool read;
    bool un_mode;
    bool msg_mode;
    char usr[1024];
    char msg[1024];
    int ui=0;
    int mi=0;
    //cout<<a;
    int p=0;
    int sector=999;
    string sec;
    while(sector>0){
    sec.clear();
    sec=a.substr(p, 3);
    p+=3;
    sector=atoi(sec.c_str());
    if(read==true){
     if(un_mode){
            cout<<decode(sector);
     //usr[ui]=decode(sector);
     ui++;
     }
     if(msg_mode){
     //msg[mi]=decode(sector);
     mi++;
     cout<<decode(sector);
     }

    }
    if(sector==START) read=true;
    if(sector==STOP){
            read=false;
            sector=0;
    }
    if(sector==STARTUSERNAME) un_mode=true;
    if(sector==STOPUSERNAME) un_mode=false;
    if(sector==STARTMESSAGE) msg_mode=true;
    if(sector==STOPMESSAGE) msg_mode=false;

    }
string username(usr);
string message(msg);
cout<<username<<": "<<message;
fin>>a;
}
}
