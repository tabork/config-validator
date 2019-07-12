// file for input.
// 

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>
#include <algorithm>
#include <regex>

#include "file_inputter.h"
#include "common.h"

using std::ifstream;
using std::cout;
using std::endl;
using std::string;
using std::unordered_set;
using std::regex_match;

const std::string WHITESPACE = " \r\t\f\v";
std::regex a ("<.*>");
std::regex n (".*\\{.*");
std::regex n1 ("\\}");

ConfigSet readFiles (TYPE type, string path){
	ifstream configFile (path);
	ConfigSet set;

	std::cout << "\t\t\t" << path << std::endl << std::endl;

	if (configFile.is_open()){
		string line = "";
		while(getline(configFile,line)){
			// std::cout << line << std::endl;
			string s = trim(line);
			if (s.length() != 0){
				if (s[0] != '#'){
					if ( (type == APACHE && !(regex_match(s,a))) || (type == NGINX && !(regex_match(s,n1)) && !(regex_match(s,n)) ) || type == SSH || type == MAIL) {
						set.insert(s);
						// std::cout << s << std::endl;
					}			
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



