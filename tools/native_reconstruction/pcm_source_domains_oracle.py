#!/usr/bin/env python3
"""Exact reconstructed121 PCM missing/shared-channel domain observations.

No native core is imported. The full pinned CriAudio.cpp runs unchanged with
the existing supplied clock and no-device/sound-bank mocks. Input transcripts
are separate from measured pre/post state and actual unordered traversal.
"""
import argparse
import hashlib
import importlib.util
import json
import os
from pathlib import Path
import shutil
import struct
import subprocess

ROOT=Path(__file__).resolve().parents[2]
ORIGINAL_HARNESS_SHA='697194d2089779baf86074cf8cce28819607c4f7fd2e7561bcf557ac1d189183'
RECEIPT_SHA='2b8088a430a63517ad2a77910970e37bccf9658e3c7c91ac6525a70b1db0cca8'

HARNESS=r'''
#include <sstream>
float master_gain=1;
std::unordered_map<std::uint32_t,float> gains;
std::vector<std::uint32_t> gain_reads;
float reoAudioMasterGain(){return master_gain;}
float reoAudioStreamGain(std::uint32_t key){gain_reads.push_back(key);return gains.at(key);}
void reoAudioPoll(){}
void reoAudioResetStreams(){}
namespace ps2_reo_sound {void mix(float*,unsigned){}void reset(){}void reportAudioPaths(){}}
namespace a=ps2_cri_audio;
std::string scenario;
template<class T>void numbers(std::ostream& out,const T& values){out<<'[';bool comma=false;for(auto value:values){if(comma)out<<',';comma=true;out<<+value;}out<<']';}
std::vector<std::uint32_t> order(){std::vector<std::uint32_t> result;for(const auto& row:a::voices)result.push_back(row.first);return result;}
std::string state(){
 std::ostringstream out;const auto raw_order=order();out<<"{\"raw_voice_order\":";numbers(out,raw_order);
 out<<",\"bucket_count\":"<<a::voices.bucket_count()<<",\"clock_ns\":"<<controlled_clock::nanoseconds
    <<",\"frame_clock\":"<<(a::externalClock?"true":"false")
    <<",\"last_tick_ns\":"<<std::chrono::duration_cast<std::chrono::nanoseconds>(a::lastTick.time_since_epoch()).count()
    <<",\"master_gain_bits\":"<<std::bit_cast<std::uint32_t>(master_gain)<<",\"voices\":[";
 auto keys=raw_order;std::sort(keys.begin(),keys.end());bool comma=false;
 for(auto key:keys){if(comma)out<<',';comma=true;const auto& v=a::voices.at(key);
  out<<"{\"key\":"<<key<<",\"left\":"<<v.left<<",\"right\":"<<v.right<<",\"channels\":"<<v.channels
    <<",\"frequency\":"<<v.frequency<<",\"volume\":"<<v.volume
    <<",\"playing\":"<<(v.playing?"true":"false")<<",\"draining\":"<<(v.draining?"true":"false")
    <<",\"gain_bits\":"<<std::bit_cast<std::uint32_t>(gains.at(key))
    <<",\"cached_mixer_gain_bits\":"<<std::bit_cast<std::uint32_t>(v.mixerGain)
    <<",\"phase_bits\":"<<std::bit_cast<std::uint64_t>(v.phase)
    <<",\"late\":"<<v.lateSamples<<",\"skipped\":"<<v.skippedSamples<<'}';}
 out<<"],\"channels\":[";keys.clear();for(const auto& row:a::channels)keys.push_back(row.first);std::sort(keys.begin(),keys.end());comma=false;
 for(auto key:keys){if(comma)out<<',';comma=true;const auto& c=a::channels.at(key);
  out<<"{\"key\":"<<key<<",\"queued_bytes\":"<<c.queued<<",\"consumed_bytes\":"<<c.consumed
    <<",\"sample_count\":"<<c.pcm.size()<<",\"samples_i16\":";numbers(out,c.pcm);out<<'}';}
 out<<"],\"output_frames\":"<<a::outputFrames<<",\"signal_frames\":"<<a::signalFrames
    <<",\"underrun_frames\":"<<a::underrunFrames<<'}';return out.str();
}
void start(const std::string& name,bool frame_clock){scenario=name;controlled_clock::nanoseconds=0;a::reset();gains.clear();gain_reads.clear();master_gain=1;if(frame_clock)a::render(nullptr,0);}
void queue(std::uint32_t key,std::initializer_list<std::int16_t> values){std::vector<std::int16_t> copy(values);std::uint64_t end=0;if(!a::queue(key,reinterpret_cast<const std::uint8_t*>(copy.data()),static_cast<unsigned>(copy.size()*2),end))throw std::runtime_error("queue refused");}
template<class Call>void observe(const char* operation,unsigned action,const char* kind,unsigned frames,bool defined,Call call){
 const auto declared=order();const auto before=state();gain_reads.clear();std::vector<float> pcm(frames*2,123);
 const auto result=call(pcm);const auto after=state();
 std::cout<<"{\"case\":\""<<scenario<<"\",\"operation\":\""<<operation<<"\",\"action_index\":"<<action
    <<",\"call_kind\":\""<<kind<<"\",\"frames\":"<<frames<<",\"declared_raw_order\":";numbers(std::cout,declared);
 std::cout<<",\"gain_read_order\":";numbers(std::cout,gain_reads);std::cout<<",\"result_is_defined\":"<<(defined?"true":"false")<<",\"result_u64\":";
 if(defined)std::cout<<result;else std::cout<<"null";
 std::cout<<",\"float_bits\":[";for(std::size_t i=0;i<pcm.size();++i){if(i)std::cout<<',';std::cout<<std::bit_cast<std::uint32_t>(pcm[i]);}
 std::cout<<"],\"pre_state\":"<<before<<",\"state\":"<<after<<"}\n";
}
'''


