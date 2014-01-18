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

	struct traits
	{
		typedef string_type; 
	}; 

	namespace http
	{
		template<>
		struct host
		{	
			typedef base_type;
			using typename base_type::request_type;
			using typename base_type::response_type;

			host();
			virtual ~host();
			virtual response_type get(request_type);
			virtual response_type post(request_type);
			virtual response_type put(request_type);
			virtual response_type del(request_type);

		private:
			using typename base_type::impl_type;
			impl_type m_impl;
		};
	}
}

#include "host.hxx"
#endif // HOST_H__uamc8N3wBOdUbFZ6vsHiyLhe1QYJlG