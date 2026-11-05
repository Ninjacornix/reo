"""Freeze synthetic inputs; observe complete unchanged124 bank source, no candidate.

No native-bank candidate is imported, read or compiled. Python constructs only
asset/action wire bytes and records source-produced observations; it implements
no VAG, sequence, envelope, mixer or expected-state algorithm.
"""
import argparse
import hashlib
import json
import os
from pathlib import Path
import shutil
import struct
import subprocess

ROOT = Path(__file__).resolve().parents[2]
SOURCE = "ps2xRuntime/src/lib/Kernel/Syscalls/Helpers/ReoSoundBanks.cpp"
HEADER = "ps2xRuntime/src/lib/Kernel/Syscalls/Helpers/ReoSoundBanks.h"
SOURCE_SHA = "e164ba72cc002311d4811d803be2e2df9a6228d5abcaa0c4fa419a31ee09b818"
HEADER_SHA = "28963da544d533ae8f04765558ff0665c4dc87c38cfba767a4828705c07616c8"
RECEIPT_SHA = "944b72d4cc977ac01d8e7a4459c601f0a331b06c8adbb5048bec45a2963f91cb"


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def canonical(value):
    return (json.dumps(value, sort_keys=True, separators=(",", ":")) + "\n").encode()


def synthetic_bank(name, *, layers=1, seed=1, loop=True, exponential=False,
                   crossfade=False, bad_filter=False, no_end=False, fallback=False,
                   bad_header=False, bad_tq=False, bad_record=False, velocity_curve=0,
                   loop_start=0):
    """Authored format bytes checked against the original loader, not DSP output."""
    hd = bytearray(0x380)
    def put16(at, value):
        struct.pack_into("<H", hd, at, value & 65535)
    def put32(at, value):
        struct.pack_into("<I", hd, at, value)
    def signature(at, kind):
        hd[at:at+8] = b"IECS" + kind.encode()[::-1]
    signature(0, "Vers"); signature(0x10, "Head")
    chunks = ((0x40, "Prog", (0x60, 0xA0)), (0x140, "Sset", (0x160, 0x180)),
              (0x1C0, "Smpl", (0x1E0, 0x210, 0x240, 0x270)),
              (0x300, "Vagi", (0x320, 0x328, 0x330, 0x338)))
    for i, (base, kind, records) in enumerate(chunks):
        put32(0x24 + i*4, base); signature(base, kind)
        put32(base+12, len(records)-1)
        for index, record in enumerate(records): put32(base+16+index*4, record-base)
    for index, record in enumerate((0x60, 0xA0)):
        put32(record, 0x24); hd[record+4] = 1
        hd[record+6:record+10] = bytes((64, 64, 0 if index == 0 else 244, 0 if index == 0 else 4))
        region = record + 0x24
        put16(region, index)
        hd[region+2:region+5] = bytes((128 if crossfade else 0, 60, 255 if crossfade else 127))
        put16(region+6, 256); put16(region+8, 384)
        hd[region+16:region+20] = bytes((64,64,0,0))
    for index, record in enumerate((0x160, 0x180)):
        count = layers if index == 0 else 1
        hd[record:record+4] = bytes((velocity_curve, 0,127,count))
        for sample in range(count): put16(record+4+sample*2, sample if index == 0 else 1)
    for index, record in enumerate((0x1E0,0x210,0x240,0x270)):
        put16(record,index)
        hd[record+2:record+5] = bytes((128 if crossfade else 0,64,255 if crossfade else 127))
        hd[record+11:record+14] = bytes((60,0,64))
        hd[record+16] = 64
        put16(record+0x12,0x8804 if exponential else 0x000F)
        put16(record+0x14,0xC124 if exponential else 0x0004)
    for index, record in enumerate((0x320,0x328,0x330,0x338)):
        put32(record,index*48); put16(record+4,(24000,48000,16000,12000)[index])
        hd[record+6] = index
    bd = bytearray()
    filters = ((0,1,2),(3,4,0),(4,3,2),(0,0,0))
    for sample in range(4):
        for block in range(3):
            shift = (8,9,15 if sample == 3 else 12)[block]
            flags = (4 if block == loop_start else 0) | ((3 if loop else 1) if block == 2 else 0)
            bd.extend(bytes(((filters[sample][block] << 4) | shift, flags)))
            bd.extend(bytes((((n + seed + sample) & 15) | (((15 - n + seed + block) & 15) << 4)) for n in range(14)))
    starts = [0x40 + index*0x40 for index in range(8)]
    sequences = [
        [0xE0,110,0xE2,0,0xE1,48,0xE4,100,0xE3,0,64,0xB0,127,0,0,0xE5,0,0,0xFF],
        [0xE2,0,0xB0,110,0,0,0xE5,0,0,0xF8,starts[1]+2,0],
        [0xE2,1,0xE0,90,0xE4,80,0xE1,100,0xE3,0,80,0xE7,3,0xBC,0x85,96,2,0,0xFE,0xFE],
        [0xB0,127,0,0,0xEB],
        [0xF8,starts[4] & 255,starts[4] >> 8],
        [0xFF],
        [0xB0,0x83,127,0,0,0xB0,0x83,0,0,0,0xFE,1],
        [0xB0,100,1,0xE5,0,0,0xFF],
    ]
    # Jump targets are little-endian words; sequence1 loops back to its note.
    sequences[1][-2:] = [(starts[1]+2) & 255,(starts[1]+2) >> 8]
    tq = bytearray(0x240)
    struct.pack_into("<H",tq,14,8)
    for index,(at,commands) in enumerate(zip(starts,sequences)):
        struct.pack_into("<I",tq,16+index*4,at | ((32 if index == 5 else 255 if index == 7 else 64) << 24))
        tq[at:at+len(commands)] = bytes(commands)
    if fallback:
        tq = bytearray(0x20); tq[4:11] = bytes((0xE2,0,0xB0,127,0,0,0xFF))
    if bad_filter: bd[0] = 0xF8
    if no_end:
        bd = bd[:48]
        for at in (1,17,33): bd[at] = 0
    if bad_header: hd[0] ^= 1
    if bad_tq: struct.pack_into("<H",tq,14,65535)
    if bad_record: put32(0x1C0+16,0xFFFFFFFF)
    return {"name":name,"hd_hex":hd.hex(),"bd_hex":bd.hex(),"tq_hex":tq.hex()}


