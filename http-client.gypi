{
	'target_defaults': {
		'include_dirs': [
			'.'
		],
		'sources': [
			'src/client.h',
			'src/client.hxx',
			'src/host.h',
			'src/host.hxx',
			'src/request.h',
			'src/request.hxx',
			'src/response.h',
			'src/response.hxx',
			'src/clients/mac.h',
			'src/clients/mac.hxx'
		], #sources
		'cflags': [ '-std=c++11', '-stdlib=libc++' ],
		'ldflags': [ '-stdlib=libc++' ],
	},
}