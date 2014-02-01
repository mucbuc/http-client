#!/usr/bin/env node

var http = require( 'http' )
  , port = (process.argv.length >= 3) ? parseInt( process.argv[2], 10 ) : 3000; 

console.log( 'listening on port: ' + port );

var server = http.createServer(function(req, res){
  res.end( 'ok' );
  console.log( 'got request:', req );
}); 

server.listen(port);
