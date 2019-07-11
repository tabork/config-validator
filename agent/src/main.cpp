
#include <iostream>

#include "jarvis_the_bee.h"

int main() {
    ConfigSet baseline;
    baseline.insert("test");
    baseline.insert("testagain");
    baseline.insert("whadup");

    ConfigSet compare;
    compare.insert("test");
    compare.insert("nicetry");
    compare.insert("hello");
    compare.insert("whadup");
    compare.insert("whatwhat");
    compare.insert("trybreaking");
    compare.insert("imabee");
    compare.insert("testagain");

    double J = compare_configs(baseline, compare);

    std::cout << "J = " << J << std::endl;
    return 0;
}