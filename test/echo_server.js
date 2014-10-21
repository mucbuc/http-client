#!/usr/bin/env node

var http = require( 'http' )
  , port = (process.argv.length >= 3) ? parseInt( process.argv[2], 10 ) : 3000; 

console.log( 'listening on port: ' + port );

var server = http.createServer(function(req, res){
	var item = '';
	req.setEncoding( 'utf8' );
	req.on( 'data', function(data){
		item += data;
	});
	req.on( 'end', function() {
		console.log( 'got data', item );
		res.end( req.method + ':' + item );
	});
}); 

server.listen(port);
