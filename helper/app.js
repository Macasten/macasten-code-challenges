const http = require('http');

const express = require('express');
const app = express();

const port = process.env.PORT;

app.listen( port , () => {
  console.log('Code Challenges helper is up on port ' + port);
})

console.log("Code Challenges Helper");