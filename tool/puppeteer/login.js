"use strict";

const path = require("path");
const fs = require("fs");
const puppeteer = require("puppeteer");
const cookie = require("./cookie");

const config = require("../config.json");
const loginURL = config.loginURL;
const settings = { headless: false, slowMo: 20 };

(async () => {
  const browser = await puppeteer.launch(settings);
  const page = await browser.newPage();
  await page.goto(loginURL);

  await page.focus('input[name="name"]');
  await page.type('input[name="name"]', config.username);
  await page.focus('input[name="password"]');
  await page.type('input[name="password"]', config.password);
  const btn = await page.$("button[type=submit]");
  await btn.click();

  await page.waitForNavigation({
    timeout: 60000,
    waitUntil: "domcontentloaded"
  });

  const cookies = await page.cookies();
  cookie.save(cookies);
  await browser.close();
})();
