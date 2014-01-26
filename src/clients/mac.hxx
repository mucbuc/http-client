
namespace om636
{
	namespace http
	{
		template<class T, template<class> class U>
		mac_client< T, U >::mac_client()
		: base_type()
		{}

		template<class T, template<class> class U>
		void mac_client< T, U >::get(request_type, function_type done)
		{
            NSURL * url = [ NSURL URLWithString:@"www.google.com" ];
			NSMutableURLRequest * req = [ NSMutableURLRequest requestWithURL:url ];
            [ req setHTTPMethod:@"GET" ];
            
            [ NSURLConnection sendAsynchronousRequest:req queue:[[NSOperationQueue alloc] init ] completionHandler:^(NSURLResponse *response, NSData *data, NSError *error){
                done( response_type() );
             } ];
		}
		
		template<class T, template<class> class U>
		void mac_client< T, U >::request(request_type r, function_type done)
		{
            NSURL * url = [ NSURL URLWithString:@"www.google.com" ];
			NSMutableURLRequest * req = [ NSMutableURLRequest requestWithURL:url ];
            //[ req setHTTPMethod:@"GET" ];
            
            [ NSURLConnection sendAsynchronousRequest:req queue:[[NSOperationQueue alloc] init ] completionHandler:^(NSURLResponse *response, NSData *data, NSError *error) {
                NSLog( @"got reply" );
                done( response_type() );
            }];
		}

	}	//http
}	// om636
