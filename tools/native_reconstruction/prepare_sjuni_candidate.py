#!/usr/bin/env python3
"""Create a separate SJUNI test input kit from a fully verified sealed File #1 SDK.

Preserves the SDK's coherent runtime/backend sources, libraries and game recipes.
Adds only the authored native SJUNI boundary and its optional registration. It
does not reuse a precompiled PS2 runtime, modify the input SDK/player build,
import game bytes or launch anything. Compile with the ordinary local worker.
"""
import argparse
import hashlib
import json
from pathlib import Path
import shutil

ROOT = Path(__file__).resolve().parents[2]
ELF_SHA = '06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46'
FILES = [
    'game/native/sjuni/sjuni.hpp', 'game/native/sjuni/sjuni.cpp',
    'game/native/sjuni_adapter/guest_image.h',
    'game/native/sjuni_adapter/queue_bridge.h', 'game/native/sjuni_adapter/queue_bridge.cpp',
    'recomp/overrides/native_sjuni/runtime_adapter.h',
    'recomp/overrides/native_sjuni/runtime_adapter.cpp',
    'recomp/overrides/native_geometry/reo_vu_native_sha256.h',
]
UNITS = [
    ('native_sjuni_core', FILES[1]),
    ('native_sjuni_wire_bridge', FILES[4]),
    ('native_sjuni_runtime_adapter', FILES[6]),
]


def sha(path):
    with path.open('rb') as stream:
        return hashlib.file_digest(stream, 'sha256').hexdigest()


def verify(kit):
    manifest = json.loads((kit / 'build-kit.json').read_text(encoding='utf-8'))
    plan = json.loads((kit / 'compile-plan.json').read_text(encoding='utf-8'))
    if (manifest.get('format') != 1 or manifest.get('architecture') != 'win-x64' or
        manifest.get('elfSha256') != ELF_SHA or plan.get('game') != 'file1' or
        plan.get('elfSha256') != ELF_SHA or plan.get('runtimeAbi') != manifest.get('runtimeAbi')):
        raise ValueError('A sealed, coherent File #1 Windows input SDK is required')
    seen = set()
    for item in manifest['files']:
        name = item['path']
        relative = Path(name)
        source = (kit / relative).resolve()
        if (relative.is_absolute() or '..' in relative.parts or
            name.casefold() in seen or not source.is_relative_to(kit) or
            not source.is_file() or sha(source) != item['sha256']):
            raise ValueError('Invalid or changed sealed SDK member: ' + name)
        seen.add(name.casefold())
    # Runtime is reconstructed from SDK source, never mixed with a private old lib.
    runtime_units = [u for u in plan['units'] if u.get('archive') == 'runtime']
    if not runtime_units or any('ps2_runtime' in i['path'].lower() for i in plan['independentInputs']):
        raise ValueError('SDK must rebuild PS2 runtime from source')
    for item in plan['independentInputs']:
        prefix = '{kit}/'
        if not item['path'].startswith(prefix):
            raise ValueError('External opaque library input is not allowed')
        relative = item['path'][len(prefix):]
        if relative.casefold() not in seen or sha(kit / relative) != item['sha256']:
            raise ValueError('Independent library identity mismatch: ' + relative)
    header = (kit / 'source/third_party/PS2Recomp/ps2xRuntime/include/ps2_runtime.h').read_text(encoding='utf-8')
    if 'class GuestExecutionScope' not in header or 'hasFunction(' not in header:
        raise ValueError('SDK public runtime interface lacks required migration boundary')
    return manifest, plan


