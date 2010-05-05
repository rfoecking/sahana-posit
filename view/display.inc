
<?php
include_once $global['approot'] . 'mod/posit/model/Model.php';
include_once $global['approot'] . 'mod/posit/model/dao.php';
global $global;
global $dao;
$dao = new DAO($global["db"]);
function _posit_show()
{
?>
<h2>View all finds</h2>
<div id="result">
	<table>
		<thead>
			<td>Name</td>
			<td>ID</td>
			<td>Description</td>
			<td>Barcode</td>
			<td>Latitude</td>
			<td>Longitude</td>
			<td>Revision</td>
			<td>Imei</td>
		</thead>
<?php
	global $dao;
	$finds =  $dao->getAllFinds();
	$counter = 0;
	while($counter!=count($finds,1)/count($finds,0)-1)
	{
?>
		<tr>
		<td><a href="index.php?mod=posit&act=details&id=<?= $finds['id'][$counter]?>">
		<?= $finds['name'][$counter] ?></a> </td>
		<td><?=$finds['id'][$counter] ?></td>
		<td><?=$finds['description'][$counter] ?> </td>
		<td><?= $finds['barcodeId'][$counter] ?></td>
		<td><?=$finds['latitude'][$counter] ?></td>
		<td><?= $finds['longitude'][$counter] ?> </td>
		<td><?= $finds['revision'][$counter] ?> </td>
		<td><?=$finds['imei'][$counter]?> </td>
		</tr>	
<?php
	$counter = $counter + 1;
	}
?>
	</table>
</div>
</body>
</html>
<?php
}

function _posit_details($id) 
{
	global $dao;
	$find =  $dao->getFind($id);
?>
<h2> Find Details </h2>
<?php
	shn_form_fopen("",null);
	shn_form_fsopen($find['name']);
	shn_form_label("Name",$find['name']);
	shn_form_label("ID",$find['id']);
	shn_form_label("Description",$find['description']);
	shn_form_label("Barcode",$find['barcodeId']);
	shn_form_label("Latitude",$find['latitude']);
	shn_form_label("Longitude",$find['longitude']);
	shn_form_label("Revision",$find['revision']);
	shn_form_label("Imei",$find['imei']);
	shn_form_fsopen("Map");
	?>
	<center>
	<img src="http://maps.google.com/maps/api/staticmap?zoom=14&size=256x256&markers=color:red|<?=$find['latitude']?>,<?=$find['longitude']?>&sensor=false&key=ABQIAAAAl-U6nA2OYa7Leg_UhWuVUxQUUPPMqhoyC21Cn56cdmhTku0sORSY3akrTXsbapNrjdZ_qCh8JQn0vA"/>
	</center>


<?php
}

function _posit_default() 
{
?>
<h2> POSIT Module </h2>
<h3> Description </h3>
	<p> Welcome to the POSIT module.  This module allows communication between Sahana and a little app called
	<a href="http://posit.hfoss.org"> POSIT.</a>  
	</p>
<h3> Things you can do </h3>
	<ul>
		<li><a href="index.php?mod=posit&act=show">View all finds</a></li>
	</ul>
<?php

}
?>

