#!/usr/bin/env python3
"""Seal a private File #1 candidate from committed root and audited dependency sources.

This is input preparation only. It never builds, launches, resets a checkout, or
reads authored changes from the working tree. Existing kits are immutable.
"""
import argparse
import copy
import hashlib
import json
from pathlib import Path, PurePosixPath
import re
import shutil
import subprocess

ROOT = Path(__file__).resolve().parents[2]
ELF_SHA = '06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46'
CARRIER_SHA = 'bf5a89f4fc6a75bb2a735260f57676c9dc5396f9308593d2b29a66b76fb4e7f1'
BASE_REVISION = 'c46d1c7d8ab00fbfa18d2c1f764c559e4e5dc78f'
COMPILER_SHA = 'f1377bd9c4e35669930d0fb2ebdc51cac1d1f4ca16638c0ed0d77c113bc195d3'
RECOMPILER_SHA = '108544f224fb358a1f111ce016a2176c552beaafe80795bc97f79d73c3df0ef9'
TOOLCHAIN_ARCHIVE_SHA = '2d96a4b758f7f8deaec5065833fe025aa53cfc5f704d0524002510984da0ccf4'
STOCK_BUILD_CONFIG = {
    'CMakeLists.txt': '3b26586276bdf4aa417ba94e4dd9f109d26680629832adaa8bb9c16942e35e6f',
    'ps2xRuntime/CMakeLists.txt': '2ebbb9e8085f9c8a5de73e6fed234c214b6845ed5c9d8c2b982d6ce5c5bf0ca9',
}
LIBRARIES = {
    'libraylib.a': 'bd5ba7baf25e93ac68ec92fa70d72321750e80b4ef2188637ee9240af4319c3c',
    'libfmt.a': 'a9b318c1f8130fdd9e846d1672611b00793c4f419a50b51690375f2f6537e6b5',
    'libdwarf.a': '596833224ba805b24d7d6e8b4ecaee62e49599333c11a69fc49b1c575171de69',
    'libgranite-vulkan.a': '348f79017c26d7f125cb56b4a2ece5f551ca2ab17f1c5bc8cce066dc89c3ff1a',
    'libgranite-volk.a': '22537de0c793a4a7e4bb10532352c67808f830f22db58bb2b4ca23418a76c0cc',
    'libgranite-util.a': 'de07eef8cfd750af5f6b2906a7eb224f1709974d75278328f33c1d0c7a4b39c0',
    'libgranite-math.a': '12cded23c84b5b8fe626f0edf64afdd1f8acd0f70c86d5e31ede48e14a25211a',
}
RAYLIB_REVISION = 'c1ab645ca298a2801097931d1079b10ff7eb9df8'
RAYLIB_FILES = {
    'raudio.c': '2d6a2d5b9f86b44b879605f654659c542a317d97477ddfde54683019e8bfeacc',
    'external/stb_vorbis.c': 'c8daf8d9f0dad818a1cb6c9194eeb4503b63b8cbf8c744efc12942f3d679f686',
    'external/qoaplay.c': '5e51732c03f20ece80f180cf9d24a179d7c5685fc1b9c49af6bd8415c16ed915',
}
NEW_UNITS = (
    ('native_network_state', 'network/native/native_netcode.cpp'),
    ('native_network_world', 'network/native/world_sync.cpp'),
    ('native_serial_worker', 'game/native/tasks/serial_worker.cpp'),
    ('native_cd_owner', 'recomp/overrides/native_cd_owner/runtime_adapter.cpp'),
)
DISC_STREAM_UNITS = (
    ('native_disc_stream_core', 'game/native/disc_stream/disc_stream.cpp'),
    ('native_disc_stream_adapter', 'recomp/overrides/native_disc_stream/runtime_adapter.cpp'),
)
RESOURCE_READ_UNITS = (
    ('native_resource_session', 'game/native/resources/resource_session.cpp'),
    ('native_resource_view', 'game/native/resources/virtual_file_view.cpp'),
    ('native_import_manifest', 'game/native/resources_windows/import_manifest.cpp'),
    ('native_pinned_file', 'game/native/resources_windows/pinned_file.cpp'),
    ('native_mounted_resources', 'game/native/resources_windows/mounted_resources.cpp'),
    ('native_mounted_reader', 'game/native/resources_windows/mounted_reader.cpp'),
    ('native_resource_reads_adapter', 'recomp/overrides/native_resource_reads/runtime_adapter.cpp'),
)
ADX_BLOCK_UNITS = (
    ('native_adx_block_core', 'game/native/adx_block/adx_block.cpp'),
    ('native_adx_block_adapter', 'recomp/overrides/native_adx_block/runtime_adapter.cpp'),
)
ADX_STEREO_UNITS = (
    ('native_adx_stereo_core', 'game/native/adx_stereo/adx_stereo.cpp'),
    ('native_adx_stereo_adapter', 'recomp/overrides/native_adx_stereo/runtime_adapter.cpp'),
)
PCM_BACKEND_UNITS = (
    ('native_pcm_core', 'game/native/pcm/pcm.cpp'),
    ('native_pcm_session_bridge', 'game/native/pcm_bridge/session_bridge.cpp'),
    ('native_audio_output_owner', 'game/native/audio_output/audio_output_owner.cpp'),
    ('native_audio_stream_provider', 'runtime/audio/native_stream_provider.cpp'),
    ('native_pcm_backend', 'recomp/overrides/native_pcm/runtime_adapter.cpp'),
)
AUDIO_BACKEND_UNITS = PCM_BACKEND_UNITS[:-1] + (
    ('native_audio_bank_algorithms_v2', 'game/native/audio_banks/v2/algorithms.cpp'),
    ('native_audio_bank_session_v2', 'game/native/audio_banks/v2/session.cpp'),
    ('native_audio_packet_v3', 'recomp/overrides/native_banks/v3/packet_adapter.cpp'),
    ('native_audio_aggregate_v2', 'recomp/overrides/native_audio/v2/aggregate.cpp'),
    ('native_audio_aggregate_v4', 'recomp/overrides/native_audio/v4/aggregate.cpp'),
    ('native_sound_ram_gate_v2', 'game/native/ram_capture/v2/cpu_authority_gate.cpp'),
    ('native_sound_address', 'recomp/overrides/native_sound_ram/address_domain.cpp'),
    ('native_sound_identity', 'recomp/overrides/native_sound_ram/build_identity.cpp'),
    ('native_sound_memory', 'recomp/overrides/native_sound_ram/runtime_memory.cpp'),
    ('native_sound_composite', 'recomp/overrides/native_sound_ram/composite_backend.cpp'),
    ('native_adxt_runtime_observer', 'recomp/overrides/native_adxt/runtime_observer.cpp'),
    ('native_resources_bounded_view', 'game/native/resources/bounded_view.cpp'),
    ('native_resource_io', 'game/native/resource_io/async_read_owner.cpp'),
    ('native_sjrb', 'game/native/sjrb/sjrb.cpp'),
    ('native_adx_header', 'game/native/adx_header/adx_header.cpp'),
    ('native_adxt_refill', 'game/native/adxt_refill/adxt_refill.cpp'),
    ('native_adx_pcm_store_v2', 'game/native/adx_pcm_store/v2/pcm_store.cpp'),
    ('native_adx_workspace', 'game/native/adx_workspace/adx_workspace.cpp'),
    ('native_adxt_estimated_clock', 'game/native/adxt_estimated_clock/estimated_clock.cpp'),
    ('native_adxt_integer_clock', 'game/native/adxt_integer_clock/integer_clock.cpp'),
    ('native_audio_mix_tail', 'game/native/audio_mix_tail/mixer.cpp'),
    ('native_adxt_output_session', 'game/native/adxt_output_session/session.cpp'),
    ('native_adx_sequence', 'game/native/adx_sequence/sequence.cpp'),
    ('native_adx_clip', 'game/native/adx_sequence/clip.cpp'),
    ('native_adxt_attenuation', 'game/native/adxt_attenuation/attenuation.cpp'),
    ('native_adxt_lsc_input', 'game/native/adxt_lsc_input/input.cpp'),
    ('native_adxt_shared_source', 'game/native/adxt_shared_source/shared_source.cpp'),
    ('native_lsc_queue', 'game/native/lsc_queue/queue.cpp'),
    ('native_adxt_phased_player', 'game/native/adxt_phased_player/player.cpp'),
    ('native_adx_service_window', 'game/native/adx_window/v2/service_r4/stream_window.cpp'),
    ('native_adxt_playback', 'game/native/adxt_playback/playback.cpp'),
    ('native_adxt_service_group', 'game/native/adxt_service_group/service_group.cpp'),
    ('native_adxt_serviced_clock', 'game/native/adxt_serviced_clock/completion.cpp'),
    ('native_adxt_transfer_groups', 'game/native/adxt_transfer_groups/transfer_groups.cpp'),
    ('native_adxt_control_session', 'game/native/adxt_control_session/control_session.cpp'),
    ('native_adxt_instances', 'game/native/adxt_instances/instances.cpp'),
    ('native_adxt_control_owner', 'game/native/adxt_control_owner/owner.cpp'),
) + RESOURCE_READ_UNITS[:2]
MOVIE_POSITION_UNITS = (
    ('native_movie_position_core', 'game/native/movie_position/movie_position.cpp'),
    ('native_movie_position_adapter', 'recomp/overrides/native_movie_position/runtime_adapter.cpp'),
)
ORDINARY_ADXT_UNITS = (
    ('native_afs_source_range', 'game/native/afs_source_range/afs_source_range.cpp'),
    ('native_movie_instance_audio', 'game/native/movie_instance_audio/source.cpp'),
    ('native_adxt_game_handles', 'recomp/overrides/native_adxt/game_handles.cpp'),
    ('native_adxt_file_source', 'recomp/overrides/native_adxt/source_profile.cpp'),
    ('native_adxt_ordinary_runtime', 'recomp/overrides/native_adxt/ordinary_runtime.cpp'),
)
HEADER_ROOTS = ('game/', 'media/', 'network/', 'recomp/', 'runtime/', 'src/',
                'tools/parallel_gs_backend/', 'tools/vu_whole_aot/',
                'tools/source_instrumentation/')


