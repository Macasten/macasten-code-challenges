const fs = require("fs");
const path = require("path");

const { ConfigTemplate } = require("./config-getter");

function getFileContent(filePath) {
  return fs.readFileSync(filePath, {
    encoding: "utf8",
    flag: "r",
  });
}

function createFile(filePath, fileContent) {
  fs.writeFileSync(filePath, fileContent);
}

class TemplateFilesManager {
  constructor(challengeProvider) {
    this.challengeProvider = challengeProvider;
    console.log("MainFile: ", this.mainFile);
  }
  //-------------------------------------------------------------------- Getters
  get mainFileName() {
    return this.challengeProvider.mainSourceCodeName;
  }

  get type() {
    return this.challengeProvider.type;
  }

  get languageTag() {
    return this.challengeProvider.languageTag;
  }

  get challengeTitle() {
    return this.challengeProvider.title;
  }

  get mainFile() {
    return ConfigTemplate.getMainFile(this.type, this.languageTag);
  }

  get readmeFile() {
    return ConfigTemplate.getREADMEFile(this.type);
  }

  get status() {
    return this.challengeProvider.status;
  }
  //------------------------------------------------ Templates Manager Functions
  copyAllFiles(destinationFolder) {
    // Create main file
    createFile(
      path.join(destinationFolder, this.mainFileName),
      this.createMainFile()
    );
    // Copy readme file
    createFile(path.join(destinationFolder, "README.md"), this.createReadme());
  }

  // Tags replacement
  createReadme() {
    const data = getFileContent(this.readmeFile);
    return data
      .replace("/*Challenge Title*/", this.challengeTitle)
      .replace("/*Status*/", this.status)
      .replace("/*Language TAG*/", this.languageTag)
      .replace("/*File Name*/", path.parse(this.mainFileName).name);
  }

  createMainFile() {
    const data = getFileContent(this.mainFile);
    return data.replace("/*Challenge Title*/", this.challengeTitle);
  }

  toString() {
    return `{
  "main-file-name" : ${this.mainFileName}
  "main-file" : ${this.mainFile}
  "readme-file" : ${this.readmeFile}
  "challenge-title" : ${this.challengeTitle}
}`;
  }
}

module.exports = {
  TemplateFilesManager,
};