def packet(values, *, ram=b"", null=False):
    return {"op":"packet","bytes_hex":bytes(values).hex(),"ram_hex":bytes(ram).hex(),"null":null}


def many_layers_bank():
    base = synthetic_bank("resolution_65025")
    original = bytes.fromhex(base["hd_hex"])
    hd = bytearray(0x1940); hd[:0x34] = original[:0x34]
    for index,(at,kind,record) in enumerate(((0x40,"Prog",0x60),(0x1500,"Sset",0x1520),
                                            (0x1800,"Smpl",0x1820),(0x1900,"Vagi",0x1920))):
        hd[at:at+8] = b"IECS" + kind.encode()[::-1]
        struct.pack_into("<I",hd,0x24+index*4,at)
        struct.pack_into("<I",hd,at+12,0)
        struct.pack_into("<I",hd,at+16,record-at)
    hd[0x60:0x82] = original[0x60:0x82]
    struct.pack_into("<I",hd,0x60,0xA0); hd[0x64] = 255
    for index in range(255): hd[0x100+index*20:0x100+(index+1)*20] = original[0x84:0x98]
    hd[0x1520:0x1524] = bytes((0,0,127,255))
    hd[0x1820:0x184A] = original[0x1E0:0x20A]
    hd[0x1920:0x1928] = original[0x320:0x328]
    base["hd_hex"] = hd.hex(); base["bd_hex"] = base["bd_hex"][:96]
    return base


def wire_load(asset, port, opcode=0x4D, alias=0):
    ram = bytearray(0x1000); command = bytearray((opcode,port >> 8,port & 255))
    for at, name in zip((0x100,0x500,0x800),("hd_hex","bd_hex","tq_hex")):
        data = bytes.fromhex(asset[name]); assert len(data) % 16 == 0
        ram[at:at+len(data)] = data
        address = at | alias; size = len(data)
        command.extend(((address >> 24)&255,(address >> 16)&255,(address >> 8)&255,
                        (address & 240) | ((size >> 20)&15),(size >> 12)&255,(size >> 4)&255))
    return packet(command,ram=ram)


