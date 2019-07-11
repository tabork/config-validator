
#ifndef CONFIG_COMPARE_FILE_INPUTTER_H
#define CONFIG_COMPARE_FILE_INPUTTER_H

#include <string>
#include <unordered_set>

#include "common.h"

ConfigSet readFiles (std::string);
std::string formatLine (std::string);
std::string trim (const std::string&);
std::string rtrim (const std::string&);
std::string ltrim (const std::string&);

ConfigSet readFiles (std::string path);


#endif //CONFIG_COMPARE_FILE_INPUTTER_H
