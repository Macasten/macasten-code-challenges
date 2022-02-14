const fs = require("fs");
const path = require("path");

const { ConfigTemplate } = require("./config-getter");

class TemplateFilesManager {
  constructor(fileBaseName, type) {
    this.mainFileName = fileBaseName;
    this.mainFile = ConfigTemplate.getMainFile(type);
    this.readmeFile = ConfigTemplate.getREADMEFile(type);
  }

  copyAllFiles(destinationFolder) {
    // Copy main file
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
