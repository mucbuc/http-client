//
//  main.cpp
//  http-client
//
//  Created by mucbuc on 1/24/14.
//  Copyright (c) 2014 markymark. All rights reserved.
//


#include "impl.h"

int main(int argc, const char * argv[])
{
//    NSURLRequest
    using namespace impl;
	std::unique_ptr< client_type > c( make_client() );
	request_type req;
	response_type res( c->post( req ) );
   
    return 0;
}

