/** Proof of concept that we have C++20 modules
 * bit of a pain to build on GCC-12 need to build gcm.cache once via
 * g++ -std=c++20 -fmodules-ts -x c++-system-header array iostream map string vector
 *
 * VSCode will say everything is errors because of using clang-tidy to check which
 * can't deal with GCC precompiled headers for modules
 */

import <iostream>;
import <array>;
import <map>;
import <vector>;

int main()
{
    std::cout << "C++20 Modules\n";

    std::cout << "Array:\n\t";
    std::array<int, 3> arr{1, 2, 3};
    for (auto &&x: arr) {
        std::cout << x << ", ";
    }
    std::cout << "\n";

    std::cout << "Vector:\n\t";
    std::vector<int> vec{1, 2, 3};
    for (auto &&x: vec) {
        std::cout << x << ", ";
    }
    std::cout << "\n";

    std::cout << "Map:\n\t";
    std::map<int, int> map{{1, 10}, {2, 20}, {3, 30}};
    for (auto &&x: map) {
        std::cout << x.first << " = " << x.second << ", ";
    }
    std::cout << "\n";
    return 0;
}
