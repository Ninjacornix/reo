#!/usr/bin/env python3
"""Exact reconstructed121 PCM traversal/mix evidence; no native candidate/device.

The full pinned CriAudio.cpp is compiled unchanged. Only its host device,
sound-bank sink and clock are substituted using the existing frozen harness.
Actual unordered-map traversal and float outputs are observed, never predicted
by a Python mixer. Fixtures are compiler-specific, not an EE/IOP hardware oracle.
"""
import argparse
import hashlib
import importlib.util
import itertools
import json
import os
from pathlib import Path
import shutil
import subprocess
import struct

ROOT = Path(__file__).resolve().parents[2]
TRANSCRIPT_SHA = '697194d2089779baf86074cf8cce28819607c4f7fd2e7561bcf557ac1d189183'
RECEIPT_SHA = '2b8088a430a63517ad2a77910970e37bccf9658e3c7c91ac6525a70b1db0cca8'

HARNESS = r'''
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
unsigned records=0;
template<class T>void numbers(const T& values){std::cout<<'[';bool comma=false;for(auto value:values){if(comma)std::cout<<',';comma=true;std::cout<<+value;}std::cout<<']';}
void start(const std::string& name){scenario=name;controlled_clock::nanoseconds=0;a::reset();gains.clear();gain_reads.clear();master_gain=1;a::render(nullptr,0);}
void queue(std::uint32_t key,std::int16_t value,unsigned count){std::vector<std::int16_t> values(count,value);std::uint64_t end=0;if(!a::queue(key,reinterpret_cast<const std::uint8_t*>(values.data()),static_cast<unsigned>(values.size()*2),end))throw std::runtime_error("queue refused");}
void observe(const char* operation,unsigned frames=0){
 std::vector<std::uint32_t> order;for(const auto& row:a::voices)order.push_back(row.first);
 gain_reads.clear();std::vector<float> pcm(frames*2,123);a::render(pcm.data(),frames);
 std::cout<<"{\"case\":\""<<scenario<<"\",\"operation\":\""<<operation<<"\",\"frames\":"<<frames<<",\"declared_raw_order\":";numbers(order);
 std::cout<<",\"gain_read_order\":";numbers(gain_reads);
 std::cout<<",\"bucket_count\":"<<a::voices.bucket_count()<<",\"float_bits\":[";
 for(std::size_t i=0;i<pcm.size();++i){if(i)std::cout<<',';std::cout<<std::bit_cast<std::uint32_t>(pcm[i]);}
 std::cout<<"],\"voices\":[";std::vector<std::uint32_t> keys=order;std::sort(keys.begin(),keys.end());bool comma=false;
 for(auto key:keys){if(comma)std::cout<<',';comma=true;const auto& v=a::voices.at(key);
  std::cout<<"{\"key\":"<<key<<",\"left\":"<<v.left<<",\"playing\":"<<(v.playing?"true":"false")<<",\"draining\":"<<(v.draining?"true":"false")
   <<",\"frequency\":"<<v.frequency<<",\"volume\":"<<v.volume<<",\"gain_bits\":"<<std::bit_cast<std::uint32_t>(gains.at(key))
   <<",\"phase_bits\":"<<std::bit_cast<std::uint64_t>(v.phase)<<",\"late\":"<<v.lateSamples<<",\"skipped\":"<<v.skippedSamples<<'}';}
 std::cout<<"],\"channels\":[";keys.clear();for(const auto& row:a::channels)keys.push_back(row.first);std::sort(keys.begin(),keys.end());comma=false;
 for(auto key:keys){if(comma)std::cout<<',';comma=true;const auto& c=a::channels.at(key);std::cout<<"{\"key\":"<<key<<",\"queued\":"<<c.queued<<",\"consumed\":"<<c.consumed<<",\"remaining\":"<<c.pcm.size()<<'}';}
 std::cout<<"],\"output_frames\":"<<a::outputFrames<<",\"signal_frames\":"<<a::signalFrames<<",\"underrun_frames\":"<<a::underrunFrames<<"}\n";++records;
}
'''


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def input_transcript():
    """Synthetic API inputs only; expected observations are produced by C++."""
    cases = []
    bits = lambda number:struct.unpack('<I',struct.pack('<f',number))[0]
    def reset():
        return dict(kind='reset',now_ns=0,frame_clock=True,master_gain_bits=bits(1))
    def gain(key,value):
        return dict(kind='gain',voice=key,value_f32_bits=bits(value))
    def queue(key,value):
        return dict(kind='queue',channel=key+1000,sample_i16=value,sample_count=64,now_ns=0)
    def config(key,playing=True):
        return dict(kind='configure',voice=key,left=key+1000,right=0,channels=1,
            frequency=48000,volume=256,playing=playing,now_ns=0)
    def observe(name,frames=1):
        return dict(kind='render_observe',operation=name,frames=frames)
    def payload():
        return [gain(10,7.7),gain(20,7.7),gain(30,0.01),queue(10,32767),queue(20,-32767),queue(30,1)]
    for number,order in enumerate(itertools.permutations((10,20,30))):
        cases.append(dict(case='three_cancel_'+str(number),actions=[reset()]+payload()+
            [config(key) for key in order]+[observe('three_voice_render',2)]))
    actions = [reset()]+payload()+[config(key) for key in (10,20,30)]+[
        observe('inserted'),config(20),observe('reconfigure_existing'),
        dict(kind='release',voice=20),observe('erase_middle'),config(20),observe('reinsert_middle'),
        config(20,False),observe('paused_record'),config(20),dict(kind='drain',voice=20),
        observe('draining_record'),reset(),observe('reset_empty',0)]+payload()+[
        config(key) for key in (30,10,20)]+[observe('recreate_after_reset')]
    cases.append(dict(case='mutations',actions=actions))
    actions = [reset()]
    for index in range(32):
        key = 100+index
        actions += [gain(key,1),queue(key,index+1),config(key),observe('insert',0)]
    actions += [observe('many_voice_render'),dict(kind='release',voice=115),
        observe('erase_after_rehash'),config(115),observe('reinsert_after_rehash')]
    cases.append(dict(case='rehash',actions=actions))
    return cases


