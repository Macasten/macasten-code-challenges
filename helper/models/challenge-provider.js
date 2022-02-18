const fs = require("fs");
const path = require("path");

const { TemplateFilesManager } = require("./template");

class ChallengeProvider {
  constructor(title, type, languageTag = "cpp") {
    this.type = type;
    this.title = title;
    this.workingDir = title;
    this.mainSourceCodeName = title;
    this.languageTag = languageTag;
    this.status = "Unsolved";
  }

  createWorkingFolder() {
    if (!fs.existsSync(this.workingDir)) {
      fs.mkdirSync(this.workingDir);
    } else {
      console.log(`" Failed: ${this.workingDir} already exist "`);
      process.exit(1);
    }

    var temp = new TemplateFilesManager( this );
    temp.copyAllFiles(this.workingDir);
  }

  toString() {
    return `Code Challenge Manager:
Type          : ${this.type}
Language      : ${this.languageTag}
Original title: ${this.title}
Working folder: ${this.workingDir}
Main file name: ${this.mainSourceCodeName}
`;
  }
}

module.exports = {
  ChallengeProvider,
};
