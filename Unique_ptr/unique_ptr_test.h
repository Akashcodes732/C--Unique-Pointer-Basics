#pragma once
#include <memory>
#include <iostream>

class unique_ptr_test
{
private:
    int Id_;
public:
    unique_ptr_test(int id);
    ~unique_ptr_test();
    const int getId() const {return Id_;}
};