def apply_sound_ram_cohort(plan):
    """Require one instrumented class/body cohort across app AND runtime TUs."""
    selected = [unit for unit in plan['units'] if unit.get('language') != 'c']
    selected += [group for group in plan.get('sourceGroups', []) if group.get('language') != 'c']
    marker = '/DREO_BUILD_NATIVE_SOUND_RAM_CAPTURE'
    definition = '/DREO_BUILD_NATIVE_SOUND_RAM_CAPTURE=2'
    def definitions(options):
        return [value for value in options if value == marker or value.startswith(marker + '=')]
    common = definitions(plan.get('compileOptions', []))
    if common and common != [definition]:
        raise ValueError('Conflicting common sound RAM instrumentation cohort')
    for unit in selected:
        existing = definitions(unit.get('options', []))
        if existing and existing != [definition]:
            raise ValueError('Conflicting sound RAM instrumentation cohort: ' + unit['id'])
    for unit in selected:
        if not common and definition not in unit.get('options', []):
            unit.setdefault('options', []).append(definition)


def digest_bytes(data):
    return hashlib.sha256(data).hexdigest()


def sha(path):
    with Path(path).open('rb') as stream:
        return hashlib.file_digest(stream, 'sha256').hexdigest()


def member(root, name):
    relative = PurePosixPath(name)
    if relative.is_absolute() or '..' in relative.parts or '\\' in name or ':' in name:
        raise ValueError('Unsafe relative input path: ' + name)
    result = (root / name).resolve()
    if not result.is_relative_to(root.resolve()) or result.is_symlink():
        raise ValueError('Input escapes its declared root: ' + name)
    return result


