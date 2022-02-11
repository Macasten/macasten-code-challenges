const fs = require("fs");
const path = require("path");

//TODO: Remove hard code

const templatesStorage = "../templates";

// Name conversion functions
function titleToFolderName(title) {
  return title.replace(/ /gi, "-").replace(".-", "_");
}

function titleToFileName(title) {
  return title.replace(/ /gi, "-").replace(".", "") + ".cpp";
}

//TODO: Move this functions separated file.
function getTemplateFiles() {
  return ["leetcode-daily-challenge.cpp", "leetcode-daily-challenge.md"];
}

class TemplateFiles {
  static getMainFile(type) {
    switch (type) {
      case "leetcode":
        return path.join(templatesStorage, "leetcode-daily-challenge.cpp");
      default:
        break;
    }
  }

  static getREADMEFile(type) {
    switch (type) {
      case "leetcode":
        return path.join(templatesStorage, "leetcode-daily-challenge.md");
      default:
        break;
    }
  }
}

class TemplateFilesManager {
  constructor(fileBaseName, type) {
    this.mainFileName = fileBaseName;
    this.mainFile = TemplateFiles.getMainFile(type);
    this.readmeFile = TemplateFiles.getREADMEFile(type);
  }

  copyAllFiles(destinationFolder) {
    // Copy main file
    console.log(path.join(destinationFolder, this.mainFileName));
    fs.copyFileSync(
      this.mainFile,
      path.join(destinationFolder, this.mainFileName),
      fs.constants.COPYFILE_EXCL
    );
    // Copy readme file
    fs.copyFileSync(
      this.readmeFile,
      path.join(destinationFolder, "README.md"),
      fs.constants.COPYFILE_EXCL
    );
  }
}

// Test input
const challengesTitle = process.argv[2];
if (!challengesTitle) {
  console.log("Lack of input", challengesTitle);
  process.exit(1);
}

// Make Folder
const baseFolder = titleToFolderName(challengesTitle);
const newFolder = path.join(".", baseFolder);
if (!fs.existsSync(newFolder)) {
  fs.mkdirSync(newFolder);
} else {
  console.log(`" Failed: ${newFolder} already exist "`);
  process.exit(1);
}

// Copy template files to new challenge
const templates = new TemplateFilesManager(
  titleToFileName(challengesTitle),
  "leetcode"
);
templates.copyAllFiles(newFolder);

// console.log("Base Folder : ", baseFolder);

// console.log("Args: ", process.argv);

// var challengesTitle = process.argv[2];
// if (!challengesTitle) {
//   console.log("Lack of input", challengesTitle);
// }

// var newFolder = "./temp";

// console.log("Folder Name: ", titleToFolderName(challengesTitle));
// console.log("File Name: ", titleToFileName(challengesTitle));
