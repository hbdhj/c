-- MySQL dump 10.13  Distrib 5.7.19, for Linux (x86_64)
--
-- Host: localhost    Database: jenkins
-- ------------------------------------------------------
-- Server version	5.7.19-0ubuntu0.16.04.1

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `bll_ut_coverage`
--

DROP TABLE IF EXISTS `bll_ut_coverage`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `bll_ut_coverage` (
  `build_id` int(11) DEFAULT NULL,
  `coverage` float DEFAULT NULL,
  `component` varchar(20) DEFAULT NULL,
  KEY `build_id` (`build_id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `bll_ut_coverage_build`
--

DROP TABLE IF EXISTS `bll_ut_coverage_build`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `bll_ut_coverage_build` (
  `build_id` int(11) DEFAULT NULL,
  `build_date` datetime DEFAULT NULL,
  `build_result` varchar(45) DEFAULT NULL,
  KEY `build_id` (`build_id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `bll_ut_coverage_build_changeslist`
--

DROP TABLE IF EXISTS `bll_ut_coverage_build_changeslist`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `bll_ut_coverage_build_changeslist` (
  `build_id` int(11) DEFAULT NULL,
  `changeslist_id` int(11) DEFAULT NULL,
  KEY `build_id` (`build_id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `il_ut_coverage`
--

DROP TABLE IF EXISTS `il_ut_coverage`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `il_ut_coverage` (
  `build_id` int(11) DEFAULT NULL,
  `coverage` float DEFAULT NULL,
  `component` varchar(20) DEFAULT NULL,
  KEY `build_id` (`build_id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `il_ut_coverage_build`
--

DROP TABLE IF EXISTS `il_ut_coverage_build`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `il_ut_coverage_build` (
  `build_id` int(11) DEFAULT NULL,
  `build_date` datetime DEFAULT NULL,
  `build_result` varchar(45) DEFAULT NULL,
  KEY `build_id` (`build_id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `il_ut_coverage_build_changeslist`
--

DROP TABLE IF EXISTS `il_ut_coverage_build_changeslist`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `il_ut_coverage_build_changeslist` (
  `build_id` int(11) DEFAULT NULL,
  `changeslist_id` int(11) DEFAULT NULL,
  KEY `build_id` (`build_id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2017-08-21  8:49:48