def git(root, *arguments):
    return subprocess.check_output(['git', '-C', str(root), *arguments])


class Commit:
    def __init__(self, root, revision):
        if not re.fullmatch(r'[0-9a-fA-F]{7,40}', revision):
            raise ValueError('--revision must be an explicit commit hash')
        self.root = root
        self.revision = git(root, 'rev-parse', '--verify', revision + '^{commit}').decode().strip()
        self.entries = {}
        for record in git(root, 'ls-tree', '-r', '-z', self.revision).split(b'\0'):
            if not record:
                continue
            metadata, name = record.split(b'\t', 1)
            mode, kind, identity = metadata.decode().split()
            name = name.decode('utf-8')
            if kind == 'blob':
                if mode not in ('100644', '100755'):
                    raise ValueError('Committed symlink is not admitted: ' + name)
                member(root, name)
                self.entries[name] = identity
        self.cache = {}

    def read(self, name):
        if name not in self.entries:
            raise ValueError('Required file is absent from committed revision: ' + name)
        if name not in self.cache:
            self.cache[name] = git(self.root, 'cat-file', 'blob', self.entries[name])
        return self.cache[name]


def verify_carrier(kit):
    if sha(kit / 'build-kit.json') != CARRIER_SHA:
        raise ValueError('Expected the exact sealed candidate-inputs-v1 carrier')
    manifest = json.loads((kit / 'build-kit.json').read_text(encoding='utf-8'))
    seen = set()
    for item in manifest['files']:
        name = item['path']
        if name.casefold() in seen or sha(member(kit, name)) != item['sha256']:
            raise ValueError('Changed or duplicate carrier member: ' + name)
        seen.add(name.casefold())
    plan = json.loads((kit / 'compile-plan.json').read_text(encoding='utf-8'))
    if (manifest.get('format') != 1 or manifest.get('architecture') != 'win-x64' or
            manifest.get('elfSha256') != ELF_SHA or plan.get('elfSha256') != ELF_SHA or
            plan.get('game') != 'file1' or plan.get('toolchain') != 'llvm-mingw' or
            not plan.get('externalToolchain') or plan.get('externalCompilerSha256') != COMPILER_SHA or
            plan.get('runtimeAbi') != manifest.get('runtimeAbi')):
        raise ValueError('Carrier architecture/game/toolchain contract differs')
    actual = {PurePosixPath(x['path']).name: x['sha256'] for x in plan['independentInputs']}
    if actual != LIBRARIES or len(plan['independentInputs']) != len(LIBRARIES):
        raise ValueError('Only the seven pinned independent stock libraries are admitted')
    for item in plan['independentInputs']:
        if item['provenance'] != 'third-party' or not item['path'].startswith('{kit}/libraries/'):
            raise ValueError('Opaque or external library input')
        if sha(member(kit, item['path'].removeprefix('{kit}/'))) != item['sha256']:
            raise ValueError('Stock library identity differs')
    if sha(kit / 'tools/ps2_recomp.exe') != RECOMPILER_SHA:
        raise ValueError('Carrier independent recompiler identity differs')
    proof = json.loads((kit / 'notices/PS2RECOMP-SOURCE-PROOF.json').read_text(encoding='utf-8'))
    sdk = json.loads((kit / 'notices/independent-sdk-sources.json').read_text(encoding='utf-8'))
    if (proof.get('upstreamRevision') != BASE_REVISION or len(proof['patchSeries']) != 110 or
            not proof.get('generatorUnchangedFromProof02') or
            not proof.get('independentLibrarySourcesUnchangedFromProof02') or
            next(x['revision'] for x in sdk if x.get('component') == 'raylib') != RAYLIB_REVISION):
        raise ValueError('Carrier stock-library/compiler source provenance differs')
    return manifest, plan, proof


