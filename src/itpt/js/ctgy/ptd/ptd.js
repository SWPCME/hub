// pretty diff
var global = {},
    args   = {
        source: "./test_1",
        diff  : "./test_2",
        lang  : "text",
    };
// var output = prettydiff(args);
var fragment = document.createDocumentFragment();
var display = document.getElementById('display');
display.appendChild(fragment);
