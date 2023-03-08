#include "filter_lib.h"
#include <fstream>

#define UNUSED(variable) (void)variable

int main(int argc, char const *argv[]) {
    UNUSED(argc);
    UNUSED(argv);

    try {
        pool_ip ip_pool;
        for(std::string line; std::getline(std::cin, line);) {
            auto v = split(line, '\t');
            ip_pool.push_back(split(v.at(0), '.'));
        }
       /* std::ifstream in("ip_filter.tsv");
        if(in.is_open()) {
            for(std::string line; std::getline(in, line);) {
                auto v = split(line, '\t');
                ip_pool.push_back(split(v.at(0), '.'));
            }
        } else{std::cout << "File open error";}
        in.close();
        */
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
