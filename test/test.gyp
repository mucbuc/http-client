{
	'includes':[
		'../http-client.gypi',
		'../plank/def/mac-targets.gypi'
	],#inclues
	'target_defaults': {
		'target_name': 'test',
		'type': 'executable', 
		'sources': [
			'../test/src/main.mm',
			'../test/src/impl.h',
		], #sources
		'include_dirs': [
			'../plank/src/',
			'../'
		], #include_dirs		
	}, #target_defaults
}