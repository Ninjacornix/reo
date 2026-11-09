"""Analyze completed native movie/audio traces without live process access."""
import argparse
import hashlib
import json
import re
from pathlib import Path

from analyze_host_movie_playtest import read_trace
from analyze_audio_control_trace import read_trace as read_audio, analyze as analyze_audio

SECTIONS = [('wake', 'wake_begin_ns', 'wake_end_ns'),
            ('controls', 'wake_end_ns', 'controls_end_ns'),
            ('state', 'controls_end_ns', 'state_end_ns'),
            ('transfer', 'state_end_ns', 'transfer_end_ns'),
            ('readback', 'transfer_end_ns', 'readback_end_ns'),
            ('publication', 'readback_end_ns', 'publish_end_ns')]


def sha(path):
    with path.open('rb') as stream:
        return hashlib.file_digest(stream, 'sha256').hexdigest()


def segments(row):
    result = []
    for name, a, b in SECTIONS:
        if row[a] and row[b]:
            assert row[b] >= row[a], (row['line'], name)
            result.append((name, row[a], row[b]))
    last = max(row[k] for k in ('state_end_ns', 'transfer_end_ns', 'readback_end_ns', 'publish_end_ns'))
    assert row['end_ns'] >= last
    result.append(('tail', last, row['end_ns']))
    return result


def maxima(rows):
    result = {}
    for row in rows:
        for name, a, b in segments(row):
            if name not in result or b-a > result[name]['duration_ns']:
                result[name] = dict(duration_ns=b-a, duration_ms=(b-a)/1e6,
                    line=row['line'], generation=row['generation'], clip=row['clip'],
                    ordinal=row['ordinal'], begin_ns=a, end_ns=b)
    return result


def epochs(rows):
    result, current, previous = [], [], None
    for row in rows:
        if not row['publish_end_ns']:
            continue
        if previous and ((row['generation'],row['clip']) != (previous['generation'],previous['clip']) or row['ordinal'] < previous['ordinal']):
            result.append(current)
            current = []
        current.append(row)
        previous = row
    if current:
        result.append(current)
    return result


def describe_gap(a,b,producer,consumer):
    start,end=a['publish_end_ns'],b['publish_end_ns']
    overlapping=[r for r in producer if r['end_ns']>=start and r['wake_begin_ns']<=end]
    section_totals={name:0 for name in [s[0] for s in SECTIONS]+['tail']}
    for r in overlapping:
        for name,begin,finish in segments(r):
            section_totals[name]+=max(0,min(end,finish)-max(start,begin))
    requests=[r for r in consumer if start<=r['begin_ns']<=end and r['generation']==a['generation']]
    return dict(gap_ms=(end-start)/1e6,begin_ns=start,end_ns=end,
        previous_publication=a,next_publication=b,recorded_iterations=overlapping,
        clipped_recorded_sections_ms={k:v/1e6 for k,v in section_totals.items()},
        time_outside_recorded_iterations_ms=((end-start)-sum(section_totals.values()))/1e6,
        consumer_requests_in_interval=len(requests),consumer_fresh_frames=sum(r['available'] for r in requests),
        consumer_lines=[r['line'] for r in requests],
        interpretation='Measured publication interval; time outside recorded iterations includes unrecorded work and scheduling, not proven idle time.')


