#include <aio.h>

#include <cstdio>
#include <cstdlib>

#include "../cpp_test/rolly.h"
#include "./cxxopts-master/include/cxxopts.hpp"

using namespace std;
using namespace cxxopts;

int main(int argc, char* argv[]) {
    Options ops("TestDemo", "this is example command line options:");
    ops.add_options()("h,help", "get fucking help")("c,cnm", "cnmlgbd", cxxopts::value<std::string>())(
        "w,wdnmd", "wdnmd", cxxopts::value<std::string>())("i,int", 1, cxxopts::value<int>())(
        "b,bool", cxxopts::value<bool>()->default_value("false"));

    auto res = ops.parse(argc, argv);
    
    if (res.count("help")) {
        fmt_Println(ops.help());
        return 0;
    }
    if (res.count("cnm")) {
        fmt_Println(res["cnm"].as<std::string>());
    }
    if (res.count("wdnmd"))



    if (result.count("input")) {
        std::cout << "Input file: " << result["input"].as<std::string>() << std::endl;
    }

    if (result.count("output")) {
        std::cout << "Output file: " << result["output"].as<std::string>() << std::endl;
    }

    if (result.count("verbose")) {
        std::cout << "Verbose output enabled" << std::endl;
    }

    return 0;
}
