var addon = require('./build/Release/addon.node');

module.exports = {
  cleanup : addon.winSparkleCleanup,
  setAppcastUrl : addon.winSparkleSetAppcastUrl,
  checkUpdateWithUI : addon.winSparkleCheckUpdateWithUI,
  init : addon.winSparkleInit,
  setAutomaticCheckForUpdates : addon.winSparkleSetAutomaticCheckForUpdates,
  getAutomaticCheckForUpdates : addon.winSparkleGetAutomaticCheckForUpdates
};