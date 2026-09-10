#ifndef TEST_DBG
#define TEST_DBG

#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>


std::string MSG_ARRAY[] = {
    "std::cerr_start: ",
    "test: "
};
std::string MSG = MSG_ARRAY[1];

template <typename... Args> void p_(const Args&... args) {
    std::cerr << MSG;
    ((std::cerr << args << ' '), ...);
}

template <typename... Args> void pl_(const Args&... args) {
    std::cerr << MSG;
    ((std::cerr << args << ' '), ...) << '\n';
}

template <typename T, typename U> void pl_(const std::pair<T, U> t) {
    std::cerr << MSG;
    std::cerr << "{"<< t.first << ", " << t.second << "}\n";
}

template <typename T> void pl_(const std::vector<T>& t) {
    std::cerr << MSG;
    for (const auto& x : t) {
        std::cerr << t << ' ';
    }
    std::cerr << '\n';
}

template <typename T, typename U> void pl_(const std::map<T, U>& t) {
    std::cerr << MSG;
    for (const auto& [first, second] : t) {
        std::cerr << '{' << first << ", " << second << "} ";
    }
    std::cerr << '\n';
}

#endif // TEST_DBG