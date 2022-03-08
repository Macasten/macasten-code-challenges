const http = require('http');

const express = require('express');
const bodyParser = require("body-parser");

const app = express();
app.use(bodyParser.urlencoded({ extended: false }));

const port = process.env.PORT;

app.set("view engine", "ejs");
app.set("views", "views");

app.listen(port, () => {
  console.log("Code Challenges helper is up on port " + port);
});