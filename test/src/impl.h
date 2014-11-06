
#ifndef IMPL_INCLUDE_GUARD
#define IMPL_INCLUDE_GUARD

#include <string>

#include <lib/http-client/src/client.h>
#include <lib/http-client/src/request.h>
#include <lib/http-client/src/response.h>
#include <lib/http-client/src/clients/mac.h>

namespace impl
{
    static size_t passed(0);
    
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
        typedef std::function<void(response_type)> function_type;
    };

	typedef om636::http::Client< void, client_traits > client_type; 

	client_type * make_client() 
	{
		return new om636::http::mac_client< void, client_traits >(); 
	}

	template<class T>
	void test_get(T & c, const char * url )
	{
	    using namespace impl;
	    request_type req;
	    req.url() = url;
	    c->get( req, [&](response_type r){
	        if (r.data() == "GET:")
            {
	            ++passed;
                std::cout << "http_client::get passed" << std::endl;
            }
        } );
	}

	template<class T>
	void test_post(T & c, const char * url )
	{
	    using namespace impl;
	    request_type req;
	    req.url() = url;
	    req.method() = "POST";
	    req.content() = "hello";
	    c->request( req, [&](response_type r){
	        if (r.data() == "POST:hello")
            {
	            ++passed;
                std::cout << "http_client::post passed" << std::endl;
            }
        } );
	}

	template<class T>
	void test_put(T & c, const char * url )
	{
	    using namespace impl;
	    request_type req;
	    req.url() = url;
	    req.method() = "PUT";
	    req.content() = "hello";
	    c->request( req, [&](response_type r){
	        if (r.data() == "PUT:hello")
            {
	            ++passed;
                std::cout << "http_client::put passed" << std::endl;
            }
        } );
	}

	template<class T>
	void test_delete(T & c, const char * url )
	{
	    using namespace impl;
	    request_type req;
	    req.url() = url;
	    req.method() = "DELETE";
	    req.content() = "hello";
	    c->request( req, [&](response_type r){
	        if (r.data() == "DELETE:hello")
            {
	            ++passed;
                std::cout << "http_client::delete passed" << std::endl;
            }
        } );
	}

	void run_test(const char * arg)
	{
	    using namespace std;
	    using namespace impl;
	    
	    // setup test
	    unique_ptr< client_type > c( make_client() );
		request_type req;
	    req.url() = arg;
	    
	    test_get( c, arg );
	    test_post( c, arg  );
	    test_put( c, arg  );
	    test_delete( c, arg  );
	    
	    // 
	    sleep( 3 );
        ASSERT( passed >= 4 );
        
        std::cout << "http-client test" << " passed" << std::endl;
    }
}

#endif