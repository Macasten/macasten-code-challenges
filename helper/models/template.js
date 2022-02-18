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
  constructor(fileBaseName, type, title, languageTag) {
    this.mainFileName = fileBaseName;
    this.mainFile = ConfigTemplate.getMainFile(type, languageTag);
    this.readmeFile = ConfigTemplate.getREADMEFile(type);
    this.challengeTitle = title;
    this.languageTag = languageTag;
  }

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
