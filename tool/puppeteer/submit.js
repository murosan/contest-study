"use strict";

const puppeteer = require("puppeteer");
const clipboardy = require("clipboardy");
const cookie = require("./cookie");

const config = require("../config.json");
const q = config.beginner[process.argv[2]];
if (!q) {
  throw new Error("argv is empty.");
}
const url = config.beginner.base + q;
const btnSelector = "#outer-inner > p > .btn > .lang > .lang-ja";
const codeSelector = "textarea[name=source_code]";
const submitSelector = "button[type=submit]";

const settings = { headless: false };

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

  const accept = await page.evaluate(() => confirm("submit?"));
  if (accept) {
    const btn = await page.$(submitSelector);
    await btn.click();
    await page.waitForNavigation({
      timeout: 60000,
      waitUntil: "domcontentloaded"
    });
  }

  await browser.close();
})();
