#ifndef RESPONSE_H__GOMKtEHwczr9g0fj13dy8bQS2DPVeW
#define RESPONSE_H__GOMKtEHwczr9g0fj13dy8bQS2DPVeW

namespace om636
{
	namespace http
	{
		template<template<class> class T> 
		struct Response
		: private T< Response< T > >  
		{
			typedef T< Response > traits_type;
			using typename traits_type::string_type; 
			
			virtual ~Response(); 
			virtual void onData(string_type) = 0;
			virtual void onError(string_type) = 0;
		};

		template<template<class> class T> 
		struct BasicResponse
		: private T< BasicResponse< T > >
		, public Response< T > 
		{
			typedef T< BasicResponse< T > > traits_type; 
			typedef Response< T > base_type;
			using typename traits_type::string_type; 

			BasicResponse();
//            BasicResponse(const BasicResponse &) = default;
//            BasicResponse & operator=(const BasicResponse &) = default;
			virtual ~BasicResponse();
			virtual void onData(string_type);
			virtual void onError(string_type);
		};


	}	// http
}	// 	om636

#include "response.hxx"
#endif // RESPONSE_H__GOMKtEHwczr9g0fj13dy8bQS2DPVeW