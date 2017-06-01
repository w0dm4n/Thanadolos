/*
Navicat MySQL Data Transfer

Source Server         : localhost_3306
Source Server Version : 50520
Source Host           : localhost:3306
Source Database       : symbioz

Target Server Type    : MYSQL
Target Server Version : 50520
File Encoding         : 65001

Date: 2017-05-15 00:27:57
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for `experiences`
-- ----------------------------
DROP TABLE IF EXISTS `experiences`;
CREATE TABLE `experiences` (
  `Level` smallint(6) NOT NULL AUTO_INCREMENT,
  `Xp` bigint(20) DEFAULT NULL,
  `Honor` varchar(255) DEFAULT NULL,
  `Guild` bigint(200) DEFAULT NULL,
  PRIMARY KEY (`Level`)
) ENGINE=MyISAM AUTO_INCREMENT=201 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of experiences
-- ----------------------------
INSERT INTO `experiences` VALUES ('1', '0', '0', '0');
INSERT INTO `experiences` VALUES ('2', '110', '500', '1100');
INSERT INTO `experiences` VALUES ('3', '650', '1500', '6500');
INSERT INTO `experiences` VALUES ('4', '1500', '3000', '15000');
INSERT INTO `experiences` VALUES ('5', '2800', '5000', '28000');
INSERT INTO `experiences` VALUES ('6', '4800', '7500', '48000');
INSERT INTO `experiences` VALUES ('7', '7300', '10000', '73000');
INSERT INTO `experiences` VALUES ('8', '10500', '12500', '105000');
INSERT INTO `experiences` VALUES ('9', '14500', '15000', '145000');
INSERT INTO `experiences` VALUES ('10', '19200', '17500', '192000');
INSERT INTO `experiences` VALUES ('11', '25200', '0', '252000');
INSERT INTO `experiences` VALUES ('12', '32600', '0', '326000');
INSERT INTO `experiences` VALUES ('13', '41000', '0', '410000');
INSERT INTO `experiences` VALUES ('14', '50500', '0', '505000');
INSERT INTO `experiences` VALUES ('15', '61000', '0', '610000');
INSERT INTO `experiences` VALUES ('16', '75000', '0', '750000');
INSERT INTO `experiences` VALUES ('17', '91000', '0', '910000');
INSERT INTO `experiences` VALUES ('18', '115000', '0', '1150000');
INSERT INTO `experiences` VALUES ('19', '142000', '0', '1420000');
INSERT INTO `experiences` VALUES ('20', '171000', '0', '1710000');
INSERT INTO `experiences` VALUES ('21', '202000', '0', '2020000');
INSERT INTO `experiences` VALUES ('22', '235000', '0', '2350000');
INSERT INTO `experiences` VALUES ('23', '270000', '0', '2700000');
INSERT INTO `experiences` VALUES ('24', '310000', '0', '3100000');
INSERT INTO `experiences` VALUES ('25', '353000', '0', '3530000');
INSERT INTO `experiences` VALUES ('26', '398500', '0', '3985000');
INSERT INTO `experiences` VALUES ('27', '448000', '0', '4480000');
INSERT INTO `experiences` VALUES ('28', '503000', '0', '5030000');
INSERT INTO `experiences` VALUES ('29', '561000', '0', '5610000');
INSERT INTO `experiences` VALUES ('30', '621600', '0', '6216000');
INSERT INTO `experiences` VALUES ('31', '687000', '0', '6870000');
INSERT INTO `experiences` VALUES ('32', '755000', '0', '7550000');
INSERT INTO `experiences` VALUES ('33', '829000', '0', '8290000');
INSERT INTO `experiences` VALUES ('34', '910000', '0', '9100000');
INSERT INTO `experiences` VALUES ('35', '1000000', '0', '10000000');
INSERT INTO `experiences` VALUES ('36', '1100000', '0', '11000000');
INSERT INTO `experiences` VALUES ('37', '1240000', '0', '12400000');
INSERT INTO `experiences` VALUES ('38', '1400000', '0', '14000000');
INSERT INTO `experiences` VALUES ('39', '1580000', '0', '15800000');
INSERT INTO `experiences` VALUES ('40', '1780000', '0', '17800000');
INSERT INTO `experiences` VALUES ('41', '2000000', '0', '20000000');
INSERT INTO `experiences` VALUES ('42', '2250000', '0', '22500000');
INSERT INTO `experiences` VALUES ('43', '2530000', '0', '25300000');
INSERT INTO `experiences` VALUES ('44', '2850000', '0', '28500000');
INSERT INTO `experiences` VALUES ('45', '3200000', '0', '32000000');
INSERT INTO `experiences` VALUES ('46', '3570000', '0', '35700000');
INSERT INTO `experiences` VALUES ('47', '3960000', '0', '39600000');
INSERT INTO `experiences` VALUES ('48', '4400000', '0', '44000000');
INSERT INTO `experiences` VALUES ('49', '4860000', '0', '48600000');
INSERT INTO `experiences` VALUES ('50', '5350000', '0', '53500000');
INSERT INTO `experiences` VALUES ('51', '5860000', '0', '58600000');
INSERT INTO `experiences` VALUES ('52', '6390000', '0', '63900000');
INSERT INTO `experiences` VALUES ('53', '6950000', '0', '69500000');
INSERT INTO `experiences` VALUES ('54', '7530000', '0', '75300000');
INSERT INTO `experiences` VALUES ('55', '8130000', '0', '81300000');
INSERT INTO `experiences` VALUES ('56', '8765100', '0', '87651000');
INSERT INTO `experiences` VALUES ('57', '9420000', '0', '94200000');
INSERT INTO `experiences` VALUES ('58', '10150000', '0', '101500000');
INSERT INTO `experiences` VALUES ('59', '10894000', '0', '108940000');
INSERT INTO `experiences` VALUES ('60', '11650000', '0', '116500000');
INSERT INTO `experiences` VALUES ('61', '12450000', '0', '124500000');
INSERT INTO `experiences` VALUES ('62', '13280000', '0', '132800000');
INSERT INTO `experiences` VALUES ('63', '14130000', '0', '141300000');
INSERT INTO `experiences` VALUES ('64', '15170000', '0', '151700000');
INSERT INTO `experiences` VALUES ('65', '16251000', '0', '162510000');
INSERT INTO `experiences` VALUES ('66', '17377000', '0', '173770000');
INSERT INTO `experiences` VALUES ('67', '18553000', '0', '185530000');
INSERT INTO `experiences` VALUES ('68', '19778000', '0', '197780000');
INSERT INTO `experiences` VALUES ('69', '21055000', '0', '210550000');
INSERT INTO `experiences` VALUES ('70', '22385000', '0', '223850000');
INSERT INTO `experiences` VALUES ('71', '23529000', '0', '235290000');
INSERT INTO `experiences` VALUES ('72', '25209000', '0', '252090000');
INSERT INTO `experiences` VALUES ('73', '26707000', '0', '267070000');
INSERT INTO `experiences` VALUES ('74', '28264000', '0', '282640000');
INSERT INTO `experiences` VALUES ('75', '29882000', '0', '298820000');
INSERT INTO `experiences` VALUES ('76', '31563000', '0', '315630000');
INSERT INTO `experiences` VALUES ('77', '33307000', '0', '333070000');
INSERT INTO `experiences` VALUES ('78', '35118000', '0', '351180000');
INSERT INTO `experiences` VALUES ('79', '36997000', '0', '369970000');
INSERT INTO `experiences` VALUES ('80', '38945000', '0', '389450000');
INSERT INTO `experiences` VALUES ('81', '40965000', '0', '409650000');
INSERT INTO `experiences` VALUES ('82', '43059000', '0', '430590000');
INSERT INTO `experiences` VALUES ('83', '45229000', '0', '452290000');
INSERT INTO `experiences` VALUES ('84', '47476000', '0', '474760000');
INSERT INTO `experiences` VALUES ('85', '49803000', '0', '498030000');
INSERT INTO `experiences` VALUES ('86', '52211000', '0', '522110000');
INSERT INTO `experiences` VALUES ('87', '54704000', '0', '547040000');
INSERT INTO `experiences` VALUES ('88', '57284000', '0', '572840000');
INSERT INTO `experiences` VALUES ('89', '59952000', '0', '599520000');
INSERT INTO `experiences` VALUES ('90', '62712000', '0', '627120000');
INSERT INTO `experiences` VALUES ('91', '65565000', '0', '655650000');
INSERT INTO `experiences` VALUES ('92', '68514000', '0', '685140000');
INSERT INTO `experiences` VALUES ('93', '71561000', '0', '715610000');
INSERT INTO `experiences` VALUES ('94', '74710000', '0', '747100000');
INSERT INTO `experiences` VALUES ('95', '77963000', '0', '779630000');
INSERT INTO `experiences` VALUES ('96', '81323000', '0', '813230000');
INSERT INTO `experiences` VALUES ('97', '84792000', '0', '847920000');
INSERT INTO `experiences` VALUES ('98', '88374000', '0', '883740000');
INSERT INTO `experiences` VALUES ('99', '92071000', '0', '920710000');
INSERT INTO `experiences` VALUES ('100', '95886000', '0', '958860000');
INSERT INTO `experiences` VALUES ('101', '99823000', '0', '998230000');
INSERT INTO `experiences` VALUES ('102', '103885000', '0', '1038850000');
INSERT INTO `experiences` VALUES ('103', '108075000', '0', '1080750000');
INSERT INTO `experiences` VALUES ('104', '112396000', '0', '1123960000');
INSERT INTO `experiences` VALUES ('105', '116853000', '0', '1168530000');
INSERT INTO `experiences` VALUES ('106', '121447000', '0', '1214470000');
INSERT INTO `experiences` VALUES ('107', '126184000', '0', '1261840000');
INSERT INTO `experiences` VALUES ('108', '131066000', '0', '1310660000');
INSERT INTO `experiences` VALUES ('109', '136098000', '0', '1360980000');
INSERT INTO `experiences` VALUES ('110', '141283000', '0', '1412830000');
INSERT INTO `experiences` VALUES ('111', '146626000', '0', '1466260000');
INSERT INTO `experiences` VALUES ('112', '152130000', '0', '1521300000');
INSERT INTO `experiences` VALUES ('113', '157800000', '0', '1578000000');
INSERT INTO `experiences` VALUES ('114', '163640000', '0', '1636400000');
INSERT INTO `experiences` VALUES ('115', '169655000', '0', '1696550000');
INSERT INTO `experiences` VALUES ('116', '175848000', '0', '1758480000');
INSERT INTO `experiences` VALUES ('117', '182225000', '0', '1822250000');
INSERT INTO `experiences` VALUES ('118', '188791000', '0', '1887910000');
INSERT INTO `experiences` VALUES ('119', '195550000', '0', '1955500000');
INSERT INTO `experiences` VALUES ('120', '202507000', '0', '2025070000');
INSERT INTO `experiences` VALUES ('121', '209667000', '0', '2096670000');
INSERT INTO `experiences` VALUES ('122', '217037000', '0', '2170037000');
INSERT INTO `experiences` VALUES ('123', '224620000', '0', '2246200000');
INSERT INTO `experiences` VALUES ('124', '232424000', '0', '2324240000');
INSERT INTO `experiences` VALUES ('125', '240452000', '0', '2404520000');
INSERT INTO `experiences` VALUES ('126', '248712000', '0', '2487120000');
INSERT INTO `experiences` VALUES ('127', '257209000', '0', '2572090000');
INSERT INTO `experiences` VALUES ('128', '265949000', '0', '2659490000');
INSERT INTO `experiences` VALUES ('129', '274939000', '0', '2749390000');
INSERT INTO `experiences` VALUES ('130', '284186000', '0', '2841860000');
INSERT INTO `experiences` VALUES ('131', '293694000', '0', '2936940000');
INSERT INTO `experiences` VALUES ('132', '303473000', '0', '3034730000');
INSERT INTO `experiences` VALUES ('133', '313527000', '0', '3135270000');
INSERT INTO `experiences` VALUES ('134', '323866000', '0', '3236660000');
INSERT INTO `experiences` VALUES ('135', '334495000', '0', '3344950000');
INSERT INTO `experiences` VALUES ('136', '345423000', '0', '3454230000');
INSERT INTO `experiences` VALUES ('137', '356657000', '0', '3566570000');
INSERT INTO `experiences` VALUES ('138', '368206000', '0', '3682060000');
INSERT INTO `experiences` VALUES ('139', '380076000', '0', '3800760000');
INSERT INTO `experiences` VALUES ('140', '392278000', '0', '3922780000');
INSERT INTO `experiences` VALUES ('141', '404818000', '0', '4048180000');
INSERT INTO `experiences` VALUES ('142', '417706000', '0', '4177060000');
INSERT INTO `experiences` VALUES ('143', '430952000', '0', '4309520000');
INSERT INTO `experiences` VALUES ('144', '444564000', '0', '4445640000');
INSERT INTO `experiences` VALUES ('145', '458551000', '0', '4585510000');
INSERT INTO `experiences` VALUES ('146', '472924000', '0', '4729240000');
INSERT INTO `experiences` VALUES ('147', '487693000', '0', '4876930000');
INSERT INTO `experiences` VALUES ('148', '502867000', '0', '5028670000');
INSERT INTO `experiences` VALUES ('149', '518458000', '0', '5184580000');
INSERT INTO `experiences` VALUES ('150', '534476000', '0', '5344760000');
INSERT INTO `experiences` VALUES ('151', '502867000', '0', '5510000000');
INSERT INTO `experiences` VALUES ('152', '567839000', '0', '5678390000');
INSERT INTO `experiences` VALUES ('153', '585206000', '0', '5852060000');
INSERT INTO `experiences` VALUES ('154', '603047000', '0', '6030470000');
INSERT INTO `experiences` VALUES ('155', '621374000', '0', '6213740000');
INSERT INTO `experiences` VALUES ('156', '640199000', '0', '6401990000');
INSERT INTO `experiences` VALUES ('157', '659536000', '0', '6595360000');
INSERT INTO `experiences` VALUES ('158', '679398000', '0', '6793980000');
INSERT INTO `experiences` VALUES ('159', '699798000', '0', '6997980000');
INSERT INTO `experiences` VALUES ('160', '720751000', '0', '7207510000');
INSERT INTO `experiences` VALUES ('161', '742772000', '0', '7422720000');
INSERT INTO `experiences` VALUES ('162', '764374000', '0', '7643740000');
INSERT INTO `experiences` VALUES ('163', '787074000', '0', '7870740000');
INSERT INTO `experiences` VALUES ('164', '810387000', '0', '8103870000');
INSERT INTO `experiences` VALUES ('165', '834329000', '0', '8343290000');
INSERT INTO `experiences` VALUES ('166', '858917000', '0', '8589170000');
INSERT INTO `experiences` VALUES ('167', '884167000', '0', '8841670000');
INSERT INTO `experiences` VALUES ('168', '910098000', '0', '9100980000');
INSERT INTO `experiences` VALUES ('169', '936727000', '0', '9367270000');
INSERT INTO `experiences` VALUES ('170', '964073000', '0', '9640730000');
INSERT INTO `experiences` VALUES ('171', '992154000', '0', '9921540000');
INSERT INTO `experiences` VALUES ('172', '1020991000', '0', '10209910000');
INSERT INTO `experiences` VALUES ('173', '1050603000', '0', '10506030000');
INSERT INTO `experiences` VALUES ('174', '1081010000', '0', '10810100000');
INSERT INTO `experiences` VALUES ('175', '1112235000', '0', '11122350000');
INSERT INTO `experiences` VALUES ('176', '1144298000', '0', '11442980000');
INSERT INTO `experiences` VALUES ('177', '1177222000', '0', '11772220000');
INSERT INTO `experiences` VALUES ('178', '1211030000', '0', '12110300000');
INSERT INTO `experiences` VALUES ('179', '1245745000', '0', '12457450000');
INSERT INTO `experiences` VALUES ('180', '1281393000', '0', '12813930000');
INSERT INTO `experiences` VALUES ('181', '1317997000', '0', '13179970000');
INSERT INTO `experiences` VALUES ('182', '1355584000', '0', '13555840000');
INSERT INTO `experiences` VALUES ('183', '1404179000', '0', '14041790000');
INSERT INTO `experiences` VALUES ('184', '1463811000', '0', '14338110000');
INSERT INTO `experiences` VALUES ('185', '1534506000', '0', '14745060000');
INSERT INTO `experiences` VALUES ('186', '1616294000', '0', '15162940000');
INSERT INTO `experiences` VALUES ('187', '1709205000', '0', '15592050000');
INSERT INTO `experiences` VALUES ('188', '1813267000', '0', '16032670000');
INSERT INTO `experiences` VALUES ('189', '1928513000', '0', '16485130000');
INSERT INTO `experiences` VALUES ('190', '2054975000', '0', '16949750000');
INSERT INTO `experiences` VALUES ('191', '2192686000', '0', '17426860000');
INSERT INTO `experiences` VALUES ('192', '2341679000', '0', '17916460000');
INSERT INTO `experiences` VALUES ('193', '2501990000', '0', '18419900000');
INSERT INTO `experiences` VALUES ('194', '2673655000', '0', '18936550000');
INSERT INTO `experiences` VALUES ('195', '2856710000', '0', '19467100000');
INSERT INTO `experiences` VALUES ('196', '3051194000', '0', '20011940000');
INSERT INTO `experiences` VALUES ('197', '3257146000', '0', '20571460000');
INSERT INTO `experiences` VALUES ('198', '3474606000', '0', '21146060000');
INSERT INTO `experiences` VALUES ('199', '3703616000', '0', '21736160000');
INSERT INTO `experiences` VALUES ('200', '7407232000', '0', '22356230000');
