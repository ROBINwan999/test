#include <aio.h>

#include <cstdio>
#include <cstdlib>

#include "../cpp_test/rolly.h"
#include "./cxxopts-master/include/cxxopts.hpp"

using namespace std;
using namespace cxxopts;

int main(int argc, char* argv[]) {
    cxxopts::Options ops("TestDemo", " - this is example command line options:");

    ops.add_options()("h,help", "get fucking help")("c,cnm", "cnmlgbd", cxxopts::value<std::string>())(
        "w,wdnmd", "wdnmd", cxxopts::value<std::string>())("i,int", "123", cxxopts::value<int>())(
        "b,bool", "zheshiweimaone", cxxopts::value<bool>()->default_value("false"));

    auto res = ops.parse(argc, argv);

    if (res.count("help")) {
        fmt_Println(ops.help());
        return 0;
    }
    if (res.count("cnm")) {
        fmt_Println(res["cnm"].as<std::string>());
    }
    if (res.count("wdnmd")) {
        fmt_Println(res["wdnmd"].as<std::string>());
    }
    if (res.count("bool")) {
        fmt_Println(res["bool"].as<bool>());
    }

    auto args = res.arguments();
    for (const auto &arg: args) {
        fmt_Println(arg.key(), arg.value(), arg.as);
    }

    return 0;
}
