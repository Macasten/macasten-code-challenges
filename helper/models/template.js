const fs = require("fs");
const path = require("path");

const templatesStorage = process.env.TEMPLATES_STORAGE;

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

  toString() {
    return `{
  "main-file-name" : ${this.mainFileName}
  "main-file" : ${this.mainFile}
  "readme-file" : ${this.readmeFile}
}`;
  }
}

module.exports = {
  TemplateFilesManager,
};
