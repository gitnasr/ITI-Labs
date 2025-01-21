#include <iostream>
#include <cstring>

using namespace std;
class Nasr
{
    static int counter;
    static char *schoolName;

    int UserID;
    char *userName;

public:
    void setUserID(int UserID)
    {
        this->UserID = UserID;
    }
    int getUserID()
    {
        return this->UserID;
    }
    char *getUserName()
    {
        return this->userName;
    }
    void setUserName(const char *userName)
    {
        this->userName = new char[strlen(userName) + 1];
        strcpy(this->userName, userName);
    }

    static int getCount()
    {
        return counter;
    }
    static char* getSchoolName() {
        return schoolName;
    }

    Nasr()
    {
        this->counter += 1;
    }
    ~Nasr()
    {

        this->counter -= 1;
        cout << "Current Object count : " << this->counter << endl;
    }
};
int Nasr::counter = 0;
char* Nasr::schoolName = strcpy(new char[strlen("SLS School") + 1],"SLS School");

int main()
{

    Nasr o1;
    o1.setUserID(4);
    o1.setUserName("NASRIKA");

    Nasr o2;
    o2.setUserID(2);
    o2.setUserName("NASR");

    cout << o2.getCount() << endl;
    cout << o1.getCount() << endl;
    cout << o1.getSchoolName() << endl;
}