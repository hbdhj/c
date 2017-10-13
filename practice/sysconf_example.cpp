#include <iostream>
#include <unistd.h>

using namespace std;

int main() {
    cout << "_SC_ARG_MAX is set to " << sysconf(_SC_ARG_MAX) << endl;
    cout << "_SC_CHILD_MAX is set to " << sysconf(_SC_CHILD_MAX) << endl;
    cout << "_SC_HOST_NAME_MAX is set to " << sysconf(_SC_HOST_NAME_MAX) << endl;
    cout << "_SC_LOGIN_NAME_MAX is set to " << sysconf(_SC_LOGIN_NAME_MAX) << endl;
    cout << "_SC_NGROUPS_MAX is set to " << sysconf(_SC_NGROUPS_MAX) << endl;
    cout << "_SC_CLK_TCK is set to " << sysconf(_SC_CLK_TCK) << endl;
    cout << "_SC_OPEN_MAX is set to " << sysconf(_SC_OPEN_MAX) << endl;
    cout << "_SC_PAGESIZE is set to " << sysconf(_SC_PAGESIZE) << endl;
    cout << "_SC_RE_DUP_MAX is set to " << sysconf(_SC_RE_DUP_MAX) << endl;
    cout << "_SC_STREAM_MAX is set to " << sysconf(_SC_STREAM_MAX) << endl;
    cout << "_SC_SYMLOOP_MAX is set to " << sysconf(_SC_SYMLOOP_MAX) << endl;
    cout << "_SC_TTY_NAME_MAX is set to " << sysconf(_SC_TTY_NAME_MAX) << endl;
    cout << "_SC_TZNAME_MAX is set to " << sysconf(_SC_TZNAME_MAX) << endl;
    cout << "_SC_VERSION is set to " << sysconf(_SC_VERSION) << endl;
    cout << "_SC_NPROCESSORS_CONF is set to " << sysconf(_SC_NPROCESSORS_CONF) << endl;
    cout << "_SC_NPROCESSORS_ONLN is set to " << sysconf(_SC_NPROCESSORS_ONLN) << endl;
    return 0;
}