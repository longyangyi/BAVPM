const Migrations = artifacts.require("Migrations");
const BAVPM = artifacts.require("BAVPM");
module.exports = function(deployer) {
  deployer.deploy(Migrations);
  deployer.deploy(BAVPM);
};
