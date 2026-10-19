param([Parameter(Mandatory=$true)][string]$Cache)
$ErrorActionPreference = 'Stop'
[Net.ServicePointManager]::SecurityProtocol = [Net.SecurityProtocolType]::Tls12
$Cache = [IO.Path]::GetFullPath($Cache)
New-Item -ItemType Directory -Path $Cache -Force | Out-Null
$bootstrap = Join-Path $Cache ('vs-buildtools-' + [guid]::NewGuid().ToString('N') + '.exe')
# Only Microsoft's authenticated installer may install the compiler/Windows SDK.
# No unattended licence acceptance, automatic reboot, or compiler redistribution.
Invoke-WebRequest -Uri 'https://aka.ms/vs/17/release/vs_buildtools.exe' -OutFile $bootstrap -UseBasicParsing
$signature = Get-AuthenticodeSignature -LiteralPath $bootstrap
if ($signature.Status -ne 'Valid' -or $signature.SignerCertificate.Subject -notmatch '(^|,\s*)CN=Microsoft Corporation(,|$)') {
    throw 'Microsoft compiler installer signature verification failed.'
}
$installer = Start-Process -FilePath $bootstrap -ArgumentList @('--wait', '--norestart', '--add',
    'Microsoft.VisualStudio.Workload.VCTools', '--includeRecommended') -WindowStyle Normal -PassThru -Wait
exit $installer.ExitCode