def transcript():
    assets = [synthetic_bank("loop"),synthetic_bank("loop_changed_bd",seed=7),
        synthetic_bank("one_shot",loop=False),synthetic_bank("layers",layers=4),
        synthetic_bank("exponential",exponential=True,crossfade=True),
        synthetic_bank("bad_filter",bad_filter=True),synthetic_bank("no_end",no_end=True),
        synthetic_bank("bad_header",bad_header=True),synthetic_bank("bad_tq",bad_tq=True),
        synthetic_bank("bad_record",bad_record=True),synthetic_bank("fallback_tq",fallback=True),
        synthetic_bank("velocity_curve",velocity_curve=1),many_layers_bank(),
        synthetic_bank("loop_offset",loop_start=1)]
    max_events = synthetic_bank("events_1025")
    tq = bytearray(0x430); struct.pack_into("<H",tq,14,1)
    struct.pack_into("<I",tq,16,0x20 | (64 << 24))
    tq[0x20:0x20+1025] = bytes([0xE5]*1023 + [0xFE,1])
    max_events["tq_hex"] = tq.hex(); assets.append(max_events)
    byname = {asset["name"]:asset for asset in assets}
    def load(port=2,asset="loop"): return {"op":"bank","port":port,"asset":asset}
    def req(port=2,index=1,group=3,trailer=0): return packet((0,port,index,group,trailer))
    def mix(frames,kind="normal"): return {"op":"mix","frames":frames,"kind":kind,"fill_bits":[0x3D800000,0xBD000000]}
    def case(name,actions): return {"name":name,"actions":[{"op":"reset"},{"op":"gain","mode":0},*actions]}
    cases = [
        case("empty_gain_sampling",[{"op":"gain","mode":1},mix(17,"null"),mix(0),mix(1),
             {"op":"query","port":14,"index":0,"group":0}]),
        case("parser_vag_sequence",[{"op":"probe","asset":a["name"]} for a in assets]),
        case("split_600",[load(),req(),mix(1),mix(198),mix(1),mix(1),mix(199),mix(200)]),
        case("whole_600",[load(),req(),mix(600)]),
        case("cancel_tail",[load(),req(),mix(20),packet((8,2,1,3)),
             {"op":"query","port":2,"index":129,"group":131},mix(1),mix(64),mix(115),mix(200)]),
        case("stop_unload_replace",[load(),req(),mix(10),load(asset="loop_changed_bd"),req(group=5),mix(1),
             packet((0x4A,2)),mix(1),req(group=6),mix(1),packet((0x47,2)),mix(187),
             wire_load(byname["one_shot"],2),req(index=7,group=1,trailer=1),mix(33),
             packet((0x43,)),{"op":"reset"}]),
        case("controls",[load(asset="exponential"),packet((7,2,2,5,90,16,0x28,0,0)),mix(1),mix(128),
             packet((15,2,128,128,50,120,0x10,0,0)),mix(100),packet((0x4C,2,1,128)),mix(1),
             packet((0x29,0,128,0x42,0,0x41,1)),mix(220),packet((0x41,0,0x42,1)),
             packet((9,2,2,5,0,0)),mix(200),packet((9,2,2,5,127,0)),mix(400)]),
        case("all_ports_gain_order",[{"op":"gain","mode":1},*[load(port=p) for p in range(14)],
             *[req(port=p,index=p%8,group=p) for p in range(14)],mix(1),mix(200)]),
        case("request_priority",[load(port=0),*[req(port=0,index=5,group=g) for g in range(16)],
             req(port=0,index=0,group=20),packet((15,0,128,128,80,110,0x30,0,0)),mix(1),
             packet((8,0,128,128)),req(port=128,index=1,group=3),mix(1),req(port=128,index=0,group=4),mix(200)]),
        case("voice_capacity",[load(port=0,asset="layers"),*[req(port=0,index=1,group=g) for g in range(16)],
             mix(1),packet((0x40,)),mix(1),req(port=0,group=30),mix(198),mix(1)]),
        case("packet_prefix_failures",[load(),req(),mix(1),packet((0x41,1,0x4C,2,0,64,0x10)),
             packet((0x4C,2,1)),packet((0x44,0,0,0,0,0,0x45,1,2,3,0x4B,4,5)),
             packet((0x4D,0,14,*([0]*18))),packet((255,0x41,0)),packet(()),packet((0,),null=True),mix(1)]),
        case("wire_load",[wire_load(byname["loop"],3,alias=0xA0000000),
             packet((0x4E,0,3,*([255]*18))),wire_load(byname["bad_header"],3),
             packet((0x29,1,64,0x4D,0,3,*([0]*18))),packet((0x4E,0,0,*([255]*18))),
             req(port=3),mix(9),packet((0x28,)),packet((0x48,3)),packet((0x49,13)),
             wire_load(byname["one_shot"],3),req(port=3,index=7,trailer=1),mix(200)]),
        case("sample_refusals",[load(asset="bad_filter"),req(),mix(1),load(asset="velocity_curve"),req(),mix(200),
             load(asset="no_end"),req(),mix(200),load(asset="bad_record"),req(),mix(200)]),
        case("exponential_release",[load(asset="exponential"),req(),mix(800),packet((8,2,1,3)),mix(400),mix(400)]),
        case("invalid_load_retains",[load(),req(),mix(5),load(asset="bad_header"),load(port=14),mix(195),
             {"op":"query","port":99,"index":0,"group":0}]),
        case("layer_count_boundary",[load(port=0,asset="resolution_65025"),req(port=0,index=0),mix(1)]),
        case("event_count_boundary",[load(port=0,asset="events_1025"),req(port=0,index=0),mix(1)]),
        case("loop_offset_envelope_phases",[load(asset="loop_offset"),req(index=7),mix(1),mix(1),mix(1),mix(1),
             mix(300),packet((8,2,7,3)),mix(32),mix(64)]),
    ]
    return {"schema":1,"purpose":"source-only complete bank-session observations",
            "assets":assets,"cases":cases,"max_mix_frames":1200,"max_wire_bytes":65536}


