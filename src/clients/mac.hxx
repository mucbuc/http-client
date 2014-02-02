
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
            request( req, done );
        }
		
		template<class T, template<class> class U>
		void mac_client< T, U >::request(request_type r, function_type done)
		{
            NSURL * url = [ NSURL URLWithString:[ NSString stringWithCString:r.url().c_str() encoding:NSUTF8StringEncoding ] ];
			NSMutableURLRequest * req = [ NSMutableURLRequest requestWithURL:url ];
            
            if (r.method() == "POST")
                [ req setHTTPMethod:@"POST" ];
            else if (r.method() == "PUT")
                [ req setHTTPMethod:@"PUT" ];
            else if (r.method() == "DELETE")
                [ req setHTTPMethod:@"DELETE" ];
            
            if (!r.content().empty())
                [ req setHTTPBody:[ NSData dataWithBytes:r.content().c_str() length:r.content().size() ] ];
            
            request( req, done );
        }
        
        template<class T, template<class> class U>
		void mac_client< T, U >::request(NSMutableURLRequest * req, function_type done)
        {
            [ NSURLConnection sendAsynchronousRequest:req queue:[[NSOperationQueue alloc] init ] completionHandler:^(NSURLResponse *response, NSData *data, NSError *error){
             NSString * result = [ [ NSString alloc ] initWithData:data encoding:NSUTF8StringEncoding ];
             done( response_type( [ result UTF8String ] ) );
             } ];
        }

	}	//http
}	// om636
