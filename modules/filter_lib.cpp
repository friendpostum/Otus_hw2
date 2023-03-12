#include "filter_lib.h"

ip split(const std::string &str) {
    ip r;
    std::string::size_type start = 0, stop = str.find_first_of('.');;
    int i = 0;
    while (stop != std::string::npos) {
        r[i++] = std::stoi(str.substr(start, stop - start));
        start = stop + 1;
        stop = str.find_first_of('.', start);
    }
    r[i] = std::stoi(str.substr(start));
    return r;
}

void radixSort(pool_ip &pool) {
    /*for (int i = 3; i >= 0; --i) {
        std::stable_sort(pool.begin(), pool.end(), [i](ip a, ip b) {
          return a[i] > b[i];
        });
    }*/
    std::sort(pool.rbegin(), pool.rend());
}

void print_pool(pool_ip::const_iterator b, pool_ip::const_iterator e) {
    std::for_each(b, e, [](const auto &ip) {
      std::cout << ip[0] << "." << ip[1] << "." << ip[2] << "." << ip[3] << '\n';
    });
}

void filter(const pool_ip &pool, unsigned first, unsigned second) {
    struct Comp {
      int d;
      bool operator()(const ip &ip, int i) const { return ip[d] > i; }
      bool operator()(int i, const ip &ip) const { return i > ip[d]; }
    };

    auto p = std::equal_range(pool.begin(), pool.end(), first, Comp{0});
    if (second < 256)
      p = std::equal_range(p.first, p.second, second, Comp{1});

    print_pool(p.first, p.second);
}

void filter_any(const pool_ip &pool, int any) {
    for (const auto &ip: pool) {
      /* if (any == ip[0] ||
             any == ip[1] ||
             any == ip[2] ||
             any == ip[3])*/
      if (std::find(ip.begin(), ip.end(), any) != ip.end())
          std::cout << ip[0] << "." << ip[1] << "." << ip[2] << "." << ip[3]
                    << '\n';
    }
}