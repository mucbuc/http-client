//
//  main.cpp
//  http-client
//
//  Created by mucbuc on 1/24/14.
//  Copyright (c) 2014 markymark. All rights reserved.
//
#include <cassert>

#include "impl.h"

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
    size_t passed(0);
    req.url() = argv[1];
    
    // test get
    c->get( req, [&](response_type r){
        if (r.data() == "GET:")
            ++passed;
        cout << r.data() << endl;
    } );
    
    // test post
    req.method() = "POST";
    req.content() = "hello";
    c->request( req, [&](response_type r){
        if (r.data() == "POST:hello")
            ++passed;
        cout << r.data() << endl;
    } );
    
    // 
    sleep( 3 );
    assert( passed >= 2 );
    return 0;
}

