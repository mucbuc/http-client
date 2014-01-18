#ifndef HOST_H__uamc8N3wBOdUbFZ6vsHiyLhe1QYJlG
#define HOST_H__uamc8N3wBOdUbFZ6vsHiyLhe1QYJlG

namespace om636
{
	struct policy
	{
		template<typename T, typename U, typename V> 
		static T get(U &, V);

		template<typename T, typename U, typename V> 
		static T post(U &, V);

		template<typename T, typename U, typename V> 
		static T put(U &, V);

		template<typename T, typename U, typename V> 
		static T del(U &, V);
	};

	struct owner
	{
		template<typename T> 
		static T * create();

		template<typename T> 
		static void destroy(T &);
	};

	namespace http
	{
		template<template<class> class T, class U, class V>
		struct Host
		: private< T< Host< T, U, V > > 
		, public Client< T > 
		{	
			typedef T< Host > traits_type;
			typedef Client< T > base_type;
			typedef U impl_policy; 
			typedef V owner_policy; 
			using typename traits_type::request_type;
			using typename traits_type::response_type;

			Host();
			virtual ~Host();
			virtual response_type get(request_type);
			virtual response_type post(request_type);
			virtual response_type put(request_type);
			virtual response_type del(request_type);

		private:
			using typename traits_type::impl_type;
			impl_type m_impl;
		};
	}
}

#include "host.hxx"
#endif // HOST_H__uamc8N3wBOdUbFZ6vsHiyLhe1QYJlG