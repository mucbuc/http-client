#include <iostream>
#include <string>

#include <http-client/src/request.h>
#include <http-client/src/response.h>
#include <http-client/src/client.h>
#include <http-client/src/clients/mac.h>

template<class>
struct test_traits
{
	typedef std::string string_type;
};

template<class>
struct client_traits
{
	typedef om636::http::BasicRequest< test_traits > request_type;
	typedef om636::http::BasicResponse< test_traits > response_type;
};

typedef om636::http::Client< void, client_traits > client_type; 

client_type * make_client() 
{
	return new om636::http::mac_client< void, client_traits >(); 
}

int main(int argc, char *argv[])
{
	using namespace std; 
	using namespace om636;
		
	client_type * c( make_client() );

	typedef typename client_type::request_type request_type;
	typedef typename client_type::response_type response_type;
	request_type req;
	response_type res( c->post( req ) ); 
}