def verify_dependency(dependency, receipt_path, commit, compiler_proof):
    receipt = json.loads(receipt_path.read_text(encoding='utf-8'))
    patches = sorted(n for n in commit.entries if n.startswith('third_party/patches/ps2recomp/')
                     and n.endswith('.patch'))
    recorded = receipt.get('patches', [])
    if (receipt.get('status') != 'passed' or receipt.get('base_revision') != BASE_REVISION or
            receipt.get('applied_count') != len(patches) or len(recorded) != len(patches) or
            len(patches) < 121 or {x['path'] for x in recorded} != set(patches) or
            Path(receipt['checkout']).resolve() != dependency):
        raise ValueError('Dependency receipt must cover the entire committed patch series (121 or later)')
    if git(dependency, 'rev-parse', 'HEAD').decode().strip() != BASE_REVISION:
        raise ValueError('Audited dependency base revision differs')
    for item in recorded:
        if (item.get('check_exit_code') != 0 or item.get('apply_exit_code') != 0 or
                digest_bytes(commit.read(item['path'])) != item['sha256']):
            raise ValueError('Dependency patch does not match the committed series: ' + item['path'])
    for name, expected in receipt['source_sha256'].items():
        if sha(member(dependency, name)) != expected:
            raise ValueError('Changed audited dependency source: ' + name)
    for name, expected in STOCK_BUILD_CONFIG.items():
        if receipt['source_sha256'].get(name) != expected:
            raise ValueError('Stock-library build configuration needs fresh review: ' + name)
    # A new runtime proof does not justify retaining an old compiler if generator
    # inputs have changed. Require every compiler input from its prior proof.
    for item in compiler_proof['files']:
        if item['path'].startswith('ps2xRecomp/'):
            if receipt['source_sha256'].get(item['path']) != item['sha256']:
                raise ValueError('Rebuild/reprove the recompiler before preparing: ' + item['path'])
    return receipt


def verify_toolchain(toolchain):
    path = toolchain / 'compiler-setup.json'
    receipt = json.loads(path.read_text(encoding='utf-8'))
    if (receipt.get('Format') != 1 or receipt.get('ArchiveSha256') != TOOLCHAIN_ARCHIVE_SHA or
            len(receipt.get('Files', [])) != 5601):
        raise ValueError('The pinned complete LLVM/MinGW compiler/sysroot receipt is required')
    seen = set()
    for item in receipt['Files']:
        name = item['Path'].replace('\\', '/')
        file = member(toolchain, name)
        if (name.casefold() in seen or file.stat().st_size != item['Bytes'] or sha(file) != item['Sha256']):
            raise ValueError('Changed compiler/sysroot member: ' + name)
        seen.add(name.casefold())
    if sha(toolchain / 'bin/x86_64-w64-mingw32-clang++.exe') != COMPILER_SHA:
        raise ValueError('Compiler driver identity differs')
    return {'receipt_sha256': sha(path), 'verified_members': len(seen),
            'compiler_sha256': COMPILER_SHA, 'archive_sha256': TOOLCHAIN_ARCHIVE_SHA}


def runtime_sources(dependency):
    cmake = (dependency / 'ps2xRuntime/CMakeLists.txt').read_text(encoding='utf-8')
    match = re.search(r'add_library\(ps2_runtime STATIC(.*?)\n\)', cmake, re.S)
    if not match:
        raise ValueError('Unrecognized patched runtime source declaration')
    result = set(re.findall(r'src/[^\s)]+\.cpp', match.group(1)))
    base = dependency / 'ps2xRuntime'
    result.update(p.relative_to(base).as_posix() for p in (base / 'src/lib/Kernel').rglob('*.cpp'))
    result.update(p.relative_to(base).as_posix() for p in (base / 'src/lib/ipu').glob('*.cpp'))
    return result


