const { Leetcode } = require("./models/leetcode");

const leetcode = new Leetcode();

// //TODO: Move this functions separated file.
// function getTemplateFiles() {
//   return ["leetcode-daily-challenge.cpp", "leetcode-daily-challenge.md"];
// }

// // Test input
// const challengesTitle = process.argv[2];
// if (!challengesTitle) {
//   console.log("Lack of input", challengesTitle);
//   process.exit(1);
// }

// // Make Folder
// const baseFolder = titleToFolderName(challengesTitle);
// const newFolder = path.join(".", baseFolder);
// if (!fs.existsSync(newFolder)) {
//   fs.mkdirSync(newFolder);
// } else {
//   console.log(`" Failed: ${newFolder} already exist "`);
//   process.exit(1);
// }

// // Copy template files to new challenge
// const templates = new TemplateFilesManager(
//   titleToFileName(challengesTitle),
//   "leetcode"
// );
// templates.copyAllFiles(newFolder);

// console.log("Base Folder : ", baseFolder);

// console.log("Args: ", process.argv);

// var challengesTitle = process.argv[2];
// if (!challengesTitle) {
//   console.log("Lack of input", challengesTitle);
// }

// var newFolder = "./temp";

// console.log("Folder Name: ", titleToFolderName(challengesTitle));
// console.log("File Name: ", titleToFileName(challengesTitle));
