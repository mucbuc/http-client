#include <iostream>
#include <string>

#include <http-client/src/request.h>
#include <http-client/src/client.h>

template<class>
struct test_traits
{
	typedef std::string string_type; 
};

int main(int argc, char *argv[])
{
	using namespace std; 
	using namespace om636; 
	http::BasicRequest< test_traits > r;
	http::Client< void, test_traits > * c;
}