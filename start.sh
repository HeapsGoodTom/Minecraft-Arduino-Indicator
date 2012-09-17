while (true) do
echo Sending packet to arduino
echo -n `php run.php` > /dev/cu.usbmodem3d11
sleep 5
done
