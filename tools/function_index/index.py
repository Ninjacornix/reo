#!/usr/bin/env python3
"""Offline File #1 research index. Never imports, starts, or attaches to the game."""
from __future__ import annotations

import argparse
from bisect import bisect_right
from collections import Counter, defaultdict
from contextlib import closing, contextmanager
import csv
from dataclasses import dataclass
import hashlib
import json
from pathlib import Path
import re
import sqlite3
import struct
import sys

ROOT = Path(__file__).resolve().parents[2]
HERE = Path(__file__).resolve().parent
DEFAULT_DB = ROOT / 'build-function-index/index.sqlite'
ELF_SHA = '06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46'
INSN = re.compile(r'^\s*// 0x([\da-f]+): 0x([\da-f]+)\s', re.I)
LINK = re.compile(r'\[([^\]]+)\]\(([^)]+)\)')
SOURCE = re.compile(r'/(output|output_extra|output_ovl/o\d+)/[^/]+_0x([\da-f]+)\.cpp$', re.I)
CATALOGUE_LINK = re.compile(r'(?:^|/)recomp/config/(outbreak_ghidra_functions\.csv|extra_functions\.csv|overlay_maps/ovl(\d+)\.csv)$', re.I)


def hx(value):
    return f'0x{value:08X}'


def key(image, address):
    return f'{image}:{hx(address)}'


def number(value):
    return int(value, 0) if isinstance(value, str) else int(value)


def relative(path, root):
    return Path(path).relative_to(root).as_posix()


def import_notes(root, paths):
    """Import each linked guest entry, including paired entries in one table row."""
    records = {}
    catalogue = None
    for path in paths:
        path = Path(path)
        for line_no, line in enumerate(path.read_text(encoding='utf-8-sig').splitlines(), 1):
            if not line.startswith('| ['):
                continue
            # Narrative may contain an escaped |. Only the first three columns are parsed.
            cells = line.split('|', 4)
            if len(cells) < 5:
                continue
            name, confidence = cells[2].strip(), cells[3].strip()
            names = re.findall(r'`([^`]+)`', name)
            entries = []
            for label, target in LINK.findall(cells[1]):
                match = SOURCE.search(target)
                catalogue_match = CATALOGUE_LINK.search(target)
                if not match and not catalogue_match:
                    continue
                # Entry may live inside a merged neighboring source file.
                label_address = re.search(r'0x([\da-f]+)', label, re.I)
                if not label_address:
                    continue
                address = int(label_address[1], 16)
                if match:
                    image = match[1].split('/')[-1] if match[1].startswith('output_ovl/') else 'main'
                else:
                    # A body can be reviewed from owned raw words even when its
                    # generated C++ is absent. Keep that coverage absent; never
                    # fabricate a source filename to import the reviewed role.
                    image = f'o{catalogue_match[2]}' if catalogue_match[2] else 'main'
                    label_image = re.match(r'(o\d+|main)\b', label, re.I)
                    if label_image and label_image[1].lower() != image:
                        raise ValueError(f'Image label disagrees with linked catalogue: {label}')
                    expected = root / 'recomp/config' / catalogue_match[1]
                    if (path.parent / target).resolve() != expected.resolve():
                        raise ValueError(f'Catalogue link outside expected checkout: {target}')
                    if catalogue is None:
                        catalogue = Catalogue(root)
                    function = catalogue.functions.get(key(image, address))
                    if function is None or function.catalogue != relative(expected, root):
                        raise ValueError(f'Entry absent from linked catalogue: {image}:{hx(address)}')
                entries.append((image, address, target))
            for pos, (image, address, target) in enumerate(entries):
                proposed = names[pos] if len(names) == len(entries) else (names[0] if names else name)
                tier = ('confirmed_static' if confidence.lower().startswith('confirmed') else
                        'probable' if confidence.lower().startswith('probable') else 'speculative')
                item = dict(id=key(image, address), image=image, address=hx(address),
                            proposed_name=proposed, confidence=tier, confidence_detail=confidence,
                            evidence=[dict(path=relative(path, root), line=line_no)],
                            rationale=cells[4].strip().rstrip('|').strip())
                if item['id'] in records:
                    raise ValueError(f'Duplicate annotation: {item["id"]}')
                records[item['id']] = item
    return dict(schema=1, edition='SLUS-20765', elf_sha256=ELF_SHA,
                provenance='Reviewed notebook hypotheses; import does not increase confidence.',
                annotations=sorted(records.values(), key=lambda x: (x['image'], number(x['address']))))


