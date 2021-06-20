/*
 Navicat Premium Data Transfer

 Source Server         : 腾讯云数据库
 Source Server Type    : MySQL
 Source Server Version : 80024
 Source Host           : 42.193.228.185:3306
 Source Schema         : data

 Target Server Type    : MySQL
 Target Server Version : 80024
 File Encoding         : 65001

 Date: 20/06/2021 11:01:17
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for account
-- ----------------------------
DROP TABLE IF EXISTS `account`;
CREATE TABLE `account`  (
  `username` varchar(20) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `passwd` varchar(20) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `onlyID` int(0) NOT NULL AUTO_INCREMENT,
  `avatorUrl` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '头像图片存储的地址，使用sm.ms图床\r\n',
  `deleteUrl` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '头像图片删除地址',
  PRIMARY KEY (`onlyID`) USING BTREE
) ENGINE = MyISAM AUTO_INCREMENT = 23 CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of account
-- ----------------------------
INSERT INTO `account` VALUES ('remmeiko', 'remmeiko', 1, 'https://i.loli.net/2021/06/12/JgQjwXxSzURpFuI.jpg', 'https://sm.ms/delete/JgQjwXxSzURpFuI.jpg');
INSERT INTO `account` VALUES ('mikasa', 'mikasa', 5, 'https://i.loli.net/2021/06/13/UnYNMsfuk7AHItx.jpg', 'https://sm.ms/delete/75FaLpd9GNwOBT8ckXsWm2jHvJ');
INSERT INTO `account` VALUES ('mikasa2', 'mikasa2', 10, 'https://i.loli.net/2021/06/14/WIRYeJENCMuGtTP.png', 'https://sm.ms/delete/pW2veSc4u1yZg36iDCPQkM5BwX');
INSERT INTO `account` VALUES ('1', '1', 23, 'https://i.loli.net/2021/06/20/jhM98HJiaI3zNtc.jpg', 'https://sm.ms/delete/oxgUIDmy5OSfbQhiVk34EBwR8e');
INSERT INTO `account` VALUES ('rem', 'rem', 24, 'https://i.loli.net/2021/06/20/w9AKM5SBL6I3jsY.png', 'https://sm.ms/delete/x7VnmKYBcdeAzGZowMLHyg6tuT');
INSERT INTO `account` VALUES ('tan35', 'tan35', 25, 'https://i.loli.net/2021/06/20/jhM98HJiaI3zNtc.jpg', 'https://sm.ms/delete/oxgUIDmy5OSfbQhiVk34EBwR8e');

-- ----------------------------
-- Table structure for data
-- ----------------------------
DROP TABLE IF EXISTS `data`;
CREATE TABLE `data`  (
  `temperature` int(0) NOT NULL,
  `humanity` int(0) NOT NULL,
  `date` timestamp(0) NOT NULL DEFAULT CURRENT_TIMESTAMP(0) ON UPDATE CURRENT_TIMESTAMP(0),
  `id` int(0) NOT NULL,
  `ppm` varchar(100) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Compact;

-- ----------------------------
-- Records of data
-- ----------------------------
INSERT INTO `data` VALUES (27, 84, '2021-06-17 15:27:27', 1, '300');
INSERT INTO `data` VALUES (26, 85, '2021-06-16 15:48:05', 1, '300');
INSERT INTO `data` VALUES (22, 77, '2021-06-16 15:48:06', 1, '300');
INSERT INTO `data` VALUES (32, 64, '2021-06-16 15:48:08', 1, '100');
INSERT INTO `data` VALUES (30, 24, '2021-06-17 15:28:29', 1, '50');
INSERT INTO `data` VALUES (20, 56, '2021-06-17 17:03:26', 1, '60');
INSERT INTO `data` VALUES (25, 60, '2021-06-17 17:03:52', 1, '70');
INSERT INTO `data` VALUES (30, 50, '2021-06-17 17:04:09', 1, '75');
INSERT INTO `data` VALUES (25, 40, '2021-06-17 17:04:19', 1, '80');
INSERT INTO `data` VALUES (31, 82, '2021-06-17 19:33:36', 1, '90');

SET FOREIGN_KEY_CHECKS = 1;
