#ifndef ROLLY_H
#define ROLLY_H

// Unix
#include <aio.h>
#include <arpa/inet.h>
#include <dlfcn.h>
#include <fcntl.h>
#include <fmtmsg.h>
#include <fnmatch.h>
#include <ftw.h>
#include <glob.h>
#include <grp.h>
#include <iconv.h>
#include <langinfo.h>
#include <libgen.h>
#include <monetary.h>
#include <net/if.h>
#include <netdb.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <nl_types.h>
#include <poll.h>
#include <pthread.h>
#include <pwd.h>
#include <regex.h>
#include <sched.h>
#include <search.h>
#include <semaphore.h>
#include <spawn.h>
#include <strings.h>
#include <sys/ipc.h>
#include <sys/mman.h>
#include <sys/msg.h>
#include <sys/resource.h>
#include <sys/select.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/statvfs.h>
#include <sys/time.h>
#include <sys/timeb.h>
#include <sys/times.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <sys/un.h>
#include <sys/utsname.h>
#include <sys/wait.h>
#include <syslog.h>
#include <tar.h>
#include <termios.h>
#include <ulimit.h>
#include <unistd.h>
#include <utime.h>

// C
#ifndef _GLIBCXX_NO_ASSERT

#include <cassert>

#endif

#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cwchar>
#include <cwctype>

#if __cplusplus >= 201103L

#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>

#endif

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L

#include <array>
#include <atomic>
#include <chrono>
#include <codecvt>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <type_traits>
#include <typeindex>
#include <unordered_map>
#include <unordered_set>

#endif

#if __cplusplus >= 201402L

#include <shared_mutex>

#endif

#if __cplusplus >= 201703L

#include <any>
#include <charconv>
// #include <execution>
#include <filesystem>
#include <optional>
#include <string_view>
#include <variant>

#endif

#if __cplusplus > 201703L

#include <barrier>
#include <bit>
#include <compare>
#include <concepts>

#if __cpp_impl_coroutine
#include <coroutine>
#endif

#include <latch>
#include <numbers>
#include <ranges>
#include <semaphore>
#include <span>
#include <version>

#endif

using namespace std;
using namespace filesystem;
using namespace chrono;

// enum class的输出运算符重载
template<typename T>
ostream &operator<<(typename enable_if<is_enum<T>::value, ostream>::type &os, const T &e) {
    return os << static_cast<typename underlying_type<T>::type>(e);
}

template<typename T>
ostream &operator<<(ostream &os, const vector<T> &arr) {
    const int n{static_cast<int>(arr.size()) - 1};
    os << '{';
    for (int i = 0; i < n; ++i) {
        os << arr[i] << ", ";
    }
    os << arr[n] << '}';
    return os;
}

template<typename T, typename U>
ostream &operator<<(ostream &os, const unordered_map<T, U> &m) {
    os << '{';
    for (const auto &[key, val]: m) {
        os << "[" << key << " = " << val << "]";
    }
    os << '}';
    return os;
}

template<typename...Types>
void fmt_Println(const Types &...args) {
    initializer_list<int>{([&args] { cout << args << ' '; }(), 0)...};
    cout << '\n';
}

template<typename T, typename... Types>
static constexpr inline void t(const T &firstArg,
                               const Types &... args) noexcept {
    cout << ">>>>>test: " << firstArg << '\n';
    if constexpr (sizeof...(args) > 0) {
        t(args...);
    }
}

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right)
            : val(x), left(left), right(right) {}
};

struct ListNode {
    int val{0};
    ListNode *next{nullptr};

    explicit ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//按照传入的分割符dim来分割字符串
vector<string> splitString(const string &s, char dim) {
    vector<string> res;
    istringstream is(s);
    string temp;
    for (; getline(is, temp, dim);) {
        res.emplace_back(move(temp));
    }
    return res;
}

//默认按照空格来分割字符串
vector<string> splitString(const string &s) {
    vector<string> res;
    stringstream ss(s);
    string temp;
    for (; ss >> temp;) {
        res.emplace_back(move(temp));
    }
    return res;
}

class Timer {
public:
    Timer() : m_begin(high_resolution_clock::now()) {}

    // 重置计时器时间
    void reset() { m_begin = high_resolution_clock::now(); }

    // 输出毫秒(ms)
    int64_t elapsed_milli() const {
        return duration_cast<chrono::milliseconds>(
                high_resolution_clock::now() - m_begin)
                .count();
    }

    // 输出秒(s)
    double elapsed_second() const {
        return duration_cast<duration<double>>(high_resolution_clock::now() -
                                               m_begin)
                .count();
    }

    // 输出微秒(μs)
    int64_t elapsed_micro() const {
        return duration_cast<chrono::microseconds>(
                high_resolution_clock::now() - m_begin)
                .count();
    }

    // 输出纳秒(ns)
    int64_t elapsed_nano() const {  // 纳秒
        return duration_cast<chrono::nanoseconds>(high_resolution_clock::now() -
                                                  m_begin)
                .count();
    }

    // 输出分钟(m)
    int64_t elapsed_minutes() const {  // 分钟
        return duration_cast<chrono::minutes>(high_resolution_clock::now() -
                                              m_begin)
                .count();
    }

    // 输出小时(h)
    int64_t elapsed_hours() const {  // 小时
        return duration_cast<chrono::hours>(high_resolution_clock::now() -
                                            m_begin)
                .count();
    }

private:
    time_point<high_resolution_clock> m_begin;
};

#endif