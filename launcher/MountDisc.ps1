param([Parameter(Mandatory=$true)][string]$Iso)
$ErrorActionPreference='Stop'
$ProgressPreference='SilentlyContinue'
$discPath=(Resolve-Path -LiteralPath $Iso).Path
$image=Get-DiskImage -ImagePath $discPath -ErrorAction SilentlyContinue
$created=$false
if (!$image -or !$image.Attached) {
    try { $image=Mount-DiskImage -ImagePath $discPath -Access ReadOnly -PassThru; $created=$true }
    catch {
        $image=Get-DiskImage -ImagePath $discPath -ErrorAction SilentlyContinue
        if (!$image -or !$image.Attached) { throw }
    }
}
$letter=$null
for ($attempt=0; $attempt -lt 20 -and !$letter; $attempt++) {
    $letter=($image | Get-Volume).DriveLetter
    if (!$letter) { Start-Sleep -Milliseconds 200 }
}
if (!$letter) { throw 'The disc has no readable drive letter.' }
# Keep the read-only mount available: another agent may share it. Never eject
# an existing/owned mount behind a running game or repeatedly remount it.
@{root="${letter}:\";created=$created} | ConvertTo-Json -Compress