class Elf:
    def __init__(self, path):
        self.data = Path(path).read_bytes()
        self.sha256 = hashlib.sha256(self.data).hexdigest()
        if self.sha256 != ELF_SHA:
            raise ValueError('ELF identity mismatch: this profile accepts only the verified File #1 ELF')
        if len(self.data) < 52 or self.data[:6] != b'\x7fELF\x01\x01':
            raise ValueError('Expected an ELF32 little-endian image')
        phoff = struct.unpack_from('<I', self.data, 28)[0]
        stride, count = struct.unpack_from('<HH', self.data, 42)
        if stride < 32 or phoff + stride * count > len(self.data):
            raise ValueError('Invalid ELF program headers')
        self.segments = []
        for offset in range(phoff, phoff + stride * count, stride):
            kind, file_off, addr, _, size, _, _, _ = struct.unpack_from('<8I', self.data, offset)
            if kind == 1 and size:
                if file_off + size > len(self.data):
                    raise ValueError('ELF segment exceeds file')
                self.segments.append((addr, file_off, size))

    def read(self, address, length):
        for base, offset, size in self.segments:
            if base <= address and address + length <= base + size:
                return self.data[offset + address - base:offset + address - base + length]
        return None

    def string(self, address):
        for base, offset, size in self.segments:
            if base <= address < base + size:
                start = offset + address - base
                data = self.data[start:min(start + 256, offset + size)]
                end = data.find(b'\0')
                if end < 4:
                    return None
                raw = data[:end]
                if all(x in (9, 10, 13) or 32 <= x < 127 for x in raw):
                    return raw.decode('ascii')
        return None


@dataclass
class Function:
    image: str
    start: int
    end: int
    symbol: str
    catalogue: str
    catalogue_line: int
    source: str = ''
    source_bytes: int = 0
    source_line: int = 0

    @property
    def id(self):
        return key(self.image, self.start)


class Catalogue:
    def __init__(self, root):
        self.functions = {}
        self.by_image = defaultdict(list)
        self.starts = {}
        self.warnings = []
        config = root / 'recomp/config'
        maps = [('main', config / 'outbreak_ghidra_functions.csv'),
                ('main', config / 'extra_functions.csv')]
        maps += [(f'o{p.stem[3:]}', p) for p in sorted((config / 'overlay_maps').glob('ovl*.csv'))]
        self.input_hashes = {}
        for image, path in maps:
            if not path.exists():
                continue
            self.input_hashes[relative(path, root)] = hashlib.sha256(path.read_bytes()).hexdigest()
            with path.open(encoding='utf-8-sig', newline='') as stream:
                for line, row in enumerate(csv.DictReader(stream), 2):
                    start, end = number(row['start']), number(row['end'])
                    if end <= start:
                        raise ValueError(f'Invalid catalogue bounds at {path}:{line}')
                    if start % 4 or end % 4:
                        self.warnings.append(f'{key(image, start)}: unaligned catalogue interval; possible data or analysis artifact')
                    ident = key(image, start)
                    if ident in self.functions:
                        if end != self.functions[ident].end:
                            self.warnings.append(f'{ident}: additional catalogue has different end {hx(end)}')
                        continue
                    self.functions[ident] = Function(image, start, end, row['name'], relative(path, root), line)
        for f in self.functions.values():
            self.by_image[f.image].append(f)
        for image, rows in self.by_image.items():
            rows.sort(key=lambda f: f.start)
            self.starts[image] = [f.start for f in rows]

    def owner(self, image, address):
        rows = self.by_image.get(image, [])
        pos = bisect_right(self.starts.get(image, []), address) - 1
        if pos >= 0 and address < rows[pos].end:
            return rows[pos]
        return None

    def resolve(self, image, address):
        # Local overlay and permanently resident main code have precedence.
        for tag in dict.fromkeys((image, 'main')):
            found = self.owner(tag, address)
            if found:
                return [found.id], 'exact' if found.start == address else 'interior'
        candidates = [found.id for tag in self.by_image if tag not in (image, 'main')
                      if (found := self.owner(tag, address))]
        if candidates:
            return sorted(candidates), 'overlay_unverified' if len(candidates) == 1 else 'ambiguous_overlay'
        return [], 'unresolved'


