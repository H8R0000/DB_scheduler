-- MySQL dump 10.13  Distrib 8.0.33, for Win64 (x86_64)
--
-- Host: 127.0.0.1    Database: students_db
-- ------------------------------------------------------
-- Server version	8.0.33

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
-- Table structure for table `laba`
--

DROP TABLE IF EXISTS `laba`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `laba` (
  `idlaba` mediumint unsigned NOT NULL AUTO_INCREMENT,
  `name` varchar(45) NOT NULL,
  `direction` char(4) NOT NULL,
  PRIMARY KEY (`idlaba`),
  UNIQUE KEY `name_UNIQUE` (`name`)
) ENGINE=InnoDB AUTO_INCREMENT=153 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `laba`
--

LOCK TABLES `laba` WRITE;
/*!40000 ALTER TABLE `laba` DISABLE KEYS */;
INSERT INTO `laba` VALUES (1,'Gauss1','TERM'),(2,'Gauss2','TERM'),(3,'Gauss3','TERM'),(4,'Gauss4','TERM'),(5,'Gauss5','TERM'),(6,'Gauss6','TERM'),(7,'Gauss7','TERM'),(8,'Gauss8','TERM'),(9,'Gauss9','TERM'),(10,'Gauss10','TERM'),(11,'Maxwell1','TERM'),(12,'Maxwell2','TERM'),(13,'Maxwell3','TERM'),(14,'Maxwell4','TERM'),(15,'Maxwell5','TERM'),(16,'Maxwell6','TERM'),(17,'Maxwell7','TERM'),(18,'Maxwell8','TERM'),(19,'Maxwell9','TERM'),(20,'Maxwell10','TERM'),(21,'Adiabata1','TERM'),(22,'Adiabata2','TERM'),(23,'Adiabata3','TERM'),(24,'Vyazkost1','TERM'),(25,'Vyazkost2','TERM'),(26,'Vyazkost3','TERM'),(27,'Vyazkost4','TERM'),(28,'Vyazkost5','TERM'),(29,'Paroobrazovanie1','TERM'),(30,'Paroobrazovanie2','TERM'),(31,'Paroobrazovanie3','TERM'),(32,'Fazovii_Perehod1','TERM'),(33,'Fazovii_Perehod2','TERM'),(34,'Fazovii_Perehod3','TERM'),(35,'Skorost_Sveta1','TERM'),(36,'Skorost_Sveta2','TERM'),(37,'Skorost_Sveta3','TERM'),(38,'Termopara1','TERM'),(39,'Termopara2','TERM'),(40,'Termopara3','TERM'),(41,'Idealnii_Gaz1','TERM'),(42,'Idealnii_Gaz2','TERM'),(43,'Idealnii_Gaz3','TERM'),(44,'Natyazhenie1','TERM'),(45,'Natyazhenie2','TERM'),(46,'Natyazhenie3','TERM'),(47,'Holodilnick_Peltie1','TERM'),(48,'Holodilnick_Peltie2','TERM'),(49,'Holodilnick_Peltie3','TERM'),(50,'Holodilnick_Peltie4','TERM'),(51,'Dlina1','MECH'),(52,'Dlina2','MECH'),(53,'Dlina3','MECH'),(54,'Dlina4','MECH'),(55,'Obyom1','MECH'),(56,'Obyom2','MECH'),(57,'Obyom3','MECH'),(58,'Obyom4','MECH'),(59,'Plotnost1','MECH'),(60,'Plotnost2','MECH'),(61,'Plotnost3','MECH'),(62,'Plotnost4','MECH'),(63,'Uprugost1','MECH'),(64,'Uprugost2','MECH'),(65,'Uprugost3','MECH'),(66,'Uprugost4','MECH'),(67,'Sluchaynie_Oshibki1','MECH'),(68,'Sluchaynie_Oshibki2','MECH'),(69,'Sluchaynie_Oshibki3','MECH'),(70,'Sluchaynie_Oshibki4','MECH'),(71,'Precesii1','MECH'),(72,'Precesii2','MECH'),(73,'Precesii3','MECH'),(74,'Precesii4','MECH'),(75,'Nutacii1','MECH'),(76,'Nutacii2','MECH'),(77,'Nutacii3','MECH'),(78,'Nutacii4','MECH'),(79,'Generator_toka1','MECH'),(80,'Generator_toka2','MECH'),(81,'Generator_toka3','MECH'),(82,'Generator_toka4','MECH'),(83,'Zakon_Newtona1','MECH'),(84,'Zakon_Newtona2','MECH'),(85,'Zakon_Newtona3','MECH'),(86,'Zakon_Newtona4','MECH'),(87,'Moment_inercii1','MECH'),(88,'Moment_inercii2','MECH'),(89,'Moment_inercii3','MECH'),(90,'Moment_inercii4','MECH'),(91,'Zakon_Oma1','ELEC'),(92,'Zakon_Oma2','ELEC'),(93,'Zakon_Oma3','ELEC'),(94,'Zakon_Oma4','ELEC'),(95,'Zakon_Kirhgofa1','ELEC'),(96,'Zakon_Kirhgofa2','ELEC'),(97,'Zakon_Kirhgofa3','ELEC'),(98,'Zakon_Kirhgofa4','ELEC'),(99,'Impedans1','ELEC'),(100,'Impedans2','ELEC'),(101,'Impedans3','ELEC'),(102,'Impedans4','ELEC'),(103,'Transformator1','ELEC'),(104,'Transformator2','ELEC'),(105,'Transformator3','ELEC'),(106,'Transformator4','ELEC'),(107,'Const_Faradeya1','ELEC'),(108,'Const_Faradeya2','ELEC'),(109,'Const_Faradeya3','ELEC'),(110,'Const_Faradeya4','ELEC'),(111,'Most_Tomsona1','ELEC'),(112,'Most_Tomsona2','ELEC'),(113,'Most_Tomsona3','ELEC'),(114,'Most_Tomsona4','ELEC'),(115,'Diod1','ELEC'),(116,'Diod2','ELEC'),(117,'Diod3','ELEC'),(118,'Diod4','ELEC'),(119,'Triod1','ELEC'),(120,'Triod2','ELEC'),(121,'Triod3','ELEC'),(122,'Triod4','ELEC'),(123,'Ferromagnetiki1','ELEC'),(124,'Ferromagnetiki2','ELEC'),(125,'Ferromagnetiki3','ELEC'),(126,'Ferromagnetiki4','ELEC'),(127,'DK1','ELEC'),(128,'DK2','ELEC'),(129,'DK3','ELEC'),(130,'DK4','ELEC'),(131,'Spectrometr1','OPT'),(132,'Spectrometr2','OPT'),(133,'Spectrometr3','OPT'),(134,'Spectrometr4','OPT'),(135,'Opt_system1','OPT'),(136,'Opt_system2','OPT'),(137,'Opt_system3','OPT'),(138,'Opt_system4','OPT'),(139,'Dyfrakciya_UltraZvuk1','OPT'),(140,'Dyfrakciya_UltraZvuk2','OPT'),(141,'Dyfrakciya_UltraZvuk3','OPT'),(142,'Dyfrakciya_UltraZvuk4','OPT'),(143,'Geom_Optika1','OPT'),(144,'Geom_Optika2','OPT'),(145,'Geom_Optika3','OPT'),(146,'Geom_Optika4','OPT'),(147,'Poglashenie_czveta1','OPT'),(148,'Poglashenie_czveta2','OPT'),(149,'Poglashenie_czveta3','OPT'),(150,'Poglashenie_czveta4','OPT'),(152,'шгрнеа','MECH');
/*!40000 ALTER TABLE `laba` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2023-04-27 10:11:06
