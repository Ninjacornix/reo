"""Hash-verified owned script tables and conservative qualified-flow frontiers.

Never executes a script/game and never scans an arbitrary whole extent as code.
"""
import argparse,collections,hashlib,json,os,re,shutil,struct,subprocess
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3];HERE=Path(__file__).resolve().parent
INDEX=ROOT/'build-native-sjuni/audio-asset-inventory/file1-v1'
ELF_SHA='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46'
OVERLAY_SHA='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226'
OPENERS={0xe6,8,0xe3,0x34,0xe9,0xea,0xec,0xed,0x14,0x113,0x150,0x151,0x152,0x153,0x155,0x156,0xc2,0xc3,0xee,0x36,0x47,0x48,0x49,0x4d,0xb7,0xb8,0x158,0x180,0x159,0x17,0x1aa,0x1ac}
CONDITIONS={8,0x14,0x17,0x34,0x36,0x47,0x48,0x49,0x4d,0xe3,0xe6,0xe9,0xec,0xed,0xef,0x113,0xb7,0xb8}
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def write(p,d):p.write_text(json.dumps(d,indent=2)+'\n')
def word(b,at):return struct.unpack_from('<I',b,at)[0]
def invoke(cmd,out,label):
    result=subprocess.run(cmd,capture_output=True,text=True,timeout=180)
    (out/(label+'.stdout.txt')).write_text(result.stdout);(out/(label+'.stderr.txt')).write_text(result.stderr)
    if result.returncode:raise RuntimeError(label+' failed: '+result.stderr[-4000:])
    return dict(command=cmd,exit_code=result.returncode,stdout_sha256=sha(out/(label+'.stdout.txt')),stderr_sha256=sha(out/(label+'.stderr.txt')))
def objects(data,kind):
    count=32 if kind=='E' else 16
    if len(data)<4*count:raise ValueError('Truncated declared script table')
    table=struct.unpack_from('<'+'I'*count,data);result=[]
    for i,start in enumerate(table):
        if not start:continue
        if not 4*count<=start<=len(data):raise ValueError('Unbounded declared script reference')
        end=min([n for n in table if n>start]+[len(data)])
        role=(0 if i<8 else 1 if i<16 else 2 if i<24 else 3) if kind=='E' else (0 if i>=8 else 3)
        record=dict(table_index=i,role=role,offset=start,upper_bound_bytes=end-start)
        if role==2:
            at=start;references=[]
            while at+4<=end:
                value=word(data,at);at+=4
                if not value:break
                if not 4*count<=value<=len(data):raise ValueError('Unbounded indirect reference')
                references.append(value)
            else:raise ValueError('Unterminated indirect reference table')
            record['indirect_count']=len(references)
        result.append(record)
    return table,result
