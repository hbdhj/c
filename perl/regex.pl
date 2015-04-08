#!/opt/tsdrd/bin/perl
$version = "C.05.70.00023";
#$version = "TSD.A97_SBM_MSS_System.0015";
if ($version !~ m/^(?:([A-Z]?)\.)?(\d+)(?:\.(\d+)(?:[\.-](.*))?)?$/io) 
{
    print"Invalid version string: '$version'\n";
	exit 1;
}
else
{
    print"Valid version string: '$version'\n";
}

$arch = $1;
$version = [$2, $3];
$release = $4;

print "'$arch', '$version', '$release'\n"