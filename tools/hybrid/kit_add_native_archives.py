"""Post-process a refreshed hybrid kit: per-unit defines + prebuilt native archives.

usage: hybrid_kit_libs.py KIT ARCHIVE_ROOT ARCHIVE_LIST DEFINE UNIT [UNIT ...]
  KIT           refreshed kit directory (modified in place, manifest resealed)
  ARCHIVE_ROOT  native CMake build directory holding the .a files
  ARCHIVE_LIST  text file, one archive path per line, relative to ARCHIVE_ROOT
  DEFINE        e.g. REO_BUILD_NATIVE_ROOM_CAMERA=1
  UNIT          repository-relative source whose compile unit gets /D<DEFINE>
"""
import hashlib, json, shutil, sys
from pathlib import Path


def sha(path):
    with open(path, 'rb') as f:
        return hashlib.file_digest(f, 'sha256').hexdigest()


kit, root, listing, define, units = Path(sys.argv[1]), Path(sys.argv[2]), Path(sys.argv[3]), sys.argv[4], sys.argv[5:]
manifest = json.loads((kit / 'build-kit.json').read_text())
plan_path = kit / 'compile-plan.json'
plan = json.loads(plan_path.read_text())

option = '/D' + define
for name in units:
    matches = [u for u in plan['units'] if '{work}/project/' + name in u['sources']]
    if len(matches) != 1:
        raise SystemExit(f'expected one unit for {name}, found {len(matches)}')
    if option not in matches[0]['options']:
        matches[0]['options'].append(option)

target_dir = kit / 'libraries/native'
target_dir.mkdir(parents=True, exist_ok=True)
existing = {item['path'] for item in plan['independentInputs']}
for line in listing.read_text().splitlines():
    rel = line.strip()
    if not rel:
        continue
    source = root / rel
    name = rel.replace('/', '__')
    target = target_dir / name
    shutil.copyfile(source, target)
    entry = '{kit}/libraries/native/' + name
    if entry not in existing:
        plan['independentInputs'].append({'path': entry, 'sha256': sha(target), 'provenance': 'authored-runtime'})
plan_path.write_text(json.dumps(plan, indent=2) + '\n', encoding='utf-8')

manifest['files'] = [{'path': p.relative_to(kit).as_posix(), 'sha256': sha(p)}
                     for p in sorted(kit.rglob('*')) if p.is_file() and p.name != 'build-kit.json']
(kit / 'build-kit.json').write_text(json.dumps(manifest, indent=2) + '\n')
print(json.dumps({'units': units, 'archives': len(list(target_dir.iterdir())),
                  'kitSha256': sha(kit / 'build-kit.json')}))
