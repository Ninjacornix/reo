"""Image-independent VU instruction/CFG decoding and owned local input loader."""
import argparse
import collections
import hashlib
import json
from pathlib import Path
import struct

BRANCHES={0x20,0x21,0x24,0x25,0x28,0x29,0x2c,0x2d,0x2e,0x2f}
INDIRECT={0x24,0x25}
CONDITIONAL={0x28,0x29,0x2c,0x2d,0x2e,0x2f}

def decode(code,pc):
    lo,hi=struct.unpack_from('<II',code,pc)
    literal=bool(hi&0x80000000)
    op=(lo>>25)&127
    branch=not literal and op in BRANCHES
    immediate=lo&2047
    if immediate&1024:immediate-=2048
    target=(pc+8+immediate*8)&16383
    return dict(pc=pc,lower=lo,upper=hi,literal=literal,e=bool(hi&0x40000000),
        branch=branch,indirect=branch and op in INDIRECT,conditional=branch and op in CONDITIONAL,
        target=target,xgkick=not literal and op==0x40 and lo&2047==0x6fc,
        upper_pipeline='FMAC',lower_pipeline='FDIV' if not literal and op==0x40 and lo&2047 in (0x3bc,0x3bd,0x3be)
        else 'EFU' if not literal and op==0x40 and lo&2047 in (0x73c,0x73d,0x73e,0x73f,0x77e,0x7bd,0x7bc,0x7be)
        else 'literal' if literal else 'integer_memory_control')

def reachable(code,starts):
    """Explore branch/E delay state, including branch in a delay pair.

    Reachable indirect control conservatively includes every aligned PC. It is
    never narrowed using one captured register value or a historical trace.
    """
    queue=collections.deque((pc,None,False) for pc in starts)
    seen=set();pcs=set();resume=set()
    while queue:
        pc,pending,e_pending=queue.popleft()
        if (pc,pending,e_pending) in seen:continue
        seen.add((pc,pending,e_pending));pcs.add(pc)
        ins=decode(code,pc)
        if ins['indirect']:
            return list(range(0,len(code),8)),dict(reason='reachable_indirect_conservative_full_memory',states=len(seen),resume_pcs=sorted(resume))
        next_pc=pending if pending is not None else (pc+8)%len(code)
        targets=[None]
        if ins['branch']:
            targets=[ins['target']]
            if ins['conditional']:targets.append(None)
        for target in targets:
            if e_pending:resume.add(target if target is not None else next_pc)
            else:queue.append((next_pc,target,ins['e']))
    return sorted(pcs),dict(reason='complete_static_branch_and_E_delay_closure',states=len(seen),resume_pcs=sorted(resume))

def load_inputs(args):
    programs={}
    def add(code,start,provenance,enabled_by_default=False):
        if len(code)!=16384 or start&7 or start>=16384:raise ValueError('Expected16KiB code/aligned startPC')
        digest=hashlib.sha256(code).hexdigest()
        item=programs.setdefault(digest,dict(code=code,starts=set(),default_starts=set(),provenance=set(),enabled_by_default=False))
        if item['code']!=code:raise ValueError('FullSHA256 collision with unequal bytes')
        item['starts'].add(start);item['provenance'].add(provenance)
        item['enabled_by_default'] |= enabled_by_default
        if enabled_by_default:item['default_starts'].add(start)
    for folder in args.capture_dir:
        for path in sorted(folder.glob('*.code.bin')):
            state=Path(str(path)[:-9]+'.state.bin').read_bytes()
            if len(state)!=632:raise ValueError('Unsupported632-byte capture state format')
            add(path.read_bytes(),struct.unpack_from('<I',state,604)[0],str(path))
    if args.collection:
        images={}
        for raw in (args.collection/'events.jsonl').read_text().splitlines():
            event=json.loads(raw)
            if event['event']=='image':
                enabled_by_default=event.get('enabled_by_default',False)
                if type(enabled_by_default) is not bool:raise ValueError('Invalid VU default policy')
                path=(args.collection/event['file']).resolve()
                if path.parent!=args.collection.resolve():raise ValueError('Image path escapes collection')
                code=path.read_bytes()
                if len(code)!=event['bytes'] or hashlib.sha256(code).hexdigest()!=event['sha256']:raise ValueError('Image hash/size mismatch')
                images[event['image']]=(code,enabled_by_default)
            if event['event']=='launch':
                code,enabled_by_default=images[event['image']]
                if hashlib.sha256(code).hexdigest()!=event['sha256']:raise ValueError('Launch image identity mismatch')
                add(code,event['start_pc'],str(args.collection/'events.jsonl'),enabled_by_default)
    if not programs:raise ValueError('No owned launch identities')
    return programs