def prepared_inputs(root, revision, kit, dependency, dependency_receipt, toolchain, raylib,
                    disc_stream=False, resource_reads=False, adx_block=False, adx_stereo=False,
                    pcm_backend=False, movie_position=False, audio_backend=False):
    if pcm_backend and audio_backend:
        raise ValueError('Choose one complete audio backend candidate')
    commit = Commit(root, revision)
    manifest, plan, compiler_proof = verify_carrier(kit)
    receipt = verify_dependency(dependency, dependency_receipt, commit, compiler_proof)
    compiler = verify_toolchain(toolchain)
    source = {}
    # Refresh every authored carrier member which exists in the selected commit,
    # plus the full committed header cohort used by its runtime/backend units.
    for item in manifest['files']:
        name = item['path']
        if name.startswith('source/') and name[7:] in commit.entries:
            source[name] = commit.read(name[7:])
    for name in commit.entries:
        suffix = PurePosixPath(name).suffix
        if name.startswith(HEADER_ROOTS) and suffix in ('.h', '.hpp', '.inl', '.inc'):
            source['source/' + name] = commit.read(name)
        if (name.startswith(('tools/local_build/', 'tools/vu_whole_aot/')) and suffix == '.py') or (
                name.startswith('tools/') and name in {x['path'] for x in manifest['files']}):
            source[name] = commit.read(name)
        if name.startswith('recomp/config/') and suffix in ('.json', '.csv', '.toml'):
            source['metadata/' + name.removeprefix('recomp/config/')] = commit.read(name)
    for name in receipt['source_sha256']:
        data = member(dependency, name).read_bytes()
        if digest_bytes(data) != receipt['source_sha256'][name]:
            raise ValueError('Dependency changed during preparation: ' + name)
        source['source/third_party/PS2Recomp/' + name] = data
    selected_units = NEW_UNITS + (DISC_STREAM_UNITS if disc_stream else ()) + \
        (RESOURCE_READ_UNITS if resource_reads else ()) + (ADX_BLOCK_UNITS if adx_block else ()) + \
        (ADX_STEREO_UNITS if adx_stereo else ()) + (PCM_BACKEND_UNITS if pcm_backend else ()) + \
        (MOVIE_POSITION_UNITS if movie_position else ()) + (AUDIO_BACKEND_UNITS if audio_backend else ()) + \
        (ORDINARY_ADXT_UNITS if resource_reads and audio_backend else ())
    # Native ADXT and native file payloads share the same resource-view bodies.
    # Keep exact tuple duplicates once; conflicting paths/IDs still fail below.
    selected_units = tuple(dict.fromkeys(selected_units))
    required = [n for _, n in selected_units] + [
        'recomp/overrides/native_cd_owner/runtime_adapter.h',
        'recomp/overrides/native_cd_owner/ram_configuration.h', 'game/native/tasks/serial_worker.hpp',
        'recomp/overrides/reo_cd_async.h', 'runtime/audio/reo_output_device.h']
    for name in required:
        source['source/' + name] = commit.read(name)
    bootstrap = commit.read('recomp/reo_bootstrap.cpp').decode('utf-8')
    override = commit.read('recomp/overrides/reo_override.cpp').decode('utf-8')
    async_header = commit.read('recomp/overrides/reo_cd_async.h').decode('utf-8')
    if ('REO_BUILD_NATIVE_RESOURCE_OWNER' not in bootstrap or
            'reo_cd_async::configure' not in bootstrap or
            'reo_cd_async::sifCallRpc' not in override or
            'native_cd_owner/runtime_adapter.h' not in async_header):
        raise ValueError('Commit lacks the reviewed native CD configure/dispatch integration')
    if disc_stream and 'reo_native_disc_stream::install(runtime)' not in override:
        raise ValueError('Commit lacks the optional native disc-stream installation')
    if adx_block and 'reo_native_adx_block::install(runtime)' not in bootstrap:
        raise ValueError('Commit lacks the optional keyed mono ADX installation')
    if adx_stereo and 'reo_native_adx_stereo::install(runtime)' not in bootstrap:
        raise ValueError('Commit lacks the optional keyed stereo ADX installation')
    if movie_position and 'reo_native_movie_position::install(runtime)' not in bootstrap:
        raise ValueError('Commit lacks the optional guarded movie-position installation')
    if pcm_backend:
        if 'reo_native_pcm::install(runtime,' not in bootstrap or 'dtxCompatLayoutSnapshot()' not in bootstrap:
            raise ValueError('Commit lacks observed-profile native PCM installation')
        syscall_header = source['source/third_party/PS2Recomp/ps2xRuntime/include/ps2_syscalls.h']
        backend_header = source.get('source/third_party/PS2Recomp/ps2xRuntime/src/lib/Kernel/Syscalls/Helpers/CriAudioBackend.h', b'')
        if b'PS2_RUNTIME_HAS_DTX_LAYOUT_SNAPSHOT 1' not in syscall_header or b'PS2_RUNTIME_HAS_PCM_BACKEND_DISPATCH 1' not in backend_header:
            raise ValueError('Native PCM requires matching dispatch and layout snapshot dependency source')
        pcm_header = source['source/third_party/PS2Recomp/ps2xRuntime/src/lib/Kernel/Syscalls/Helpers/CriAudio.h']
        if b'resetBeforeRuntimeRun' not in pcm_header:
            raise ValueError('Native PCM requires the explicit pre-run configuration reset transaction')
    if audio_backend:
        if ('sound_ram::install(runtime,' not in bootstrap or
                'sound_ram::observe_build_identity' not in bootstrap or
                'reo_cd_async::configureWithReceipt' not in bootstrap):
            raise ValueError('Commit lacks complete sound identity/configuration/publication integration')
        companion = source.get('source/third_party/PS2Recomp/ps2xRuntime/src/lib/Kernel/Syscalls/Helpers/CriAudioRamCapture.h', b'')
        profile = source.get('source/third_party/PS2Recomp/ps2xRuntime/src/lib/gs_sound_ram_profile.h', b'')
        route = source.get('source/third_party/PS2Recomp/ps2xRuntime/src/lib/gs_backend_route.h', b'')
        if (b'installBackendWithNativeSoundRamBeforeRunV1' not in companion or
                b'acquireSoundRamProfileBeforeRunV1' not in profile or
                b'PS2_RUNTIME_HAS_GS_SOUND_RAM_PROFILE 1' not in route):
            raise ValueError('Complete sound candidate requires matching RAM companion and selected-GS profile source')
    if resource_reads and ('reo_native_resource_reads::configure' not in bootstrap or
            'reo_native_resource_reads::tryRead' not in commit.read('recomp/overrides/reo_hw_bridge.cpp').decode('utf-8')):
        raise ValueError('Commit lacks the optional synchronous native read integration')
    for name, expected in RAYLIB_FILES.items():
        data = member(raylib, name).read_bytes()
        if digest_bytes(data) != expected:
            raise ValueError('Pinned raylib audio source identity differs: ' + name)
        source['source/third_party/PS2Recomp/out/build/_deps/raylib-src/src/' + name] = data
    # Run only the selected committed, self-contained source transform. No game
    # or compiler is executed, and the upstream file is never modified.
    transform_name = 'tools/local_build/prepare_audio_output.py'
    transform = {'__name__': 'committed_audio_transform'}
    exec(compile(commit.read(transform_name), commit.revision + ':' + transform_name, 'exec'), transform)
    audio_path = 'source/build-ninja/recomp/reo_audio_output.c'
    source[audio_path] = transform['instrument'](source[
        'source/third_party/PS2Recomp/out/build/_deps/raylib-src/src/raudio.c'].decode('utf-8')).encode('utf-8')
    plan = copy.deepcopy(plan)
    def unit_for(name):
        matches = [u for u in plan['units'] if u['sources'] == ['{work}/project/' + name]]
        if len(matches) != 1:
            raise ValueError('Expected exactly one carrier unit: ' + name)
        return matches[0]
    template = unit_for('recomp/overrides/reo_override.cpp')
    for name in ('recomp/reo_bootstrap.cpp', 'recomp/overrides/reo_override.cpp'):
        options = unit_for(name)['options']
        if '/DREO_BUILD_NATIVE_RESOURCE_OWNER=1' not in options:
            options.append('/DREO_BUILD_NATIVE_RESOURCE_OWNER=1')
    if disc_stream:
        template['options'].append('/DREO_BUILD_NATIVE_DISC_STREAM=1')
    if adx_block:
        for name in ('recomp/reo_bootstrap.cpp', 'recomp/overrides/reo_override.cpp'):
            unit_for(name)['options'].append('/DREO_BUILD_NATIVE_ADX_BLOCK=1')
    if adx_stereo:
        for name in ('recomp/reo_bootstrap.cpp', 'recomp/overrides/reo_override.cpp'):
            unit_for(name)['options'].append('/DREO_BUILD_NATIVE_ADX_STEREO=1')
    if pcm_backend:
        template['options'].append('/DREO_BUILD_NATIVE_PCM=1')
        unit_for('recomp/reo_bootstrap.cpp')['options'].append('/DREO_BUILD_NATIVE_PCM=1')
    if audio_backend:
        template['options'].append('/DREO_BUILD_NATIVE_AUDIO=1')
        unit_for('recomp/reo_bootstrap.cpp')['options'].append('/DREO_BUILD_NATIVE_AUDIO=1')
    if movie_position:
        template['options'].append('/DREO_BUILD_NATIVE_MOVIE_POSITION=1')
        unit_for('recomp/reo_bootstrap.cpp')['options'].append('/DREO_BUILD_NATIVE_MOVIE_POSITION=1')
    if resource_reads:
        for name in ('recomp/reo_bootstrap.cpp', 'recomp/overrides/reo_override.cpp', 'recomp/overrides/reo_hw_bridge.cpp'):
            unit_for(name)['options'].append('/DREO_BUILD_NATIVE_RESOURCE_READS=1')
    if resource_reads or audio_backend:
        for library in ('bcrypt.lib', 'runtimeobject.lib'):
            if library not in plan['linkOptions']:
                plan['linkOptions'].append(library)
    ids = {u['id'] for u in plan['units']}
    for identifier, name in selected_units:
        if identifier in ids or any('{work}/project/' + name in u['sources'] for u in plan['units']):
            raise ValueError('Duplicate candidate compilation unit: ' + name)
        options = list(template['options'])
        if (identifier, name) in PCM_BACKEND_UNITS or (identifier, name) in AUDIO_BACKEND_UNITS:
            options.append('/I{work}/project/third_party/PS2Recomp/ps2xRuntime/src/lib')
        plan['units'].append({'id': identifier, 'sources': ['{work}/project/' + name],
                              'options': options})
        ids.add(identifier)
    if audio_backend:
        # Service's instrumented class and source wrappers must have one coherent
        # definition across every C++ TU, including the freshly rebuilt runtime.
        # Reusing a precompiled SDK or setting the flag only on the bootstrap
        # would not qualify that linked body or its layout.
        apply_sound_ram_cohort(plan)
    audio_options = [x for x in template['options'] if not x.startswith('/DREO_BUILD_NATIVE_')]
    audio_options += ['/DMA_DEFAULT_PERIOD_SIZE_IN_MILLISECONDS_LOW_LATENCY=5', '/DMA_DEFAULT_PERIODS=2']
    plan['units'].append({'id': 'audioOutputNative', 'sources': ['{work}/project/' + audio_path[7:]],
                          'options': audio_options, 'language': 'c', 'standard': 'c11'})
    actual = {s.split('/ps2xRuntime/')[1] for u in plan['units'] if u.get('archive') == 'runtime'
              for s in u['sources']}
    if actual != runtime_sources(dependency):
        raise ValueError('Runtime TU closure differs; missing=' + str(sorted(runtime_sources(dependency) - actual)) +
                         ', extra=' + str(sorted(actual - runtime_sources(dependency))))
    recipes = json.loads(commit.read('recomp/config/local_source_recipes.json'))
    recipe_outputs = {'source/' + r['destination'] for r in recipes['recipes']}
    for name in recipe_outputs:
        member(kit, name)  # Validate path syntax even though reconstruction is deferred.
    for unit in plan['units']:
        for name in unit['sources']:
            if name.startswith('{work}/project/'):
                relative = 'source/' + name.removeprefix('{work}/project/')
                # Recipe-owned original bodies are reconstructed by build_game.
                if relative not in source and not (kit / relative).is_file() and relative not in recipe_outputs:
                    raise ValueError('Compilation source is absent: ' + relative)
    source['compile-plan.json'] = (json.dumps(plan, indent=2) + '\n').encode()
    return commit, manifest, plan, receipt, compiler, source