def prefix_graph(data,kind,table,declared,mask,profile,filters):
    bounds=[(x['offset'],x['offset']+x['upper_bound_bytes']) for x in declared if x['role']==0]
    roots=[i for i in ([0,4] if kind=='E' else [8,12]) if table[i]]
    queue=collections.deque((table[i],i,None,0) for i in roots);seen=set();executed={};scanned=set();frontiers={};max_states=20000
    def frontier(reason,pc,block,opcode=None):
        frontiers[(reason,pc,block,opcode)]=dict(reason=reason,offset=pc,block_index=block,opcode=opcode)
    def read(pc,scan=False):
        bound=next(((lo,hi) for lo,hi in bounds if lo<=pc<hi),None)
        if not bound or pc&3 or pc+4>bound[1]:raise ValueError('unproven_code_extent')
        header=word(data,pc);span=((1<<((header>>24)&31))*4)&0xffffffff;op=header&0xffffff
        if not span or pc+span>bound[1]:raise ValueError('invalid_or_unproven_record_extent')
        if not scan and op>=432:raise ValueError('unknown_opcode')
        return op,span
    def scan(pc,condition,failed):
        saved=condition
        for _ in range(4096):
            _,span=read(pc,True);pc+=span;op,span=read(pc,True);scanned.add(pc);condition=(condition+(op in OPENERS))&0xffffffff
            if failed and op==0xe4 and condition==saved:return pc+span,condition
            if op==0xe5:
                if condition==saved:return pc+span,(condition-1)&0xffffffff
                condition=(condition-1)&0xffffffff
            if op in [0xa,0xd]:return pc,0
        raise ValueError('bounded_scanner_frontier')
    while queue and len(seen)<max_states:
        pc,block,saved,condition=queue.popleft();state=(pc,block,saved,condition)
        if state in seen:continue
        seen.add(state)
        try:op,span=read(pc)
        except ValueError as error:frontier(str(error),pc,block);continue
        executed[pc]=op;next_pc=pc+span
        def add(target,new_block=block,new_saved=saved,new_condition=condition):queue.append((target,new_block,new_saved,new_condition))
        # Context gates can vary across real invocations. Retaining both paths
        # is conservative and is not a proof that either occurred in a session.
        if profile=='offline_actor' and any(filters[op]):
            try:
                target,nesting=scan(pc,(condition+1)&0xffffffff,True) if op in OPENERS else (next_pc,condition)
                add(target,new_condition=nesting)
            except ValueError as error:frontier('skip_'+str(error),pc,block,op)
        if not mask[op]:frontier('unsupported_handler_semantics',pc,block,op);continue
        def payload(at):
            if at+4>span-4:raise ValueError('truncated_qualified_payload')
            return word(data,pc+4+at)
        try:
            if op in [0xe8,0xe9] and payload(0)>=2:raise ValueError('native_counter_index_profile_refused')
            if op in [0x10,0x11] and payload(0)>=256:raise ValueError('native_sequence_index_profile_refused')
            if op in [5,6] and profile=='ordinary' and payload(0)>=4:raise ValueError('native_actor_event_slot_profile_refused')
            if op==1:add(next_pc,new_saved=next_pc)
            elif op in [2,0xa]:
                if saved is None:raise ValueError('initial_saved_pointer_unknown')
                add(saved,new_condition=0 if op==0xa else condition)
            elif op in [7,0xd]:
                index=block+1
                if index>=len(table) or not table[index]:raise ValueError('next_block_unbound')
                if not any(x['role']==0 and x['table_index']==index for x in declared):raise ValueError('next_block_role_unproven')
                add(table[index],new_block=index,new_condition=0 if op==0xd else condition)
            elif op==3:
                count=payload(0);target=pc
                if count>4096:raise ValueError('bounded_skip_count_frontier')
                for _ in range(count):_,size=read(target,True);target+=size
                add(target)
            elif op==4:add(next_pc,new_condition=0 if payload(0) else condition)
            elif op==0xe4:
                target,nesting=scan(pc,condition,False);add(target,new_condition=nesting)
            elif op==0xe5:add(next_pc,new_condition=(condition+1)&0xffffffff)
            elif op in CONDITIONS:
                if op==0x113 and payload(0)>=4:add(next_pc);continue
                nesting=(condition+(op!=0x36))&0xffffffff
                if op!=0x17 or payload(4) in [0,1]:add(next_pc,new_condition=nesting)
                if op==0x113 and payload(8)>=6:continue
                target,nesting=scan(pc,nesting,True);add(target,new_condition=nesting)
            else:add(next_pc)
        except ValueError as error:frontier(str(error),pc,block,op)
    if queue:frontier('state_budget_exhausted',queue[0][0],queue[0][1])
    return dict(profile=profile,configured_nonnull_roots=roots,states=len(seen),candidate_records=[dict(offset=p,opcode=op,native_algorithm=mask[op]) for p,op in sorted(executed.items())],
        scanned_header_offsets=sorted(scanned),frontiers=list(frontiers.values()),closed_under_qualified_model=not frontiers,
        runtime_reachability_proven=False,native_game_admission_proven=False,full_native_payload_profile_checked=False)
