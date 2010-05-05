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
 		//if(debug_show_queries)
 		//{
 		//	global $query_count;
 		//	echo (++$query_count). " $query<br />\n";
 		//}
 		return $this->db->Execute($query);
 	}
	function saveFind($guid, $projectId, $description, $barcode_id, $name, $latitude, $longitude, $revision, $imei)
	{
		$sql="INSERT INTO `posit_find` ( `id` , `project_id` , `description` , `barcode_id` , `name` , `add_time` , `modify_time` , `latitude` ,
		`longitude` , `revision` , `imei` )
		VALUES (
		'" . $guid . "', '" . $projectid . "', '" . $description . "', '" . $barcode_id . "',
		'" . $name . "', '', '', '" . $latitude . "', '" . $longitude . "', '" . $revision . "', 
		'" . $imei . "')";
		$result = $this->execute($sql);
	}
	function getAllFinds()
	{
		$sql = "SELECT * FROM `posit_find`";
		$result = $this->execute($sql);
		while(!$result->EOF)
 		{
 			$finds['id'][] = $result->fields['id'];
			$finds['projectId'][] = $result->fields['project_id'];
			$finds['description'][] = $result->fields['description'];
			$finds['barcodeId'][] = $result->fields['barcode_id'];
			$finds['name'][] = $result->fields['name'];
			$finds['latitude'][] = $result->fields['latitude'];
			$finds['longitude'][] = $result->fields['longitude'];
			$finds['revision'][] = $result->fields['revision'];
			$finds['imei'][] = $result->fields['imei'];
 			$result->moveNext();
 		}
		return $finds;
	}
function getFind($id)
	{
		$sql = "SELECT * FROM `posit_find` where id = " . $id;
		$result = $this->execute($sql);
		//$result->moveNext();
 		$find['id'] = $result->fields['id'];
		$find['projectId'] = $result->fields['project_id'];
		$find['description'] = $result->fields['description'];
		$find['barcodeId']= $result->fields['barcode_id'];
		$find['name']= $result->fields['name'];
		$find['latitude'] = $result->fields['latitude'];
		$find['longitude'] = $result->fields['longitude'];
		$find['revision'] = $result->fields['revision'];
		$find['imei'] = $result->fields['imei'];
		return $find;
	}
}