def source_files(root):
    config = root / 'recomp/config'
    for folder in ('output', 'output_extra'):
        for path in sorted((config / folder).glob('*.cpp')):
            if re.search(r'_0x[\da-f]+\.cpp$', path.name, re.I):
                yield 'main', path
    for directory in sorted((config / 'output_ovl').glob('o*')):
        if directory.is_dir() and re.fullmatch(r'o\d+', directory.name):
            for path in sorted(directory.glob('*.cpp')):
                if re.search(r'_0x[\da-f]+\.cpp$', path.name, re.I):
                    yield directory.name, path


def read_instructions(path):
    """Never load generated C++ as code. Return only instruction addresses/words/line numbers."""
    result = {}
    with path.open(encoding='utf-8-sig', errors='replace') as stream:
        for line_no, line in enumerate(stream, 1):
            match = INSN.match(line)
            if match:
                address, word = int(match[1], 16), int(match[2], 16)
                if word > 0xffffffff:
                    raise ValueError(f'Invalid instruction word: {path}:{line_no}')
                if address in result and result[address][0] != word:
                    raise ValueError(f'Conflicting instruction comments: {path}:{line_no}')
                result[address] = word, line_no
    return result


def signed16(word):
    return (word & 0x7fff) - (word & 0x8000)


def control(pc, word):
    op, rs, rt = word >> 26, (word >> 21) & 31, (word >> 16) & 31
    if op in (2, 3):
        return True, ((pc + 4) & 0xf0000000) | ((word & 0x3ffffff) << 2)
    if (op in (1, 4, 5, 6, 7, 20, 21, 22, 23) or
            (op in (16, 17, 18) and rs == 8)):
        return True, (pc + 4 + signed16(word) * 4) & 0xffffffff
    return op == 0 and word & 63 in (8, 9), None


def address_class(address):
    if 0x10000 <= address < 0x2000000:
        return 'ram_candidate'
    if 0x10000000 <= address < 0x14000000:
        return 'mmio_candidate'
    if 0x70000000 <= address < 0x70004000:
        return 'scratchpad_candidate'
    for base in (0x20000000, 0x80000000, 0xa0000000):
        if base <= address < base + 0x2000000:
            return 'ram_alias_candidate'
    return None


def physical(address):
    return address & 0x1fffffff if address_class(address) == 'ram_alias_candidate' else address


def extract(function, instructions):
    """Conservative constants within straight-line blocks, not full MIPS dataflow analysis."""
    cuts = {function.start}
    for pc, word, _ in instructions:
        branch, target = control(pc, word)
        if branch:
            cuts.add(pc + 8)
            if target is not None:
                cuts.add(target)
    known, previous = {}, None
    edges, refs = [], []
    for pc, word, line in instructions:
        if pc in cuts or previous is not None and pc != previous + 4:
            known.clear()
        known[0] = 0
        op, rs, rt, rd, fn = word >> 26, (word >> 21) & 31, (word >> 16) & 31, (word >> 11) & 31, word & 63
        a, b = known.get(rs), known.get(rt)
        branch, target = control(pc, word)
        kind = None
        if op == 3 or op == 1 and rt in (16, 17, 18, 19):
            kind = 'call'
        elif op == 2 and not function.start <= target < function.end:
            kind = 'tail_jump_candidate'
        elif op == 0 and fn == 9:
            kind, target = 'indirect_call', a
        elif op == 0 and fn == 8 and rs != 31:
            # Switches use JR too; never label these as confirmed calls.
            kind, target = 'indirect_jump', a
        if kind:
            edges.append(dict(site=pc, target=target, kind=kind, line=line))
        value = None
        if op == 15:
            value = (word & 0xffff) << 16
            known[rt] = value
        elif op in (8, 9, 24, 25, 13, 12, 14):
            if a is not None:
                value = ((a | (word & 0xffff)) if op == 13 else
                         (a & (word & 0xffff)) if op == 12 else
                         (a ^ (word & 0xffff)) if op == 14 else a + signed16(word)) & 0xffffffff
            known.pop(rt, None)
            if value is not None:
                known[rt] = value
                if op in (8, 9, 24, 25, 13) and address_class(value):
                    refs.append(dict(site=pc, address=value, kind='materialized_address_candidate', line=line))
        elif op in (10, 11, 26, 27) or op in (16, 17, 18) and rs in (0, 1, 2):
            known.pop(rt, None)
        elif 32 <= op <= 63 or op in (30, 31):
            # Memory references are stronger evidence than materialized integers.
            if a is not None and rs not in (0, 29, 30) and op != 47:
                value = (a + signed16(word)) & 0xffffffff
                if address_class(value):
                    stores = op in (31, 40, 41, 42, 43, 44, 45, 46, 56, 57, 58, 60, 61, 62, 63)
                    refs.append(dict(site=pc, address=value, kind='memory_write' if stores else 'memory_read', line=line))
            if op in (30, 32, 33, 34, 35, 36, 37, 38, 39, 48, 52, 55, 56, 60):
                known.pop(rt, None)
        elif op == 0:
            result = None
            if fn in (33, 45, 37) and a is not None and b is not None:
                result = (a | b) if fn == 37 else (a + b) & 0xffffffff
            if fn not in (8, 9, 12, 13, 15, 17, 19, 24, 25, 26, 27, 28, 29, 30, 31):
                known.pop(rd, None)
                if result is not None:
                    known[rd] = result
        elif op == 28:
            # R5900 MMI decoding is deliberately not guessed.
            known.clear()
        elif op not in (1, 2, 3, 4, 5, 6, 7, 16, 17, 18, 20, 21, 22, 23):
            known.clear()
        known.pop(0, None)
        if op == 3:
            known.pop(31, None)
        previous = pc
    return edges, refs


