#!/usr/bin/env node

var assert = require( 'assert' )
  , events = require( 'events' )
  , Processor = require( 'mucbuc-jsthree').Processor;

assert( typeof Processor !== 'undefined' && typeof events !== 'undefined' ); 

var e = new events.EventEmitter();
var p = new Processor( { 'arg': ['--depth==.'], 'cwd': __dirname, 'cmd': 'gyp'} , e );

e.on( 'stdout', function(data) {
	console.log( data.toString() ); 
} );

e.emit( "execute" );