#!/usr/bin/env node

var assert = require( 'assert' )
  , events = require( 'events' )
  , Processor = require( 'mucbuc-jsthree').Processor
  , path = require( 'path' );

assert( typeof Processor !== 'undefined' && typeof events !== 'undefined' ); 

generateProject( makeEmitter() ); 

function makeEmitter() 
{
	var e = new events.EventEmitter();
	e.on( 'stdout', function(data) {
		process.stdout.write( data.toString() ); 
	} );
	return e;
}

function generateProject(emitter) 
{
	var p = new Processor( { 'args': ['--depth==.'], 'cwd': __dirname, 'cmd': 'gyp'} , emitter );
	console.log( 'generate target' );

	emitter.once( 'close', function() {
		process.nextTick( function() {
			buildTarget(makeEmitter());
		} );
	} );

	emitter.emit( "execute" );
}

function buildTarget(emitter)
{
	var p = new Processor( { 'args': [], 'cwd': __dirname, 'cmd': 'xcodebuild'} , emitter );
	console.log( 'build target' );

	emitter.once( 'close', function() {
		process.nextTick( function() { 
			testBuild(makeEmitter());
		} );
	}); 

	emitter.emit( "execute" );
}

function testBuild(emitter)
{
	var cmd = 'build/Default/test'; // cwd is broke :(
	var p = new Processor( { 'args': ['http://mucbuc.com:3000'], 'cwd': __dirname, 'cmd': 'build/Default/test'} , emitter );

	console.log( 'test build' );

	emitter.emit( "execute" );
}



