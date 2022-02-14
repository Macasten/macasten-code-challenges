const fs = require("fs");
const path = require("path");

const { TemplateFilesManager } = require("./template");

class ChallengeProvider {
  constructor(title, type) {
    this.type = type;
    this.title = title;
    this.workingDir = title;
    this.mainSourceCodeName = title;
  }

  createWorkingFolder() {
    var newFolder = path.join(".", this.workingDir);
    if (!fs.existsSync(newFolder)) {
      fs.mkdirSync(newFolder);
    } else {
      console.log(`" Failed: ${newFolder} already exist "`);
      process.exit(1);
    }

    var temp = new TemplateFilesManager(this.mainSourceCodeName, this.type);
    temp.copyAllFiles(this.workingDir);
  }

  toString() {
    return `Code Challenge Manager:
Type          : ${this.type}
Original title: ${this.title}
Working folder: ${this.workingDir}
Main file name: ${this.mainSourceCodeName}
`;
  }
}

module.exports = {
  ChallengeProvider,
};
