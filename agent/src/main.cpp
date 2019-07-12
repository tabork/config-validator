
#include <iostream>

#include "jarvis_the_bee.h"
#include "file_inputter.h"
#include "rest_server.h"
#include "common.h"

int main() {
    // ConfigSet baseline;
    // baseline.insert("test");
    // baseline.insert("testagain");
    // baseline.insert("whadup");

    // ConfigSet compare;
    // compare.insert("test");
    // compare.insert("nicetry");
    // compare.insert("hello");
    // compare.insert("whadup");
    // compare.insert("whatwhat");
    // compare.insert("trybreaking");
    // compare.insert("imabee");
    // compare.insert("testagain");

    // double J = compare_configs(baseline, compare);

    // std::string file_path = "test_file.txt";

    // ConfigSet cs = readFiles(SSH, file_path);

    // std::cout << "J = " << J << std::endl;

    // for (auto& item : cs)
    //     std::cout << item << std::endl;
    //     
    run_rest_server(8080, "0.0.0.0");
    return 0;
}