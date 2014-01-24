#include <memory> 
#include "impl.h"

int main(int argc, char *argv[])
{
	using namespace impl;
	std::unique_ptr< client_type > c( make_client() );
	request_type req;
	response_type res( c->post( req ) ); 
}