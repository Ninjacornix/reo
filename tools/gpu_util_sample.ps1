# Samples total 3D-engine GPU utilisation (sum over processes) and the game's share
# once per second for N seconds; writes CSV. Usage: gpu_util_sample.ps1 -Seconds 200 -Out file.csv
param([int]$Seconds = 200, [Parameter(Mandatory)][string]$Out)
"t,total3d,game3d" | Set-Content -Encoding ascii $Out
for ($i = 0; $i -lt $Seconds; $i++) {
    $game = (Get-Process reo_recomp* -ErrorAction SilentlyContinue | Select-Object -First 1).Id
    $s = (Get-Counter '\GPU Engine(*engtype_3D)\Utilization Percentage' -ErrorAction SilentlyContinue).CounterSamples
    $total = ($s | Measure-Object CookedValue -Sum).Sum
    $g = if ($game) { ($s | Where-Object { $_.InstanceName -match "pid_${game}_" } | Measure-Object CookedValue -Sum).Sum } else { 0 }
    "{0},{1:N1},{2:N1}" -f $i, $total, $g | Add-Content -Encoding ascii $Out
    Start-Sleep -Milliseconds 700
}
