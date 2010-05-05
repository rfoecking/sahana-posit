<?php
require_once('model/dao.php');
require_once('model/Model.php');
require_once('view/display.inc');
include_once $global['approot'] . "/inc/lib_menu.inc";
global $global;
global $dao;
$dao = new DAO($global["db"]);


function shn_posit_default()
{
   _posit_default();
}

function shn_posit_receive()
{
	global $dao;
	$dao->saveFind($_REQUEST['guid'],$_REQUEST['projectId'],$_REQUEST['description'],$_REQUEST['barcodeId'],$_REQUEST['name'],
	$_REQUEST['latitude'],$_REQUEST['longitude'],$_REQUEST['revision'],$_REQUEST['imei']);
}

function shn_posit_show()
{
	_posit_show();
}

function shn_posit_details()
{
	$id = $_REQUEST['id'];
	_posit_details($id);

}

function shn_posit_mainmenu()
{
    global $global;
    $module = $global['module'];

    shn_mod_menuopen("POSIT");
    shn_mod_menuitem("default","Home");
    shn_mod_menuitem("show","View All Finds");

    shn_mod_menuclose();

    include $global['approot']."/inc/handler_mainmenu.inc";
}


?>

