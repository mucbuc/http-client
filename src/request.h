#ifndef REQUEST_H__HDlqeOcnvPMXGW7bkmJ0wxFoQAS5Ly
#define REQUEST_H__HDlqeOcnvPMXGW7bkmJ0wxFoQAS5Ly

	struct traits
	{
		typedef std::string string_type; 
	}; 


namespace om636
{
	namespace http
	{
		template<template<class> class T> 
		struct Request
		: private T< Request< T > >  
		{
			typedef T< Request< T > > traits_type;
			using typename traits_type::string_type; 
			
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