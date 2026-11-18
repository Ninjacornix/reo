"""Read-only correlation of a completed native audio shortage and resource stall."""
import argparse,csv,hashlib,json,re
from pathlib import Path
from analyze_audio_control_trace import read_trace,analyze


def sha(path):
    with path.open('rb') as stream:
        return hashlib.file_digest(stream,'sha256').hexdigest()


def main():
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('--session',type=Path,required=True)
    p.add_argument('--output',type=Path,required=True)
    a=p.parse_args();folder=a.session.resolve()
    assert not a.output.exists()
    check=json.loads((folder/'native-game-session-check.json').read_bytes())
    run=json.loads((folder/'native-game-session-running.json').read_bytes())
    launch=json.loads((folder/'launch.json').read_bytes())
    assert check['exit_code']==0 and not check['forced_cleanup'] and run['executable_sha256']==launch['sha256']
    trace=read_trace(folder/'native-audio-control.csv');summary=analyze(trace)
    windows=sorted(summary['largest_shortage_windows'],key=lambda x:x['begin_ns'])
    assert 0<len(windows)<=32 and len(windows)==summary['shortage_windows']
    begin,end=windows[0]['begin_ns'],windows[-1]['end_ns']
    snapshots=[s for s in trace['snapshots'] if begin<=s['begin_ns']<=end]
    text=(folder/'stderr.log').read_text(errors='replace').splitlines()
    log=[];resource=[]
    for line,t in enumerate(text,1):
        match=re.search(r'\[NATIVE-RESOURCE-READS\] slow begin_ns=(\d+) end_ns=(\d+) lba=(\d+) sectors=(\d+) destination=([\da-f]+)',t)
        if match and begin<=int(match[1])<=end:
            resource.append(dict(line=line,begin_ns=int(match[1]),end_ns=int(match[2]),duration_ms=(int(match[2])-int(match[1]))/1e6,lba=int(match[3]),sectors=int(match[4]),destination=match[5],text=t))
            log.extend(dict(line=i+1,text=text[i]) for i in range(max(0,line-3),min(len(text),line+11)))
    with (folder/'frames.csv').open() as s:
        retention=next(s).strip();frames=[{k:int(v) for k,v in row.items()} for row in csv.DictReader(s)]
    frame_intervals=[dict(before_line=i+3,after_line=i+4,gap_ms=(b['begin_ns']-v['begin_ns'])/1e6,before=v,after=b) for i,(v,b) in enumerate(zip(frames,frames[1:])) if v['begin_ns']<=end and b['begin_ns']>=begin]
    lines=(folder/'clock.csv').read_text().splitlines()
    clock_origin=int(re.search(r'# first_room_ns=(\d+)','\n'.join(lines))[1])
    clock=[{k:int(v) for k,v in row.items()} for row in csv.DictReader(x for x in lines if not x.startswith('#'))]
    clock_intervals=[dict(gap_ms=(b['elapsed_ns']-v['elapsed_ns'])/1e6,before=v,after=b) for v,b in zip(clock,clock[1:]) if clock_origin+v['elapsed_ns']<=end and clock_origin+b['elapsed_ns']>=begin]
    manifest=Path(launch['discRoot']).parent/'import.json';imported=json.loads(manifest.read_bytes());routes=[];next_lba=0x1000000
    for item in sorted(imported['Files'],key=lambda x:x['Name'].replace('/','\\').upper()):
        sectors=(item['Length']+2047)//2048
        routes.append(dict(item,virtual_lba=next_lba));next_lba+=sectors+0x4000
    inventory=Path(__file__).resolve().parents[2]/'build-native-sjuni/audio-asset-inventory/file1-v1'
    members=json.loads((inventory/'members.json').read_bytes());containers=json.loads((inventory/'containers.json').read_bytes())
    assets=[]
    for read in resource:
        route=next(x for x in routes if x['virtual_lba']<=read['lba']<x['virtual_lba']+(x['Length']+2047)//2048)
        offset=(read['lba']-route['virtual_lba'])*2048;container=next(x for x in containers if x['path']==route['Name'])
        member=next(x for x in members if x['container']==route['Name'] and x['iso_offset']==container['offset']+offset)
        with (Path(launch['discRoot'])/route['Name']).open('rb') as s:s.seek(offset);raw=s.read(read['sectors']*2048)
        assert len(raw)==read['sectors']*2048 and hashlib.sha256(raw[:member['bytes']]).hexdigest()==member['sha256']
        assets.append(dict(route=route,offset=offset,member=member,read_bytes=len(raw),padded_read_sha256=hashlib.sha256(raw).hexdigest(),padding_bytes=len(raw)-member['bytes'],padding_all_zero=not any(raw[member['bytes']:])) )
    result=dict(schema=1,status='completed audio shortage correlated; native audio resilience gate failed',
        game_run=False,process_access=False,window_actions=False,step3_complete=False,fix_confirmed=False,
        source_sha256=sha(Path(__file__)),check=check,executable_sha256=run['executable_sha256'],audio_analysis=summary,
        incident=dict(begin_ns=begin,end_ns=end,host_ms=(end-begin)/1e6,underrun_frames=summary['measured_underrun_increase'],equivalent_48khz_seconds=summary['measured_underrun_increase']/48000,snapshots=snapshots,windows=windows),
        slow_resource_reads=resource,resolved_resource_assets=assets,log_excerpts=log,
        presentation=dict(retention=retention,intervals=frame_intervals),
        actor_clock=dict(metadata=[x for x in lines if x.startswith('#')],origin_ns=clock_origin,intervals=clock_intervals),
        evidence_sha256={name:sha(folder/name) for name in ('native-game-session-check.json','native-game-session-running.json','launch.json','stderr.log','native-audio-control.csv','clock.csv','frames.csv')},
        import_manifest=dict(path=str(manifest),sha256=sha(manifest)),
        inventory_sha256={name:sha(inventory/name) for name in ('members.json','containers.json')},
        limitations=['Resource-operation duration includes native locks/provider work/I/O/scheduling; physical storage is not isolated.',
                    'The second 1.4-second ownership gap has no inner stack evidence.',
                    'Actor callbacks repeat global clock values; do not count callbacks as updates or ignore journal drops/eligibility.',
                    'Two affected streams share an aggregate output shortage; do not double the aggregate count.'])
    a.output.write_text(json.dumps(result,indent=2)+'\n',encoding='utf8')
    print(json.dumps(dict(underrun_frames=summary['measured_underrun_increase'],windows=len(windows),host_ms=(end-begin)/1e6,assets=[x['member']['names'] for x in assets])))


if __name__=='__main__':main()
