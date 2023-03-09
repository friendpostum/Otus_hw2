#include "filter_lib.h"

int main() {

    try {
      pool_ip ip_pool;

        for(std::string line; std::getline(std::cin, line);) {
            auto v = split(line);
            ip_pool.push_back(v);
        }

        radixSort(ip_pool);

        print_pool(ip_pool.begin(), ip_pool.end());

        filter(ip_pool, 1);

        filter(ip_pool, 46, 70);

        filter_any(ip_pool, 46);

    }
    catch(const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
