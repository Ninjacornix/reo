"""Static authored opcode inventory tied to a real native admission cohort."""
import argparse,collections,hashlib,json,struct
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def main():
    p=argparse.ArgumentParser();p.add_argument('--admission',type=Path,required=True);p.add_argument('--output',type=Path,required=True);p.add_argument('--inventory-resource-receipt',type=Path);p.add_argument('--historical-inventory-resource-receipt',type=Path);a=p.parse_args()
    receipt_path=a.admission.resolve();receipt=json.loads(receipt_path.read_bytes());assert receipt['status']=='passed'and not receipt['current_shared_source_drift']
    result_path=receipt_path.parent/'run-after.stdout.txt';assert receipt['commands'][-1]['stdout_sha256']==hashlib.sha256(result_path.read_text().encode()).hexdigest()
    coverage=json.loads(result_path.read_bytes())['coverage'];inventory=ROOT/'build-native-sjuni/gameplay-script-content-llvm-v21/inventory.json';members=json.loads(inventory.read_bytes())
    out=a.output.resolve();assert not out.exists()and out.is_relative_to(ROOT/'build-native-sjuni');out.mkdir()
    inventory_proof=None
    assert not(a.inventory_resource_receipt and a.historical_inventory_resource_receipt)
    if a.inventory_resource_receipt or a.historical_inventory_resource_receipt:
        proof_path=(a.inventory_resource_receipt or a.historical_inventory_resource_receipt).resolve();proof=json.loads(proof_path.read_bytes())
        assert proof['status']=='passed'and not proof['source_drift']and not proof['archive_drift']
        matching=proof['native_library_sha256']==receipt['native_library_sha256']
        if a.inventory_resource_receipt:assert matching
        assert proof['observed']['vm_dispatches']>0
        inventory_proof=dict(path=str(proof_path.relative_to(ROOT)),sha256=sha(proof_path),qualification_scope='matching_current_archives'if matching else'historical_original_body_receipt',current_archives_match=matching)
    rows=[];totals=[collections.Counter(),collections.Counter()];limited=[collections.Counter(),collections.Counter()];resources=[0,0];presentation=[0,0]
    for member in members:
        if member['format']!='E':continue
        assert any(row['name']==member['name']and row['sha256']==member['sha256']for row in receipt['members'])
        with Path(member['archive']).open('rb')as source:source.seek(member['archive_offset']);raw=source.read(member['bytes'])
        assert hashlib.sha256(raw).hexdigest()==member['sha256']
        records=[]
        for obj in member['declared_objects']:
            if obj['role']!=0:continue
            at=0;size=obj['upper_bound_bytes'];assert obj['offset']+size<=len(raw)
            while at<size:
                assert at+4<=size
                header=struct.unpack_from('<I',raw,obj['offset']+at)[0];opcode=header&0xffffff;extent=4<<(header>>24);assert extent<=size-at
                record=dict(block=obj['table_index'],offset=at,opcode=opcode,bytes=extent)
                if opcode==0x63:
                    assert extent>=8
                    record['request_mode']=struct.unpack_from('<I',raw,obj['offset']+at+4)[0]
                records.append(record);at+=extent
        profiles=[]
        for profile in range(2):
            unsupported=[r for r in records if r['opcode']>=len(coverage[profile])or not coverage[profile][r['opcode']]];counts=collections.Counter(r['opcode']for r in unsupported);totals[profile].update(counts)
            # The opcode mask cannot prove the distinct zero-mode provider.
            # Its actual resource producer needs its matching-archive oracle;
            # active inventory drawing remains a separate product consumer.
            zero=[r for r in records if r['opcode']==0x63 and coverage[profile][0x63]and r['request_mode']==0]
            profile_limits=[]if inventory_proof else[dict(r,reason='unowned604310/6DDD70 asset reset')for r in zero]
            presentation_limits=[dict(r,reason='active native inventory presentation remains unimplemented')for r in zero]if inventory_proof else[]
            limited[profile].update(r['opcode']for r in profile_limits)
            resources[profile]+=len(zero)if inventory_proof else 0;presentation[profile]+=len(presentation_limits)
            profiles.append(dict(name=('ordinary','offline_actor')[profile],unsupported_instructions=len(unsupported),counts={hex(k):v for k,v in sorted(counts.items())},records=unsupported,profile_limits=profile_limits,qualified_zero_mode_resources=zero if inventory_proof else[],presentation_limits=presentation_limits))
        rows.append(dict(name=member['name'],sha256=member['sha256'],authored_records=len(records),profiles=profiles))
    assert len(rows)==5
    result=dict(schema='reo.native.scenario_opcode_frontier.v1',status='passed',admission_receipt=str(receipt_path.relative_to(ROOT)),admission_sha256=sha(receipt_path),coverage_result_sha256=sha(result_path),inventory_sha256=sha(inventory),tool_sha256=sha(Path(__file__).resolve()),banks=rows,
        inventory_resource_proof=inventory_proof,current_inventory_resource_original_qualified=bool(inventory_proof and inventory_proof['current_archives_match']),totals=[dict(profile=('ordinary','offline_actor')[i],unsupported_instructions=sum(c.values()),counts={hex(k):v for k,v in sorted(c.items())},known_profile_limits=sum(limited[i].values()),profile_limit_counts={hex(k):v for k,v in sorted(limited[i].items())},known_unimplemented_instructions=sum(c.values())+sum(limited[i].values()),qualified_zero_mode_resources=resources[i],visible_inventory_consumer_limits=presentation[i])for i,c in enumerate(totals)],
        limitations=['Counts cover every linearly encoded role0 record in five owned EVBs, including branches that may never execute.','A historical inventory resource receipt identifies implemented and previously qualified work; it does not requalify changed current archives or ABI.','This is static authored coverage and actual Program admission, not a claim of dynamic reachability, complete providers or installed gameplay.'],game_launched=False,stage4_complete=False)
    (out/'receipt.json').write_text(json.dumps(result,indent=2)+'\n');print(json.dumps(result['totals']))
if __name__=='__main__':main()
