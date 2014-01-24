
namespace om636
{
	namespace http
	{
		template<class T, template<class> class U>
		mac_client< T, U >::mac_client()
		: base_type()
		{}

		template<class T, template<class> class U>
		auto mac_client< T, U >::get(request_type) -> response_type
		{
			return response_type();
		}
		
		template<class T, template<class> class U>
		auto mac_client< T, U >::post(request_type) -> response_type
		{
            NSURL * url = [ NSURL URLWithString:@"www.google.com" ];
			NSURLRequest * req = [ NSURLRequest requestWithURL:url ];
            NSURLConnection * con = [[NSURLConnection alloc] initWithRequest:req delegate:nil startImmediately:NO];
            
			return response_type();
		}

		template<class T, template<class> class U>
		auto mac_client< T, U >::put(request_type) -> response_type
		{
			return response_type();
		}

		template<class T, template<class> class U>
		auto mac_client< T, U >::del(request_type) -> response_type
		{
			return response_type();
		}
	}	//http
}	// om636
