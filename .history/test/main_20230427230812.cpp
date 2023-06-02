#include <aio.h>

#include <cstdio>
#include <cstdlib>
#include <cxxopts.hpp>

#include "../cpp_test/rolly.h"
#include "./cxxopts-master/include/cxxopts.hpp"

using namespace std;
using namespace cxxopts;

#如何导入cxxopts

cxxopts是一个C++命令行参数解析库，能够帮助开发者轻松地解析命令行参数。以下是导入cxxopts的步骤：

1. 从Github上下载cxxopts的源代码：[https://github.com/jarro2783/cxxopts](https://github.com/jarro2783/cxxopts)
2. 将cxxopts的头文件cxxopts.hpp复制到你的项目目录下。
3. 在你的代码中包含cxxopts的头文件： `#include "cxxopts.hpp"`
4. 在你的代码中使用cxxopts解析命令行参数。

以下是一个简单的例子，演示如何使用cxxopts：

```
#include <iostream>

#include "cxxopts.hpp"

int main(int argc, char* argv[])
{
    cxxopts::Options options("MyProgram", " - example command line options");

    options.add_options()("h,help", "Print help")("i,input", "Input file", cxxopts::value<std::string>())(
        "o,output", "Output file", cxxopts::value<std::string>())("v,verbose", "Verbose output",
                                                                  cxxopts::value<bool>()->default_value("false"));

    auto result = options.parse(argc, argv);

    if (result.count("help")) {
        std::cout << options.help() << std::endl;
        return 0;
    }

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