def action_program(cases):
    lines = ['int main(){try{']
    for case in cases:
        for action in case['actions']:
            kind = action['kind']
            if kind == 'reset':
                lines.append('start('+json.dumps(case['case'])+');')
            elif kind == 'gain':
                lines.append('gains[%du]=std::bit_cast<float>(%du);' % (action['voice'],action['value_f32_bits']))
            elif kind == 'queue':
                lines.append('queue(%du,%d,%du);' % (action['channel'],action['sample_i16'],action['sample_count']))
            elif kind == 'configure':
                arguments = [action[key] for key in ('voice','left','right','channels','frequency','volume')]
                lines.append('a::configure('+','.join(str(value)+'u' for value in arguments)+','+str(action['playing']).lower()+');')
            elif kind in ('release','drain'):
                lines.append('a::'+kind+'('+str(action['voice'])+'u);')
            elif kind == 'render_observe':
                lines.append('observe('+json.dumps(action['operation'])+','+str(action['frames'])+'u);')
            else:
                raise ValueError('Unknown synthetic action: '+kind)
    return '\n'.join(lines)+'\nreturn 0;\n}catch(const std::exception& e){std::cerr<<e.what()<<\'\\n\';return 1;}}\n'


def validate(rows,inputs=None):
    if len(rows) != 49:
        raise ValueError('Expected all 49 independently observed snapshots')
    if inputs is not None:
        planned = [(case['case'],a['operation'],a['frames']) for case in inputs
            for a in case['actions'] if a['kind'] == 'render_observe']
        observed = [(r['case'],r['operation'],r['frames']) for r in rows]
        if planned != observed:
            raise ValueError('Input transcript and observed execution differ')
    for row in rows:
        if row['declared_raw_order'] != row['gain_read_order']:
            raise ValueError('Gain acquisition does not match actual traversal')
        if len(row['declared_raw_order']) != len(row['voices']) or len(set(row['declared_raw_order'])) != len(row['voices']):
            raise ValueError('Invalid voice permutation')
    cancellation = [r for r in rows if r['operation'] == 'three_voice_render']
    outputs = {tuple(r['float_bits']) for r in cancellation}
    if len(outputs) < 2:
        raise ValueError('Three-term associativity counterexample not demonstrated')
    mutation = {r['operation']:r for r in rows if r['case'] == 'mutations'}
    if mutation['inserted']['declared_raw_order'] != mutation['reconfigure_existing']['declared_raw_order']:
        raise ValueError('Existing configure unexpectedly changes traversal')
    if mutation['erase_middle']['declared_raw_order'] != [key for key in mutation['reconfigure_existing']['declared_raw_order'] if key != 20]:
        raise ValueError('Erase changes surviving voice order')
    if mutation['reset_empty']['declared_raw_order']:
        raise ValueError('Reset retained voices')
    buckets = [r['bucket_count'] for r in rows if r['case'] == 'rehash' and r['operation'] == 'insert']
    if len(set(buckets)) < 2:
        raise ValueError('Automatic rehash was not exercised')
    paused = mutation['paused_record']
    if 20 not in paused['gain_read_order'] or next(v for v in paused['voices'] if v['key'] == 20)['playing']:
        raise ValueError('Paused voice gain acquisition not observed')
    return dict(cases=len({r['case'] for r in rows}),snapshots=len(rows),
        distinct_cancellation_outputs=len(outputs),float_values=sum(len(r['float_bits']) for r in rows),
        rehash_bucket_counts=list(dict.fromkeys(buckets)))