SCHEMA = '''
CREATE TABLE metadata(key TEXT PRIMARY KEY, value TEXT NOT NULL);
CREATE TABLE functions(id TEXT PRIMARY KEY,image TEXT,start INTEGER,end INTEGER,symbol TEXT,
 catalogue TEXT,catalogue_line INTEGER,source TEXT,source_line INTEGER,source_bytes INTEGER,
 instruction_count INTEGER,coverage TEXT,proposed_name TEXT,confidence TEXT,confidence_detail TEXT,
 rationale TEXT,evidence TEXT);
CREATE TABLE edges(caller TEXT,site INTEGER,target INTEGER,kind TEXT,resolution TEXT,candidates TEXT,
 source TEXT,line INTEGER);
CREATE TABLE edge_targets(edge_id INTEGER,callee TEXT);
CREATE TABLE refs(owner TEXT,site INTEGER,address INTEGER,physical INTEGER,kind TEXT,address_class TEXT,
 string TEXT,string_evidence TEXT,source TEXT,line INTEGER);
CREATE INDEX edge_caller ON edges(caller);
CREATE INDEX edge_callee ON edge_targets(callee);
CREATE INDEX ref_owner ON refs(owner);
CREATE INDEX ref_address ON refs(address);
CREATE INDEX ref_physical ON refs(physical);
CREATE INDEX func_start ON functions(start);
'''


def load_annotations(annotation_path, entry_ids):
    annotations_doc = json.loads(annotation_path.read_text(encoding='utf-8'))
    if (annotations_doc.get('schema'), annotations_doc.get('edition'), annotations_doc.get('elf_sha256')) != (1, 'SLUS-20765', ELF_SHA):
        raise ValueError('Annotation identity/schema mismatch')
    annotations = {x['id']: x for x in annotations_doc['annotations']}
    if len(annotations) != len(annotations_doc['annotations']):
        raise ValueError('Duplicate annotation ids')
    for ident, item in annotations.items():
        if ident != key(item['image'], number(item['address'])) or ident not in entry_ids:
            raise ValueError(f'Annotation has no matching catalogue entry: {ident}')
        if item['confidence'] not in ('confirmed_static', 'probable', 'speculative'):
            raise ValueError(f'Unsupported annotation confidence: {ident}')
    return annotations


def refresh_annotations(root, database, annotation_path):
    """Update reviewed hypotheses only; graph and binary/source verification remain a snapshot."""
    root = root.resolve()
    with connect(database) as db:
        expected = json.loads(db.execute("SELECT value FROM metadata WHERE key='expected_main_elf_sha256'").fetchone()[0])
        if expected != ELF_SHA:
            raise ValueError('Index target identity mismatch')
        catalogue_hashes = json.loads(db.execute("SELECT value FROM metadata WHERE key='catalogue_hashes'").fetchone()[0])
        if Catalogue(root).input_hashes != catalogue_hashes:
            raise ValueError('Catalogue changed; rebuild static index before refreshing annotations')
        ids = {r[0] for r in db.execute('SELECT id FROM functions')}
    annotations = load_annotations(annotation_path, ids)
    uri = database.resolve().as_uri() + '?mode=rw'
    with closing(sqlite3.connect(uri, uri=True)) as db, db:
        db.execute("UPDATE functions SET proposed_name='',confidence='unknown',confidence_detail='',rationale='',evidence='[]'")
        db.executemany('UPDATE functions SET proposed_name=?,confidence=?,confidence_detail=?,rationale=?,evidence=? WHERE id=?',
                       [(x['proposed_name'], x['confidence'], x.get('confidence_detail', ''),
                         x.get('rationale', ''), json.dumps(x.get('evidence', [])), x['id']) for x in annotations.values()])
        db.execute("UPDATE metadata SET value=? WHERE key='annotation_sha256'",
                   (json.dumps(hashlib.sha256(annotation_path.read_bytes()).hexdigest()),))
    return len(annotations)


