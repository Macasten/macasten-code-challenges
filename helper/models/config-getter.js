const path = require("path");

class ConfigProviderChallenge {
  static getWorkingDir(type) {
    switch (type) {
      case "leetcode":
        return process.env.LEETCODE_DAILY_CHALLENGE_FOLDER;
      default:
        return undefined;
    }
  }

  static getNewWorkingDir(type, newWorkingDir) {
    var aux = this.getWorkingDir(type);
    return aux ? path.join(aux, newWorkingDir) : aux;
  }
}

class ConfigTemplate {
  static getMainFile(type) {
    switch (type) {
      case "leetcode":
        return path.join(
          process.env.TEMPLATES_STORAGE,
          "leetcode-daily-challenge.cpp"
        );
      default:
        return undefined;
    }
  }

  static getREADMEFile(type) {
    switch (type) {
      case "leetcode":
        return path.join(
          process.env.TEMPLATES_STORAGE,
          "leetcode-daily-challenge.md"
        );
      default:
        return undefined;
    }
  }
}

module.exports = {
  ConfigTemplate,
  ConfigProviderChallenge,
};