def encode(value):
    output = bytearray(b"RBSO1\0\0\0")
    def u32(v): output.extend(struct.pack("<I",v))
    def blob(v): u32(len(v)); output.extend(v)
    def text(v): blob(v.encode())
    u32(len(value["assets"]))
    names = {}
    for index, asset in enumerate(value["assets"]):
        names[asset["name"]] = index; text(asset["name"])
        for k in ("hd_hex","bd_hex","tq_hex"): blob(bytes.fromhex(asset[k]))
    kinds = {"reset":0,"bank":1,"packet":2,"mix":3,"gain":4,"probe":5,"query":6}
    u32(len(value["cases"]))
    for case in value["cases"]:
        text(case["name"]); u32(len(case["actions"]))
        for action in case["actions"]:
            u32(kinds[action["op"]])
            if action["op"] == "bank": u32(action["port"]); u32(names[action["asset"]])
            elif action["op"] == "packet":
                u32(int(action["null"])); blob(bytes.fromhex(action["bytes_hex"])); blob(bytes.fromhex(action["ram_hex"]))
            elif action["op"] == "mix":
                u32(action["frames"]); u32(int(action["kind"] == "null"))
                for bits in action["fill_bits"]: u32(bits)
            elif action["op"] == "gain": u32(action["mode"])
            elif action["op"] == "probe": u32(names[action["asset"]])
            elif action["op"] == "query":
                for key in ("port","index","group"): u32(action[key])
    return bytes(output)


