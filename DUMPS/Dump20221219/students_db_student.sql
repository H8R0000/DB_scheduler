CREATE DATABASE  IF NOT EXISTS `students_db` /*!40100 DEFAULT CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci */ /*!80016 DEFAULT ENCRYPTION='N' */;
USE `students_db`;
-- MySQL dump 10.13  Distrib 8.0.31, for Win64 (x86_64)
--
-- Host: 127.0.0.1    Database: students_db
-- ------------------------------------------------------
-- Server version	8.0.31

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `student`
--

DROP TABLE IF EXISTS `student`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `student` (
  `id_st` int NOT NULL AUTO_INCREMENT,
  `name` varchar(45) NOT NULL,
  `surname` varchar(45) NOT NULL,
  `patronymic` varchar(45) DEFAULT NULL,
  `st` varchar(45) NOT NULL,
  `alive` tinyint DEFAULT '1',
  `id_group` int DEFAULT NULL,
  `id_labg` int DEFAULT NULL,
  PRIMARY KEY (`id_st`),
  UNIQUE KEY `st_UNIQUE` (`st`),
  KEY `gr_idx` (`id_group`) /*!80000 INVISIBLE */,
  KEY `fk_labg_idx` (`id_labg`),
  CONSTRAINT `fk_labg` FOREIGN KEY (`id_labg`) REFERENCES `lab group` (`id_lg`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `gr` FOREIGN KEY (`id_group`) REFERENCES `group` (`id_g`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=14 DEFAULT CHARSET=utf8mb3;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `student`
--

LOCK TABLES `student` WRITE;
/*!40000 ALTER TABLE `student` DISABLE KEYS */;
INSERT INTO `student` VALUES (1,'Karimm1','Niggma1','Vladov1','st076348',1,1,NULL),(2,'Karimm2','Niggma2','vladov2','st076338',1,2,NULL),(3,'Karimm3','Niggma3','Vladov3','st076537',1,2,NULL),(4,'Karimm4','Niggma4','Vladov4','st052658',1,1,NULL),(6,'Karimm6','Niggma6','Vladov6','st053874',1,1,NULL),(7,'Karimm7','Niggma7','Vladov7','st023697',1,3,NULL),(8,'Karimm8','Niggma8','Vladov8','st024957',1,3,NULL),(9,'Rinat','Nizamov','Failevich','st076968',1,2,NULL),(12,'Vlad','Krasnikov','KArimovich','st076961',1,2,NULL),(13,'Atryom','Rymyantev','Sergeevich','st074359',1,1,NULL);
/*!40000 ALTER TABLE `student` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2022-12-19 12:33:25
