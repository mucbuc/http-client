#ifndef REQUEST_H__HDlqeOcnvPMXGW7bkmJ0wxFoQAS5Ly
#define REQUEST_H__HDlqeOcnvPMXGW7bkmJ0wxFoQAS5Ly

namespace om636
{
	namespace http
	{
		template<> 
		struct Request
		{
			typedef .. string_type; 
			virtual ~Request(); 
			virtual string_type & url() = 0;
			virtual string_type url() const = 0; 
			virtual string_type & header() = 0;
			virtual string_type header() const = 0; 
			virtual string_type & content() = 0;
			virtual string_type content() const = 0; 
		};

	}	// http
}	// 	om636

#include "request.hxx"
#endif // REQUEST_H__HDlqeOcnvPMXGW7bkmJ0wxFoQAS5Ly