#ifndef CLIENT_H__4T9H5bEG0FmMWYhlauDv1Ow7KpyQLn
#define CLIENT_H__4T9H5bEG0FmMWYhlauDv1Ow7KpyQLn

namespace om636
{
	namespace http
	{
		template<class T, template<class> class U> 
		struct client
		: private U< client< T, U > > 
		{
			typedef U< client< T, U > > traits_type;
			using typename traits_type::response_type;
			using typename traits_type::request_type;

			virtual ~client();
			virtual response_type get(request_type) = 0;
			virtual response_type post(request_type) = 0;
			virtual response_type put(request_type) = 0;
			virtual response_type del(request_type) = 0;
		};
	}
}	// om636

#include "client.hxx"
#endif // CLIENT_H__4T9H5bEG0FmMWYhlauDv1Ow7KpyQLn