def f32_bits(value):return struct.unpack('<I',struct.pack('<f',value))[0]
def sha(path):return hashlib.sha256(path.read_bytes()).hexdigest()


def input_transcript():
    cases=[]
    def reset(frame_clock=True):return dict(kind='reset',now_ns=0,frame_clock=frame_clock,master_gain_bits=f32_bits(1))
    def gain(key,value=1):return dict(kind='gain',voice=key,value_f32_bits=f32_bits(value))
    def queue(key,samples):return dict(kind='queue',channel=key,samples_i16=list(samples),now_ns=0)
    def config(voice,left,right=0,channels=1,frequency=48000,volume=256,playing=True,now_ns=0):
        return dict(kind='configure',voice=voice,left=left,right=right,channels=channels,
            frequency=frequency,volume=volume,playing=playing,now_ns=now_ns)
    def render(operation,frames):return dict(kind='render_observe',operation=operation,frames=frames)
    def state(operation):return dict(kind='state_observe',operation=operation)
    def add(name,actions):cases.append(dict(case=name,actions=actions))
    samples=[1000,-2000,3000,-4000,5000,-6000,7000,-8000]
    right=[-900,1800,-2700,3600,-4500,5400,-6300,7200]
    add('left_zero_skip',[reset(),gain(10),config(10,0,frequency=96000),render('zero_left',3),
        config(10,1,frequency=96000),render('nonzero_missing_left',2)])
    add('missing_left_queue',[reset(),gain(10),config(10,1),render('starve',3),
        queue(1,samples),render('refill',2)])
    add('stereo_right_zero',[reset(),gain(10),queue(1,samples),config(10,1,0,2),render('missing_right_zero',3)])
    add('stereo_right_missing',[reset(),gain(10),queue(1,samples),config(10,1,2,2),
        render('starve',3),queue(2,right),render('refill',2)])
    add('stereo_left_missing',[reset(),gain(10),queue(2,right),config(10,1,2,2),
        render('starve',2),queue(1,samples),render('refill',2)])
    add('disabled_channels',[reset(),gain(10),queue(1,samples),config(10,1,channels=0,frequency=96000),
        render('disabled',3),config(10,1),render('enabled',2)])
    add('raw_voice_zero',[reset(),gain(0),queue(1,samples),config(0,1),render('voice_zero',3),
        dict(kind='release',voice=0),state('released_zero')])
    add('channels_clamp',[reset(),gain(10),queue(1,samples),queue(2,right),
        config(10,1,2,3,frequency=0,volume=0xFFFFFFFF),render('channels3',2),
        config(10,1,2,0xFFFFFFFF,frequency=192000,playing=False),render('paused_max_channels',2),
        config(10,1,2,0xFFFFFFFF,frequency=192000),render('resumed_clamped',2)])
    for reverse in (False,True):
        setup=[config(10,1),config(20,1,frequency=24000)]
        if reverse:setup.reverse()
        add('shared_mono_'+str(reverse),[reset(),gain(10,0.25),gain(20,0.75),queue(1,samples)]+setup+
            [render('shared_first',4),queue(1,right),render('shared_refill',4)])
        setup=[config(10,1,2,2),config(20,1,2,2,frequency=96000)]
        if reverse:setup.reverse()
        add('shared_stereo_'+str(reverse),[reset(),gain(10,0.25),gain(20,0.75),
            queue(1,samples),queue(2,right)]+setup+[render('shared_first',4),queue(1,right),queue(2,samples),render('shared_refill',3)])
    add('shared_left_stereo_mono',[reset(),gain(10,0.7),gain(20,1.3),queue(1,samples),queue(2,right),
        config(10,1,2,2),config(20,1,frequency=24000),render('partial_share',5)])
    add('shared_right_stereo',[reset(),gain(10,0.7),gain(20,1.3),queue(1,samples),queue(2,right),queue(3,list(reversed(samples))),
        config(10,1,2,2,frequency=44100),config(20,3,2,2),render('partial_share',5)])
    add('cross_stereo',[reset(),gain(10,0.7),gain(20,1.3),queue(1,samples),queue(2,right),
        config(10,1,2,2),config(20,2,1,2),render('cross_share',5)])
    add('shared_three_mixed',[reset(),gain(10,1.3),gain(20,0.75),gain(30,0.1),queue(1,samples),queue(2,right),
        config(10,1,frequency=8000),config(20,1,2,2,frequency=96000),config(30,2,frequency=44100),render('three_voice_share',8)])
    add('shared_drain_pause',[reset(),gain(10),gain(20),queue(1,samples+right),config(10,1,frequency=96000),
        config(20,1,frequency=24000),dict(kind='drain',voice=20),config(20,1,frequency=24000,playing=False),
        render('drain_overrides_false',3),config(10,1,frequency=96000,playing=False),render('drain_tail',22),
        dict(kind='release',voice=20),state('release_retains_channel')])
    add('headless_unknown_consumed',[reset(False),gain(10),queue(1,samples),config(10,1),
        dict(kind='consumed_observe',operation='unknown_query',channel=999,now_ns=83334),
        dict(kind='consumed_observe',operation='known_query_same_time',channel=1,now_ns=83334)])
    observed=config(20,2,now_ns=41667);observed.update(kind='configure_observe',operation='insert_after_tick')
    add('headless_configure_before_insert',[reset(False),gain(10,0.25),gain(20,0.75),queue(1,samples),queue(2,right),
        config(10,1),observed,dict(kind='consumed_observe',operation='both_after_insert',channel=2,now_ns=83334),
        render('select_frame_clock',0)])
    return cases


