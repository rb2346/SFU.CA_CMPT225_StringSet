#include <iostream>
#include <StringSet.h>

StringSet::StringSet() {
    stringArr = new std::string[2];
    max = 2;
    cur = 0;
}

StringSet::StringSet(const StringSet &s) {
    max = s.max;
    cur = s.cur;
    stringArr = new std::string[max];
    for(int i = 0; i < size(); i++) {
        stringArr[i] = s.stringArr[i];
    }
}

StringSet::~StringSet() {
    delete [] stringArr;
    cur = 0;
}

StringSet & StringSet::operator=(const StringSet &s) {
    max = s.max;
    cur = s.cur;
    stringArr = new std::string[max];
    for(int i = 0; i < size(); i++) {
        stringArr[i] = s.stringArr[i];
    }
    return *this;
}

bool StringSet::insert(const string string1) {
    bool flag = true;
    if(find(string1) == -1){
        if(size() < max){
            stringArr[size()] = string1;
            cur += 1;
            return true;
        } else {
            max *= 2;
            string * temp = new string[max];
            for(int i = 0; i < size(); i++){
                temp[i] = stringArr[i];
            }
            delete [] stringArr;
            stringArr = temp;
            return insert(string1);
        }
    } else {
        return false;
    }

}

void StringSet::remove(const string string1) {
    int i = find(string1);
    if(i != -1){
        stringArr[i] = stringArr[size()-1];
        cur--;
    }
}

int StringSet::find(const string srchTerm) const {
    for(int i = 0; i < size(); i++){
        if(stringArr[i] == srchTerm){
            return i;
        }
    }
    return -1;
}

int StringSet::size() const {
    return cur;
}

StringSet StringSet::unions(const StringSet &s) const {
    StringSet result;

    for(int i = 0; i < size(); i++)
        result.insert(stringArr[i]);

    for(int i = 0; i < s.size(); i++)
        result.insert(s.stringArr[i]);

    //cout << *this << " Union " << s << " = " << result << endl; Debugging Edits

    return result;
}

StringSet StringSet::intersection(const StringSet &s) const {
    StringSet result;

    for(int i = 0; i < size(); i++){
        if(s.find(stringArr[i]) != -1)
            result.insert(stringArr[i]);
    }
    //cout << *this << " Intersection " << s << " = " << result << endl; Debugging Edits
    return result;
}

StringSet StringSet::difference(const StringSet &s) const {
    StringSet result;
    for(int i = 0; i < size(); i++){
        if(s.find(stringArr[i]) == -1)
            result.insert(stringArr[i]);
    }
    //cout << *this << " Difference " << s << " = " << result << endl; Debugging Edits
    return result;
}

/*ostream& operator << (ostream& out, const StringSet &s)  //Ostream implemented for debugging
{
    if (s.size() == 0)
        out << "[Empty List]";
    else
    {
        out << " [ ";
        for (int i = 0; i < s.size(); i++){
            out << s.stringArr[i];
            out << " ";
        }
        out << "] ";
    }
    return out;
}*/