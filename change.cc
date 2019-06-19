#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, char **argv)
{
    if(argc != 2)
    {
        cout << "wrong arguments" << endl;
        return -1;
    }

    ifstream ifs;
    ofstream ofs;
    ifs.open(argv[1]);
    ofs.open("out");
    char ch;
    while(ifs.get(ch))
    {
        if(ch >= 'A' & ch <= 'Z')
            ch += 'a'-'A';
        else if(ch == '\n')
            ch = '\n';
        else if(ch < 'a' || ch > 'z')
            ch = ' ';

        ofs << ch;
    }
    ifs.close();
    ofs.close();
    return 0;
}

