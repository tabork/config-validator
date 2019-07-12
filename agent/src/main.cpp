
#include <iostream>

#include "jarvis_the_bee.h"
#include "file_inputter.h"
#include "rest_server.h"
#include "common.h"
#include <vector>

int main() {
        
    run_rest_server(3000, "127.0.0.1");
    return 0;
}
