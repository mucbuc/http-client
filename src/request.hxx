namespace om636
{
	namespace http
	{
		template<template<class> class T> 
		Request<T>::~Request()
		{}

		template<template<class> class T> 
		BasicRequest<T>::BasicRequest()
		: traits_type()
		, base_type()
		, m_url()
		, m_header()
		, m_content()
        , m_method()
		{}
		
		template<template<class> class T> 
		BasicRequest<T>::~BasicRequest()
		{}

		template<template<class> class T> 
		auto BasicRequest<T>::url() -> string_type & 
		{
			return m_url;
		}
		
		template<template<class> class T> 
		auto BasicRequest<T>::url() const -> string_type
		{
			return m_url;
		}
		
		template<template<class> class T> 
		auto BasicRequest<T>::header() -> string_type & 
		{
			return m_header;
		}
		
		template<template<class> class T> 
		auto BasicRequest<T>::header() const -> string_type
		{
			return m_header;
		} 
		
		template<template<class> class T> 
		auto BasicRequest<T>::content() -> string_type & 
		{
			return m_content;
		}			

		template<template<class> class T> 
		auto BasicRequest<T>::content() const -> string_type 
		{
			return m_content;
		}
        
        template<template<class> class T>
		auto BasicRequest<T>::method() -> string_type &
        {
            return m_method;
        }
        
        template<template<class> class T>
		auto BasicRequest<T>::method() const -> string_type
        {
            return m_method;
        }
        
	}	// http
}	// 	om636