// var one = 'beep boop',
//     other = 'beep boob blah',
// var one = 'file:///home/swpcme/file/source/swpcme/hub/data/geojson/tmp/diff/test_1.json',
//     other = 'file:///home/swpcme/file/source/swpcme/hub/data/geojson/tmp/diff/test_2.json',
// var one = {a: 123, b: 456, d: 354},
//     other = {a: 123, b: 456, c: 789},
// var one = JSON.parse(test1),
//     other = JSON.parse(test2),
// var one = require('./test_1.json'),
//     other = require('./test_2.json'),
// var one = require('/home/swpcme/file/source/swpcme/hub/data/geojson/tmp/diff/test_1.json'),
//     other = require('/home/swpcme/file/source/swpcme/hub/data/geojson/tmp/diff/test_2.json'),
var imported = document.createElement('script');
// imported.src = 'file:///home/swpcme/file/source/swpcme/hub/src/itpt/js/hub_modulectl.js';
// imported.src = 'file:///home/swpcme/file/source/swpcme/hub/lib/itpt/js/diffhtml.js';
// document.head.appendChild(imported);
// diff.outerHTML(document.body, '<h1>beep</h1>');

var one = 'beep boop',
    other = 'beep boob blah',
    color = '',
    span = null;

// $.getJSON("file:///home/swpcme/file/source/swpcme/hub/data/geojson/tmp/diff/test_1.json", function(json){
//     one = json;
// });
// $.getJSON("file:///home/swpcme/file/source/swpcme/hub/data/geojson/tmp/diff/test_2.json", function(json){
//     other = json;
// });

var diff = JsDiff.diffChars(one, other),
    display = document.getElementById('display'),
    fragment = document.createDocumentFragment();

diff.forEach(function(part){
    // green for additions, red for deletions
    // grey for common parts
    color = part.added ? 'green' :
        part.removed ? 'red' : 'grey';
    span = document.createElement('span');
    span.style.color = color;
    span.appendChild(document.createTextNode(part.value));
    fragment.appendChild(span);
});

display.appendChild(fragment);

// require('colors')
// var jsdiff = require('diff');

// var one = 'beep boop';
// var other = 'beep boob blah';

// var diff = jsdiff.diffChars(one, other);

// diff.forEach(function(part){
//     // green for additions, red for deletions
//     // grey for common parts
//     var color = part.added ? 'green' :
//         part.removed ? 'red' : 'grey';
//     process.stderr.write(part.value[color]);
// });

// console.log()
