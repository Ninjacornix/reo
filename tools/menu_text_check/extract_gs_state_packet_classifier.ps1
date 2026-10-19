param([Parameter(Mandatory=$true)][string]$Source,[Parameter(Mandatory=$true)][string]$Output)
$ErrorActionPreference='Stop'
$text=[System.IO.File]::ReadAllText($Source)
$start=$text.IndexOf('    // GS_STATE_PACKET_CLASSIFIER_BEGIN')
$end=$text.IndexOf('    // GS_STATE_PACKET_CLASSIFIER_END')
if($start -lt 0 -or $end -le $start){throw 'Private classifier extraction markers missing or unordered'}
[System.IO.File]::WriteAllText($Output,$text.Substring($start,$end-$start),[System.Text.UTF8Encoding]::new($false))
