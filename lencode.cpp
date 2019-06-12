#include<iostream>
#include<fstream>
#include<algorithm>

using namespace std;

int main(int argc, char* argv[]){
    char data[100];
    // if(find(argv[0],argv[argc-1],"-l") != argv[argc-1]){
    cout<<find(argv,argv+argc,"-l")<<endl;
    cout<<argv+argc<<endl;
    cout<<*(argv+argc-1)<<endl;
    cout<<argc<<endl;
    if(
        (find(argv,argv+argc,"-l")!= argv+argc)||
        (find(argv,argv+argc,"-l") == argv+argc && strcmp(argv[argc-1],"-l")==0)
    ){
        // ifstream infile;
        // infile.open("test.txt",ios::in);
        // infile >> data;
        cin >> data;
        cout << "content:" << data << endl;
    }
    return 0;
}