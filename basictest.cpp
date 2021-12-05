#include "StringSet.h"
#include "iostream"

using namespace std;

void basicTest()
{
    StringSet sset1;
    sset1.insert("cat");
    sset1.insert("bat");
    sset1.insert("rat");
    cout << "insert success: " << sset1.insert("badger") << endl;

    StringSet sset2;
    sset2.insert("elephant");
    sset2.insert("bat");
    sset2.insert("hamster");
    sset2.insert("weasel");
    sset2.remove("weasel");
    cout << "index of weasel = " << sset2.find("weasel") << endl;
    // Use the copy constructor to build a StringSet with sset1 U sset2
    StringSet sset3(sset1.unions(sset2));

    // Use overloaded assignment operator to make a StringSet with sset2 int sset1
    StringSet sset4;
    sset4 = sset2.intersection(sset1);

    // Use overloaded assignment operator to make a StringSet with sset2 - sset1
    sset4 = sset2.difference(sset1);


    cout << "end basic test" << endl;
}

int main(){
    basicTest();
}