def build(root, output, annotation_path, elf_path=None):
    catalogue = Catalogue(root)
    annotations = load_annotations(annotation_path, catalogue.functions)
    elf = Elf(elf_path) if elf_path else None
    # Resolve ownership per catalogue entry even if a generated file merges several routines.
    collected = defaultdict(dict)
    source_hashes, conflicts = {}, set()
    file_count = 0
    for image, path in source_files(root):
        file_count += 1
        source = relative(path, root)
        raw = path.read_bytes()
        source_hashes[source] = hashlib.sha256(raw).hexdigest()
        words = read_instructions(path)
        start_match = re.search(r'_0x([\da-f]+)\.cpp$', path.name, re.I)
        file_start = int(start_match[1], 16)
        for pc, (word, line) in words.items():
            f = catalogue.owner(image, pc)
            if not f or pc % 4 or pc + 4 > f.end:
                continue
            old = collected[f.id].get(pc)
            if old and old[0] != word:
                conflicts.add((f.id, pc))
                continue
            # Prefer this entry's dedicated file over a merged neighboring file.
            if old is None or file_start == f.start:
                collected[f.id][pc] = word, line, source
            if not f.source or file_start == f.start:
                f.source, f.source_bytes = source, len(raw)
            if pc == f.start and source == f.source:
                f.source_line = line
        if file_count % 2000 == 0:
            print(f'Read {file_count} static source files...', file=sys.stderr, flush=True)
    for ident, pc in conflicts:
        collected[ident].pop(pc, None)
    output.parent.mkdir(parents=True, exist_ok=True)
    temporary = output.with_name(output.name + '.building')
    if temporary.exists():
        raise ValueError(f'Previous incomplete build exists: {temporary}; choose a different output or inspect it')
    try:
        with closing(sqlite3.connect(temporary)) as db, db:
            db.executescript(SCHEMA)
            verification = Counter()
            for ident, f in sorted(catalogue.functions.items()):
                records = collected.get(ident, {})
                instructions = [(pc, r[0], r[1]) for pc, r in sorted(records.items())]
                annotation = annotations.get(ident, {})
                covered = len(instructions) * 4
                coverage = ('unaligned_catalogue' if f.start % 4 or f.end % 4 else
                            'complete' if covered == f.end - f.start else 'partial' if covered else 'missing')
                db.execute('INSERT INTO functions VALUES(?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)',
                           (ident, f.image, f.start, f.end, f.symbol, f.catalogue, f.catalogue_line,
                            f.source, f.source_line, f.source_bytes, len(instructions), coverage,
                            annotation.get('proposed_name', ''), annotation.get('confidence', 'unknown'),
                            annotation.get('confidence_detail', ''), annotation.get('rationale', ''),
                            json.dumps(annotation.get('evidence', []))))
                if elf and f.image == 'main':
                    for pc, word, _ in instructions:
                        actual = elf.read(pc, 4)
                        verification['matched' if actual == struct.pack('<I', word) else
                                     'unmapped' if actual is None else 'mismatched'] += 1
                edges, refs = extract(f, instructions)
                for edge in edges:
                    candidates, resolution = (catalogue.resolve(f.image, edge['target']) if edge['target'] is not None
                                              else ([], 'dynamic_unresolved'))
                    cursor = db.execute('INSERT INTO edges VALUES(?,?,?,?,?,?,?,?)',
                                        (ident, edge['site'], edge['target'], edge['kind'], resolution,
                                         json.dumps(candidates), records[edge['site']][2], edge['line']))
                    db.executemany('INSERT INTO edge_targets VALUES(?,?)', [(cursor.lastrowid, target) for target in candidates])
                for ref in refs:
                    addr = ref['address']
                    text = elf.string(physical(addr)) if elf else None
                    db.execute('INSERT INTO refs VALUES(?,?,?,?,?,?,?,?,?,?)',
                               (ident, ref['site'], addr, physical(addr), ref['kind'], address_class(addr), text,
                                ('verified_main_elf:' + ELF_SHA) if text else '', records[ref['site']][2], ref['line']))
            metadata = dict(schema=1, edition='SLUS-20765', expected_main_elf_sha256=ELF_SHA,
                            main_elf_checked=bool(elf), main_instruction_comparison=dict(verification),
                            catalogue_hashes=catalogue.input_hashes, source_hashes=source_hashes,
                            annotation_sha256=hashlib.sha256(annotation_path.read_bytes()).hexdigest(),
                            generated_sources_read=file_count, conflicting_instruction_sites=len(conflicts),
                            warnings=catalogue.warnings,
                            limitations=['Catalogue intervals are inferred ownership, not proof of semantic boundaries.',
                                         'Calls/references are static candidates, not measured execution or complete dataflow.',
                                         'Cross-overlay edges do not establish runtime residency.',
                                         'Source comments may differ from original ELF or actual compiled binary.',
                                         'Only bounded ASCII strings in the hash-verified main ELF are decoded.',
                                         'Supplemental authored registration groups are outside this catalogue profile.'])
            db.executemany('INSERT INTO metadata VALUES(?,?)', [(k, json.dumps(v, sort_keys=True)) for k, v in metadata.items()])
        temporary.replace(output)
    except BaseException:
        # Keep the previous completed index intact. A failed temporary is inspectable.
        raise
    return output


