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
//    NSURLRequest
    using namespace impl;
	std::unique_ptr< client_type > c( make_client() );
	request_type req;
    bool passed(0);
    req.url() = "http://localhost:3000";
    c->get( req, [&](response_type r){
        passed = 1;
    } );
    sleep( 100 );
    assert( passed );
    return 0;
}

