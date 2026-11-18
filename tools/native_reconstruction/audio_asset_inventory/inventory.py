#!/usr/bin/env python3
"""Read-only owned File1 ISO/AFS metadata inventory; never extracts payloads."""
import argparse
from collections import Counter, deque
import hashlib
import importlib.util
import json
from pathlib import Path
import struct

ROOT = Path(__file__).resolve().parents[3]
HERE = Path(__file__).resolve().parent
ELF_SHA256 = '06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46'
SECTOR = 2048
AUTHORITIES = [
    'launcher/DiscImage.cs', 'launcher/DiscImport.cs',
    'tools/assets/extract_assets.py', 'game/native/adx_header/adx_header.cpp',
    'game/native/adx_header/adx_header.hpp',
    'game/native/audio_banks/v2/algorithms.cpp',
    'game/native/audio_banks/v2/session.cpp',
    'game/native/audio_banks/v2/session.hpp',
    'recomp/overrides/native_banks/v3/packet_adapter.h',
    'media/sofdec/sofdec_decoder.cpp',
]


def digest(path):
    with path.open('rb') as stream:
        return hashlib.file_digest(stream, 'sha256').hexdigest()


def write(path, value):
    path.write_text(json.dumps(value, indent=2) + '\n', encoding='utf-8', newline='\n')


def read_at(stream, offset, size, limit):
    if offset < 0 or size < 0 or offset > limit or size > limit-offset:
        raise ValueError('Read escapes owned container extent')
    stream.seek(offset)
    value = stream.read(size)
    if len(value) != size:
        raise ValueError('Truncated owned container')
    return value


def extent_digest(stream, base, size, limit):
    result = hashlib.sha256()
    while size:
        count = min(size, 4*1024*1024)
        result.update(read_at(stream, base, count, limit))
        base += count
        size -= count
    return result.hexdigest()


def dual32(data, offset):
    little = struct.unpack_from('<I', data, offset)[0]
    if little != struct.unpack_from('>I', data, offset+4)[0]:
        raise ValueError('ISO dual-endian disagreement')
    return little


