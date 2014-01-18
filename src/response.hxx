namespace om636
{
	namespace http
	{
 		template<template<class> class T> 
		Response<T>::~Response()
		{}
		
		template<template<class> class T>
		BasicResponse<T>::BasicResponse()
		: traits_type()
		, base_type()
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
	}	// http
}	// 	om636