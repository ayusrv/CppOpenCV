#include <iostream>
#include <cstdlib> // For getenv
#include <X11/Xlib.h>
#include <vector>
#include <unistd.h>
#include <X11/Xutil.h>
using namespace std;
bool flag = true;
Display *d = XOpenDisplay(NULL);
std::vector<int> v;

void NotifyUser(void (*p)())
{

    p();
}

void user()
{
    cout << "Notified";
}
void GetDir(Display *d)
{
    int i = 10;
    while (1)
    {
        char nk[256] = "";
        flag = true;
        XQueryKeymap(d,nk);
        for (int i = 0; i < 256; i++)
        {
            if ((int)nk[i] && flag)
            {
                cout<<i<<": "<<nk[i]<<" ";
                NotifyUser(user);
                cout << endl;
                flag = false;
            }
        }
        // cout << "Keymap content: " << nk << std::endl;
    }
}

int main(int argc, char *argv[], char **env)
{
    std::cout << "LOGNAME: " << getenv("LOGNAME") << std::endl;
    GetDir(d);
    return 0;
}
