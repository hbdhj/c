#include <string>
#include <map>

using namespace std;

class IniLineParser  {
public:
    IniLineParser ();
    virtual ~IniLineParser();
    int init(string str);
    void dump();
    int parseLine(string str);
    string stripString(string str);
    string query(string scsn, string item);
private:
    map<string, map<string, string> > cfgmap;
    string cur_session;
    int cntComments;
    int cntFailedLines;
    int cntSections;
    int cntEntry;
};
