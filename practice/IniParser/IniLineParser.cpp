#include <fstream>
#include <iostream>
#include "IniLineParser.hpp"

using namespace std;

IniLineParser::IniLineParser () {
    cout<<"IniLineParser::IniLineParser"<<endl;
    cur_session = "";
    cntComments = 0;
    cntFailedLines  = 0;
    cntSections = 0;
    cntEntry = 0;
}

IniLineParser::~IniLineParser() {
    cout<<"IniLineParser::~IniLineParser"<<endl;
}

int IniLineParser::init(string str) {
    cout<<"IniLineParser::init"<<endl;
    fstream ifs;
    ifs.open (str, ifstream::in);
    int lineNum = 1;
    while (ifs.good()) {
        // read one line
        string line;
        getline(ifs, line);
        cout<<"line num - "<<lineNum++<<" ";
        parseLine(line);

    }
    ifs.close();
    cur_session = "";
    return 0;
}

int IniLineParser::parseLine(string str) {
    cout<<"line length = "<<str.size()<<": "<<str<<endl;
    string stripped_str = stripString(str);
    if (stripped_str.length()) {
        cout<<stripped_str<<endl;
        if ( stripped_str[0] == '#' ) {
            cout<<"it is commit"<<endl;
            cntComments++;
        }
        else if ( stripped_str[0] == '[' and stripped_str[stripped_str.length()-1] == ']' ) {
            cout<<"it is session"<<endl;
            string section_name = stripped_str.substr(1, stripped_str.length()-2);
            cur_session = stripString(section_name);
            cout<<"now we meet a new session: "<<cur_session<<endl;
            cntSections++;
        }
        else if ( stripped_str.find('=') != string::npos ) {
            cout<<"maybe it is a configuration item"<<endl;
            std::size_t pos = stripped_str.find("=");
            string cfgItemName = stripString(stripped_str.substr(0, pos));
            string cfgItemVal = stripString(stripped_str.substr(pos+1, stripped_str.length()-pos-1));
            cout<<"cfgItemName = "<<cfgItemName<<", cfgItemVal = "<<cfgItemVal<<endl;
            if ((cfgItemName.length())&&(cfgItemVal.length())) {
                // add this to map
                if (cur_session.length()) {
                    cfgmap[cur_session][cfgItemName] = cfgItemVal;
                    cntEntry++;
                } else {
                    cntFailedLines++;
                }
            } else {
                cntFailedLines++;
            }
        } else {
            cout<<"can't parse this line"<<endl;
            cntFailedLines++;
        }
    }
    return 0;
}

string IniLineParser::stripString(string str) {
    int start = 0;
    int end = str.length() - 1;
    while (str[start]==' '&&start<end)
        start++;
    if (start==end)
        return "";
    while (str[end]==' '&&start<end)
        end--;
    if (start==end)
        return "";
    cout<<"start = "<<start<<", end = "<<end<<endl;
    if (start<end)
        return str.substr(start, end-start+1);
    return "";
}

void IniLineParser::dump() {
    cout<<endl<<"IniLineParser::dump"<<endl;
    for (map<string, map<string, string> >::iterator scsnIter=cfgmap.begin(); scsnIter!=cfgmap.end(); ++scsnIter) {
        cout << scsnIter->first<<":"<<endl;
        for (map<string, string>::iterator itemIter=scsnIter->second.begin(); itemIter!=scsnIter->second.end(); ++itemIter) {
            cout<<itemIter->first<<" - "<<itemIter->second<<endl;
        }
    }
}

string IniLineParser::query(string scsn, string item) {
    if (cfgmap.find(scsn)!= cfgmap.end()) {
        if(cfgmap[scsn].find(item)!= cfgmap[scsn].end()) {
            return cfgmap[scsn][item];
        }
    }
    return "";
}
