namespace om636
{	
	namespace http
	{	
		host<>::host()
		: base_type()
		, m_impl( new impl_type() )
		{}

		auto host<>::get(request_type req) -> response_type
		{
			return policy_type::get(m_impl, req);
		}
		
		auto host<>::post(request_type req) -> response_type
		{
			return policy_type::post(m_impl, req);
		}
		
		auto host<>::put(request_type req) -> response_type
		{
			return policy_type::put(m_impl, req);
		}
		
		auto host<>::del(request_type req) -> response_type
		{
			return policy_type::del(m_impl, req);
		}
	}
}	// om636