/**
 * This program I shortly wrote to check the how we can access raw data from the file
 * just with the pointer to the any element. For example if we have uint32_t pointer
 * to rob marker (so its a pointer to the rob fragment), only with this pointer we
 * can read the whole fragment using ptr[element]
 */

#include <iostream>
class data{
public:
    uint32_t A = 2;
    uint32_t B = 3;
    uint32_t C = 4;
};
int main() {
    data* dataobj = new data();
    uint32_t *ptr = (uint32_t*)(dataobj);
    // one way of doing that
    std::cout<<"first way of doing this first value: "<<ptr[0]<<std::endl;
    std::cout<<"first way of doing this second value: "<<ptr[1]<<std::endl;
    std::cout<<"first way of doing this third value: "<<ptr[2]<<std::endl;
    // other way of doing that
    std::cout<<"other way of doing first value: "<<*(ptr + 0)<<std::endl;
    std::cout<<"other way of doing second value: "<<*(ptr + 1)<<std::endl;
    std::cout<<"other way of doing third value: "<<*(ptr + 2)<<std::endl;

    return 0;
}