def prepare(args):
    root, kit, output, dependency, receipt_path, toolchain, raylib = [Path(p).resolve() for p in
        (args.root, args.kit, args.output, args.dependency, args.dependency_receipt, args.toolchain, args.raylib_source)]
    allowed = (ROOT / 'build-native-sjuni').resolve()
    if (output == allowed or not output.is_relative_to(allowed) or output.exists() or
            any(output.is_relative_to(x) or x.is_relative_to(output) for x in (kit, dependency, toolchain, raylib))):
        raise ValueError('Use a fresh independent candidate directory below build-native-sjuni')
    commit, manifest, plan, receipt, compiler, updates = prepared_inputs(
        root, args.revision, kit, dependency, receipt_path, toolchain, raylib,
        disc_stream=args.disc_stream_adapter, resource_reads=args.resource_reads, adx_block=args.adx_block_adapter,
        adx_stereo=args.adx_stereo_adapter, pcm_backend=args.pcm_backend,
        movie_position=args.movie_position_adapter, audio_backend=args.audio_backend)
    result = {'schema': 1, 'root_revision': commit.revision, 'carrier_manifest_sha256': CARRIER_SHA,
              'preparer_sha256': sha(Path(__file__)),
              'dependency_receipt_sha256': sha(receipt_path), 'dependency_patch_count': receipt['applied_count'],
              'compiler': compiler, 'recompiler_sha256': RECOMPILER_SHA,
              'runtime_source_units': sum(u.get('archive') == 'runtime' for u in plan['units']),
              'compilation_units': len(plan['units']), 'updated_files': len(updates),
              'check_only': args.check_only, 'game_launched': False, 'build_started': False,
              'precompiled_ps2_runtime_reused': False}
    result['optional_adapters'] = dict(disc_stream=args.disc_stream_adapter, resource_reads=args.resource_reads,
                                       adx_block=args.adx_block_adapter, adx_stereo=args.adx_stereo_adapter,
                                       pcm_backend=args.pcm_backend, movie_position=args.movie_position_adapter,
                                       audio_backend=args.audio_backend)
    if args.check_only:
        return result
    output.mkdir(parents=True)
    for item in manifest['files']:
        target = member(output, item['path'])
        target.parent.mkdir(parents=True, exist_ok=True)
        shutil.copyfile(member(kit, item['path']), target)
        if sha(target) != item['sha256']:
            raise ValueError('Carrier copy failed integrity check: ' + item['path'])
    for name, data in updates.items():
        target = member(output, name)
        target.parent.mkdir(parents=True, exist_ok=True)
        target.write_bytes(data)
    notices = output / 'notices'
    shutil.copyfile(kit / 'notices/PS2RECOMP-SOURCE-PROOF.json',
                    notices / 'PS2RECOMP-CARRIER-COMPILER-PROOF.json')
    (notices / 'PS2RECOMP-SOURCE-PROOF.json').write_text(json.dumps({
        'schema': 1, 'scope': 'candidate runtime; supersedes the carrier 110-patch runtime proof',
        'receipt': 'PS2RECOMP-CANDIDATE-DEPENDENCY-RECEIPT.json', 'receiptSha256': sha(receipt_path),
        'rootRevision': commit.revision, 'upstreamRevision': BASE_REVISION,
        'compilerProof': 'PS2RECOMP-CARRIER-COMPILER-PROOF.json',
        'compilerSourceHashesUnchanged': True, 'independentLibrariesRetained': LIBRARIES,
    }, indent=2) + '\n', encoding='utf-8')
    shutil.copyfile(receipt_path, notices / 'PS2RECOMP-CANDIDATE-DEPENDENCY-RECEIPT.json')
    for item in receipt['patches']:
        target = notices / 'ps2recomp-patches' / PurePosixPath(item['path']).name
        target.parent.mkdir(parents=True, exist_ok=True)
        target.write_bytes(commit.read(item['path']))
    (notices / 'SDK-SOURCES.txt').write_text(
        'Carrier stock-library/compiler corresponding sources retain their recorded archive identity.\n'
        'That older archive does not describe this candidate runtime. See PS2RECOMP-SOURCE-PROOF.json,\n'
        'PS2RECOMP-CANDIDATE-DEPENDENCY-RECEIPT.json, the complete included patch series, and\n'
        'native-candidate-source-delta.json for this candidate\'s committed source identities.\n', encoding='utf-8')
    delta = dict(result, updated_files_sha256={n: digest_bytes(b) for n, b in sorted(updates.items())},
                 dependency_source_sha256=receipt['source_sha256'], stock_libraries_sha256=LIBRARIES,
                 authored_source_origin='git blobs from root_revision; dirty working files excluded',
                 audio_source_sha256=RAYLIB_FILES,
                 limitations=['Input preparation only; compilation and gameplay are unvalidated.',
                              'Optional generated DNAS/network include bodies remain optional as in committed source.'])
    (notices / 'native-candidate-source-delta.json').write_text(json.dumps(delta, indent=2) + '\n', encoding='utf-8')
    shutil.copyfile(notices / 'native-sjuni-candidate.json', notices / 'CARRIER-NATIVE-SJUNI-CANDIDATE.json')
    # The existing private build driver hashes this compatibility notice. Make
    # that identity describe the new candidate rather than its older carrier.
    (notices / 'native-sjuni-candidate.json').write_text(json.dumps({
        'schema': 1, 'purpose': 'committed-source native candidate; supersedes carrier SJUNI-only preparation',
        'root_revision': commit.revision, 'source_delta': 'native-candidate-source-delta.json',
        'source_delta_sha256': sha(notices / 'native-candidate-source-delta.json'),
        'historical_carrier_notice': 'CARRIER-NATIVE-SJUNI-CANDIDATE.json',
    }, indent=2) + '\n', encoding='utf-8')
    manifest['files'] = [{'path': p.relative_to(output).as_posix(), 'sha256': sha(p)}
                         for p in sorted(output.rglob('*')) if p.is_file() and p != output / 'build-kit.json']
    (output / 'build-kit.json').write_text(json.dumps(manifest, indent=2) + '\n', encoding='utf-8')
    return dict(result, candidate_manifest_sha256=sha(output / 'build-kit.json'), output=str(output))


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--root', type=Path, default=ROOT)
    parser.add_argument('--revision', required=True)
    parser.add_argument('--kit', type=Path, required=True)
    parser.add_argument('--output', type=Path, required=True)
    parser.add_argument('--dependency', type=Path, required=True)
    parser.add_argument('--dependency-receipt', type=Path, required=True)
    parser.add_argument('--toolchain', type=Path, required=True)
    parser.add_argument('--raylib-source', type=Path, required=True, help='Pinned raylib src directory')
    parser.add_argument('--check-only', action='store_true', help='Verify all inputs without creating output')
    parser.add_argument('--disc-stream-adapter', action='store_true', help='Compile the opt-in four-entry DVCI scalar adapter')
    parser.add_argument('--resource-reads', action='store_true', help='Compile the opt-in synchronous exact PAK read adapter')
    parser.add_argument('--adx-block-adapter', action='store_true', help='Compile the opt-in keyed mono ADX block adapter')
    parser.add_argument('--adx-stereo-adapter', action='store_true', help='Compile the opt-in keyed stereo/downmix ADX adapters')
    parser.add_argument('--pcm-backend', action='store_true', help='Compile the default-off bounded complete File1 PCM candidate')
    parser.add_argument('--audio-backend', action='store_true', help='Compile the private complete PCM/bank/RAM candidate with a coherent flag2 runtime rebuild')
    parser.add_argument('--movie-position-adapter', action='store_true', help='Compile the default-off guarded File1 movie position publisher')
    print(json.dumps(prepare(parser.parse_args()), indent=2))


if __name__ == '__main__':
    main()