def validate_inputs(cases):
    names=set()
    for case in cases:
        if case['case'] in names:raise ValueError('Duplicate source-domain case')
        names.add(case['case'])
        if not case['actions'] or case['actions'][0]['kind']!='reset':raise ValueError('Case must reset source state')
        for action in case['actions']:
            kind=action['kind']
            if kind=='queue':
                if not 0<action['channel']<=0xFFFFFFFF or not 1<=len(action['samples_i16'])<=64:
                    raise ValueError('Queue outside bounded source domain')
                if any(not isinstance(v,int) or not -32768<=v<=32767 for v in action['samples_i16']):
                    raise ValueError('Queue samples must be signed16')
            elif kind in ('configure','configure_observe'):
                for key in ('voice','left','right','channels','frequency','volume'):
                    if not 0<=action[key]<=0xFFFFFFFF:raise ValueError('Raw source argument outside uint32')
                if action['channels']>1 and action['left']==action['right']:
                    raise ValueError('Same-voice stereo self-alias excluded before any execution')
            elif kind=='render_observe' and not 0<=action['frames']<=64:
                raise ValueError('Frame bound exceeded')
            elif kind not in ('reset','gain','release','drain','discard','render_observe','state_observe','consumed_observe'):
                raise ValueError('Unsupported source-domain action')


