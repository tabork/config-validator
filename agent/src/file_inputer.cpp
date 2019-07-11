// main file for input.
// 

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>
#include <algorithm>

using std::ifstream;
using std::cout;
using std::endl;
using std::string;
using std::unordered_set;
using ConfigSet = unordered_set<string>;

ConfigSet readFiles (string);
string formatLine (string);
string trim (const string&);
string rtrim (const string&);
string ltrim (const string&);

const std::string WHITESPACE = " \n\r\t\f\v";


ConfigSet readFiles (string path){
	ifstream sshConfigFile (path);
	ConfigSet set;

	if (sshConfigFile.is_open()){
		//cout << "file opened.\n";
		string line = "";
		while(getline(sshConfigFile,line)){
			if (line.length() != 0){
				if (line[0] != '#'){
					//cout << line << endl;
					string ss = trim(line);
					set.insert(line);
				}
			}	
		}
	}
	sshConfigFile.close();
	return set;
}

string trim(const string& s)
{
    return rtrim(ltrim(s));
}

string ltrim(const string& s)
{
    size_t start = s.find_first_not_of(WHITESPACE);
    return (start == string::npos) ? "" : s.substr(start);
}

string rtrim(const string& s)
{
    size_t end = s.find_last_not_of(WHITESPACE);
    return (end == string::npos) ? "" : s.substr(0, end + 1);
}



