#include <iostream>
#include <unordered_set>

int main() {
    std::unordered_set<unsigned int> set;
    set.insert(1);
    set.insert(1);
    set.insert(1);
    set.insert(2);
    set.insert(2);
    std::cout<<set.insert(3).second<<std::endl;
    // what's the use of .second -> if the insert was successful the whole thing will return 1,
    // if we insert same value again then the insert is not successful and it returns 0
    // count total number of insert
    std::cout<<set.count(2)<<std::endl;
    return 0;
}
