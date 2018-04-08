#include <iostream>

using namespace std; 

bool dictionaryContains(string s) {
    string dictionary[] = {"mobile","samsung","sam","sung","man","mango","icecream","and","go","i","like","ice","cream"};
    int size_dict = sizeof(dictionary)/sizeof(string);
    for (int i = 0; i < size_dict; i++) {
        if (dictionary[i].compare(s) == 0)
            return true;
    }
    return false;
}

bool wordBreak(string s) {
    int size = s.size();

    if (s.size() == 0)
        return true;

    for (int i = 1; i <= s.size(); i++) {
        if (dictionaryContains(s.substr(0, i)) && wordBreak(s.substr(i, size - i)))
            return true;
    }

    return false; 
}

int main(int argc, char ** argv) {    
    wordBreak("ilikesamsung")? cout <<"Yesn": cout << "Non";
    wordBreak("iiiiiiii")? cout <<"Yesn": cout << "Non";
    wordBreak("")? cout <<"Yesn": cout << "Non";
    wordBreak("ilikelikeimangoiii")? cout <<"Yesn": cout << "Non";
    wordBreak("samsungandmango")? cout <<"Yesn": cout << "Non";
    wordBreak("samsungandmangok")? cout <<"Yesn": cout << "Non";
}
