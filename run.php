<?php
/**
 * MC-Server-Status:
 * Server Online or Offline
 **/

// Include MC-SS Class
include('MinecraftStatus.class.php');
// Create a new Server Object
$Server = new MinecraftStatus('94.170.234.60');
echo $Server->Online ? '1' : '0';
?>
