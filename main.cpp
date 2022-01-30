#include "unique_ptr_test.h"

int main(){

    /*
    // Three possible ways to doing the initialization
    //
    // 1. std::unique_ptr<unique_ptr_test> TestPtr(new unique_ptr_test(23));
    // 2. std::unique_ptr<unique_ptr_test> TestPtr{std::make_unique<unique_ptr_test>(23)};
    // 3. auto TestPtr{std::make_unique<unique_ptr_test>(23)};
    // NOTE: 3 is the best practice
    */
    auto TestPtr{std::make_unique<unique_ptr_test>(23)};
    
    /*
    We cannot do 
    std::unique_ptr<unique_ptr_test> TestPtr = new unique_ptr_test(23)
    It will give compile error
    */

    if(TestPtr != nullptr){
        std::cout << "Test pointer is not empty" << std::endl;
    }

    //Accessing the values
    std::cout << "Mid: " <<  TestPtr->getId() << std::endl;

    //Empty the pointer using reset
    TestPtr.reset();

    if(TestPtr == nullptr ){
        std::cout << "Test Pointer is empty" << std::endl;
    }
    
    std::cout << "Creating test pointer two" << std::endl;

    auto TestPtr2(std::make_unique<unique_ptr_test>(55));
    std::cout << "Mid: " <<  TestPtr2->getId() << std::endl;
    //Reallocation using move semantics
    {
        //Note the usage of std::move
        //This is done to tranfer the ownership as the unique pointer cannot be copied
        //it can only be moved
        std::unique_ptr<unique_ptr_test> TestPtr3 = std::move(TestPtr2);
        std::cout << "Created Test ptr 3 and moved the ownership of TestPtr2" << std::endl;
        std::cout << "Printing from Testptr3:ID = " <<  TestPtr3->getId() << std::endl;
    }

    //Contents of TestPtr2 are moved
    //Thus it should be a nullptr and it should be empty
    if(TestPtr2){
        std::cout << "Testptr2 is filled" << std::endl;
    }
    else{
        //This should get printed
        std::cout << "Testptr2 is empty" << std::endl;
    }

    return 0;
}


/*
https://thispointer.com/c11-unique_ptr-tutorial-and-examples/
https://stackoverflow.com/questions/24609271/errormake-unique-is-not-a-member-of-std
https://www.learncpp.com/cpp-tutorial/stdunique_ptr/
*/