def prepare(kit, output):
    kit, output = kit.resolve(), output.resolve()
    allowed = (ROOT / 'build-native-sjuni').resolve()
    if output == allowed or not output.is_relative_to(allowed) or output.exists():
        raise ValueError('Choose a fresh candidate-kit directory below build-native-sjuni')
    manifest, plan = verify(kit)
    base_manifest = sha(kit / 'build-kit.json')
    output.mkdir(parents=True)
    for item in manifest['files']:
        target = output / item['path']
        target.parent.mkdir(parents=True, exist_ok=True)
        shutil.copyfile(kit / item['path'], target)
        if sha(target) != item['sha256']:
            raise ValueError('SDK copy integrity failure: ' + item['path'])

    override_name = 'source/recomp/overrides/reo_override.cpp'
    override = output / override_name
    text = override.read_text(encoding='utf-8')
    include = '#include "game_overrides.h"'
    marker = '    // Self-execution (REO_NATURAL) / REO_NO_OVERRIDES:'
    if text.count(include) != 1 or text.count(marker) != 1 or 'native_sjuni/runtime_adapter.h' in text:
        raise ValueError('SDK override registration differs from the reviewed source boundary')
    text = text.replace(include, include + '\n#if defined(REO_GAME_FILE1) && defined(REO_BUILD_NATIVE_SJUNI_ADAPTER)\n'
                        '#include "native_sjuni/runtime_adapter.h"\n#endif')
    text = text.replace(marker, '#if defined(REO_BUILD_NATIVE_SJUNI_ADAPTER)\n'
                        '    reo_native_sjuni::install(runtime);\n#endif\n' + marker)
    override.write_text(text, encoding='utf-8', newline='\n')
    native_hashes = {}
    for relative in FILES:
        target = output / 'source' / relative
        target.parent.mkdir(parents=True, exist_ok=True)
        shutil.copyfile(ROOT / relative, target)
        native_hashes[relative] = sha(target)

    matches = [u for u in plan['units'] if u['sources'] == ['{work}/project/recomp/overrides/reo_override.cpp']]
    if len(matches) != 1:
        raise ValueError('Expected exactly one independently compiled override unit')
    template = matches[0]
    template['options'] = [*template['options'], '/DREO_BUILD_NATIVE_SJUNI_ADAPTER=1']
    existing = {u['id'] for u in plan['units']}
    for name, relative in UNITS:
        if name in existing:
            raise ValueError('SDK already has a native SJUNI compilation unit')
        plan['units'].append({'id': name, 'sources': ['{work}/project/' + relative],
                              'options': list(template['options'])})
    (output / 'compile-plan.json').write_text(json.dumps(plan, indent=2) + '\n', encoding='utf-8', newline='\n')
    delta = dict(schema=1, purpose='isolated SJUNI migration equivalence candidate',
                 base_kit_manifest_sha256=base_manifest, elf_sha256=ELF_SHA,
                 runtime_abi=manifest['runtimeAbi'], verified_base_members=len(manifest['files']),
                 sdk_runtime_source_units=sum(u.get('archive') == 'runtime' for u in plan['units']),
                 copied_native_source_sha256=native_hashes,
                 original_sdk_override_sha256=sha(kit / override_name),
                 candidate_override_sha256=sha(override),
                 dependency_source_changed=False, precompiled_ps2_runtime_reused=False,
                 behavior_switch='same candidate binary: REO_NATIVE_SJUNI=0 versus =1 and REO_NATIVE_SJUNI_GUARDED=1',
                 limitations=['This prepares inputs; it does not build or validate gameplay.',
                              'The frozen SDK baseline can differ from an existing player executable.',
                              'Compare original/native modes using this same coherent source build.'])
    delta_path = output / 'notices/native-sjuni-candidate.json'
    delta_path.write_text(json.dumps(delta, indent=2) + '\n', encoding='utf-8', newline='\n')
    manifest['files'] = [{'path': p.relative_to(output).as_posix(), 'sha256': sha(p)}
                         for p in sorted(output.rglob('*')) if p.is_file()]
    (output / 'build-kit.json').write_text(json.dumps(manifest, indent=2) + '\n', encoding='utf-8', newline='\n')
    print(json.dumps({'candidate_manifest_sha256': sha(output / 'build-kit.json'), **delta}, indent=2))


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--kit', type=Path, required=True)
    parser.add_argument('--output', type=Path, required=True)
    args = parser.parse_args()
    prepare(args.kit, args.output)


if __name__ == '__main__':
    main()
