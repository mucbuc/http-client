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



	}	// http
}	// 	om636

#include "response.hxx"
#endif // RESPONSE_H__GOMKtEHwczr9g0fj13dy8bQS2DPVeW