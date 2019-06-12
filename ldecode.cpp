#include<iostream>
#include<fstream>
#include<algorithm>

using namespace std;

int main(int argc, char* argv[]){
    char data[100];
    cin >> data;
    cout << data << endl;
    if(
        (find(argv,argv+argc,"-l")!= argv+argc)||
        (find(argv,argv+argc,"-l") == argv+argc && strcmp(argv[argc-1],"-l")==0)
    ){
        // ifstream infile;
        // infile.open("test.txt",ios::in);
        // infile >> data;
        cout << "content:" << data << endl;
    }
    return 0;
}