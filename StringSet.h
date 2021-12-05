#include <string>

using namespace std;

class StringSet{
private:
    string * stringArr;
    int cur;
    int max;
public:
    StringSet();
    StringSet(const StringSet &);

    ~StringSet();

    StringSet& operator = (const StringSet &);

    bool insert(const string);
    void remove(const string);
    int find(const string) const;
    int size() const;

    StringSet unions(const StringSet &) const;
    StringSet intersection(const StringSet &) const;
    StringSet difference(const StringSet &) const; // calling object - parameter

    //friend ostream& operator << (ostream&, const StringSet &); // debugging edits
};
