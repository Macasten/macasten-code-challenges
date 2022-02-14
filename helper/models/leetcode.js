const { ChallengeProvider } = require("./challenge-provider");

function titleToFolderName(title) {
  return title.replace(/ /gi, "-").replace(".-", "_");
}

function titleToFileName(title) {
  return title.toLowerCase().replace(/ /gi, "-").replace(".", "") + ".cpp";
}

class Leetcode extends ChallengeProvider {
  constructor(title) {
    super(title, "leetcode");
    this.mainSourceCodeName = titleToFileName(this.title);
    this.workingDir = titleToFolderName(this.title);
  }
}

module.exports = {
  Leetcode,
};