def generate(dependency, compiler, output):
    dependency, output = dependency.resolve(), output.resolve()
    allowed = ROOT/'build-native-sjuni'
    if output == allowed or not output.is_relative_to(allowed):
        raise ValueError('Use a private ignored output directory')
    transcript = ROOT/'tools/native_reconstruction/pcm_owner_oracle.py'
    if sha(transcript) != TRANSCRIPT_SHA:
        raise ValueError('Frozen original harness changed')
    spec = importlib.util.spec_from_file_location('pcm_original_harness',transcript)
    ref = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(ref)
    source = dependency/'ps2xRuntime/src/lib'
    identities = {name:sha(source/name) for name in ref.EXPECTED}
    if identities != ref.EXPECTED:
        raise ValueError('Exact reconstructed121 source identity changed')
    receipt = ROOT/'build-native-sjuni/dependency-workers-reapply-v2-receipt.json'
    if sha(receipt) != RECEIPT_SHA:
        raise ValueError('Reconstruction receipt changed')
    tool = shutil.which(str(compiler))
    if not tool:
        raise ValueError('Existing C++20 compiler required')
    output.mkdir(parents=True,exist_ok=True)
    snapshot = output/'snapshot'
    helpers = snapshot/'Kernel/Syscalls/Helpers'
    helpers.mkdir(parents=True,exist_ok=True)
    for name in ('CriAudio.cpp','CriAudio.h'):
        shutil.copyfile(source/'Kernel/Syscalls/Helpers'/name,helpers/name)
    shutil.copyfile(source/'cri_pcm_retire.h',snapshot/'cri_pcm_retire.h')
    for name, contents in [('Kernel/Syscalls/Helpers/ReoSoundBanks.h',ref.MOCK_BANK),('ps2_host_backend.h',ref.MOCK_HOST),('vblank_music_diag.h',ref.MOCK_DIAG)]:
        (snapshot/name).write_text(contents,encoding='utf-8',newline='\n')
    prefix = ref.HARNESS.split('float master_gain=',1)[0]
    if prefix == ref.HARNESS:
        raise ValueError('Exact original source-include boundary missing')
    harness, exe = output/'probe.cpp', output/'probe.exe'
    inputs = input_transcript()
    harness.write_text(prefix+HARNESS+action_program(inputs),encoding='utf-8',newline='\n')
    cc = Path(tool).resolve()
    command = [tool,'-std=c++20','-O1','-ffp-contract=off','-Wall','-Wextra','-Wpedantic','-Werror','-I'+str(snapshot),str(harness),'-o',str(exe)]
    env = dict(os.environ)
    for name in list(env):
        if name.startswith(('REO_CRI_','REO_AUDIO_PATH','REO_RNA_STOP')):
            env.pop(name,None)
    env['PATH'] = str(cc.parent)+os.pathsep+env.get('PATH','')
    proof = dict(schema=1,status='running',compiler=str(cc),compiler_sha256=sha(cc),
        source_sha256=identities,tool_sha256=sha(Path(__file__)),harness_sha256=sha(harness),
        original_harness_sha256=TRANSCRIPT_SHA,dependency_receipt_sha256=RECEIPT_SHA,
        command=command,game_run=False,device_opened=False,assets_read=False)
    try:
        build = subprocess.run(command,env=env,capture_output=True,text=True,timeout=90)
        proof['compile'] = dict(exit_code=build.returncode,stderr=build.stderr)
        if build.returncode:
            raise RuntimeError(build.stderr)
        run = subprocess.run([str(exe)],env=env,capture_output=True,text=True,timeout=30)
        proof['execution'] = dict(exit_code=run.returncode,stderr=run.stderr)
        if run.returncode:
            raise RuntimeError(run.stderr)
        rows = [json.loads(line) for line in run.stdout.splitlines()]
        summary = validate(rows,inputs)
        fixture = output/'fixtures.json'
        fixture.write_text(json.dumps(dict(schema=2,source_sha256=identities,compiler_sha256=sha(cc),
            inputs=inputs,records=rows),indent=2)+'\n',encoding='utf-8',newline='\n')
        proof.update(status='passed',**summary,fixture_sha256=sha(fixture),fixture_bytes=fixture.stat().st_size)
    except Exception as error:
        proof.update(status='failed',failure=str(error))
        raise
    finally:
        (output/'receipt.json').write_text(json.dumps(proof,indent=2)+'\n',encoding='utf-8',newline='\n')
    return proof


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--dependency',type=Path,default=ROOT/'build-native-sjuni/dependency-workers-reapply-v2')
    parser.add_argument('--cxx',required=True)
    parser.add_argument('--output',type=Path,required=True)
    args = parser.parse_args()
    proof = generate(args.dependency,args.cxx,args.output)
    print(json.dumps({key:proof[key] for key in ('status','cases','snapshots','distinct_cancellation_outputs','float_values','rehash_bucket_counts','fixture_sha256')}))


if __name__ == '__main__':
    main()
