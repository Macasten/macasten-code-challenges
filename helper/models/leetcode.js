const { ChallengeProvider } = require("./challenge-provider");
const { ConfigProviderChallenge } = require("./config-getter");

function titleToFolderName(title) {
  return title.replace(/ /gi, "-").replace(".-", "_");
}

function titleToFileName(title, languageTag) {
  return (
    title.toLowerCase().replace(/ /gi, "-").replace(".", "") + "." + languageTag
  );
}

class Leetcode extends ChallengeProvider {
  constructor(title, languageTag = "cpp") {
    super(title, "leetcode", languageTag);
    this.mainSourceCodeName = titleToFileName(this.title, this.languageTag);
    this.workingDir = ConfigProviderChallenge.getNewWorkingDir(
      this.type,
      titleToFolderName(this.title)
    );
  }
}

module.exports = {
  Leetcode,
};