def main(a):
    cc=Path(a.compiler).resolve();out=a.output.resolve();data_root=a.data_root.resolve()
    assert cc.exists() and not out.exists() and out.is_relative_to(ROOT/'build-native-sjuni');out.mkdir(parents=True)
    index_receipt=json.loads((INDEX/'receipt.json').read_text());assert index_receipt['status']=='passed'
    for name,digest in index_receipt['output_sha256'].items():assert sha(INDEX/name)==digest
    members=json.loads((INDEX/'members.json').read_text());containers={r['path']:r for r in json.loads((INDEX/'containers.json').read_text())}
    imported=json.loads((data_root.parent/'import.json').read_text());assert imported['ElfSha256']==ELF_SHA
    files={r['Name']:r for r in imported['Files']};asset_path=data_root.parent/'assets.json';asset_index=json.loads(asset_path.read_text());assets={r['path']:r for r in asset_index['entries']}
    selected=[r for r in members if r['names'] and r['names'][-1].lower().endswith(('.evb','.rdt'))]
    assert len(selected)==171
    case_lines=[];payloads=[];identities=[];source_stamps={}
    for r in selected:
        archive=data_root/r['container'];container=containers[r['container']];offset=r['iso_offset']-container['offset'];entry=assets[r['member']]
        assert files[r['container']]['Sha256']==r['container_sha256'] and archive.stat().st_size==container['bytes']
        assert entry['offset']==offset and entry['size']==r['bytes'] and entry['name'].lower()==r['names'][-1].lower() and not entry['isArchive']
        source_stamps[str(archive)]=(archive.stat().st_size,archive.stat().st_mtime_ns)
        with archive.open('rb') as stream:stream.seek(offset);raw=stream.read(r['bytes'])
        assert hashlib.sha256(raw).hexdigest()==r['sha256'];kind='E' if r['names'][-1].lower().endswith('.evb') else 'R'
        if kind=='R':
            if len(raw)<256:raise ValueError('Truncated RDT directory')
            for i in range(32):
                off,size=struct.unpack_from('<II',raw,8*i)
                if size and (off>len(raw) or size>len(raw)-off):raise ValueError('Unbounded RDT section')
            off,size=struct.unpack_from('<II',raw,8);bank=raw[off:off+size] if size else None
        else:bank=raw
        case_lines.append('\t'.join([kind,str(archive),str(offset),str(r['bytes'])]));payloads.append((kind,bank))
        identities.append(dict(member=r['member'],name=r['names'][-1],archive=str(archive),archive_offset=offset,bytes=r['bytes'],sha256=r['sha256']))
    (out/'cases.tsv').write_text('\n'.join(case_lines)+'\n')
    sources=[HERE/'content_checks.cpp',Path(__file__),ROOT/'game/native/gameplay_scenario/content.hpp',ROOT/'game/native/gameplay_scenario/content.cpp']
    before={p.relative_to(ROOT).as_posix():sha(p) for p in sources}
    for p in sources:shutil.copyfile(p,out/p.name)
    os.environ['PATH']=str(cc.parent)+os.pathsep+os.environ.get('PATH','');exe=out/'content-checks.exe'
    checks=[invoke([str(cc),'-std=c++20','-O2','-Wall','-Wextra','-Wpedantic','-Werror','-I'+str(ROOT),str(ROOT/'game/native/gameplay_scenario/content.cpp'),str(HERE/'content_checks.cpp'),'-o',str(exe)],out,'compile')]
    checks.append(invoke([str(exe)],out,'fixtures'));checks.append(invoke([str(exe),str(out/'cases.tsv')],out,'owned-members'))
    native=json.loads((out/'owned-members.stdout.txt').read_text());assert len(native)==len(selected)
    qualification_path=a.qualification.resolve();qualification=json.loads(qualification_path.read_text());assert len(qualification['bindings'])==432
    overlay=(ROOT/'build-function-index/owned-overlays/o2.bin').read_bytes();assert hashlib.sha256(overlay).hexdigest()==OVERLAY_SHA
    filters=[struct.unpack_from('<3B',overlay,0x73cbe0-0x570000+8*i+4) for i in range(432)]
    masks={profile:[r[profile]['native_algorithm'] for r in qualification['bindings']] for profile in ['ordinary','offline_actor']}
    records=[];totals=collections.Counter();frontier_ops={p:collections.Counter() for p in masks};candidate_ops={p:collections.Counter() for p in masks}
    for index,((kind,bank),identity,actual) in enumerate(zip(payloads,identities,native)):
        table,declared=objects(bank,kind) if bank is not None else ((),[])
        assert actual==dict(index=index,objects=declared,absent=bank is None)
        profiles=[]
        for profile,mask in masks.items():
            graph=prefix_graph(bank,kind,table,declared,mask,profile,filters) if bank else dict(profile=profile,frontiers=[],candidate_records=[],closed_under_qualified_model=True)
            profiles.append(graph)
            for r in graph['candidate_records']:candidate_ops[profile][r['opcode']]+=1
            for r in graph['frontiers']:
                if r.get('opcode') is not None:frontier_ops[profile][r['opcode']]+=1
            totals[profile+'_open_banks']+=bool(graph['frontiers'])
        totals[kind+'_members']+=1;totals[kind+'_declared_code_candidates']+=sum(r['role']==0 for r in declared)
        records.append(dict(**identity,format=kind,declared_objects=declared,profiles=profiles))
    authority={};instruction_comments=0
    for ident in ['0068C260','0068C410','0068C570','00700330']:
        p=next((ROOT/'recomp/config/output_ovl/o2').glob('o2_'+ident+'_*'));authority[p.relative_to(ROOT).as_posix()]=sha(p)
        for pc,opcode in re.findall(r'// (0x[0-9a-f]+): (0x[0-9a-f]+)\s',p.read_text()):assert word(overlay,int(pc,16)-0x570000)==int(opcode,16);instruction_comments+=1
    elf=data_root/'SLUS_207.65';assert sha(elf)==ELF_SHA;raw=elf.read_bytes();phoff=word(raw,28);size,count=struct.unpack_from('<HH',raw,42);loads=[struct.unpack_from('<8I',raw,phoff+i*size) for i in range(count)];loads=[p for p in loads if p[0]==1]
    for ident in ['001D3790','001D3830','001D3E90']:
        p=next((ROOT/'recomp/config/output').glob('sub_'+ident+'_*'));authority[p.relative_to(ROOT).as_posix()]=sha(p)
        for pc,opcode in re.findall(r'// (0x[0-9a-f]+): (0x[0-9a-f]+)\s',p.read_text()):
            at=int(pc,16);segment=next(s for s in loads if s[2]<=at and at+4<=s[2]+s[4]);assert word(raw,segment[1]+at-segment[2])==int(opcode,16);instruction_comments+=1
    assert all(sha(ROOT/p)==digest for p,digest in before.items())
    assert all((Path(p).stat().st_size,Path(p).stat().st_mtime_ns)==stamp for p,stamp in source_stamps.items())
    summary=dict(status='passed',counts=dict(totals),distinct_prefix_candidates={p:len(v) for p,v in candidate_ops.items()},
        candidate_opcode_occurrences={p:{f'{k:03X}':v for k,v in sorted(c.items())} for p,c in candidate_ops.items()},
        frontier_opcode_occurrences={p:{f'{k:03X}':v for k,v in c.most_common()} for p,c in frontier_ops.items()},
        unknown_named_sgl_members=sum(bool(r['names']) and r['names'][-1].lower().endswith('.sgl') for r in members),unnamed_archive_members=sum(not r['names'] for r in members),
        runtime_reachability_proven=False,full_stock_program_admission=False)
    write(out/'inventory.json',records);write(out/'summary.json',summary)
    receipt=dict(status='passed',compiler=str(cc),compiler_sha256=sha(cc),source_sha256=before,source_authority_sha256=authority,checked_owned_instruction_comments=instruction_comments,
        index_receipt_sha256=sha(INDEX/'receipt.json'),assets_manifest_sha256=sha(asset_path),import_manifest_sha256=sha(data_root.parent/'import.json'),capability_ledger_sha256=sha(qualification_path),
        checks=checks,native_fixture_result=json.loads((out/'fixtures.stdout.txt').read_text()),owned_member_count=len(selected),owned_payload_sha256_verified=True,
        output_sha256={n:sha(out/n) for n in ['inventory.json','summary.json','cases.tsv']},game_launched=False,live_process_access=False,installed_in_game=False,
        limitations=['Configured roots and declared ranges are source-derived; next-object bounds are not bytecode lengths.',
            'Only the selected qualified handler ledger flow is modeled. Unsupported handlers stop that execution path; their continuations remain unknown.',
            'Condition and context choices are conservative alternatives, not proof that a path is reachable in a real stock session.',
            'Initial saved pointer, profile failures, extent and state-budget frontiers remain explicit unknowns.',
            'Five named SGL files and unnamed archive members are unparsed, including offline room variant script resources.',
            'No script was executed or installed, no whole archive/ISO was rehashed, and no performance measurement was made.'])
    write(out/'receipt.json',receipt);print(json.dumps(dict(status='passed',output=str(out),counts=summary['counts'],distinct_prefix_candidates=summary['distinct_prefix_candidates'],fixture_checks=receipt['native_fixture_result']['checks'])))
if __name__=='__main__':
    p=argparse.ArgumentParser();p.add_argument('--compiler',required=True);p.add_argument('--output',required=True,type=Path);p.add_argument('--data-root',required=True,type=Path);p.add_argument('--qualification',type=Path,default=ROOT/'tools/native_reconstruction/gameplay_scenario_qualification_v4.json');main(p.parse_args())
