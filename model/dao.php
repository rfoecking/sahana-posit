<?php

/**
* Data Access Object
**/

/**
 * The DAO class is designed to handle the retrieval and manipulation
 * of information from the database.
 */

global $global;

 class DAO
 {
 	private $db;	//a reference to Sahana's database object

	/**
	 * Constructor that stores Sahana's object object
	 *
	 * @access public
	 * @param $db 	- reference to sahana's database
	 * @return void
	 */

 	function DAO(&$db)
 	{
 		$this->db = &$db;
 		$this->execute("set names 'utf8'");
 	}

	/**
	 * Performs queries to Sahana's database
	 *
	 * @access public
	 * @param $query 	- the query string
	 * @return an ADODB query result object
	 */

 	function execute($query)
 	{
 		//optionally show the query if desired
 		if(debug_show_queries)
 		{
 			global $query_count;
 			echo (++$query_count). " $query<br />\n";
 		}
 		return $this->db->Execute($query);
 	}
	function saveFind($guid, $projectId, $description, $barcode_id, $name, $latitude, $longitude, $revision, $imei)
	{
		global $global;
		$db=$global["db"];
		$sql="INSERT INTO `posit_find` ( `id` , `project_id` , `description` , `barcode_id` , `name` , `add_time` , `modify_time` , `latitude` ,
		`longitude` , `revision` , `imei` )
		VALUES (
		'" . $guid . "', '" . $projectid . "', '" . $description . "', '" . $barcode_id . "',
		'" . $name . "', '', '', '" . $latitude . "', '" . $longitude . "', '" . $revision . "', 
		'" . $imei . "')";
		$msg = $db->Execute($sql);
	}
}
