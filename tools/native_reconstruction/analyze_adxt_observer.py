#!/usr/bin/env python3
"""Summarize bounded original ABI observations, preserving incomplete evidence."""
import argparse,hashlib,json
from collections import Counter
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def value(data,at,size=4,signed=False):return int.from_bytes(data[at:at+size],'little',signed=signed)
def analyze(path):
    header=None;complete=False;counts={};events=[];invalid=[];recipes=[];profiles={};changes=[]
    with path.open(encoding='utf-8')as source:
        for line_number,line in enumerate(source,1):
            try:row=json.loads(line)
            except json.JSONDecodeError:invalid.append(line_number);continue
            if 'schema'in row:header=row;continue
            if 'export_complete'in row:complete=row.get('export_complete')is True and row.get('capture_closed')is True;continue
            if 'calls'in row:counts[f"{row['entry']:06X}"]=row['calls'];continue
            if 'stage'not in row:continue
            try:raw=bytes.fromhex(row.get('adxt',''));decoder=bytes.fromhex(row.get('decoder',''));path_bytes=bytes.fromhex(row.get('path',''))
            except (TypeError,ValueError):invalid.append(line_number);continue
            if len(raw)!=0xc4 or len(decoder)!=0x9c:invalid.append(line_number);continue
            event=dict(line=line_number,entry=f"{row['entry']:06X}",stage=row['stage'],qpc=row['qpc'],tick=row['tick'],handle=row['handle'],pc=row['pc'],handle_status=row['handle_status'],args=row['args'])
            if raw[0]==1:
                fields=dict(channels=raw[3],input_mode=raw[2],service_divisor=value(raw,0x38,signed=True),encoded_sectors=value(raw,0x3c,2,signed=True),
                    threshold_sectors=value(raw,0x3e,2,signed=True),phase=raw[1],request=value(raw,0x48,signed=True),decoder_request=value(decoder,0x38,signed=True),
                    loop_enabled=value(raw,0x6c,1,signed=True),wait_start=raw[0x70],ready_start=raw[0x71],error=value(raw,0x60,2,signed=True),pending_file=raw[0xac])
                event.update(fields)
                key=(row['handle'],raw[3],fields['service_divisor'],fields['encoded_sectors'],fields['threshold_sectors'])
                if key not in profiles:profiles[key]=dict(handle=key[0],channels=key[1],service_divisor=key[2],encoded_sectors=key[3],threshold_sectors=key[4],first_line=line_number,handle_status=row['handle_status'])
                if row['entry']==0x132c08:changes.append(event)
                # EntryAfs/LSC controls do not publish this pending file recipe;
                # their B4 field can refer to an earlier source. Keep only the
                # original ordinary-file pending start and actual lower start.
                if (row['entry']==0x133490 and row['stage']==1 and fields['pending_file']==1 and fields['input_mode']==1) or (row['entry']==0x131c50 and row['stage']==0):
                    recipes.append(dict(**event,path=path_bytes.split(b'\0',1)[0].decode('ascii',errors='backslashreplace'),parent=value(raw,0xb8),start_sector=value(raw,0xbc),sector_count=value(raw,0xc0)))
            events.append(event)
    return dict(schema=1,status='completed bounded original-call evidence'if header and header.get('schema')==1 and complete and not invalid else'partial or malformed original-call evidence',
        source=str(path),source_sha256=sha(path),header=header,export_complete=complete,invalid_json_or_records=invalid,
        calls=counts,events=len(events),handle_status_counts=dict(Counter(str(e['handle_status'])for e in events)),
        profiles=list(profiles.values()),ordinary_file_recipes=recipes,state_observations=changes,
        nonzero_callback_registrations=[e for e in events if e['entry']=='133158'and e['stage']==0 and e['args'][1]],
        native_source_playback_proven=False,root_cause_proven=False,
        limitations=['Original bodies were delegated; native source/control integration is not activated.',
            'Captured paths/ranges are observations, not immutable-mount or runtime lifetime admission.',
            'Service samples include state changes and one sample per 256 calls; intermediate states may be absent.',
            'Counters stop when capture closes; a completed export does not prove all game calls were observed.',
            'Recorder overhead, cache and run order can affect performance; this is not a controlled fix/retest.'])
def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--trace',type=Path,required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve()
    if out.exists()or not out.is_relative_to(ROOT/'build-native-sjuni'):raise ValueError('Fresh owned output directory required')
    report=analyze(a.trace.resolve());out.mkdir(parents=True);(out/'findings.json').write_text(json.dumps(report,indent=2)+'\n',encoding='utf-8',newline='\n')
    lines=['# Original ADXT integration observations','',report['status']+'. Native source playback and root cause are not proven.','',f"Captured {report['events']} events; export complete: {report['export_complete']}; dropped: {(report['header']or{}).get('dropped','unknown')}.",'','| Handle | Channels | Service divisor | Encoded sectors | Threshold sectors | Evidence line |','| --- | --- | --- | --- | --- | --- |']
    for row in report['profiles']:lines.append(f"| `{row['handle']:08X}` | {row['channels']} | {row['service_divisor']} | {row['encoded_sectors']} | {row['threshold_sectors']} | {row['first_line']} |")
    lines+=['','## Ordinary file start observations','','| Path | Start sector | Sector count | Parent argument | Evidence line |','| --- | --- | --- | --- | --- |']
    for row in report['ordinary_file_recipes']:lines.append(f"| `{row['path']}` | {row['start_sector']} | {row['sector_count']} | {row['parent']} | {row['line']} |")
    lines+=['','## Remaining uncertainty','',*['- '+v for v in report['limitations']]]
    (out/'report.md').write_text('\n'.join(lines)+'\n',encoding='utf-8',newline='\n');print(json.dumps({k:report[k]for k in ('status','events','export_complete')}))
if __name__=='__main__':main()
