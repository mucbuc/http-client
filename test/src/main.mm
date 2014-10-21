#include "test.h"

#include "impl.h"



int main(int argc, const char * argv[])
{
    if (argc < 2)
    {
        std::cout << "error: expected test server url" << std::endl;
        return 1;
    }
    else 
    	impl::run_test( argv[1] );
    return 0;
}