#ifndef MAC_H__Sq8JUEtgWjyMmwOAdQTfRleD5v6Zpi
#define MAC_H__Sq8JUEtgWjyMmwOAdQTfRleD5v6Zpi

#import <Foundation/Foundation.h>

#include <iostream>
#include <lib/http-client/src/client.h>

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
			using typename base_type::function_type;

			mac_client(); 
			virtual ~mac_client() = default;
			virtual void get(request_type, function_type);
			virtual void request(request_type, function_type);
        private:
            static void request(NSMutableURLRequest *, function_type);
		};
	}
}

#include "mac.hxx"
#endif // MAC_H__Sq8JUEtgWjyMmwOAdQTfRleD5v6Zpi