def main():
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('--session',type=Path,required=True)
    p.add_argument('--output',type=Path,required=True)
    a=p.parse_args()
    folder=a.session.resolve()
    assert not a.output.exists(), 'Fresh output required'
    check=json.loads((folder/'native-game-session-check.json').read_bytes())
    run=json.loads((folder/'native-game-session-running.json').read_bytes())
    launch=json.loads((folder/'launch.json').read_bytes())
    assert check['exit_code']==0 and not check['forced_cleanup'] and run['pid']==launch['pid'] and run['executable_sha256']==launch['sha256']
    producer=read_trace(folder/'native-movie-producer.csv')
    consumer=read_trace(folder/'native-movie-consumer.csv')
    assert producer and consumer
    for trace in (producer,consumer):
        assert re.fullmatch(r'# dropped=\d+',trace['retention'])
    published_epochs=epochs(producer['rows'])
    summaries=[]
    gaps=[]
    for rows in published_epochs:
        pairs=list(zip(rows,rows[1:]))
        gap_values=[(b['publish_end_ns']-a['publish_end_ns'])/1e6 for a,b in pairs]
        assert all(v>=0 for v in gap_values)
        summaries.append(dict(generation=rows[0]['generation'],clip=rows[0]['clip'],
            publications=len(rows),unique_ordinals=len({r['ordinal'] for r in rows}),
            first_ordinal=rows[0]['ordinal'],last_ordinal=rows[-1]['ordinal'],
            first_line=rows[0]['line'],last_line=rows[-1]['line'],
            maximum_publication_gap_ms=max(gap_values,default=0),
            gaps_above_50_ms=sum(v>50 for v in gap_values),gaps_above_100_ms=sum(v>100 for v in gap_values),
            backpressure_max=max(r['backpressure'] for r in rows)))
        gaps.extend(describe_gap(a,b,producer['rows'],consumer['rows']) for a,b in pairs if b['publish_end_ns']-a['publish_end_ns']>50_000_000)
    e3=[r for r in producer['rows'] if r['generation']==4]
    e3_publications=[r for r in e3 if r['publish_end_ns']]
    assert [r['ordinal'] for r in e3_publications]==list(range(6144)), 'Expected complete actual E3 run'
    for row in consumer['rows']:
        assert row['begin_ns']<=row['borrowed_ns']<=row['copied_ns']
        if row['available']:
            assert row['released_ns']>=row['copied_ns']
    audio=analyze_audio(read_audio(folder/'native-audio-control.csv'))
    log=(folder/'stderr.log').read_text(errors='replace')
    audio_reports=list(dict.fromkeys(re.findall(r'\[NATIVE-AUDIO-REPORT\][^\r\n]*',log)))
    result=dict(schema=1,session=folder.name,executable_sha256=run['executable_sha256'],
        source_sha256=sha(Path(__file__)),process_access=False,game_run=False,
        trace_retention={x['file']:dict(header=x['retention'],rows=len(x['rows'])) for x in (producer,consumer)},
        producer_epochs=summaries,publication_gaps_above_50_ms=sorted(gaps,key=lambda g:g['gap_ms'],reverse=True),
        maximum_recorded_sections_all_generations=maxima(producer['rows']),
        maximum_recorded_sections_generation4=maxima(e3),
        maximum_consumer_borrow_ms=max((r['borrowed_ns']-r['begin_ns'])/1e6 for r in consumer['rows']),
        maximum_consumer_copy_ms=max((r['copied_ns']-r['borrowed_ns'])/1e6 for r in consumer['rows']),
        maximum_consumer_frame_lease_ms=max((r['released_ns']-r['borrowed_ns'])/1e6 for r in consumer['rows'] if r['available']),
        native_audio_final_reports=audio_reports,audio_control_analysis=audio,
        evidence_sha256={name:sha(folder/name) for name in ['native-game-session-check.json','native-game-session-running.json','launch.json','stderr.log','native-movie-producer.csv','native-movie-consumer.csv','native-audio-control.csv','launcher-process-audio-result.json','gallery-media-driver-v1.json']},
        historical_video_incident_reproduced=False,historical_audio_incident_reproduced=False,
        historical_root_causes_confirmed=False,stutter_free_claim=False,step3_complete=False,
        limitations=['Publication and consumer timing are not final scanout or perceptual A/V synchronization.',
                    'Producer trace retains updated frames, slow iterations and periodic observations; zero drops does not mean every empty poll was logged.',
                    'Control-trace retention and final source/output totals are separate evidence.',
                    'Compilation/kit preparation overlapped the late run; this is not an isolated performance benchmark.',
                    'Clean retests do not establish historical incident fixes or root causes.'])
    a.output.mkdir(parents=True)
    (a.output/'analysis.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf8')
    print(json.dumps(dict(trace_retention=result['trace_retention'],generation4=[s for s in summaries if s['generation']==4],
        gaps_above_50_ms=len(gaps),gaps_above_100_ms=sum(g['gap_ms']>100 for g in gaps),audio={k:audio[k] for k in ('status','snapshots','dropped_snapshots','shortage_windows','measured_underrun_increase')})))


if __name__=='__main__':
    main()
