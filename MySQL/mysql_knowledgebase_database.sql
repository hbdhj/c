-- MySQL dump 10.13  Distrib 5.7.11, for osx10.11 (x86_64)
--
-- Host: localhost    Database: w3school
-- ------------------------------------------------------
-- Server version	5.7.11

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
-- Table structure for table `ACTIONS`
--

DROP TABLE IF EXISTS `ACTIONS`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ACTIONS` (
  `A_ID` int(11) NOT NULL,
  `A_NAME` varchar(255) NOT NULL,
  PRIMARY KEY (`A_ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ACTIONS`
--

LOCK TABLES `ACTIONS` WRITE;
/*!40000 ALTER TABLE `ACTIONS` DISABLE KEYS */;
INSERT INTO `ACTIONS` VALUES (1,'Create'),(2,'Read'),(3,'Update'),(4,'Delete');
/*!40000 ALTER TABLE `ACTIONS` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `OBJECTS`
--

DROP TABLE IF EXISTS `OBJECTS`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `OBJECTS` (
  `O_ID` int(11) NOT NULL,
  `O_NAME` varchar(255) NOT NULL,
  PRIMARY KEY (`O_ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `OBJECTS`
--

LOCK TABLES `OBJECTS` WRITE;
/*!40000 ALTER TABLE `OBJECTS` DISABLE KEYS */;
INSERT INTO `OBJECTS` VALUES (1,'database'),(2,'table'),(3,'column'),(4,'record');
/*!40000 ALTER TABLE `OBJECTS` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Commands`
--

DROP TABLE IF EXISTS `Commands`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Commands` (
  `C_ID` int(11) NOT NULL,
  `C_NAME` varchar(255) NOT NULL,
  PRIMARY KEY (`C_ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Commands`
--

LOCK TABLES `Commands` WRITE;
/*!40000 ALTER TABLE `Commands` DISABLE KEYS */;
INSERT INTO `Commands` VALUES (1, 'create'),(2, 'update'),(3, 'insert'),(4, 'delete'),(5, 'drop'),(6, 'alter'),(7, 'select');
/*!40000 ALTER TABLE `Commands` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `SQLs`
--

DROP TABLE IF EXISTS `SQLs`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `SQLs` (
  `S_ID` int(11) NOT NULL,
  `A_ID` int(11) NOT NULL,
  `C_ID` int(11) NOT NULL,
  `O_ID` int(11) NOT NULL,
  `Example` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`S_ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `SQLs`
--

LOCK TABLES `SQLs` WRITE;
/*!40000 ALTER TABLE `SQLs` DISABLE KEYS */;
INSERT INTO `SQLs` VALUES (1, 1, 1, 1, 'INSERT INTO Persons VALUES (\'Gates\', \'Bill\', \'Xuanwumen 10\', \'Beijing\')');
/*!40000 ALTER TABLE `SQLs` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2016-02-21 22:00:00
