<?php
require_once('model/dao.php');
require_once('model/Model.php');
global $global;
global $dao;
$dao = new DAO($global["db"]);


function shn_posit_default()
{
   print "<p>Hello World!</p>";
}

function shn_posit_receive()
{
	global $dao;
	$dao->saveFind($_REQUEST['guid'],$_REQUEST['projectId'],$_REQUEST['description'],$_REQUEST['barcodeId'],$_REQUEST['name'],
	$_REQUEST['latitude'],$_REQUEST['longitude'],$_REQUEST['revision'],$_REQUEST['imei']);
}

function shn_posit_show()
{
	global $dao;
	$finds =  $dao->getAllFinds();
	$counter = 0;
	while($counter!=count($finds,1)/count($finds,0)-1)
	{
		print "<p><strong>Name: " .  $finds['name'][$counter] . "</strong></p>";
		print "<p>ID: " .  $finds['id'][$counter] . "</p>";
		print "<p>Description: " .  $finds['description'][$counter] . "</p>";
		print "<p>Barcode: " .  $finds['barcodeId'][$counter] . "</p>";
		print "<p>Latitude: " . $finds['latitude'][$counter] . "</p>";
		print "<p>Longitude: " .  $finds['longitude'][$counter] . "</p>";
		print "<p>Revision: " .  $finds['revision'][$counter] . "</p>";
		print "<p>Imei: " . $finds['imei'][$counter] . "</p>";
		$counter = $counter + 1;
	}
}

?>