def iso_index(stream, limit):
    """Bounded read-only translation of launcher DiscImage's ISO9660 reader."""
    primary = None
    for sector in range(16, 48):
        descriptor = read_at(stream, sector*SECTOR, SECTOR, limit)
        if descriptor[1:7] != b'CD001\x01':
            raise ValueError('Not a supported ISO9660 image')
        if descriptor[0] == 1:
            primary = descriptor
            break
        if descriptor[0] == 255:
            break
    if primary is None or struct.unpack_from('<H', primary, 128)[0] != SECTOR or struct.unpack_from('>H', primary, 130)[0] != SECTOR:
        raise ValueError('Unsupported ISO descriptor/sector geometry')
    if dual32(primary, 80)*SECTOR > limit:
        raise ValueError('Truncated ISO volume')
    queue = deque([('', dual32(primary, 158), dual32(primary, 166), 0)])
    visited, names, files = set(), set(), []
    directory_bytes = 0
    while queue:
        parent, lba, size, depth = queue.popleft()
        directory_bytes += size
        if depth > 32 or lba in visited or size > 16*1024*1024 or directory_bytes > 64*1024*1024:
            raise ValueError('Invalid/cyclic/oversized ISO directories')
        visited.add(lba)
        data = read_at(stream, lba*SECTOR, size, limit)
        at = 0
        while at < len(data):
            count = data[at]
            if not count:
                at = (at//SECTOR+1)*SECTOR
                continue
            row = data[at:at+count]
            if count < 34 or len(row) != count or at%SECTOR+count > SECTOR or not row[32] or 33+row[32] > count:
                raise ValueError('Malformed ISO directory record')
            at += count
            raw = row[33:33+row[32]]
            if raw in (b'\0', b'\1'):
                continue
            if row[25]&0x80 or row[26] or row[27] or row[1]:
                raise ValueError('Unsupported multi-extent/interleaved ISO record')
            name = raw.decode('ascii')
            if ';' in name:
                name, version = name.rsplit(';', 1)
                if version != '1':
                    raise ValueError('Unsupported ISO version')
            if not name or name in ('.', '..') or any(ord(c)<32 or ord(c)>126 or c in '/\\:' for c in name):
                raise ValueError('Unsafe ISO metadata name')
            path = parent+'/'+name if parent else name
            if path.upper() in names or len(names) >= 100000:
                raise ValueError('Conflicting/oversized ISO namespace')
            names.add(path.upper())
            offset, length = dual32(row, 2)*SECTOR, dual32(row, 10)
            if offset > limit or length > limit-offset:
                raise ValueError('ISO file extent escapes image')
            if row[25]&2:
                queue.append((path, offset//SECTOR, length, depth+1))
            else:
                files.append(dict(path=path, offset=offset, bytes=length))
    return files


def adx_metadata(data, member_bytes):
    if len(data) < 2 or data[:2] != b'\x80\0':
        return None
    if len(data) < 20:
        return dict(recognition='short_adx_magic_candidate', finite_header_profile=False,
                    reasons=['header_shorter_than_20'])
    offset = struct.unpack_from('>H', data, 2)[0]+4
    encoding, block, bits, channels = data[4:8]
    rate, samples = struct.unpack_from('>II', data, 8)
    highpass = struct.unpack_from('>h', data, 16)[0]
    version, control = data[18:20]
    marker = offset >= 6 and offset <= len(data) and data[offset-6:offset] == b'(c)CRI'
    reasons = []
    checks = dict(encoding=encoding == 3, block_bytes=block == 18,
                  bits=bits in (0,4), channels=channels in (1,2),
                  version=version in (3,4), rate_filter=highpass == 500 and rate in (24000,44100,48000),
                  header_extent=20 <= offset <= min(member_bytes,4096),
                  history_extent=version < 4 or offset >= 32)
    reasons.extend(key for key, value in checks.items() if not value)
    base = 32 if version == 4 else 20
    loop = dict(status='header_too_short_for_loop')
    if offset >= base+28 and len(data) >= base+28:
        loop = dict(status='fields_read', count=struct.unpack_from('>h', data, base)[0],
                    enabled=struct.unpack_from('>H', data, base+2)[0],
                    index=struct.unpack_from('>H', data, base+6)[0],
                    positions=list(struct.unpack_from('>IIII', data, base+8)))
    return dict(recognition='adx_structural_header' if marker else 'adx_magic_candidate_unconfirmed',
                cri_marker=marker, header_bytes=offset, encoding=encoding, block_bytes=block,
                bits=bits, channels=channels, frequency=rate, total_samples=samples,
                filter=highpass, version=version, version_control=control, loop=loop,
                finite_header_profile=all(checks.values()), profile_checks=checks, reasons=reasons)


def bank_hd_metadata(data, member_bytes):
    if len(data) < 8 or data[:8] != b'IECSsreV':
        return None
    if len(data) < 0x34 or data[16:24] != b'IECSdaeH':
        return dict(recognition='hsyn_hd_signature_candidate', reason='missing_head_chunk')
    chunks = struct.unpack_from('<4I', data, 0x24)
    signatures = [b'IECSgorP', b'IECStesS', b'IECSlpmS', b'IECSigaV']
    valid = all(at+16 <= len(data) and data[at:at+8] == signature for at, signature in zip(chunks, signatures))
    return dict(recognition='hsyn_hd_structural_header' if valid else 'hsyn_hd_signature_candidate',
                chunk_offsets=list(chunks), chunk_signatures_valid=valid,
                part_limit_bytes=2*1024*1024, within_individual_part_limit=member_bytes <= 2*1024*1024,
                paired_bd_tq='unknown_no_authoritative_pairing',
                complete_bank_admission='not_tested')


def make_plan(source):
    stat = source.stat()
    return dict(schema=1, status='planned', source=dict(path=str(source), bytes=stat.st_size, mtime_ns=stat.st_mtime_ns),
                expected_file1_elf_sha256=ELF_SHA256,
                source_authority={name:digest(ROOT/name) for name in AUTHORITIES},
                inventory_tool_sha256=digest(Path(__file__)),
                read_plan=['Read ISO9660 index; reject malformed/multi-extent/interleaved records',
                           'Hash embedded SLUS_207.65 and require exact owned File1 revision',
                           'Index all regular ISO files, recursively parse only signature-qualified AFS extents',
                           'Reuse bounded extract_assets.table only; never call extract()',
                           'Hash ISO, top-level files and AFS members; read metadata through bounded windows',
                           'Recognize ADX/HSYN by structural bytes, never by filename alone',
                           'Report opaque members and undemuxed MPEG/SFD as uninspected, not compatible',
                           'Recheck source metadata and authority hashes after scan'],
                record_schema=['container/member index path and optional name labels', 'ISO absolute and parent-relative extents',
                               'full member SHA-256 and container SHA-256', 'signature-based recognition',
                               'ADX frequency/filter/encoding/bits/channels/version/block bytes/loop fields',
                               'finite header-profile checks, no complete-player claim', 'HSYN HD structural chunks and individual part limit only'],
                limitations=['Owned revision hash authenticates executable identity, not an entire retail disc',
                             'Local read-only opens/stat/hash checks are not hostile concurrent-writer exclusion',
                             'No decompression, MPEG/SFD demux, embedded signature carving, or guessed HD/BD/TQ pairing',
                             'No recording attribution, runtime packet size, simultaneous bank budget, DSP or performance proof'],
                writes='New inventory metadata only; no payload extraction or source/player-state writes')


def scan(source, out, plan):
    spec = importlib.util.spec_from_file_location('owned_afs_table', ROOT/'tools/assets/extract_assets.py')
    afs = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(afs)
    rows, containers, archives = [], [], []
    limit = plan['source']['bytes']
    with source.open('rb') as stream:
        entries = iso_index(stream, limit)
        elf = next((entry for entry in entries if entry['path'] == 'SLUS_207.65'), None)
        if not elf or extent_digest(stream, elf['offset'], elf['bytes'], limit) != ELF_SHA256:
            raise ValueError('Exact File1 ELF identity not established')
        write(out/'verified_index.json', dict(schema=1, elf_sha256=ELF_SHA256, entries=entries))
        iso_sha = extent_digest(stream, 0, limit, limit)
        for entry in entries:
            top_sha = extent_digest(stream, entry['offset'], entry['bytes'], limit)
            container = dict(**entry, sha256=top_sha, iso_sha256=iso_sha)
            containers.append(container)

            def walk(base, size, key, names, parent_relative, depth):
                if depth > 4:
                    raise ValueError('AFS nesting exceeds reviewed limit')
                prefix = read_at(stream, base, min(size,4096), limit)
                table = afs.table(stream, base, size)
                if table is not None:
                    archives.append(dict(container=entry['path'],member=key,names=names,
                                         iso_offset=base,parent_relative_offset=parent_relative,bytes=size,
                                         sha256=extent_digest(stream,base,size,limit),entry_count=len(table)))
                    for index,(offset,length,name) in enumerate(table):
                        if offset % 2048:
                            raise ValueError('Unaligned AFS member')
                        walk(base+offset,length,key+'/'+str(index),names+[name],offset,depth+1)
                    return
                row = dict(container=entry['path'], member=key, names=names,
                           iso_offset=base, parent_relative_offset=parent_relative, bytes=size,
                           container_sha256=top_sha, sha256=extent_digest(stream,base,size,limit),
                           recognition='opaque_unparsed')
                adx = adx_metadata(prefix,size)
                hd = bank_hd_metadata(prefix,size)
                if adx is not None:
                    row['recognition']=adx['recognition'];row['adx']=adx
                elif hd is not None:
                    # Four HD chunks can lie beyond the 4KiB metadata prefix.
                    # Read at most the admitted 2MiB header extent, metadata only.
                    if size <= 2*1024*1024:
                        hd=bank_hd_metadata(read_at(stream,base,size,limit),size)
                    row['recognition']=hd['recognition'];row['bank_hd']=hd
                elif prefix[:4] == b'\0\0\1\xba':
                    row['recognition']='mpeg_program_stream_undemuxed'
                elif not size:
                    row['recognition']='empty'
                rows.append(row)

            walk(entry['offset'],entry['bytes'],entry['path'],[],0,0)
            print(entry['path']+': indexed '+str(len(rows))+' leaves',flush=True)
    stat = source.stat()
    if (stat.st_size,stat.st_mtime_ns)!=(limit,plan['source']['mtime_ns']):
        raise ValueError('Owned source changed during scan')
    if any(digest(ROOT/name)!=value for name,value in plan['source_authority'].items()):
        raise ValueError('Source authority changed during scan')
    counts = Counter(row['recognition'] for row in rows)
    confirmed = [row for row in rows if row['recognition']=='adx_structural_header']
    profiles = Counter((row['adx']['frequency'],row['adx']['filter'],row['adx']['encoding'],row['adx']['bits'],row['adx']['channels'],row['adx']['version'],row['adx']['block_bytes'],row['adx']['version_control'])for row in confirmed)
    summary=dict(schema=1,status='completed_metadata_inventory',iso_sha256=iso_sha,
                 regular_iso_files=len(entries),leaf_members=len(rows),recognition_counts=dict(counts),
                 confirmed_adx=len(confirmed),finite_header_profile=sum(row['adx']['finite_header_profile']for row in confirmed),
                 outside_finite_header_profile=sum(not row['adx']['finite_header_profile']for row in confirmed),
                 adx_profiles=[dict(frequency=k[0],filter=k[1],encoding=k[2],bits=k[3],channels=k[4],version=k[5],block_bytes=k[6],version_control=k[7],count=v)for k,v in sorted(profiles.items())],
                 loop_flags=dict(Counter(str(row['adx']['loop'].get('enabled','unread'))for row in confirmed)),
                 total_adx_samples=sum(row['adx']['total_samples']for row in confirmed),
                 paired_banks=0,bank_pairing_status='not_established',
                 complete_native_player_compatibility='not_claimed',limitations=plan['limitations'])
    summary['afs_archives']=len(archives)
    write(out/'containers.json',containers);write(out/'archives.json',archives);write(out/'members.json',rows);write(out/'summary.json',summary)
    receipt=dict(schema=1,status='passed',read_only_source=True,game_run=False,device_opened=False,
                 plan_sha256=digest(out/'read_plan.json'),iso_sha256=iso_sha,
                 output_sha256={name:digest(out/name)for name in ['read_plan.json','verified_index.json','containers.json','archives.json','members.json','summary.json']},
                 source_authority=plan['source_authority'],inventory_tool_sha256=plan['inventory_tool_sha256'])
    write(out/'receipt.json',receipt)
    print(json.dumps(summary,indent=2))


def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--iso',type=Path,required=True)
    parser.add_argument('--output',type=Path,required=True)
    parser.add_argument('--scan',action='store_true',help='Execute a previously written read_plan.json')
    args=parser.parse_args();source=args.iso.resolve();out=args.output.resolve()
    if not source.is_file() or not out.is_relative_to(ROOT/'build-native-sjuni/audio-asset-inventory'):
        raise ValueError('Owned ISO and private inventory output required')
    if args.scan:
        plan=json.loads((out/'read_plan.json').read_bytes())
        if plan != make_plan(source):
            raise ValueError('Plan/source/authority changed; preserve old output and create a fresh plan')
        if (out/'receipt.json').exists():
            raise ValueError('Completed inventory already exists; preserve it')
        scan(source,out,plan)
    else:
        if out.exists():
            raise ValueError('A fresh metadata output directory is required')
        out.mkdir(parents=True)
        write(out/'read_plan.json',make_plan(source))
        print('Plan written; no asset scan performed: '+str(out/'read_plan.json'))


if __name__=='__main__':
    main()
