/*
Navicat MySQL Data Transfer

Source Server         : localhost_3306
Source Server Version : 50520
Source Host           : localhost:3306
Source Database       : thanadolos_auth

Target Server Type    : MYSQL
Target Server Version : 50520
File Encoding         : 65001

Date: 2017-06-01 15:27:23
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for `accounts`
-- ----------------------------
DROP TABLE IF EXISTS `accounts`;
CREATE TABLE `accounts` (
  `Id` bigint(11) NOT NULL AUTO_INCREMENT,
  `Account` char(100) NOT NULL,
  `Password` char(100) NOT NULL,
  `SecretQuestion` char(100) NOT NULL,
  `SecretAnswer` char(100) NOT NULL,
  `Level` bigint(11) NOT NULL,
  `Nickname` char(100) NOT NULL,
  `Banned` bigint(11) NOT NULL,
  PRIMARY KEY (`Id`)
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=latin1;

-- ----------------------------
-- Records of accounts
-- ----------------------------
INSERT INTO `accounts` VALUES ('1', 'test', 'test', 'Aime-tu le sexe ?', 'Oh oui j\'adore ça', '1', 'Héllo hacker', '0');
INSERT INTO `accounts` VALUES ('4', 'test1', 'test', 'Aime-tu le sexe ?', 'Oh oui j\'adore ça', '0', 'Coucou', '0');

-- ----------------------------
-- Table structure for `worlds_characters`
-- ----------------------------
DROP TABLE IF EXISTS `worlds_characters`;
CREATE TABLE `worlds_characters` (
  `Id` int(11) NOT NULL AUTO_INCREMENT,
  `AccountId` int(11) NOT NULL,
  `ServerId` int(11) NOT NULL,
  `CharactersCount` int(11) NOT NULL,
  PRIMARY KEY (`Id`)
) ENGINE=InnoDB AUTO_INCREMENT=12 DEFAULT CHARSET=latin1;

-- ----------------------------
-- Records of worlds_characters
-- ----------------------------
INSERT INTO `worlds_characters` VALUES ('9', '1', '1', '2');
INSERT INTO `worlds_characters` VALUES ('11', '4', '1', '1');

-- ----------------------------
-- Table structure for `worlds_servers`
-- ----------------------------
DROP TABLE IF EXISTS `worlds_servers`;
CREATE TABLE `worlds_servers` (
  `Id` int(11) NOT NULL AUTO_INCREMENT,
  `Name` char(100) NOT NULL,
  `Address` char(100) NOT NULL,
  `Port` int(11) NOT NULL,
  `MaxCapacity` int(11) NOT NULL,
  `ServerStatus` int(11) NOT NULL,
  `RequiredRole` int(11) NOT NULL,
  PRIMARY KEY (`Id`)
) ENGINE=InnoDB AUTO_INCREMENT=11 DEFAULT CHARSET=latin1;

-- ----------------------------
-- Records of worlds_servers
-- ----------------------------
INSERT INTO `worlds_servers` VALUES ('1', 'Jiva', '127.0.0.1', '5500', '10', '1', '0');
INSERT INTO `worlds_servers` VALUES ('10', 'Test', '127.0.0.1', '5501', '10', '1', '0');
