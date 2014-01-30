namespace om636
{
	namespace http
	{
 		template<template<class> class T> 
		Response<T>::~Response()
		{}
		
		template<template<class> class T>
		BasicResponse<T>::BasicResponse(const string_type & d)
		: traits_type()
		, base_type()
        , m_data( d )
		{}

		template<template<class> class T>
		BasicResponse<T>::~BasicResponse()
		{}
		
		template<template<class> class T>
		void BasicResponse<T>::onData(string_type)
		{}
		
		template<template<class> class T>
		void BasicResponse<T>::onError(string_type)
		{}
        
        template<template<class> class T>
        auto BasicResponse<T>::data() -> string_type &
        {
            return m_data;
        }
        
        template<template<class> class T>
        auto BasicResponse<T>::data() const -> const string_type &
        {
            return m_data;
        }
        
	}	// http
}	// 	om636