@contextmanager
def connect(path):
    if not path.is_file():
        raise ValueError(f'Index missing: {path}. Run build first.')
    with closing(sqlite3.connect(path.resolve().as_uri() + '?mode=ro', uri=True)) as db:
        db.row_factory = sqlite3.Row
        if json.loads(db.execute("SELECT value FROM metadata WHERE key='schema'").fetchone()[0]) != 1:
            raise ValueError('Unsupported index schema')
        yield db


def summary(db):
    total = db.execute('SELECT count(*) FROM functions').fetchone()[0]
    named = db.execute("SELECT count(*) FROM functions WHERE confidence!='unknown'").fetchone()[0]
    metadata = {r[0]: json.loads(r[1]) for r in db.execute("SELECT key,value FROM metadata WHERE key IN ('main_elf_checked','main_instruction_comparison','generated_sources_read','conflicting_instruction_sites','warnings')")}
    metadata['catalogue_warnings'] = len(metadata.pop('warnings', []))
    return dict(functions=total, annotated=named, annotated_percent=round(100 * named / total, 3) if total else 0,
                provenance=metadata,
                by_image=[dict(r) for r in db.execute("SELECT image,count(*) functions,sum(confidence!='unknown') annotated FROM functions GROUP BY image ORDER BY image")],
                source_coverage=[dict(r) for r in db.execute('SELECT coverage,count(*) functions FROM functions GROUP BY coverage')],
                edge_resolution=[dict(r) for r in db.execute('SELECT resolution,count(*) edges FROM edges GROUP BY resolution')],
                references=db.execute('SELECT count(*) FROM refs').fetchone()[0],
                string_references=db.execute('SELECT count(*) FROM refs WHERE string IS NOT NULL').fetchone()[0])


def select_function(db, query):
    if ':' in query:
        image, addr = query.split(':', 1)
        row = db.execute('SELECT * FROM functions WHERE id=?', (key(image, number(addr)),)).fetchone()
        if row:
            return row
        rows = db.execute('SELECT * FROM functions WHERE image=? AND start<=? AND end>?',
                          (image, number(addr), number(addr))).fetchall()
        if len(rows) == 1:
            return rows[0]
        if rows:
            raise ValueError('Overlapping catalogue intervals: ' + ', '.join(r['id'] for r in rows))
    else:
        rows = db.execute('SELECT * FROM functions WHERE proposed_name=? OR symbol=?', (query, query)).fetchall()
        if len(rows) == 1:
            return rows[0]
        try:
            address = number(query)
        except ValueError:
            address = None
        if address is not None:
            rows = db.execute('SELECT * FROM functions WHERE start=?', (address,)).fetchall()
            if not rows:
                rows = db.execute('SELECT * FROM functions WHERE start<=? AND end>?', (address, address)).fetchall()
        if len(rows) == 1:
            return rows[0]
        if rows:
            raise ValueError('Ambiguous entry; specify image:address. Candidates: ' + ', '.join(r['id'] for r in rows))
    raise ValueError('Function not found; use search or an image:address key')


