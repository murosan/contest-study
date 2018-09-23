"use strict";

const path = require("path");
const fs = require("fs");
const puppeteer = require("puppeteer");

const config = require("../config.json");
const loginURL = "https://practice.contest.atcoder.jp/login";
const settings = { headless: false, slowMo: 20 };
const cookieFile = path.resolve(__dirname, "../cookies/atcoder.json");

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

  const cookie = await page.cookies();
  fs.writeFileSync(cookieFile, JSON.stringify(cookie));
  await browser.close();
})();
