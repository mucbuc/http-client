#!/usr/bin/env node

var cp = require( 'child_process' )
  , server = cp.fork( './test/echo_server.js' );//, [], { stdio: 'inherit' } );


cp.spawn( 'crimp', [ 'test/test.json', '-x', 'http://localhost:3000' ], { stdio: 'inherit' } )
.on( 'exit', function() {
	server.kill();
});

