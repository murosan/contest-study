"use strict";

const puppeteer = require("puppeteer");
const clipboardy = require("clipboardy");
const cookie = require("./cookie");

const config = require("../config.json");
const url = config.beginner.base + config.beginner.a; // TODO: 動的に
const btnSelector = "#outer-inner > p > .btn > .lang > .lang-ja";
const codeSelector = "textarea[name=source_code]";
const submitSelector = "button[type=submit]";

const settings = { headless: false, slowMo: 20 };

(async () => {
  const browser = await puppeteer.launch(settings);
  const page = await browser.newPage();

  for (const c of cookie.load()) {
    await page.setCookie(c);
  }

  console.log("access to: " + url);
  await page.goto(url);
  await page.waitForSelector(btnSelector);
  await page.click(btnSelector);

  await page.focus(codeSelector);
  await page.type(codeSelector, clipboardy.readSync());

  const btn = await page.$(submitSelector);
  await btn.click();
  await page.waitForNavigation({
    timeout: 60000,
    waitUntil: "domcontentloaded"
  });

  await browser.close();
})();