def show(db, query):
    row = select_function(db, query)
    result = dict(row)
    result['start'], result['end'] = hx(row['start']), hx(row['end'])
    result['evidence'] = json.loads(row['evidence'])
    result['callees'] = [dict(r) for r in db.execute('SELECT site,target,kind,resolution,candidates,source,line FROM edges WHERE caller=? ORDER BY site', (row['id'],))]
    result['callers'] = [dict(r) for r in db.execute('SELECT e.caller,e.site,e.kind,e.resolution,e.source,e.line FROM edges e JOIN edge_targets t ON t.edge_id=e.rowid WHERE t.callee=? ORDER BY e.caller,e.site', (row['id'],))]
    result['references'] = [dict(r) for r in db.execute('SELECT site,address,physical,kind,address_class,string,string_evidence,source,line FROM refs WHERE owner=? ORDER BY site,address', (row['id'],))]
    for entry in result['callees'] + result['references'] + result['callers']:
        for field in ('site', 'target', 'address', 'physical'):
            if entry.get(field) is not None:
                entry[field] = hx(entry[field])
        if 'candidates' in entry:
            entry['candidates'] = json.loads(entry['candidates'])
    return result


def search(db, query, limit):
    # LIKE metacharacters are literal user input. Bound parameters handle quotes.
    escaped = query.replace('\\', '\\\\').replace('%', '\\%').replace('_', '\\_')
    pattern = '%' + escaped + '%'
    return [dict(r) for r in db.execute('''SELECT f.id,f.symbol,f.proposed_name,f.confidence,f.coverage,f.source
        FROM functions f WHERE f.id LIKE ? ESCAPE '\\' OR f.symbol LIKE ? ESCAPE '\\'
        OR f.proposed_name LIKE ? ESCAPE '\\' OR f.rationale LIKE ? ESCAPE '\\'
        OR EXISTS(SELECT 1 FROM refs r WHERE r.owner=f.id AND r.string LIKE ? ESCAPE '\\')
        ORDER BY (f.confidence!='unknown') DESC,f.image,f.start LIMIT ?''',
        (pattern, pattern, pattern, pattern, pattern, limit))]


def suggestions(db, limit):
    return [dict(r) for r in db.execute('''WITH links AS (
        SELECT DISTINCT e.caller a,t.callee b FROM edges e JOIN edge_targets t ON t.edge_id=e.rowid
        WHERE e.resolution IN ('exact','interior') AND e.kind IN ('call','tail_jump_candidate','indirect_call')
    ), neighbors AS (SELECT a owner,b neighbor FROM links UNION SELECT b,a FROM links)
    SELECT f.id,f.symbol,f.end-f.start guest_bytes,f.instruction_count,f.coverage,
        count(DISTINCT n.neighbor) annotated_neighbors,
        group_concat(DISTINCT k.proposed_name) neighbor_names
    FROM functions f JOIN neighbors n ON n.owner=f.id JOIN functions k ON k.id=n.neighbor
    WHERE f.confidence='unknown' AND k.confidence!='unknown'
    GROUP BY f.id ORDER BY annotated_neighbors DESC,f.instruction_count DESC,f.id LIMIT ?''', (limit,))]


def export_csv(db, output):
    output.parent.mkdir(parents=True, exist_ok=True)
    rows = db.execute('''SELECT f.id,f.image,printf('0x%08X',f.start) start,printf('0x%08X',f.end) end,
        f.symbol,f.proposed_name,f.confidence,f.coverage,f.instruction_count,f.source,f.source_line,
        f.source_bytes,f.catalogue,f.catalogue_line,f.rationale,f.evidence,
        (SELECT count(*) FROM edges e WHERE e.caller=f.id) outgoing_sites,
        (SELECT count(*) FROM edge_targets t WHERE t.callee=f.id) incoming_sites
        FROM functions f ORDER BY f.image,f.start''')
    with output.open('w', encoding='utf-8-sig', newline='') as stream:
        writer = csv.writer(stream)
        writer.writerow([x[0] for x in rows.description])
        for row in rows:
            # Prevent imported narrative/symbol fields becoming spreadsheet formulas.
            writer.writerow(["'" + x if isinstance(x, str) and x.startswith(('=', '+', '-', '@', '\t', '\r')) else x for x in row])


