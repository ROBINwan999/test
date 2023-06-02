#include <aio.h>

#include <cstdio>
#include <cstdlib>
#include <cxxopts.hpp>

#include "../cpp_test/rolly.h"
#include "./cxxopts-master/include/cxxopts.hpp"

using namespace std;
using namespace cxxopts;

int main(int argc, char **argv) {
    Option options("MyProgram", "command line options");

    options .add_options()("d,debug", "Enable debugging")  // a bool parameter
        ("i,integer", "Int param", cxxopts::value<int>())("f,file", "File name", cxxopts::value<std::string>())(
            "v,verbose", "Verbose output", cxxopts::value<bool>()->default_value("false"));

    fmt_Println(options.arg_help_, options.desc_, options.opts_, options.value_);

    return 0;
}