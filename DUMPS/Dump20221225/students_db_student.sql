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
  `spec` varchar(45) DEFAULT NULL,
  `group_name` varchar(45) DEFAULT NULL,
  PRIMARY KEY (`id_st`),
  UNIQUE KEY `st_UNIQUE` (`st`),
  KEY `gr_idx` (`id_group`) /*!80000 INVISIBLE */,
  KEY `fk_labg_idx` (`id_labg`),
  CONSTRAINT `fk_labg` FOREIGN KEY (`id_labg`) REFERENCES `lab group` (`id_lg`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `gr` FOREIGN KEY (`id_group`) REFERENCES `group` (`id_g`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=75 DEFAULT CHARSET=utf8mb3;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `student`
--

LOCK TABLES `student` WRITE;
/*!40000 ALTER TABLE `student` DISABLE KEYS */;
INSERT INTO `student` VALUES (24,'Karim0','Niggma0','Vladov0','st010900',1,1,NULL,'FZ','19.B05'),(25,'Karim1','Niggma1','Vladov1','st010901',1,1,NULL,'FZ','19.B05'),(26,'Karim2','Niggma2','Vladov2','st010902',1,1,NULL,'FZ','19.B05'),(27,'Karim3','Niggma3','Vladov3','st010903',1,1,NULL,'FZ','19.B05'),(28,'Karim4','Niggma4','Vladov4','st010904',1,1,NULL,'FZ','19.B05'),(29,'Karim5','Niggma5','Vladov5','st010905',1,1,NULL,'FZ','19.B05'),(30,'Karim6','Niggma6','Vladov6','st010906',0,1,NULL,'FZ','19.B05'),(31,'Karim7','Niggma7','Vladov7','st010907',1,1,NULL,'FZ','19.B05'),(32,'Karim8','Niggma8','Vladov8','st010908',1,1,NULL,'FZ','19.B05'),(33,'Karim9','Niggma9','Vladov9','st010909',1,2,NULL,'PMF','19.B21'),(34,'Karim10','Niggma10','Vladov10','st010010',1,2,NULL,'PMF','19.B21'),(35,'Karim11','Niggma11','Vladov11','st010011',1,2,NULL,'PMF','19.B21'),(36,'Karim12','Niggma12','Vladov12','st010012',1,2,NULL,'PMF','19.B21'),(37,'Karim13','Niggma13','Vladov13','st010013',1,2,NULL,'PMF','19.B21'),(38,'Karim14','Niggma14','Vladov14','st010014',1,2,NULL,'PMF','19.B21'),(39,'Karim15','Niggma15','Vladov15','st010015',1,2,NULL,'PMF','19.B21'),(40,'Karim16','Niggma16','Vladov16','st010016',0,2,NULL,'PMF','19.B21'),(41,'Karim17','Niggma17','Vladov17','st010017',1,2,NULL,'PMF','19.B21'),(42,'Karim18','Niggma18','Vladov18','st010018',1,2,NULL,'PMF','19.B21'),(43,'Karim19','Niggma19','Vladov19','st010019',1,2,NULL,'PMF','19.B21'),(44,'Karim20','Niggma20','Vladov20','st010020',1,2,NULL,'PMF','19.B21'),(45,'Karim21','Niggma21','Vladov21','st010021',1,2,NULL,'PMF','19.B21'),(46,'Karim22','Niggma22','Vladov22','st010022',1,2,NULL,'PMF','19.B21'),(47,'Karim23','Niggma23','Vladov23','st010023',1,3,NULL,'ASTRO','19.B20'),(48,'Karim24','Niggma24','Vladov24','st010024',1,3,NULL,'ASTRO','19.B20'),(49,'Karim25','Niggma25','Vladov25','st010025',1,3,NULL,'ASTRO','19.B20'),(50,'Karim26','Niggma26','Vladov26','st010026',1,3,NULL,'ASTRO','19.B20'),(51,'Karim27','Niggma27','Vladov27','st010027',1,3,NULL,'ASTRO','19.B20'),(52,'Karim28','Niggma28','Vladov28','st010028',1,3,NULL,'ASTRO','19.B20'),(53,'Karim29','Niggma29','Vladov29','st010029',1,3,NULL,'ASTRO','19.B20'),(54,'Karim30','Niggma30','Vladov30','st010030',1,3,NULL,'ASTRO','19.B20'),(55,'Karim31','Niggma31','Vladov31','st010031',1,3,NULL,'ASTRO','19.B20'),(56,'Karim32','Niggma32','Vladov32','st010032',1,3,NULL,'ASTRO','19.B20'),(57,'Karim33','Niggma33','Vladov33','st010033',1,3,NULL,'ASTRO','19.B20'),(58,'Karim34','Niggma34','Vladov34','st010034',1,3,NULL,'ASTRO','19.B20'),(59,'Karim35','Niggma35','Vladov35','st010035',1,3,NULL,'ASTRO','19.B20'),(60,'Karim36','Niggma36','Vladov36','st010036',1,4,NULL,'CHUM','19.B18'),(61,'Karim37','Niggma37','Vladov37','st010037',1,4,NULL,'CHUM','19.B18'),(62,'Karim38','Niggma38','Vladov38','st010038',1,4,NULL,'CHUM','19.B18'),(63,'Karim39','Niggma39','Vladov39','st010039',1,4,NULL,'CHUM','19.B18'),(64,'Karim40','Niggma40','Vladov40','st010040',1,4,NULL,'CHUM','19.B18'),(65,'Karim41','Niggma41','Vladov41','st010041',1,4,NULL,'CHUM','19.B18'),(66,'Karim42','Niggma42','Vladov42','st010042',0,4,NULL,'CHUM','19.B18'),(67,'Karim43','Niggma43','Vladov43','st010043',1,4,NULL,'CHUM','19.B18'),(68,'Karim44','Niggma44','Vladov44','st010044',1,4,NULL,'CHUM','19.B18'),(69,'Karim45','Niggma45','Vladov45','st010045',1,4,NULL,'CHUM','19.B18'),(70,'Karim46','Niggma46','Vladov46','st010046',1,4,NULL,'CHUM','19.B18'),(71,'Karim47','Niggma47','Vladov47','st010047',1,4,NULL,'CHUM','19.B18'),(72,'Karim48','Niggma48','Vladov48','st010048',1,4,NULL,'CHUM','19.B18'),(73,'Karim49','Niggma49','Vladov49','st010049',1,4,NULL,'CHUM','19.B18');
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

-- Dump completed on 2022-12-25 19:17:52
