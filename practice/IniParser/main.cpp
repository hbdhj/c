#include <fstream>
#include <iostream>
#include "IniLineParser.hpp"

using namespace std;

int main(int argc, const char** argv) {
    cout<<argc<<endl;
    for (int i = 0; i<argc; i++)
        cout<<argv[i]<<endl;
    string fileName;
    if (argc>1)
        fileName = argv[1];
    else
        fileName = "example.ini";
    IniLineParser parser;
    parser.init(fileName);
    parser.dump();
    string rst = parser.query("log", "level");
    cout<<"query result = "<<rst<<endl;
    return 0;
}
