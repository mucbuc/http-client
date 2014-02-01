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
    using namespace impl;
	std::unique_ptr< client_type > c( make_client() );
	request_type req;
    size_t passed(0);
    req.url() = "http://localhost:3000";
    c->get( req, [&](response_type r){
        if (r.data() == "ok")
            ++passed;
    } );
    c->request( req, [&](response_type r){
        if (r.data() == "ok")
            ++passed;
    } );
    
    sleep( 3 );
    assert( passed >= 2 );
    return 0;
}

