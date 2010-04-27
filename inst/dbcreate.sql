-- --------------------------------------------------------

-- 
-- Table structure for table `posit_find`
-- 

CREATE TABLE `posit_find` (
  `id` mediumint(9) NOT NULL auto_increment,
  `project_id` int(11) NOT NULL,
  `description` varchar(100) NOT NULL,
  `barcode_id` varchar(32) default NULL,
  `name` varchar(32) NOT NULL,
  `add_time` datetime NOT NULL,
  `modify_time` datetime NOT NULL,
  `latitude` double NOT NULL,
  `longitude` double NOT NULL,
  `revision` int(11) NOT NULL,
  `imei` varchar(50) NOT NULL,
  PRIMARY KEY  (`id`),
  KEY `project_id` (`project_id`)
) ENGINE=MyISAM  DEFAULT CHARSET=latin1 AUTO_INCREMENT=16 ;

-- --------------------------------------------------------

