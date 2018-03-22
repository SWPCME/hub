var jsdiff = require('./diff.js');

var one = require('./test_1.json');
var other = require('./test_2.json');

var diff = jsdiff.diffJson(one, other);

diff.forEach(function(part){
  // green for additions, red for deletions
  // grey for common parts
    var state = part.added ? 'green' : part.removed ? 'red' : 'grey';
    if (state == 'green')
    {
        process.stdout.write('Add:\n');
        process.stdout.write(part.value);
    }
    if (state == 'red')
    {
        process.stdout.write('Del:\n');
        process.stdout.write(part.value);
    }
});

console.log()
