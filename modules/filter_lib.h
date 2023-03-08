#pragma once

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using ip = std::vector<std::string>;
using pool_ip = std::vector<ip>;
using size_ip = pool_ip::size_type;

/*//split
// ("",  '.') -> [""]
// ("11", '.') -> ["11"]
// ("..", '.') -> ["", "", ""]
// ("11.", '.') -> ["11", ""]
// (".11", '.') -> ["", "11"]
// ("11.22", '.') -> ["11", "22"]*/
ip split(const std::string &str, char d);
void print_pool(pool_ip::const_iterator b, pool_ip::const_iterator e);
void radixSort(pool_ip &pool);
void filter(const pool_ip &pool, unsigned first, unsigned second = 256);
void filter_any(const pool_ip &pool, int any);