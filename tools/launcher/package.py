#!/usr/bin/env python3
"""Publish the common RC1 launcher. Mac packaging also bundles native services/game.
Windows/Linux publish the same UI; their native game payload must be built on that OS.
"""
import argparse,json,os,platform,plistlib,shutil,subprocess,sys
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
def run(*args,**kw):
    print('+',' '.join(map(str,args)),flush=True)
    subprocess.run([str(a) for a in args],check=True,**kw)
def copy(source,target):
    target=Path(target);target.parent.mkdir(parents=True,exist_ok=True)
    temporary=target.with_name(target.name+'.new');shutil.copy2(source,temporary);temporary.replace(target)
def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--runtime',default={'Darwin':'osx','Windows':'win','Linux':'linux'}[platform.system()]+'-'+('arm64' if platform.machine() in ('arm64','aarch64') else 'x64'))
    parser.add_argument('--publish-only',action='store_true')
    parser.add_argument('--reuse-services',action='store_true',help='Reuse an already frozen, unchanged service worker')
    args=parser.parse_args();build=ROOT/'build-macos';stage=ROOT/'build-launcher'/args.runtime
    run('dotnet','publish',ROOT/'launcher/desktop/Reo.Launcher.Desktop.csproj','-c','Release','-r',args.runtime,'--self-contained','true','-o',stage)
    if args.publish_only:return
    if platform.system()!='Darwin' or not args.runtime.startswith('osx-'):
        raise SystemExit('Managed launcher published. Assemble native game/services on the target OS; see docs/SHARED-LAUNCHER.md.')
    source=build/'opensnap-source';python=build/'launcher-env/bin/python'
    if not (source/'run.py').is_file() or not python.exists():raise SystemExit('Prepare openSNAP and launcher-env using docs/MACOS.md first.')
    payload=build/'common-service-payload';payload.mkdir(exist_ok=True)
    shutil.copytree(source,payload/'server',dirs_exist_ok=True,ignore=shutil.ignore_patterns('.git','__pycache__','*.pyc','tests','.env'))
    command=[python,'-m','PyInstaller','--noconfirm','--clean','--onedir','--name','Reo.Services','--distpath',build/'common-services','--workpath',build/'common-service-work','--specpath',build/'common-service-spec','--paths',source,'--collect-all','cryptography']
    for module in ('opensnap','opensnap_app','opensnap_web','opensnap_dns'):command+=['--collect-submodules',module]
    command+=['--add-data',str(payload/'server')+':server','--add-binary','/opt/homebrew/bin/ffmpeg:tools',ROOT/'network/server/worker.py']
    if not args.reuse_services:run(*command,env={**os.environ,'PYTHONPATH':str(source)})
    app=build/'common-launcher/RE Outbreak RC1.app';contents=app/'Contents';entry=contents/'MacOS';resources=contents/'Resources';mac=resources/'launcher'

    if app.exists():shutil.rmtree(app)
    mac.mkdir(parents=True,exist_ok=True);entry.mkdir(parents=True,exist_ok=True)
    shutil.copytree(stage,mac,dirs_exist_ok=True)
    tools=mac/'tools';tools.mkdir(exist_ok=True)
    shutil.copytree(build/'common-services/Reo.Services',tools/'Reo.Services',dirs_exist_ok=True,symlinks=True)
    run('clang++','-fobjc-arc','-mmacosx-version-min=14.0',ROOT/'launcher/macos/keychain.mm','-framework','Foundation','-framework','Security','-o',tools/'AccountKeychain')
    run('clang++','-std=c++17','-dynamiclib','-fobjc-arc','-mmacosx-version-min=14.0',ROOT/'launcher/desktop/Platform/controllers_macos.mm','-framework','AppKit','-framework','GameController','-framework','CoreHaptics','-o',mac/'libReo.Platform.dylib')
    record=json.loads((build/'macos-build.json').read_text());native=mac/'native';native.mkdir(exist_ok=True)
    copy(record['executable'],native/'reo_recomp')
    shutil.copytree(Path(record['executable']).parent/'reo-gpu-present',native/'reo-gpu-present',dirs_exist_ok=True)
    sys.path.insert(0,str(ROOT/'tools/macos'));from play import molten_library
    copy(molten_library(),native/'libMoltenVK.dylib')
    record.update(executable='native/reo_recomp',driver='native/libMoltenVK.dylib')
    (mac/'native-build.json').write_text(json.dumps(record,indent=2))
    (mac/'platform-services.json').write_text(json.dumps({'server':{'executable':'tools/Reo.Services/Reo.Services','source':'tools/Reo.Services/_internal/server'},'ffmpeg':'tools/Reo.Services/_internal/tools/ffmpeg'},indent=2))
    licences=resources/'licenses';licences.mkdir(exist_ok=True)
    copy(ROOT/'LICENSE',licences/'OutbreakRecomp-COPYING');copy(source/'LICENSE',licences/'openSNAP-COPYING')
    for directory in (build/'launcher-env/lib').glob('python*/site-packages/*.dist-info/licenses'):shutil.copytree(directory,licences/directory.parent.name,dirs_exist_ok=True)
    ffmpeg=Path('/opt/homebrew/opt/ffmpeg');
    for filename in ('COPYING.GPLv2','COPYING.GPLv3','LICENSE.md','LICENSE'):
        if (ffmpeg/filename).exists():copy(ffmpeg/filename,licences/('FFmpeg-'+filename))
    if (build/'Outbreak.icns').exists():copy(build/'Outbreak.icns',resources/'Outbreak.icns')
    with (contents/'Info.plist').open('wb') as stream:plistlib.dump(dict(CFBundleExecutable='Outbreak.Launcher',CFBundleIdentifier='net.ninjacornix.reo.rc1',CFBundleName='RE Outbreak RC1',CFBundlePackageType='APPL',CFBundleShortVersionString='1.0.20',CFBundleVersion='3',CFBundleIconFile='Outbreak.icns',LSMinimumSystemVersion='14.0',NSHighResolutionCapable=True,NSLocalNetworkUsageDescription='Discover and connect to Outbreak co-op servers on your local network.'),stream)
    # Sign inner Mach-O files before signing the containing app.
    for path in mac.rglob('*'):
        if not path.is_file() or path.is_symlink():continue
        with path.open('rb') as stream:magic=stream.read(4)
        if magic in (b'\xcf\xfa\xed\xfe',b'\xfe\xed\xfa\xcf',b'\xca\xfe\xba\xbe',b'\xbe\xba\xfe\xca'):
            if subprocess.run(['codesign','--verify',str(path)],stdout=subprocess.DEVNULL,stderr=subprocess.DEVNULL).returncode!=0:run('codesign','--force','--sign','-',path,stdout=subprocess.DEVNULL,stderr=subprocess.DEVNULL)
    bootstrap=build/'common-launcher-bootstrap.c'
    bootstrap.write_text("#include <mach-o/dyld.h>\n#include <unistd.h>\n#include <limits.h>\n#include <stdio.h>\n#include <string.h>\nint main(int argc,char**argv){char p[PATH_MAX],target[PATH_MAX];uint32_t n=sizeof(p);if(_NSGetExecutablePath(p,&n))return 1;char*end=strrchr(p,'/');if(!end)return 1;*end=0;snprintf(target,sizeof(target),\"%s/../Resources/launcher/Outbreak.Launcher\",p);argv[0]=target;execv(target,argv);perror(\"Outbreak launcher\");return 1;}\n")
    run('clang','-mmacosx-version-min=14.0',bootstrap,'-o',entry/'Outbreak.Launcher')
    run('codesign','--force','--sign','-',app);run('codesign','--verify','--deep','--strict',app)
    print('Common launcher:',app)
if __name__=='__main__':main()
