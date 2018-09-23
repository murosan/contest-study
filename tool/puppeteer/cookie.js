"use strict";

const fs = require("fs");
const path = require("path");
const cookieFile = path.resolve(__dirname, "../cookies/atcoder.json");

function save(cookies) {
  fs.writeFileSync(cookieFile, JSON.stringify(cookies));
}

function load() {
  return require(cookieFile);
}

module.exports = { save, load };