def report(db, output, root):
    data = summary(db)
    lines = ['# Local function index', '',
             'Offline static extraction; names retain notebook confidence. No runtime measurements.', '',
             f"Entries: **{data['functions']}**; annotated: **{data['annotated']}** ({data['annotated_percent']}%).", '',
             '| Image | Entries | Annotated |', '| --- | ---: | ---: |']
    lines += [f"| {r['image']} | {r['functions']} | {r['annotated']} |" for r in data['by_image']]
    lines += ['', '## Next mapping candidates', '',
              'Ranked by known call relationships, not measured runtime or compile cost.', '',
              '| Entry | Known neighbors | Instruction count |', '| --- | ---: | ---: |']
    for row in suggestions(db, 25):
        lines.append(f"| `{row['id']}` | {row['annotated_neighbors']} | {row['instruction_count']} |")
    lines += ['', '## Reviewed annotations', '', '| Entry | Proposed name | Confidence |', '| --- | --- | --- |']
    for row in db.execute("SELECT id,proposed_name,confidence FROM functions WHERE confidence!='unknown' ORDER BY image,start"):
        lines.append(f"| `{row['id']}` | `{row['proposed_name']}` | {row['confidence']} |")
    lines += ['', 'See tools/function_index/README.md for searches, provenance, and limitations.', '']
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_text('\n'.join(lines), encoding='utf-8')


def lower_priority():
    if sys.platform == 'win32':
        import ctypes
        ctypes.windll.kernel32.SetPriorityClass(ctypes.windll.kernel32.GetCurrentProcess(), 0x40)


def main(argv=None):
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--root', type=Path, default=ROOT)
    parser.add_argument('--db', type=Path, default=DEFAULT_DB)
    commands = parser.add_subparsers(dest='command', required=True)
    imp = commands.add_parser('import-notes', help='Create reviewed annotation seed from notebook tables')
    imp.add_argument('--out', type=Path, required=True)
    imp.add_argument('notes', nargs='*', type=Path)
    build_cmd = commands.add_parser('build', help='Read catalogues and generated instruction comments')
    build_cmd.add_argument('--annotations', type=Path, default=HERE / 'annotations.json')
    build_cmd.add_argument('--elf', type=Path, help='Optional owned main ELF: hash verification and ASCII string references')
    refresh_cmd = commands.add_parser('refresh-annotations', help='Update reviewed names without rescanning source or changing the call graph')
    refresh_cmd.add_argument('--annotations', type=Path, default=HERE / 'annotations.json')
    for name in ('search', 'show', 'refs', 'suggest', 'summary', 'export', 'report'):
        cmd = commands.add_parser(name)
        if name in ('search', 'show', 'refs'):
            cmd.add_argument('query')
        if name in ('search', 'suggest', 'refs'):
            cmd.add_argument('--limit', type=int, default=30)
        if name in ('export', 'report'):
            cmd.add_argument('--out', type=Path, required=True)
    args = parser.parse_args(argv)
    root = args.root.resolve()
    if hasattr(args, 'limit') and not 1 <= args.limit <= 1000:
        parser.error('--limit must be between 1 and 1000')
    lower_priority()
    if args.command == 'import-notes':
        notes = args.notes or sorted((root / 'docs').glob('SYMBOLS*.md'))
        result = import_notes(root, [p.resolve() for p in notes])
        args.out.parent.mkdir(parents=True, exist_ok=True)
        args.out.write_text(json.dumps(result, indent=2, ensure_ascii=False) + '\n', encoding='utf-8')
        print(f"Imported {len(result['annotations'])} annotations into {args.out}")
        return
    if args.command == 'build':
        print(build(root, args.db.resolve(), args.annotations.resolve(), args.elf))
        return
    if args.command == 'refresh-annotations':
        count = refresh_annotations(root, args.db, args.annotations.resolve())
        print(f'Refreshed {count} reviewed annotations; static graph and source snapshot retained.')
        return
    with connect(args.db) as db:
        if args.command == 'summary':
            result = summary(db)
        elif args.command == 'show':
            result = show(db, args.query)
        elif args.command == 'search':
            result = search(db, args.query, args.limit)
        elif args.command == 'suggest':
            result = suggestions(db, args.limit)
        elif args.command == 'refs':
            addr = number(args.query)
            result = [dict(r) for r in db.execute('SELECT * FROM refs WHERE address=? OR physical=? ORDER BY owner,site LIMIT ?', (addr, physical(addr), args.limit))]
        elif args.command == 'export':
            export_csv(db, args.out)
            result = dict(csv=str(args.out))
        else:
            report(db, args.out, root)
            result = dict(markdown=str(args.out))
        print(json.dumps(result, indent=2, ensure_ascii=False))


if __name__ == '__main__':
    try:
        main()
    except (ValueError, OSError, sqlite3.Error) as error:
        raise SystemExit(str(error))
