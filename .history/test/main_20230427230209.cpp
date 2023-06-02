#include "../cpp_test/rolly.h"

using namespace std;

#include "./cxxopts-master/include/cxxopts.hpp"

int main(int argc, char **argv) {
    cxxopts::Option options("MyProgram", "command line options");
    fmt_Println(options.arg_help_, options.desc_, options.opts_,
                options.value_);
                auto res = options.
    return 0;
}