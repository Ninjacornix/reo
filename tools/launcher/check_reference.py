#!/usr/bin/env python3
"""Check that the common view retains the selected Windows RC1 reference."""
from pathlib import Path
import hashlib,json,xml.etree.ElementTree as ET
root=Path(__file__).resolve().parents[2]
reference=json.loads((root/'launcher/desktop/Views/Shell.reference.json').read_text())
x='{http://schemas.microsoft.com/winfx/2006/xaml}'
original=ET.parse(root/'launcher/Shell.xaml');common=ET.parse(root/'launcher/desktop/Views/Shell.axaml')
names=lambda tree:{node.get(x+'Name'):node for node in tree.iter() if node.get(x+'Name')}
old,new=names(original),names(common)
# Avalonia transforms are not named controls; the toast offset uses RenderTransform.
old.pop("StatusToastOffset",None)
assert not old.keys()-new.keys(),f'Missing RC1 controls: {old.keys()-new.keys()}'
for source,digest in reference['sourceSha256'].items():assert hashlib.sha256((root/'launcher'/source).read_bytes()).hexdigest()==digest,f'Reference changed: {source}'
for name in reference['actions']:assert name in new,f'Command source missing: {name}'
pages=[name for name in old if name.startswith('Page') and name!='PageContent']
assert len(pages)==12
for name in pages:
    oldtext=[node.get('Text') for node in old[name].iter() if node.get('Text')]
    newtext=[node.get('Text') for node in new[name].iter() if node.get('Text')]
    assert oldtext==newtext,f'RC1 page copy/order changed: {name}'
print(json.dumps(dict(passed=True,reference=reference['reference'],namedControls=len(old),pages=len(pages),actionSources=len(reference['actions']))))
