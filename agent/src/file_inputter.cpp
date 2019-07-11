// main file for input.
// 

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>
#include <algorithm>

#include "file_inputter.h"
#include "common.h"

using std::ifstream;
using std::cout;
using std::endl;
using std::string;
using std::unordered_set;

const std::string WHITESPACE = " \n\r\t\f\v";


ConfigSet readFiles (string path){
	ifstream configFile (path);
	ConfigSet set;

	if (configFile.is_open()){
		//cout << "file opened.\n";
		string line = "";
		while(getline(configFile,line)){
			string ss = trim(line);
			if (ss.length() != 0){
				if (ss[0] != '#'){
					//cout << line << endl;
					set.insert(ss);
				}
			}	
		}
	}
	configFile.close();
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



