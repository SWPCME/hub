var fs = require("fs");
var src = "<html> sdf </html>", dst = "<html> sdf </html>";
// var src = fs.readFileSync("/home/swpcme/tmp/test_1.html"), dst = fs.readFileSync("/home/swpcme/tmp/test_2.html");
var src = fs.readFileSync('./test_1.txt', "utf8");
var dst = fs.readFileSync('./test_2.txt', "utf8");
var prettydiff = require("../../../../../lib/itpt/js/prettydiff/prettydiff"),
    args       = {
        source: src,
        diff  : dst,
        mode  : "diff",
        lang  : "text",
        parseFormat: "htmltable",
        html  : true,
        apacheVelocity : true,
        attributetoken : true
    },
    output = prettydiff(args);
process.stdout.write(output);
fs.writeFile('x.html', output,  function(err) {});
