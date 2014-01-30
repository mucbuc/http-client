#!/usr/bin/env node

var http = require( 'http' ); 

var server = http.createServer(function(req, res){
	res.end( 'ok' );
}); 

server.listen(3000);