#include "unique_ptr_test.h"

unique_ptr_test::unique_ptr_test(int Id)
{
    Id_ = Id;
}

unique_ptr_test::~unique_ptr_test()
{
    std::cout << "Unique Pointer Destructor" << std::endl;
}