namespace om636
{	
	namespace http
	{	
		template<template<class> class T, class U, class V>
		host<T, U, V>::host()
		: base_type()
		, m_impl( owner_policy::create<impl_type>() )
		{}

		template<template<class> class T, class U, class V>
		host<T, U, V>::~host()
		{
			owner_policy::destroy<impl_type>(m_impl)
		}

		template<template<class> class T, class U, class V>
		auto host<T, U, V>::get(request_type req) -> response_type
		{
			return response_type( policy_type::get(m_impl, req) );
		}
		
		template<template<class> class T, class U, class V>
		auto host<T, U, V>::post(request_type req) -> response_type
		{
			return response_type( policy_type::post(m_impl, req) );
		}
		
		template<template<class> class T, class U, class V>
		auto host<T, U, V>::put(request_type req) -> response_type
		{
			return response_type( policy_type::put(m_impl, req) );
		}
		
		template<template<class> class T, class U, class V>
		auto host<T, U, V>::del(request_type req) -> response_type
		{
			return response_type( policy_type::del(m_impl, req) );
		}
	}
}	// om636