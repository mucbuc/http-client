#ifndef CLIENT_H__4T9H5bEG0FmMWYhlauDv1Ow7KpyQLn
#define CLIENT_H__4T9H5bEG0FmMWYhlauDv1Ow7KpyQLn

namespace om636
{
	namespace http
	{
		template<class T, template<class> class U> 
		struct Client
		: private U< Client< T, U > > 
		{
			typedef U< Client< T, U > > traits_type;
			using typename traits_type::request_type;
            using typename traits_type::response_type;
            using typename traits_type::function_type;
			
			virtual ~Client() = default;
			virtual void get(request_type, function_type) = 0;
			virtual void request(request_type, function_type) = 0;
		};
	}
}	// om636

#include "client.hxx"
#endif // CLIENT_H__4T9H5bEG0FmMWYhlauDv1Ow7KpyQLn