def action_program(cases):
    validate_inputs(cases)
    lines=['int main(){try{']
    for case in cases:
        for index,a in enumerate(case['actions']):
            kind=a['kind']
            if 'now_ns' in a:lines.append('controlled_clock::nanoseconds='+str(a['now_ns'])+'LL;')
            if kind=='reset':lines.append('start('+json.dumps(case['case'])+','+str(a['frame_clock']).lower()+');')
            elif kind=='gain':lines.append('gains[%du]=std::bit_cast<float>(%du);'%(a['voice'],a['value_f32_bits']))
            elif kind=='queue':lines.append('queue(%du,{%s});'%(a['channel'],','.join(str(v) for v in a['samples_i16'])))
            elif kind in ('configure','configure_observe'):
                args=','.join(str(a[k])+'u' for k in ('voice','left','right','channels','frequency','volume'))+','+str(a['playing']).lower()
                call='a::configure('+args+');'
                if kind=='configure':lines.append(call)
                else:lines.append('observe('+json.dumps(a['operation'])+','+str(index)+'u,"configure",0,false,[&](auto&){'+call+'return 0ull;});')
            elif kind in ('release','drain','discard'):
                lines.append('a::'+kind+'('+str(a['channel'] if kind=='discard' else a['voice'])+'u);')
            elif kind=='render_observe':
                lines.append('observe('+json.dumps(a['operation'])+','+str(index)+'u,"render",'+str(a['frames'])+'u,false,[&](auto& pcm){a::render(pcm.data(),'+str(a['frames'])+'u);return 0ull;});')
            elif kind=='consumed_observe':
                lines.append('observe('+json.dumps(a['operation'])+','+str(index)+'u,"consumed",0,true,[&](auto&){return a::consumed('+str(a['channel'])+'u);});')
            elif kind=='state_observe':
                lines.append('observe('+json.dumps(a['operation'])+','+str(index)+'u,"state",0,false,[&](auto&){return 0ull;});')
    return '\n'.join(lines)+'\nreturn 0;\n}catch(const std::exception& e){std::cerr<<e.what()<<\'\\n\';return 1;}}\n'


def validate(rows,inputs):
    planned=[(c['case'],index,a['operation']) for c in inputs for index,a in enumerate(c['actions']) if a['kind'].endswith('_observe')]
    if [(r['case'],r['action_index'],r['operation']) for r in rows]!=planned:
        raise ValueError('Observed source actions differ from input transcript')
    for row in rows:
        if row['declared_raw_order']!=row['pre_state']['raw_voice_order']:raise ValueError('Pre-call traversal incomplete')
        for state in (row['pre_state'],row['state']):
            if sorted(state['raw_voice_order'])!=[v['key'] for v in state['voices']]:raise ValueError('Voice permutation malformed')
            if any(c['sample_count']!=len(c['samples_i16']) or c['consumed_bytes']>c['queued_bytes'] for c in state['channels']):
                raise ValueError('Queue/watermark snapshot malformed')
        if len(row['float_bits'])!=row['frames']*2:raise ValueError('PCM frame extent differs')
        if row['call_kind']=='render' and row['gain_read_order']!=row['declared_raw_order']:
            raise ValueError('Actual gain reads do not follow full declared voice traversal')
    by={(r['case'],r['operation']):r for r in rows}
    skipped=by[('left_zero_skip','zero_left')]
    if skipped['state']['voices'][0]['late'] or skipped['state']['underrun_frames']!=skipped['pre_state']['underrun_frames']:
        raise ValueError('Zero-left skip contract not observed')
    missing=by[('missing_left_queue','starve')]
    if missing['state']['voices'][0]['late']!=3:raise ValueError('Missing nonzero left did not accrue debt')
    rawzero=by[('raw_voice_zero','voice_zero')]
    if rawzero['declared_raw_order']!=[0] or not any(rawzero['float_bits']):raise ValueError('Raw voice zero did not play')
    unknown=by[('headless_unknown_consumed','unknown_query')]
    if unknown['result_u64']!=0 or unknown['state']['channels'][0]['consumed_bytes']!=8:
        raise ValueError('Unknown consumed query did not advance the existing voice')
    inserted=by[('headless_configure_before_insert','insert_after_tick')]
    if inserted['declared_raw_order']!=[10] or inserted['gain_read_order']!=[10] or len(inserted['state']['voices'])!=2:
        raise ValueError('Configure tick/insertion boundary not observed')
    return dict(cases=len(inputs),snapshots=len(rows),float_values=sum(len(r['float_bits']) for r in rows),
        shared_cases=sum(c['case'].startswith(('shared_','cross_')) for c in inputs))


