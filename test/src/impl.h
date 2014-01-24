
#include <string>

#include <http-client/src/client.h>
#include <http-client/src/request.h>
#include <http-client/src/response.h>
#include <http-client/src/clients/mac.h>

namespace impl
{
	template<class>
	struct test_traits
	{
		typedef std::string string_type;
	};

	typedef om636::http::BasicRequest< test_traits > request_type;
	typedef om636::http::BasicResponse< test_traits > response_type;

	template<class>
	struct client_traits
	{
		typedef request_type request_type;
		typedef response_type response_type;
	};

	typedef om636::http::Client< void, client_traits > client_type; 

	client_type * make_client() 
	{
		return new om636::http::mac_client< void, client_traits >(); 
	}
}