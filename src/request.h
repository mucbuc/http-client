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
			typedef T< Request > traits_type;
			using typename traits_type::string_type; 
			
			virtual ~Request(); 
			virtual string_type & url() = 0;
			virtual string_type url() const = 0; 
			virtual string_type & header() = 0;
			virtual string_type header() const = 0; 
			virtual string_type & content() = 0;
			virtual string_type content() const = 0;
            virtual string_type & method() = 0;
            virtual string_type method() const = 0;
		};

		template<template<class> class T> 
		struct BasicRequest
		: private T< BasicRequest< T > >
		, public Request< T >
		{
			typedef T< BasicRequest > traits_type;
			typedef Request< T > base_type; 
			using typename traits_type::string_type; 

			BasicRequest(); 
			virtual ~BasicRequest(); 
			virtual string_type & url();
			virtual string_type url() const; 
			virtual string_type & header();
			virtual string_type header() const; 
			virtual string_type & content();
			virtual string_type content() const;
            virtual string_type & method();
            virtual string_type method() const;
            
		private:
			string_type m_url;
			string_type m_header;
			string_type m_content;
            string_type m_method;
		};

	}	// http
}	// 	om636

#include "request.hxx"
#endif // REQUEST_H__HDlqeOcnvPMXGW7bkmJ0wxFoQAS5Ly