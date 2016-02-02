exports.createParticleAPIDictionary = function(hostname, path) {
	var options = {
		hostname: hostname,
		port: 443,
		path: path,
		method: 'POST',
		headers: {
			'Content-Type': 'application/x-www-form-urlencoded',
			'Accept': '*.*'
		}
	};
  return options
}