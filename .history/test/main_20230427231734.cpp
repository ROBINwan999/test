#include <aio.h>

#include <cstdio>
#include <cstdlib>

#include "../cpp_test/rolly.h"
#include "./cxxopts-master/include/cxxopts.hpp"

using namespace std;
using namespace cxxopts;

int main(int argc, char* argv[]) {
    ```
#include <iostream>
#include "cxxopts.hpp"

int main(int argc, char* argv[])
{
    cxxopts::Options options("MyProgram", " - example command line options");

    options.add_options()
        ("h,help", "Print help")
        ("i,input", "Input file", cxxopts::value<std::string>())
        ("o,output", "Output file", cxxopts::value<std::string>())
        ("v,verbose", "Verbose output", cxxopts::value<bool>()->default_value("false"));

    auto result = options.parse(argc, argv);

    if (result.count("help"))
    {
        std::cout << options.help() << std::endl;
        return 0;
    }

    if (result.count("input"))
    {
        std::cout << "Input file: " << result["input"].as<std::string>() << std::endl;
    }

    if (result.count("output"))
    {
        std::cout << "Output file: " << result["output"].as<std::string>() << std::endl;
    }

    if (result.count("verbose"))
    {
        std::cout << "Verbose output enabled" << std::endl;
    }

    return 0;
}

``` ops("TestDemo", " - this is example command line options:");
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
    if (res.count("wdnmd")) {
        fmt_Println(res["wdnmd"].as<std::string>());
    }
    if (res.count("bool")) {
        fmt_Println(res["bool"].as<bool>());
    }

    return 0;
}