HARNESS = r'''
#include "source/ReoSoundBanks.cpp"
#include <bit>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <type_traits>
namespace s = ps2_reo_sound;
struct GainCall { unsigned port,sequence; uint64_t fingerprint; float value; };
std::vector<GainCall> gainCalls;
unsigned gainMode=0;
float reoAudioBankGain(unsigned port,unsigned sequence,uint64_t fingerprint) {
    const float value=gainMode?float((port+sequence+unsigned(fingerprint&3))%5)*0.25f:1.0f;
    gainCalls.push_back({port,sequence,fingerprint,value}); return value;
}
void require(bool value,const char* why){if(!value)throw std::runtime_error(why);}
struct Input {
    std::ifstream f;
    explicit Input(const char* path):f(path,std::ios::binary){require(bool(f),"input open");}
    uint32_t word(){uint8_t b[4];f.read(reinterpret_cast<char*>(b),4);require(bool(f),"input word");return uint32_t(b[0])|uint32_t(b[1])<<8|uint32_t(b[2])<<16|uint32_t(b[3])<<24;}
    std::vector<uint8_t> blob(){auto n=word();require(n<=65536,"input blob bound");std::vector<uint8_t>b(n);if(n)f.read(reinterpret_cast<char*>(b.data()),n);require(bool(f),"input blob");return b;}
    std::string text(){auto b=blob();return {b.begin(),b.end()};}
};
void quote(std::ostream&o,const std::string&v){o<<'"';for(char c:v){if(c=='"'||c=='\\')o<<'\\';o<<c;}o<<'"';}
template<class T>void nums(std::ostream&o,const std::vector<T>&v){o<<'[';for(size_t i=0;i<v.size();++i){if(i)o<<',';o<<+v[i];}o<<']';}
struct SequenceImage {uint32_t cursor;uint16_t wait;uint8_t programOffset;bool active,hasNote;};
static_assert(std::is_standard_layout_v<s::Sequence> && std::is_trivially_copyable_v<s::Sequence>);
static_assert(sizeof(s::Sequence)==sizeof(SequenceImage)&&alignof(s::Sequence)==alignof(SequenceImage));
#if defined(__GNUC__) && !defined(__clang__)
static_assert(std::is_layout_compatible_v<s::Sequence,SequenceImage>);
#endif
SequenceImage sequenceImage(const s::Sequence& q){auto x=std::bit_cast<SequenceImage>(q);require(x.active==q.active(),"sequence observer layout");return x;}
std::vector<std::weak_ptr<const s::DecodedSample>> clipOwners;
uint64_t clipId(const std::shared_ptr<const s::DecodedSample>& data){if(!data)return 0;for(size_t i=0;i<clipOwners.size();++i)if(!clipOwners[i].owner_before(data)&&!data.owner_before(clipOwners[i]))return i+1;clipOwners.push_back(data);return clipOwners.size();}
uint64_t pcmHash(const s::DecodedSample& data){uint64_t h=14695981039346656037ull;for(auto x:data.pcm){for(unsigned shift:{0u,8u}){h^=uint8_t(uint16_t(x)>>shift);h*=1099511628211ull;}}return h;}
void clip(std::ostream&o,const std::shared_ptr<const s::DecodedSample>&d){if(!d){o<<"null";return;}o<<"{\"id\":"<<clipId(d)<<",\"pcm_hash\":"<<pcmHash(*d)<<",\"samples\":"<<d->pcm.size()<<",\"loop_start\":"<<d->loopStart<<",\"loop\":"<<d->hasLoop<<'}';}
std::array<int64_t,28> sampleWords(const s::Sample&v){return {v.bdOffset,v.sampleRate,v.adsr1,v.adsr2,v.flags,v.rootNote,v.programVolume,v.regionVolume,v.sampleVolume,v.programTranspose,v.programFine,v.regionTranspose,v.regionFine,v.sampleFine,v.programRecord,v.regionRecord,v.sampleRecord,v.vagiRecord,v.velocityCurve,v.regionLow,v.regionCenter,v.regionHigh,v.velocityLow,v.velocityCenter,v.velocityHigh,v.bendDown,v.bendUp,v.basePan};}
void sample(std::ostream&o,const s::Sample&v){auto words=sampleWords(v);o<<'[';for(unsigned i=0;i<words.size();++i){if(i)o<<',';o<<words[i];}o<<']';}
uint64_t sampleHash(const std::vector<s::Sample>&samples){uint64_t h=14695981039346656037ull;for(const auto&v:samples)for(auto word:sampleWords(v))for(unsigned shift=0;shift<64;shift+=8){h^=uint8_t(uint64_t(word)>>shift);h*=1099511628211ull;}return h;}
void snapshot(std::ostream&o){
    o<<"{\"clock\":"<<s::frameClock<<",\"request_age\":"<<s::requestAge<<",\"muted\":"<<s::muted<<",\"mono\":"<<s::mono<<",\"unsupported_reports\":"<<s::unsupportedReports<<",\"pending_loads\":"<<s::pendingLoads()<<",\"ports\":[";
    for(unsigned p=0;p<s::ports.size();++p){if(p)o<<',';const auto& port=s::ports[p];uint32_t count=999;auto state=s::portState(p,count);
        o<<"{\"loaded\":"<<port.loaded<<",\"fingerprint\":"<<port.fingerprint<<",\"volume\":"<<port.volume<<",\"bank_sequences\":"<<port.bank.sequenceCount()<<",\"query\":["<<state<<','<<count<<"],\"requests\":[";
        for(unsigned slot=0;slot<16;++slot){if(slot)o<<',';const auto&r=port.requests[slot];auto q=sequenceImage(r.sequence);
            o<<'['<<q.cursor<<','<<q.wait<<','<<+q.programOffset<<','<<q.active<<','<<q.hasNote<<','<<+r.index<<','<<+r.group<<','<<+r.priority<<','<<+r.cancelFlags<<','<<+r.requestVolume<<','<<+r.requestPan<<','<<r.requestPitch<<','<<r.pitch<<','<<r.program<<','<<r.volume<<','<<r.expression<<','<<r.pan<<','<<r.age<<','<<s::seState(p,r.index,r.group)<<']';
        }o<<"],\"resolved\":[";
        for(unsigned program=0;program<2;++program){if(program)o<<',';std::vector<s::Sample> samples;bool ok=port.bank.resolve(program,60,127,samples);o<<"{\"ok\":"<<ok<<",\"sample_count\":"<<samples.size()<<",\"sample_hash\":"<<sampleHash(samples)<<",\"metadata_complete\":"<<(samples.size()<=128)<<",\"samples\":[";for(size_t j=0;j<std::min<size_t>(128,samples.size());++j){if(j)o<<',';o<<"{\"metadata\":";sample(o,samples[j]);o<<",\"clip\":";clip(o,port.bank.decoded(samples[j]));o<<'}';}o<<"]}";}
        o<<"]}";
    }o<<"],\"voices\":[";
    require(s::voices.size()<=48,"source voice bound");
    for(size_t i=0;i<s::voices.size();++i){if(i)o<<',';const auto&v=s::voices[i];o<<"{\"port\":"<<v.port<<",\"slot\":"<<v.slot<<",\"note\":"<<+v.note<<",\"group\":"<<+v.group<<",\"velocity\":"<<+v.velocity<<",\"sample\":";sample(o,v.sample);o<<",\"clip\":";clip(o,v.data);o<<",\"position_bits\":"<<std::bit_cast<uint64_t>(v.position)<<",\"step_bits\":"<<std::bit_cast<uint64_t>(v.step)<<",\"cached_bend\":"<<v.cachedBend<<",\"envelope\":["<<unsigned(v.envelope.phase)<<','<<v.envelope.value<<','<<v.envelope.countdown<<','<<v.envelope.first<<','<<v.envelope.second<<"],\"active\":"<<v.active<<'}';}
    o<<"]}";
}
struct Asset{std::string name;std::vector<uint8_t>hd,bd,tq;};
void probe(std::ostream&o,const Asset&a){s::Bank b;bool ok=b.load(a.hd.data(),a.hd.size(),a.bd.data(),a.bd.size(),a.tq.data(),a.tq.size());o<<"{\"loaded\":"<<ok<<",\"fingerprint\":"<<b.fingerprint()<<",\"sequence_count\":"<<b.sequenceCount()<<",\"decoded\":[";
    for(unsigned i=0;i<4;++i){if(i)o<<',';s::Sample sample;sample.bdOffset=i*48;s::DecodedSample d;bool valid=b.decode(sample,d);o<<"{\"valid\":"<<valid<<",\"loop\":"<<d.hasLoop<<",\"loop_start\":"<<d.loopStart<<",\"pcm\":";nums(o,d.pcm);o<<'}';}
    o<<"],\"sequences\":[";
    for(unsigned i=0;i<9;++i){if(i)o<<',';s::Sequence q;bool start=q.start(b,i,i==7?1:0);o<<"{\"started\":"<<start<<",\"ticks\":[";for(unsigned t=0;t<12;++t){if(t)o<<',';std::vector<s::Event>events;bool active=q.tick(b,t%3==1,events);auto image=sequenceImage(q);o<<"{\"returned\":"<<active<<",\"state\":["<<image.cursor<<','<<image.wait<<','<<+image.programOffset<<','<<image.active<<','<<image.hasNote<<"],\"events\":[";for(size_t e=0;e<events.size();++e){if(e)o<<',';o<<'['<<unsigned(events[e].type)<<','<<events[e].value<<','<<+events[e].note<<','<<+events[e].group<<']';}o<<"]}";}o<<"]}";}o<<"]}";
}
int main(int argc,char**argv)try{
    require(argc==3,"input/output arguments");Input in(argv[1]);char magic[8];in.f.read(magic,8);require(std::memcmp(magic,"RBSO1\0\0\0",8)==0,"input signature");
    auto assetCount=in.word();require(assetCount<=32,"asset bound");std::vector<Asset>assets;for(unsigned i=0;i<assetCount;++i){Asset a;a.name=in.text();a.hd=in.blob();a.bd=in.blob();a.tq=in.blob();assets.push_back(std::move(a));}
    std::ofstream o(argv[2]);require(bool(o),"output open");o<<std::boolalpha<<"{\"schema\":1,\"sequence_observer_bytes\":"<<sizeof(SequenceImage)<<",\"request_fields\":[\"cursor\",\"wait\",\"program_offset\",\"active\",\"has_note\",\"index\",\"group\",\"priority\",\"cancel_flags\",\"request_volume\",\"request_pan\",\"request_pitch\",\"pitch\",\"program\",\"volume\",\"expression\",\"pan\",\"age\",\"se_state\"],\"cases\":[";
    unsigned cases=in.word();require(cases<=32,"case bound");unsigned actionTotal=0,mixTotal=0;
    for(unsigned c=0;c<cases;++c){if(c)o<<',';clipOwners.clear();std::string name=in.text();o<<"{\"name\":";quote(o,name);o<<",\"actions\":[";unsigned actions=in.word();require(actions<=128,"action bound");
        for(unsigned at=0;at<actions;++at){if(at)o<<',';++actionTotal;gainCalls.clear();unsigned kind=in.word();o<<"{\"kind\":"<<kind;bool result=true;std::vector<float>out;
            if(kind==0)s::reset();
            else if(kind==1){auto port=in.word(),index=in.word();require(index<assets.size(),"asset index");const auto&a=assets[index];result=s::submitBank(port,a.hd.data(),a.hd.size(),a.bd.data(),a.bd.size(),a.tq.data(),a.tq.size());}
            else if(kind==2){bool null=in.word()!=0;auto packet=in.blob(),ram=in.blob();result=s::submitPacket(ram.empty()?nullptr:ram.data(),ram.size(),null?nullptr:packet.data(),null?1:packet.size());}
            else if(kind==3){auto frames=in.word(),null=in.word();auto l=in.word(),r=in.word();require(frames<=1200,"mix bound");out.resize(size_t(frames)*2);for(unsigned f=0;f<frames;++f){out[f*2]=std::bit_cast<float>(l);out[f*2+1]=std::bit_cast<float>(r);}s::mix(null?nullptr:out.data(),frames);if(null)out.clear();mixTotal+=frames;}
            else if(kind==4){gainMode=in.word();require(gainMode<2,"gain mode");}
            else if(kind==5){auto index=in.word();require(index<assets.size(),"probe index");o<<",\"probe\":";probe(o,assets[index]);}
            else if(kind==6){auto port=in.word(),index=in.word(),group=in.word();uint32_t count=999;auto state=s::portState(port,count);o<<",\"query\":["<<state<<','<<count<<','<<s::seState(port,index,group)<<']';}
            else throw std::runtime_error("action kind");
            o<<",\"returned\":"<<result<<",\"pcm_bits\":[";for(size_t f=0;f<out.size();++f){if(f)o<<',';o<<std::bit_cast<uint32_t>(out[f]);}o<<"],\"gain_calls\":[";
            for(size_t g=0;g<gainCalls.size();++g){if(g)o<<',';const auto&v=gainCalls[g];o<<'['<<v.port<<','<<v.sequence<<','<<v.fingerprint<<','<<std::bit_cast<uint32_t>(v.value)<<']';}
            o<<"],\"state\":";snapshot(o);o<<'}';
        }o<<"]}";
    }o<<"]}\n";require(bool(o),"output write");char extra;require(!in.f.read(&extra,1),"input trailing bytes");std::cout<<"original bank cases="<<cases<<" actions="<<actionTotal<<" requested_mix_frames="<<mixTotal<<"\n";return 0;
}catch(const std::exception&e){std::cerr<<e.what()<<'\n';return 1;}
'''


