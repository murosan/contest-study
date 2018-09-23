"use strict";

const puppeteer = require("puppeteer");
const clipboardy = require("clipboardy");
const cookie = require("./cookie");
const cookies = cookie.load();
const caseRepo = require("./cases");

const config = require("../config.json");
const settings = { headless: false, slowMo: 20 };
const selector = '.lang-ja span[class="btn-sample-copy"]';

(async () => {
  const browser = await puppeteer.launch(settings);
  const page = await browser.newPage();

  for (const cookie of cookies) {
    await page.setCookie(cookie);
  }

  const getCases = async url => {
    console.log("access to: " + url);
    await page.goto(url);
    await page.waitForSelector(selector);
    const cookies = await page.cookies();
    cookie.save(cookies);

    const btns = await page.$$(selector);
    const inputs = [];
    const outputs = [];
    for (let i = 0; i < btns.length; i++) {
      await btns[i].click();
      const data = clipboardy.readSync().replace(/\n$/, "");
      if (i % 2 === 0) {
        inputs.push(data);
      } else {
        outputs.push(data);
      }
    }

    return inputs.map((input, index) => {
      return { in: input, out: outputs[index] };
    });
  };

  caseRepo.save("b_a", await getCases(config.base + config.beginner.a));
  caseRepo.save("b_b", await getCases(config.base + config.beginner.b));
  caseRepo.save("b_c", await getCases(config.base + config.beginner.c));
  caseRepo.save("b_d", await getCases(config.base + config.beginner.d));

  await browser.close();
})();
