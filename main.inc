<?php
require_once('model/dao.php');
require_once('model/Model.php');
global $global;
$dao = new DAO();


function shn_posit_default()
{
   print "<p>Hello World!</p>";
}

function shn_posit_receive()
{
	global $dao;
	$dao->saveFind($_REQUEST['guid'],$_REQUEST['projectId'],$_REQUEST['description'],$_REQUEST['barcodeId'],$_REQUEST['name'],
	$_REQUEST['latitude'],$_REQUEST['longitude'],$_REQUEST['revision'],$_REQUEST['imei']);
   print "did it work: " . $name;
   print "<p> Received! </p>";
   print "<p>Imei: " . $_REQUEST['imei'] . "</p>";
   print "<p>Guid: " . $_REQUEST['guid'] . "</p>";
   print "<p>Name: " . $_REQUEST['name'] . "</p>";
   print "<p>Description: " . $_REQUEST['description'] . "</p>";
   print "<p>Latitude: " . $_REQUEST['latitude'] . "</p>";
   print "<p>Longitude: " . $_REQUEST['longitude'] . "</p>";
   print "<p>Revision: " . $_REQUEST['revision'] . "</p>";

}

function shn_posit_show()
{
   global $global;
   $db=$global["db"];
   $sql = "SELECT * FROM `posit_find`";
   $result = $db->execute($sql);

   while(!$result->EOF)
    {
 	print $result->fields['name'];
 	$result->MoveNext();
    }


}

?>

