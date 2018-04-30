var sys = require('sys');
var http = require('http');
var fs = require('fs');
var url = require("url");
var router = require('./router');
const addon = require('./build/Release/addon.node');

const port = 3000;

router.register('/', function (req, res) {
  var chars = "TEST";
  let bitmap = null;
  let str = "";
  // for (let i = 0; i < chars.length; ++i) {
  //   bitmap = addon.getCharBitmap(chars[i]);
    for (let j = 0; j <= 50; ++j) {
      str+=`<g transform="translate(${12*j}, 0)">`;

      for(let k=0; k<=50; ++k){
        str+=`<rect width="10" height="10" data-id=${k+50*j} x=${j} y=${k*12} fill="#ebedf0"></rect>`;
      }

      str+='</g>';
  
    }
  //}
  res.writeHead(200, { 'Content-Type': 'text/html' });
  res.write(`<svg  width="676" height="624">
  <g id="bits" transform="translate(16, 20)"> 
  ${str}
  </g>
</svg>`);
res.end();
});

var server = http.createServer(function (req, res) {
  handler = router.route(req);
  handler.process(req, res);
});

server.listen(port);
console.log('Server running at', port);