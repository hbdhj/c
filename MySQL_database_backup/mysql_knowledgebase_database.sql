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
  `E_ID` int(11) NOT NULL,
  `E_NAME` varchar(255) NOT NULL,
  PRIMARY KEY (`E_ID`)
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
  `E_ID` int(11) NOT NULL,
  `E_NAME` varchar(255) NOT NULL,
  PRIMARY KEY (`E_ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `OBJECTS`
--

LOCK TABLES `OBJECTS` WRITE;
/*!40000 ALTER TABLE `Employees_USA` DISABLE KEYS */;
INSERT INTO `OBJECTS` VALUES (1,'database'),(2,'table'),(3,'column'),(4,'record');
/*!40000 ALTER TABLE `OBJECTS` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Orders`
--

DROP TABLE IF EXISTS `Orders`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Orders` (
  `Company` varchar(255) NOT NULL,
  `OrderNumber` int(11) NOT NULL,
  `Id_O` int(11) NOT NULL,
  `id_p` int(11) NOT NULL,
  PRIMARY KEY (`Id_O`),
  KEY `id_p` (`id_p`),
  CONSTRAINT `orders_ibfk_1` FOREIGN KEY (`id_p`) REFERENCES `Persons` (`Id_P`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Orders`
--

LOCK TABLES `Orders` WRITE;
/*!40000 ALTER TABLE `Orders` DISABLE KEYS */;
INSERT INTO `Orders` VALUES ('W3School',2356,1,4),('IBM',3532,2,3),('Apple',4698,3,2),('W3School',6953,4,1);
/*!40000 ALTER TABLE `Orders` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Persons`
--

DROP TABLE IF EXISTS `Persons`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Persons` (
  `Id_P` int(11) NOT NULL,
  `LastName` varchar(255) DEFAULT NULL,
  `FirstName` varchar(255) DEFAULT NULL,
  `Address` varchar(255) DEFAULT NULL,
  `City` varchar(255) DEFAULT 'Beijing',
  PRIMARY KEY (`Id_P`),
  KEY `PersonIndex` (`LastName`,`FirstName`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Persons`
--

LOCK TABLES `Persons` WRITE;
/*!40000 ALTER TABLE `Persons` DISABLE KEYS */;
INSERT INTO `Persons` VALUES (1,'Gates','Bill','Xuanwumen 10','Beijing'),(2,'Carter','Thomas','Changan Street','Beijing'),(3,'Wilson','Thomas','Champs-Elysees','LA'),(4,'Bush','George','Fifth Avenue','New Yort'),(5,'Carter','William','Xuanwumen 10','Beijing'),(6,'Wilson','Fred','Zhongshan 23','Nanjing'),(7,'Adams','John','Oxford Street','London');
/*!40000 ALTER TABLE `Persons` ENABLE KEYS */;
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
