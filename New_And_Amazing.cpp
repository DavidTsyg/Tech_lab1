#include <vector>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class TextFiles
{
public:
    
    TextFiles(){};

    vector<string> strings;
    vector<size_t> hashes;
    unsigned int counter;
    string filename;

    void fill(string file)
    {
        ifstream fileout;
        filename = file;
        counter = 0;
        fileout.open(file.c_str());
        if (!fileout.is_open()) 
        {
            cout << "File could not be opened" << endl;
        }
        else
        {
            string str;
            while (getline(fileout, str))
            {
                strings.push_back(str);
                hashes.push_back(hash<string>{}(str));
                ++counter;
            }
        }
        fileout.close();
    }
};

void CompareTwo(TextFiles a, TextFiles b)
{
    //cout << "File " << b.filename << " doesn't contain these strings from " << a.filename << endl;
    //cout << "**************************************************************" << endl;
    bool flag;
    for (unsigned int i = 0; i < a.counter; ++i)
    {
        flag = false;
        for (unsigned int j = 0; j < b.counter; ++j)
        {
            if (a.hashes[i] == b.hashes[j])
            {
                flag = true;
            }
        }
        if(flag == false)
        {
            cout << a.filename << " " << i+1 << " " << a.strings[i] << endl;
            //cout << "--------------------------------------------------------------" << endl;
        }
    }
}

int main(int argc, char *argv[]) {
    
    TextFiles Object1, Object2;
    Object1.fill(argv[1]);
    Object2.fill(argv[2]);
    CompareTwo(Object1, Object2);
    CompareTwo(Object2, Object1);

    return 0;
}
