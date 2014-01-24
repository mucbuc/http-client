#ifndef MAC_H__Sq8JUEtgWjyMmwOAdQTfRleD5v6Zpi
#define MAC_H__Sq8JUEtgWjyMmwOAdQTfRleD5v6Zpi

#import <Foundation/Foundation.h>
#include <iostream>
#include <http-client/src/client.h>

namespace om636
{
	namespace http
	{
		template<class T, template<class> class U>
		struct mac_client 
		: Client< T, U > 
		{	
			typedef Client< T, U > base_type; 
			using typename base_type::request_type; 
			using typename base_type::response_type;

			mac_client(); 
			virtual ~mac_client() = default;
			virtual response_type get(request_type);
			virtual response_type post(request_type);
			virtual response_type put(request_type);
			virtual response_type del(request_type);
		};
	}
}

#include "mac.hxx"
#endif // MAC_H__Sq8JUEtgWjyMmwOAdQTfRleD5v6Zpi