def generate(dependency,compiler,output):
    dependency,output=dependency.resolve(),output.resolve();allowed=ROOT/'build-native-sjuni'
    if output==allowed or not output.is_relative_to(allowed):raise ValueError('Use a private ignored output')
    transcript=ROOT/'tools/native_reconstruction/pcm_owner_oracle.py'
    if sha(transcript)!=ORIGINAL_HARNESS_SHA:raise ValueError('Frozen original harness changed')
    spec=importlib.util.spec_from_file_location('pcm_original_harness',transcript)
    ref=importlib.util.module_from_spec(spec);spec.loader.exec_module(ref)
    source=dependency/'ps2xRuntime/src/lib'
    identities={name:sha(source/name) for name in ref.EXPECTED}
    if identities!=ref.EXPECTED:raise ValueError('Exact reconstructed121 source changed')
    receipt=ROOT/'build-native-sjuni/dependency-workers-reapply-v2-receipt.json'
    if sha(receipt)!=RECEIPT_SHA:raise ValueError('Dependency reconstruction receipt changed')
    tool=shutil.which(str(compiler))
    if not tool:raise ValueError('Existing C++20 compiler required')
    output.mkdir(parents=True,exist_ok=True);snapshot=output/'snapshot';helpers=snapshot/'Kernel/Syscalls/Helpers';helpers.mkdir(parents=True,exist_ok=True)
    for name in ('CriAudio.cpp','CriAudio.h'):shutil.copyfile(source/'Kernel/Syscalls/Helpers'/name,helpers/name)
    shutil.copyfile(source/'cri_pcm_retire.h',snapshot/'cri_pcm_retire.h')
    for name,text in [('Kernel/Syscalls/Helpers/ReoSoundBanks.h',ref.MOCK_BANK),('ps2_host_backend.h',ref.MOCK_HOST),('vblank_music_diag.h',ref.MOCK_DIAG)]:
        (snapshot/name).write_text(text,encoding='utf-8',newline='\n')
    prefix=ref.HARNESS.split('float master_gain=',1)[0]
    if prefix==ref.HARNESS:raise ValueError('Original whole-source include boundary missing')
    inputs=input_transcript();harness=output/'probe.cpp';exe=output/'probe.exe'
    harness.write_text(prefix+HARNESS+action_program(inputs),encoding='utf-8',newline='\n')
    cc=Path(tool).resolve();command=[tool,'-std=c++20','-O1','-ffp-contract=off','-Wall','-Wextra','-Wpedantic','-Werror',
        '-I'+str(snapshot),str(harness),'-o',str(exe)]
    env=dict(os.environ)
    for name in list(env):
        if name.startswith(('REO_CRI_','REO_AUDIO_PATH','REO_RNA_STOP')):env.pop(name,None)
    env['PATH']=str(cc.parent)+os.pathsep+env.get('PATH','')
    proof=dict(schema=1,status='running',compiler=str(cc),compiler_sha256=sha(cc),source_sha256=identities,
        tool_sha256=sha(Path(__file__)),original_harness_sha256=ORIGINAL_HARNESS_SHA,dependency_receipt_sha256=RECEIPT_SHA,
        harness_sha256=sha(harness),command=command,game_run=False,device_opened=False,assets_read=False)
    try:
        build=subprocess.run(command,env=env,capture_output=True,text=True,timeout=90)
        proof['compile']=dict(exit_code=build.returncode,stderr=build.stderr)
        if build.returncode:raise RuntimeError(build.stderr)
        run=subprocess.run([str(exe)],env=env,capture_output=True,text=True,timeout=30)
        proof['execution']=dict(exit_code=run.returncode,stderr=run.stderr)
        if run.returncode:raise RuntimeError(run.stderr)
        rows=[json.loads(line) for line in run.stdout.splitlines()];summary=validate(rows,inputs)
        fixture=output/'fixtures.json'
        fixture.write_text(json.dumps(dict(schema=2,source_sha256=identities,compiler_sha256=sha(cc),
            inputs=inputs,records=rows),indent=2)+'\n',encoding='utf-8',newline='\n')
        proof.update(status='passed',**summary,fixture_sha256=sha(fixture),fixture_bytes=fixture.stat().st_size)
    except Exception as error:
        proof.update(status='failed',failure=str(error));raise
    finally:
        (output/'receipt.json').write_text(json.dumps(proof,indent=2)+'\n',encoding='utf-8',newline='\n')
    return proof


def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--dependency',type=Path,default=ROOT/'build-native-sjuni/dependency-workers-reapply-v2')
    parser.add_argument('--cxx',required=True);parser.add_argument('--output',type=Path,required=True)
    args=parser.parse_args();proof=generate(args.dependency,args.cxx,args.output)
    print(json.dumps({k:proof[k] for k in ('status','cases','snapshots','float_values','shared_cases','fixture_sha256')}))


if __name__=='__main__':main()
