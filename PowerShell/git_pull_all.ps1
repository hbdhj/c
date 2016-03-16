[string[]]$array = "c_practice","hbdhj.github.io","documents", "maa\xcp", "maa\xplatform", "maa\xts"
#[string[]]$array = "c_practice","hbdhj.github.io","documents"
[Collections.Generic.List[String]]$lst = $array
foreach ($folder in $lst)
{
	echo("Now update "+$folder)
	$folder_list=$folder.split("\")
	[int]$up_times = @($folder_list).length
	cd $folder
	git pull
	while($up_times -gt 0)
	{
		cd ..
		$up_times=$up_times-1
	}
}