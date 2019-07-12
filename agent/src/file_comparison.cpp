
#include <string>
#include <sstream>
#include <map>
#include <vector>

#include "file_inputter.h"
#include "jarvis_the_bee.h"
#include "common.h"

std::string do_comparisons()
{

	std::string sshPath = "/etc/ssh/sshd_config";
    std::string apachePath = "/etc/apache2/apache2.conf";
    std::string apache2Path = "/etc/apache2/conf-enabled/security.conf";
    std::string nginxPath = "/etc/nginx/nginx.conf";
    std::string dovecotPath = "/etc/dovecot/conf.d/10-ssl.conf";
    std::string postfixPath = "/etc/postfix/main.cf";

    // std::vector<ConfigSet> compare;
    // compare.push_back(readFiles(SSH, sshPath));
    // compare.push_back(readFiles(APACHE, apachePath));
    // compare.push_back(readFiles(APACHE, apache2Path));
    // compare.push_back(readFiles(NGINX, nginxPath));
    // compare.push_back(readFiles(MAIL, dovecotPath));
    // compare.push_back(readFiles(MAIL, postfixPath));


    // std::vector<ConfigSet> baseline;
    std::string sshPathBaseline = "../../sec_configs/sshd_config";
    std::string apachePathBaseline = "../../sec_configs/apache2.conf";
    std::string apache2PathBaseline = "../../sec_configs/security.conf";
    std::string nginxPathBaseline = "../../sec_configs/nginx.conf";
    std::string dovecotPathBaseline = "../../sec_configs/10-ssl.conf";
    std::string postfixPathBaseline = "../../sec_configs/main.cf";

    std::map<TYPE, std::map<std::string, double>> compare_map;

    // baseline.push_back(readFiles(SSH, sshPathBaseline));
    // baseline.push_back(readFiles(APACHE, apachePathBaseline));
    // baseline.push_back(readFiles(APACHE, apache2PathBaseline));
    // baseline.push_back(readFiles(NGINX, nginxPathBaseline));
    // baseline.push_back(readFiles(MAIL, dovecotPathBaseline));
    // baseline.push_back(readFiles(MAIL, postfixPathBaseline));

    compare_map[SSH] = std::map<std::string, double>();
    compare_map[APACHE] = std::map<std::string, double>();
    // compare_map[NGINX] = std::map<std::string, double>();
    compare_map[MAIL] = std::map<std::string, double>();

    compare_map[SSH][sshPath] = compare_configs(readFiles(SSH, sshPath), 
    											readFiles(SSH, sshPathBaseline));

    compare_map[APACHE][apachePath] = compare_configs(readFiles(APACHE, apachePath), 
    												  readFiles(APACHE, apachePathBaseline));

    compare_map[APACHE][apache2Path] = compare_configs(readFiles(APACHE, apache2Path), 
    												   readFiles(APACHE, apache2PathBaseline));

    // compare_map[NGINX][nginxPath] = compare_configs(readFiles(NGINX, nginxPath), 
    // 												readFiles(NGINX, nginxPathBaseline));

    compare_map[MAIL][dovecotPath] = compare_configs(readFiles(MAIL, dovecotPath), 
    											     readFiles(MAIL, dovecotPathBaseline));

    compare_map[MAIL][postfixPath] = compare_configs(readFiles(MAIL, postfixPath), 
    											     readFiles(MAIL, postfixPathBaseline));

    // std::vector<double> outputj;
    // auto bl = baseline.begin();
    // for (auto cp = compare.begin(); cp != compare.end(); ++cp){
    //     outputj.push_back(compare_configs(*cp, *bl));
    //     ++bl;
    // }

    // for (std::vector<double>::iterator i = outputj.begin(); i != outputj.end(); ++i)
    // {
    //     std::cout << "J = " << *i << std::endl;
    // }
    std::stringstream sstream;

    sstream << "{\"scans\":[";

    int i = 0;
    
    for (auto& type_item : compare_map)
    {

        if (i == 0)
    	   sstream << "{\"type\":\"";
        else
            sstream << ",{\"type\":\"";

    	switch (type_item.first)
    	{

    		case SSH:
    			sstream << "SSH";
    			break;
    		case APACHE:
    			sstream << "Apache";
    			break;
    		case NGINX:
    			sstream << "Nginx";
    			break;
            case MAIL:
                sstream << "Mail";
                break;

    	}
    	sstream << "\",\"files\":[";

        int j = 0;
    	for (auto& file_map : type_item.second)
    	{

            if (j == 0)
        		sstream << "{\"name\":\"" << file_map.first
        		        << "\",\"J\":\"" << file_map.second
        		        << "\"}";
            else
                sstream << ",{\"name\":\"" << file_map.first
                        << "\",\"J\":\"" << file_map.second
                        << "\"}";
            ++j;

    	}

    	sstream << "]}";
        ++i;

    }

    sstream << "]}";

    return sstream.str();

}