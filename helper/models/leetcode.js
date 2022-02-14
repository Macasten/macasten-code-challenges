const { TemplateFilesManager } = require("./template");

function titleToFolderName(title) {
  return title.replace(/ /gi, "-").replace(".-", "_");
}

function titleToFileName(title) {
  return title.replace(/ /gi, "-").replace(".", "") + ".cpp";
}

class Leetcode {
  constructor(title) {
    this.type = "leetcode";
    this.title = title;
  }

  toString() {
    return "Leetcode Challenge Manager";
  }
}

module.exports = {
  Leetcode,
};