def freeze(output):
    value = transcript()
    inputs = {"input.json":canonical(value),"input.bin":encode(value),"harness.cpp":HARNESS.encode()}
    for name, data in inputs.items():
        path = output / name
        if path.exists() and path.read_bytes() != data:
            raise ValueError(f"Frozen input changed: {path}; use a new reviewed output cohort")
        if not path.exists(): path.write_bytes(data)
    manifest = {"schema":1,"kind":"synthetic input freeze, no expected DSP",
        "source_sha256":SOURCE_SHA,"header_sha256":HEADER_SHA,
        "inputs":{name:sha(output / name) for name in inputs},
        "asset_count":len(value["assets"]),"case_count":len(value["cases"]),
        "action_count":sum(len(case["actions"]) for case in value["cases"])}
    path = output / "input-manifest.json"
    encoded = canonical(manifest)
    if path.exists() and path.read_bytes() != encoded: raise ValueError("Input manifest changed")
    path.write_bytes(encoded)
    return value, manifest


def run(command, env):
    result = subprocess.run([str(x) for x in command], capture_output=True,text=True,env=env,timeout=180)
    if result.returncode: raise RuntimeError(f"{command}\n{result.returncode}\n{result.stdout}\n{result.stderr}")
    return result


def generate(checkout, baseline, compilers, output, freeze_only=False):
    assert sha(baseline) == RECEIPT_SHA, "Unqualified reconstruction receipt"
    receipt = json.loads(baseline.read_text())
    assert receipt["status"] == "passed" and receipt["applied_count"] == 124
    for name, expected in ((SOURCE,SOURCE_SHA),(HEADER,HEADER_SHA)):
        assert sha(checkout/name) == expected == receipt["source_sha256"][name], name
    value, frozen = freeze(output)
    if freeze_only: return {"input_manifest":str(output/"input-manifest.json"),**frozen}
    source = output / "source"; source.mkdir(exist_ok=True)
    for name in (SOURCE,HEADER): shutil.copyfile(checkout/name,source/Path(name).name)
    result = {"schema":1,"status":"passed","kind":"unchanged original bank source oracle",
        "base_receipt_sha256":RECEIPT_SHA,"source_sha256":SOURCE_SHA,"header_sha256":HEADER_SHA,
        "generator_sha256":sha(Path(__file__)),"input_manifest_sha256":sha(output/"input-manifest.json"),
        "candidate_read":False,"device_opened":False,"game_run":False,"compilers":[]}
    for index, compiler in enumerate(compilers):
        folder=output/str(index);folder.mkdir(exist_ok=True)
        env=dict(os.environ);env["PATH"]=str(compiler.parent)+os.pathsep+env.get("PATH","")
        env.pop("REO_AUDIO_PATH_LOG",None)
        executable=folder/"source-bank.exe"
        command=[compiler,"-std=c++20","-O2","-DNDEBUG","-msse4.1","-fms-extensions",
                 "-Wall","-Wextra","-Werror","-Wno-misleading-indentation","-fno-fast-math",
                 "-ffp-contract=off","-fno-strict-aliasing","-fwrapv","-pthread",output/"harness.cpp","-o",executable]
        run(command,env)
        pending=folder/"observations.pending.json"
        executed=run([executable,output/"input.bin",pending],env)
        observed=json.loads(pending.read_text())
        expected=folder/"expected.json"
        data=canonical(observed)
        if expected.exists() and expected.read_bytes()!=data:
            raise ValueError("Frozen expected observations changed: "+str(expected))
        expected.write_bytes(data)
        result["compilers"].append({"compiler":str(compiler),
            "compiler_version":run([compiler,"--version"],env).stdout.splitlines()[0],
            "command":[str(x) for x in command],"stdout":executed.stdout,"stderr":executed.stderr,
            "executable_sha256":sha(executable),"expected_sha256":sha(expected),"expected":str(expected),
            "case_count":len(observed["cases"]),"action_count":sum(len(c["actions"]) for c in observed["cases"])})
        assert sha(source/"ReoSoundBanks.cpp")==SOURCE_SHA and sha(source/"ReoSoundBanks.h")==HEADER_SHA
    if len(compilers)==2:
        a=json.loads((output/"0/expected.json").read_text());b=json.loads((output/"1/expected.json").read_text())
        result["cross_compiler_exact_equal"]=a==b
    (output/"receipt.json").write_bytes(canonical(result))
    return {"receipt":str(output/"receipt.json"),"cases":frozen["case_count"],
            "actions":frozen["action_count"],"compilers":len(compilers),
            "cross_compiler_exact_equal":result.get("cross_compiler_exact_equal")}


if __name__ == "__main__":
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--checkout",type=Path,required=True)
    parser.add_argument("--baseline-receipt",type=Path,required=True)
    parser.add_argument("--output",type=Path,required=True)
    parser.add_argument("--compiler",type=Path,action="append",default=[])
    parser.add_argument("--freeze-only",action="store_true")
    args=parser.parse_args(); args.output=args.output.resolve()
    allowed=ROOT/"build-native-sjuni"
    if args.output==allowed or not args.output.is_relative_to(allowed): parser.error("Use a private ignored output subdirectory")
    if not args.freeze_only and not args.compiler: parser.error("Existing compiler required")
    args.output.mkdir(parents=True,exist_ok=True)
    print(json.dumps(generate(args.checkout,args.baseline_receipt,args.compiler,args.output,args.freeze_only),indent=2))
