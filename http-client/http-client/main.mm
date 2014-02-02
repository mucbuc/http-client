//
//  main.cpp
//  http-client
//
//  Created by mucbuc on 1/24/14.
//  Copyright (c) 2014 markymark. All rights reserved.
//
#include <cassert>
#include "impl.h"

size_t passed(0);

template<class T>
void test_get(T & c, const char * url )
{
    using namespace impl;
    request_type req;
    req.url() = url;
    c->get( req, [&](response_type r){
        if (r.data() == "GET:")
            ++passed;
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
            ++passed;
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
            ++passed;
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
            ++passed;
    } );
}

int main(int argc, const char * argv[])
{
    using namespace std;
    using namespace impl;
    
    if (argc < 2)
    {
        cout << "error: expected test server url" << endl;
        return 1;
    }
    
    // setup test
    unique_ptr< client_type > c( make_client() );
	request_type req;
    req.url() = argv[1];
    
    test_get( c, argv[1] );
    test_post( c, argv[1] );
    test_put( c, argv[1] );
    test_delete( c, argv[1] );
    
    // 
    sleep( 3 );
    assert( passed >= 4 );
    return 0;
}

