
namespace om636
{
	namespace http
	{
		template<class T, template<class> class U>
		mac_client< T, U >::mac_client()
		: base_type()
		{}

		template<class T, template<class> class U>
		void mac_client< T, U >::get(request_type r, function_type done)
		{
            NSURL * url = [ NSURL URLWithString:[ NSString stringWithCString:r.url().c_str() encoding:NSUTF8StringEncoding ] ];
			NSMutableURLRequest * req = [ NSMutableURLRequest requestWithURL:url ];
            [ req setHTTPMethod:@"GET" ];
            
            [ NSURLConnection sendAsynchronousRequest:req queue:[[NSOperationQueue alloc] init ] completionHandler:^(NSURLResponse *response, NSData *data, NSError *error){
                //NSString * result = [ [ NSString alloc ] initWithData:data encoding:NSUTF8StringEncoding ];
                done( response_type() );
             } ];
		}
		
		template<class T, template<class> class U>
		void mac_client< T, U >::request(request_type r, function_type done)
		{
            NSURL * url = [ NSURL URLWithString:[ NSString stringWithCString:r.url().c_str() encoding:NSUTF8StringEncoding ] ];
			NSMutableURLRequest * req = [ NSMutableURLRequest requestWithURL:url ];
            
            [ NSURLConnection sendAsynchronousRequest:req queue:[[NSOperationQueue alloc] init ] completionHandler:^(NSURLResponse *response, NSData *data, NSError *error) {
                 done( response_type() );
            }];
		}

	}	//http
}	// om636
