#!/usr/bin/env python3
"""Check the universal view against the preserved RC1/RC2 UI contract."""
from pathlib import Path
import json,xml.etree.ElementTree as ET
root=Path(__file__).resolve().parents[2]
reference=json.loads((root/'launcher/desktop/Views/Shell.reference.json').read_text())
x='{http://schemas.microsoft.com/winfx/2006/xaml}'
common=ET.parse(root/'launcher/desktop/Views/Shell.axaml')
controls={n.get(x+'Name'):n for n in common.iter() if n.get(x+'Name')}
missing=set(reference['requiredControls'])-controls.keys()
assert not missing,f'Missing launcher controls: {missing}'
for name in reference['actions']:assert name in controls,f'Command source missing: {name}'
assert len(reference['pageCopy'])==12
for page,copy in reference['pageCopy'].items():
    actual=[n.get('Text') for n in controls[page].iter() if n.get('Text')]
    assert actual==copy,f'Launcher page copy/order changed: {page}'
# A retirement must also update the entry points: do not retain a second WPF app.
assert not list((root/'launcher').glob('*.xaml')),'Retired WPF views are present'
assert not (root/'launcher/Reo.Launcher.csproj').exists(),'Retired WPF project is present'
for name in ['launcher/build.ps1','launcher/package-local.ps1','launcher/package-slim.ps1','tools/ci/windows.ps1']:
    assert 'desktop/Reo.Launcher.Desktop.csproj' in (root/name).read_text(),f'Wrong launcher build entry point: {name}'
print(json.dumps(dict(passed=True,reference=reference['reference'],namedControls=len(controls),pages=12,actionSources=len(reference['actions']),singleFrontend=True)))
