#include<iostream>
#include<fstream>

using namespace std;

ofstream outfile;

int main(){
    outfile.open("output.txt",ios::out);
    outfile<<"krishna sai kottakota"<<endl;
    outfile.close();
    return 0;
}