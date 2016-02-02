'use strict';
var Particle = require('./Particle');
var should = require('should');

describe('Amazon Echo NodeJS ToolKit', function () {

  describe('createParticleAPIDictionary', function () {
    it('should successfully construct a valid api dictionary', function (done) {
      var options = {
          hostname: "DJ",
          path: "PATH",
          method: 'POST',
          headers: {
            'Content-Type': 'application/x-www-form-urlencoded',
            'Accept': '*.*'
          }
      };

      var particle = Particle.createParticleAPIDictionary("DJ", "PATH");
      // Testing..
      particle.hostname.should.be.exactly(options.hostname);
      particle.path.should.be.exactly(options.path);
      particle.method.should.be.exactly(options.method);
      done();
    });
  });
});