"use strict";

const fs = require("fs");
const path = require("path");

function save(fileName, cases) {
  fs.writeFileSync(getPath(fileName), JSON.stringify(cases));
}

function load(fileName) {
  return require(getPath(fileName));
}

function getPath(fileName) {
  return path.resolve(__dirname, `../cases/${fileName}.json`);
}

module.exports = { save, load };
