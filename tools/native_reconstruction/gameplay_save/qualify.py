"""Seal native save parity, original caller contracts and unported VM inventory."""
import hashlib,json,re,struct
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3]
HERE=Path(__file__).resolve().parent
TARGET=ROOT/'tools/native_reconstruction/gameplay_save_qualification_v1.json'
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def load(p):return json.loads(p.read_bytes())
def main():
    receipts={}
    for label,directory in [('llvm','gameplay-save-llvm-v3'),('gcc','gameplay-save-gcc-v2')]:
        path=ROOT/'build-native-sjuni'/directory/'receipt.json';r=load(path)
        assert r['status']=='passed' and r['result']['checks']==1018 and all(c['exit_code']==0 for c in r['checks'])
        assert sha(Path(r['compiler']))==r['compiler_sha256']
        for name,digest in r['source_sha256'].items():assert sha(ROOT/name)==digest
        for item in r['original_sources']:assert sha(ROOT/item['path'])==item['sha256']
        receipts[label]=dict(path=path.relative_to(ROOT).as_posix(),sha256=sha(path),compiler_sha256=r['compiler_sha256'],result=r['result'],checked_original_instruction_comments=r['checked_original_instruction_comments'])
    inventory=load(ROOT/'build-native-sjuni/gameplay-save-llvm-v3/scenario-inventory.json')
    assert inventory==load(ROOT/'build-native-sjuni/gameplay-save-gcc-v2/scenario-inventory.json')
    assert len(inventory['native_mask'])==432 and not any(inventory['native_mask'])
    inventory_path=HERE/'scenario_inventory_v1.json'
    with inventory_path.open('x',encoding='utf8',newline='\n') as f:json.dump(inventory,f,indent=2);f.write('\n')
    elf=ROOT/'build-native-sjuni/launcher-native-prep-v1/imports/file1/25e64b631bbaa0cac9a4822cb66174ff14c3531851d1e502c0a06704379bf446/data/SLUS_207.65'
    raw=elf.read_bytes();assert sha(elf)=='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46'
    phoff=struct.unpack_from('<I',raw,28)[0];size,count=struct.unpack_from('<HH',raw,42)
    segments=[struct.unpack_from('<IIIIIIII',raw,phoff+i*size) for i in range(count)]
    def word(at):
        p=next(p for p in segments if p[0]==1 and p[2]<=at and at+4<=p[2]+p[4]);return struct.unpack_from('<I',raw,p[1]+at-p[2])[0]
    callers=[];paths=[]
    for ident in ['001C3150','001C3590','001C3950','001C3C90','001C4390','001C4970']:
        p=next((ROOT/'recomp/config/output').glob('sub_'+ident+'_*'));paths.append(p);sites=[]
        for pc,instruction,target in re.findall(r'// (0x[0-9a-f]+): (0x[0-9a-f]+)\s+(?:jal|j)\s+func_(1C(?:5410|55C0|5630))',p.read_text()):
            assert word(int(pc,16))==int(instruction,16)
            sites.append(dict(pc=pc,instruction=instruction,original_target='0x'+target.lower(),migrated=False))
        callers.append(dict(original_entry='0x'+ident.lower().lstrip('0'),source=p.relative_to(ROOT).as_posix(),source_sha256=sha(p),sites=sites))
    dependencies=[]
    for ident,contract in [('001BF660','Original timestamp conversion, clock fallback and calendar helpers; external service.'),('001AEC80','Shared RNG draw with argument1, after capture copies; external service.'),('001BADF0','Settings mirrors and dependent audio/settings calls before flag restoration; external service.')]:
        p=next((ROOT/'recomp/config/output').glob('sub_'+ident+'_*'));paths.append(p)
        dependencies.append(dict(entry='0x'+ident.lower().lstrip('0'),source=p.relative_to(ROOT).as_posix(),source_sha256=sha(p),contract=contract,native_owner_migrated=False))
    docs=sorted((ROOT/'docs').glob('SYMBOLS_SCENARIO*.md'))+[ROOT/'docs'/n for n in ['SYMBOLS_SCRIPT_VM.md','SYMBOLS_TASK_FLAGS.md','SYMBOLS_SAVE_SNAPSHOT_SECTIONS_AND_CODEC.md','SYMBOLS_CARD_UI_SAVE_LOAD_AND_RESUME.md']]
    paths+=docs+[ROOT/'docs/native-gameplay/SCENARIO_AND_SAVE.md',HERE/'verify.py',HERE/'qualify.py',HERE/'tests.cpp',HERE/'original_fixture.hpp',inventory_path,ROOT/'game/native/gameplay_save/snapshot.cpp',ROOT/'game/native/gameplay_save/snapshot.hpp']
    for directory in ['gameplay-save-llvm-v3','gameplay-save-gcc-v2']:
        folder=ROOT/'build-native-sjuni'/directory
        paths += [folder/name for name in ['receipt.json','snapshot.hpp','snapshot.cpp','tests.cpp','original_fixture.hpp','original_declarations.inc','original.cpp','test.stdout.txt','test.stderr.txt','scenario-inventory.json']]
    evidence={p.relative_to(ROOT).as_posix():sha(p) for p in paths}
    result=dict(schema=1,status='complete native save snapshot/codec domain passes focused original-body parity; caller and scenario migration remain open',
        owned_elf_sha256=sha(elf),owned_overlay_sha256=inventory['owned_image_sha256'],compiler_cohorts=receipts,
        implemented_original_entries=['0x'+n.lower().lstrip('0') for n in ['001C52B0','001C5300','001C5340','001C53B0','001C5410','001C5480','001C54E0','001C5500','001C5520','001C55C0','001C5630','001C56A0','001C5760']],
        save_contract=dict(container_bytes=0x3fcc0,encoded_payload_bytes=0x3fcb8,payload_halfwords=0x1fe5c,magic='0x5963',multiplier=176,modulus='0xff53',
            little_endian=True,padding_preserved=True,checksum_failure_mutates_complete_payload=True,raw_flag_bytes_preserved=True,conditional_tail_checks_only_first_byte=True),
        caller_inventory=callers,external_dependencies=dependencies,
        scenario=dict(table_address='0x717830',observed_slots=432,default_slots=220,nondefault_slots=212,distinct_original_targets=213,
            native_opcodes_implemented=0,native_mask=[False]*432,inventory=inventory_path.relative_to(ROOT).as_posix(),event_task_kinds=24,
            no_partial_vm_replacement=True),
        game_adapter_installed=False,real_callers_migrated=False,card_ui_migrated=False,game_launched=False,live_process_access=False,
        save_image_loaded_or_rewritten=False,co_op_rules_changed=False,whole_stage4_complete=False,
        evidence_sha256=evidence,
        limitations=['Offline original-body differential checks validate admitted nonaliasing fixed-size snapshots and their exact codec/copy/control contracts, not full save/card/scenario ownership.',
            'The test oracle uses bounded integer-register/memory scaffolding and explicit original dependency doubles; production library has no PS2/runtime/memory-address dependency.',
            'Original timestamp, shared RNG and settings notification remain required services. Their own downstream behavior and authoritative native ownership remain unported.',
            'Original decoder source includes an adjacent icon body whose test dependencies throw if reached; no tested decode enters it.',
            'Scenario mapping/body coverage does not imply native opcode coverage. Every native bit remains false and no game bytecode interpreter was replaced.',
            'Real save/load/resume integration, original card assets, co-op compatibility, scenario content actions and complete original task phases require further work.',
            'The first strict GCC fixture build failed misleading indentation; corrected fixture and both final compiler cohorts passed unchanged native production code.'])
    with TARGET.open('x',encoding='utf8',newline='\n') as f:json.dump(result,f,indent=2);f.write('\n')
    print(json.dumps(dict(output=str(TARGET),evidence_files=len(evidence),caller_sites=sum(len(c['sites']) for c in callers),qualification_sha256=sha(TARGET))))
if __name__=='__main__':main()
