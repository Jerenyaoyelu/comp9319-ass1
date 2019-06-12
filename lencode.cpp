#include<iostream>
#include<fstream>
#include<algorithm>

using namespace std;
// The reason for the ./ prefix is because the current path (as referred to by the shortcut ".") is not in your $PATH environment variable.
// The short answer is, put "." in your $PATH environment: 'export PATH=$PATH:.'
// but it may cause security risk

int main(int argc, char* argv[]){
    char data[100];
    // if(find(argv[0],argv[argc-1],"-l") != argv[argc-1]){
    // cout<<find(argv,argv+argc,"-l")<<endl;
    // cout<<argv+argc<<endl;
    // cout<<*(argv+argc-1)<<endl;
    // cout<<argc<<endl;
    cin >> data;
    // cout << data << endl;
    if(argc == 1){
        cout << data <<endl;
    }
    if(
        (find(argv,argv+argc,"-l")!= argv+argc)||
        (find(argv,argv+argc,"-l") == argv+argc && strcmp(argv[argc-1],"-l")==0)
    ){
        // ifstream infile;
        // infile.open("test.txt",ios::in);
        // infile >> data;
        cout << data << endl;
    }
    return 0;
}