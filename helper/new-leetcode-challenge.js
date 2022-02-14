const { Leetcode } = require("./models/leetcode");


// //TODO: Move this functions separated file.
// function getTemplateFiles() {
  //   return ["leetcode-daily-challenge.cpp", "leetcode-daily-challenge.md"];
  // }

// Test input
const challengesTitle = process.argv[2];
if (!challengesTitle) {
  console.log("Lack of input", challengesTitle);
  process.exit(1);
}

const leetcode = new Leetcode( challengesTitle );
console.log( leetcode.toString() );
leetcode.createWorkingFolder();

