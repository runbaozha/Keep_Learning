#include <string>
#include <iostream>

void* operator new(size_t size)
{
    std::cout << "Memory Allocation: " << size << "Bytes.\n";
    return malloc(size);
}

int main()
{
    std::string fullName = "MaxMaxMaxMaxMax FangFangFangFang";
    std::string firstName = fullName.substr(0,16);
    std::string lastName = fullName.substr(16,16);

    std::cout << " [fullName] " << fullName << std::endl;
    std::cout << " [firstName] " << firstName << std::endl;
    std::cout <<  " [lastName] " << lastName << std::endl;
    std::cin.get();
}
