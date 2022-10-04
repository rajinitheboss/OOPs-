#include<iostream>
#include<fstream>

using namespace std;

ofstream outfile;
outfile.open("output.txt",ios::out);

int main(){
    outfile<<"krishna sai kottakota"<<endl;
    outfile.close();
    return 0;
}