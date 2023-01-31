#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>

using namespace std;


void CompressFile(const string& input_file, const string& output_file) {
     
    ifstream in_file(input_file, ios::binary);
 
    ofstream out_file(output_file, ios::binary);
   
    vector<char> chars;
   
    while (in_file) {
        char ch;

        in_file.get(ch);

        chars.push_back(ch);
    }
   
    chars.pop_back();
   
    string curr = "";

    map<string,int> dict;

    // Number of times the current substring appears in the file.    

    int count = 0;

    // Current dictionary index (starts from 1).    

    int index = 1;

    for (char ch : chars) {

        // Add current character to substring and increase count by one.    

        curr += ch;      
        ++count;      
        dict[curr] = count;      
        cout << curr << endl;      
        cout << count << endl << endl;       
        if (dict[curr] == count) { 
            out_file << index << ' ' << curr << '\n';         
            ++index;         
            curr = ch;         
            count = 0; 
        }
        else { 
            curr += ch;          
            ++count; 
        }       
        dict[curr] = count;
    }
} int main() { CompressFile("input.txt", "output.txt"); 
return 0; 
}