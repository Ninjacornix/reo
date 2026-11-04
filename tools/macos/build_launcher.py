#!/usr/bin/env python3
"""Bundle the native game and real Mac launcher; no original assets enter the app."""
import argparse
import hashlib
import json
import os
from pathlib import Path
import shutil
import subprocess
import sys

ROOT=Path(__file__).resolve().parents[2]

def run(*args,**kwargs):
    print('+',' '.join(map(str,args)),flush=True)
    subprocess.run(list(map(str,args)),check=True,**kwargs)

def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--build',type=Path,default=ROOT/'build-macos')
    args=parser.parse_args();build=args.build.resolve()
    python=build/'launcher-env/bin/python'
    if not python.is_file():
        raise SystemExit('Create launcher-env and install launcher/macos/requirements.txt first (see docs/MACOS.md).')
    record=json.loads((build/'macos-build.json').read_text())
    payload=build/'launcher-payload';payload.mkdir(exist_ok=True)
    native=payload/'native';native.mkdir(exist_ok=True)
    artwork=payload/'artwork';artwork.mkdir(exist_ok=True)
    shutil.copy2(ROOT/'launcher/Assets/app-icon.png',artwork/'app-icon.png')
    iconset=build/'Outbreak.iconset';iconset.mkdir(exist_ok=True)
    for points in (16,32,128,256,512):
        for density,suffix in ((1,''),(2,'@2x')):
            run('sips','-z',points*density,points*density,artwork/'app-icon.png','--out',iconset/f'icon_{points}x{points}{suffix}.png',stdout=subprocess.DEVNULL)
    run('iconutil','--convert','icns','--output',build/'Outbreak.icns',iconset)
    shutil.copy2(record['executable'],native/'reo_recomp')
    shutil.copytree(Path(record['executable']).parent/'reo-gpu-present',native/'reo-gpu-present',dirs_exist_ok=True)
    sys.path.insert(0,str(ROOT/'tools/macos'))
    from play import molten_library
    from package_app import replace_copy
    replace_copy(molten_library(),native/'libMoltenVK.dylib')
    helper=build/'asset-helper/AssetHelper'
    if not helper.is_file():
        run('dotnet','publish',ROOT/'launcher/macos/asset_helper/AssetHelper.csproj','-c','Release','-r','osx-arm64','--self-contained','true','-o',helper.parent)
    tools=payload/'tools';tools.mkdir(exist_ok=True)
    replace_copy(helper,tools/'AssetHelper')
    run('clang++','-fobjc-arc',ROOT/'launcher/macos/keychain.mm','-framework','Foundation','-framework','Security','-o',tools/'AccountKeychain')
    source=build/'opensnap-source'
    if not (source/'run.py').is_file():
        raise SystemExit('Prepare the pinned openSNAP server as documented before packaging.')
    server=payload/'server'
    shutil.copytree(source,server,dirs_exist_ok=True,ignore=shutil.ignore_patterns('.git','__pycache__','.pytest_cache','tests','.env','*.pyc'))
    licences=payload/'licenses';licences.mkdir(exist_ok=True)
    for directory in (build/'launcher-env/lib').glob('python*/site-packages/*.dist-info/licenses'):
        shutil.copytree(directory,licences/directory.parent.name,dirs_exist_ok=True)
    shutil.copy2(ROOT/'LICENSE',licences/'OutbreakRecomp-COPYING')
    shutil.copy2(source/'LICENSE',licences/'openSNAP-COPYING')
    for name,folder in [('MoltenVK',Path(molten_library()).resolve().parent.parent),('Granite',build/'parallel-gs-source/Granite'),('parallel-gs',build/'parallel-gs-source')]:
        for filename in ('LICENSE','LICENSE.md','LICENSE.txt'):
            if (folder/filename).is_file():
                shutil.copy2(folder/filename,licences/(name+'-LICENSE'));break
    record.update(executable='native/reo_recomp',driver='native/libMoltenVK.dylib',
                  sourceRoot=str(ROOT),buildRoot=str(build),python='/opt/homebrew/bin/python3')
    (payload/'mac-launcher.json').write_text(json.dumps(record,indent=2))
    args=[python,'-m','PyInstaller','--noconfirm','--clean','--onedir','--windowed',
        '--name','RE Outbreak RC1','--osx-bundle-identifier','net.ninjacornix.reo.rc1',
        '--target-arch','arm64','--icon',build/'Outbreak.icns','--distpath',build/'launcher','--workpath',build/'launcher-pyinstaller',
        '--specpath',build/'launcher-spec','--paths',ROOT/'launcher/macos',
        '--paths',ROOT/'tools/local_build','--paths',ROOT/'tools','--paths',server,
        '--hidden-import','import_iso','--hidden-import','mods','--hidden-import','services',
        '--hidden-import','validation','--collect-all','cryptography']
    for module in ('opensnap','opensnap_app','opensnap_web','opensnap_dns'):
        args.extend(['--collect-submodules',module])
    for name in ('native','tools','server','licenses','artwork'):
        args.extend(['--add-data',str(payload/name)+':'+name])
    args.extend(['--add-data',str(payload/'mac-launcher.json')+':.',ROOT/'launcher/macos/main.py'])
    environment=dict(os.environ)
    environment['PYTHONPATH']=str(server)
    run(*args,env=environment)
    app=build/'launcher/RE Outbreak RC1.app'
    contents=app/'Contents'
    # PyInstaller re-signs Mach-O payloads. Record their final, bundled hash.
    target=contents/'Resources/mac-launcher.json'
    final=json.loads(target.read_text())
    bundled=contents/'Resources/native/reo_recomp'
    final['executableSha256']=hashlib.file_digest(bundled.open('rb'),'sha256').hexdigest()
    target.write_text(json.dumps(final,indent=2))
    import plistlib
    plist=contents/'Info.plist'
    with plist.open('rb') as stream:metadata=plistlib.load(stream)
    metadata.update(CFBundleShortVersionString='1.0.20',CFBundleVersion='2',NSHighResolutionCapable=True,
        NSHumanReadableCopyright='OutbreakRecomp contributors. Local build from your own disc.',
        NSLocalNetworkUsageDescription='Discover and connect to Outbreak co-op servers on your local network.')
    with plist.open('wb') as stream:plistlib.dump(metadata,stream)
    run('codesign','--force','--sign','-',app)
    run('codesign','--verify','--deep','--strict',app)
    alias=build/'RE Outbreak RC1.app'
    if not alias.exists() and not alias.is_symlink():
        alias.symlink_to(Path('launcher')/'RE Outbreak RC1.app',target_is_directory=True)
    print('Mac launcher:',app)

if __name__=='__main__':main()
