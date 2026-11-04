"""Image-independent whole-program basic-block source generator.

Inputs must be owned local code/state captures or bounded collection events.
Generated arrays and game factory output stay local/ignored; generic sources
contain no owned images, identity hashes, entry keys, or game-specific paths.
"""
import argparse
import hashlib
import importlib.util
import json
from pathlib import Path
import re
spec=importlib.util.spec_from_file_location('vu_whole_decode',Path(__file__).parent/'decode.py')
base=importlib.util.module_from_spec(spec);spec.loader.exec_module(base)

def bytes_array(name,code):
    return 'static constexpr uint8_t '+name+'[]={\n'+''.join('  '+','.join(f'0x{x:02x}' for x in code[i:i+32])+',\n' for i in range(0,len(code),32))+'};\n'

COMMON=r'''
struct BasicEntry;
using PlainFn=const BasicEntry* (*)(reo_vu_whole_aot::Invocation&);
struct BasicEntry {
    void (*math)(reo_vu_whole_aot::Invocation&);
    PlainFn plain;uint32_t pairs;bool branch,e;
};
VU_BLOCK_INLINE void normalizeZero(VU1State& s) {
    s.vf[0][0]=0;s.vf[0][1]=0;s.vf[0][2]=0;s.vf[0][3]=1;s.vi[0]=0;
}
VU_BLOCK_NOINLINE void upperCold(reo_vu_whole_aot::Invocation& in,uint32_t pc,uint32_t hi) {
    in.state.pc=pc;in.genericUpper(in.interpreter,hi);
}
VU_BLOCK_NOINLINE void lowerCold(reo_vu_whole_aot::Invocation& in,uint32_t pc,uint32_t lo,uint32_t hi) {
    in.state.pc=pc;in.genericLower(in.interpreter,lo,in.data,in.dataBytes,in.gs,in.memory,hi);
}
template<uint32_t lo,uint32_t hi> VU_BLOCK_INLINE void knownMath(reo_vu_whole_aot::Invocation& in,uint32_t pc) {
    auto& s=in.state;
    if constexpr((hi&0x7ffu)!=0x2ffu) {
        if constexpr((hi&63u)==0x1cu) {if(!vuWholeFiniteMulQ<hi>(s))upperCold(in,pc,hi);}
        else if(vuBlockUpperSafe<hi>(s))vuBlockUpper<hi>(s);
        else upperCold(in,pc,hi);
    }
    if constexpr(hi&0x80000000u) {constexpr uint32_t literal=lo;std::memcpy(&s.i,&literal,4);}
    else if constexpr(lo!=0x8000033cu) {
        if constexpr(((lo>>25)&127u)==0x40u&&(lo&2047u)==0x6fcu)lowerCold(in,pc,lo,hi);
        else if(vuBlockLowerSafe<lo,hi>(s))vuBlockLower<lo>(s,in.data,16384u,in.gs,in.memory);
        else lowerCold(in,pc,lo,hi);
    }
}
template<uint32_t lo,uint32_t hi> VU_BLOCK_NOINLINE void coldKnownMath(reo_vu_whole_aot::Invocation& in) {
    knownMath<lo,hi>(in,in.state.pc);
}
struct BasicStats {uint64_t launches=0,blocks=0,plainPairs=0,coldPairs=0;};
#ifdef REO_VU_BB_STATS
thread_local BasicStats basicStats;
#endif
reo_vu_whole_aot::Result runBasic(reo_vu_whole_aot::Invocation& in,const BasicEntry* entries) {
    auto& s=in.state;uint32_t executed=0,target=0;bool pending=false,normalized=false,ended=false,bounds=false;
    uint64_t blocks=0,plainPairs=0,coldPairs=0;
    const BasicEntry* entry=nullptr;
    while(executed<in.maxPairs&&!ended) {
        if(s.pc>=16384u||(s.pc&7u)){bounds=true;break;}
        if(!entry)entry=entries+s.pc/8u;
        if(!entry->math)throw std::logic_error("VU whole basic-block CFG omitted a valid aligned target");
        // One budget/context admission for an entire straight-line suffix.
        // First pair must consume incoming VF0/VI0 before zero normalization.
        if(normalized&&!pending&&!s.ebit&&entry->plain&&entry->pairs<=in.maxPairs-executed) {
            const uint32_t pairs=entry->pairs;
            entry=entry->plain(in);executed+=pairs;
#ifdef REO_VU_BB_STATS
            ++blocks;plainPairs+=pairs;
#endif
            continue;
        }
        const uint32_t instructionPc=s.pc;entry->math(in);
        const bool newBranch=entry->branch&&(s.pc&0x80000000u)!=0;
        const uint32_t newTarget=newBranch?s.pc&0x3fffu:0;
        normalizeZero(s);normalized=true;
        s.pc=pending?target:(instructionPc+8u)&0x3fffu;
        pending=newBranch;target=newTarget;++executed;
#ifdef REO_VU_BB_STATS
        ++coldPairs;
#endif
        if(s.ebit){if(pending)s.pc=target;ended=true;break;}
        if(entry->e)s.ebit=true;
        entry=nullptr;
    }
#ifdef REO_VU_BB_STATS
    ++basicStats.launches;basicStats.blocks+=blocks;basicStats.plainPairs+=plainPairs;basicStats.coldPairs+=coldPairs;
#endif
    return {executed,ended,bounds};
}
'''

def upper_writes_zero(hi):
    if (hi&0x7ff)==0x2ff or not ((hi>>21)&15):return False
    op=hi&63
    if op<=0x2f:return ((hi>>6)&31)==0
    if op>=0x3c:
        row=(hi>>6)&31;col=hi&3
        if row in (4,5) or (row==7 and col==1):return ((hi>>16)&31)==0
    return False

def lower_writes_zero(lo,hi):
    if hi&0x80000000 or not ((lo>>21)&15):return False
    op=(lo>>25)&127;target=(lo>>16)&31
    if op==0:return target==0
    if op==0x40 and (lo&2047) in (0x33c,0x33d,0x3fd,0x37c,0x37e,0x67c):return target==0
    return False

def regions(code,starts,pcs):
    heads=set(starts);fences=set()
    for pc in pcs:
        ins=base.decode(code,pc)
        if ins['branch'] or ins['e'] or ins['xgkick']:
            fences.add(pc);heads.update((pc,(pc+8)%16384,(pc+16)%16384))
        if ins['branch'] and not ins['indirect']:heads.add(ins['target'])
    result=[];current=[]
    for pc in pcs:
        if current and (pc!=current[-1]+8 or pc in heads or pc in fences or len(current)==64):
            result.append(current);current=[]
        if pc not in fences:current.append(pc)
    if current:result.append(current)
    return result,sorted(heads),sorted(fences)

def emit(number,code,starts,pcs):
    groups,heads,fences=regions(code,starts,pcs)
    out=bytes_array(f'code{number}',code)
    out+=f'static constexpr uint32_t starts{number}[]={{'+','.join(map(str,starts))+'};\n'
    out+=f'extern const BasicEntry basicEntries{number}[2048];\n'
    fast={}
    for group,sites in enumerate(groups):
        name=f'plain{number}_{group}';next_pc=(sites[-1]+8)%16384
        out+=f'VU_BLOCK_NOINLINE const BasicEntry* {name}(reo_vu_whole_aot::Invocation& in) {{\n    auto& s=in.state;\n    switch(s.pc){{\n'
        out+=''.join(f'    case {pc}u:goto pair_{pc:x};\n' for pc in sites)
        out+='    default:throw std::logic_error("VU plain suffix entry violated descriptor contract");\n    }\n'
        for index,pc in enumerate(sites):
            ins=base.decode(code,pc);lo,hi=ins['lower'],ins['upper']
            out+=f'pair_{pc:x}:\n    knownMath<0x{lo:08x}u,0x{hi:08x}u>(in,{pc}u);\n'
            if upper_writes_zero(hi) or lower_writes_zero(lo,hi):out+='    normalizeZero(s); // Proven VF0 writer; VI0 remains zero.\n'
            fast[pc]=(name,len(sites)-index)
        out+=f'    s.pc={next_pc}u;return basicEntries{number}+{next_pc//8}u;\n}}\n'
    out+=f'const BasicEntry basicEntries{number}[2048]={{\n'
    reachable=set(pcs)
    for pc in range(0,16384,8):
        if pc not in reachable:out+='    {},\n';continue
        ins=base.decode(code,pc);lo,hi=ins['lower'],ins['upper'];fn,pairs=fast.get(pc,('nullptr',0))
        out+=f'    {{coldKnownMath<0x{lo:08x}u,0x{hi:08x}u>,{fn},{pairs}u,{str(ins["branch"]).lower()},{str(ins["e"]).lower()}}},\n'
    out+=f'}};\nreo_vu_whole_aot::Result execute{number}(reo_vu_whole_aot::Invocation& in){{return runBasic(in,basicEntries{number});}}\n'
    return out,dict(regions=groups,heads=heads,fences=fences,plain_sites=len(fast),vf0_writers=[pc for pc in fast if upper_writes_zero(base.decode(code,pc)['upper']) or lower_writes_zero(base.decode(code,pc)['lower'],base.decode(code,pc)['upper'])])

def main():
    parser=argparse.ArgumentParser()
    parser.add_argument('--capture-dir',type=Path,action='append',default=[])
    parser.add_argument('--collection',type=Path)
    parser.add_argument('--out',type=Path,required=True)
    parser.add_argument('--factory-name',default='reo_vu_whole_registered_generated')
    args=parser.parse_args()
    if not re.fullmatch(r'[A-Za-z_][A-Za-z_0-9]*',args.factory_name):raise ValueError('Factory must be a C++ identifier')
    if args.out.exists() and any(args.out.iterdir()):raise ValueError('Fresh output required')
    programs=base.load_inputs(args)
    output='#include "'+args.factory_name+'.h"\n#include "vu_whole_program.h"\n#include "vu_math_helpers.h"\nnamespace {\n'+COMMON
    descriptors=[];default_descriptors=[];ir=[]
    for n,(digest,item) in enumerate(sorted(programs.items()),1):
        starts=sorted(item['starts']);pcs,cfg=base.reachable(item['code'],starts)
        body,lowering=emit(n,item['code'],starts,pcs);output+=body
        descriptors.append(f'{{code{n},16384,16384,starts{n},{len(starts)},execute{n}}}')
        default_starts=sorted(item['default_starts'])
        if default_starts:
            default_entries=f'starts{n}'
            if default_starts!=starts:
                default_entries=f'defaultStarts{n}'
                output+=f'static constexpr uint32_t {default_entries}[]={{'+','.join(map(str,default_starts))+'};\n'
            default_descriptors.append(f'{{code{n},16384,16384,{default_entries},{len(default_starts)},execute{n}}}')
        ir.append(dict(sha256=digest,entry_pcs=starts,sites=len(pcs),cfg=cfg,lowering=lowering,
            enabled_by_default=item['enabled_by_default'],
            default_entry_pcs=default_starts,
            provenance=sorted(item['provenance']),instructions=[base.decode(item['code'],pc) for pc in pcs]))
    output+='const reo_vu_whole_aot::Program programs[]={'+','.join(descriptors)+'};\n'
    output+='const reo_vu_whole_aot::Table table{programs,'+str(len(programs))+'};\n'
    if default_descriptors:
        output+='const reo_vu_whole_aot::Program defaultPrograms[]={'+','.join(default_descriptors)+'};\n'
        output+='const reo_vu_whole_aot::Table defaultTable{defaultPrograms,'+str(len(default_descriptors))+'};\n'
    else:output+='const reo_vu_whole_aot::Table defaultTable{nullptr,0};\n'
    output+='}\nnamespace '+args.factory_name+' {\nconst vu_whole_program::Table* programTable() noexcept{return &table;}\n'
    output+='const vu_whole_program::Table* defaultProgramTable() noexcept{return &defaultTable;}\n}\n'
    output=output.replace('reo_vu_whole_aot::','vu_whole_program::')
    header='#pragma once\n#define REO_VU_HAS_DEFAULT_PROGRAM_TABLE 1\nnamespace vu_whole_program {struct Table;}\nnamespace '+args.factory_name+' {\nconst vu_whole_program::Table* programTable() noexcept;\nconst vu_whole_program::Table* defaultProgramTable() noexcept;\n}\n'
    args.out.mkdir(parents=True,exist_ok=True)
    (args.out/(args.factory_name+'.cpp')).write_text(output,encoding='utf8',newline='\n')
    (args.out/(args.factory_name+'.h')).write_text(header,encoding='utf8',newline='\n')
    (args.out/'whole-program-ir.json').write_text(json.dumps(dict(semantic_contract='baseline_interpreter_byte_semantics_not_hardware_pipeline',programs=ir),indent=2)+'\n')
    manifest=dict(phase='complete_CFG_bounded_plain_basic_blocks_local_owned_output',programs=len(programs),default_programs=len(default_descriptors),
        native_regions=sum(len(p['lowering']['regions']) for p in ir),plain_sites=sum(p['lowering']['plain_sites'] for p in ir),
        source_sha256=hashlib.sha256(output.encode()).hexdigest(),generator_sha256=hashlib.sha256(Path(__file__).read_bytes()).hexdigest(),
        helper_sha256=hashlib.sha256((Path(__file__).parent/'vu_math_helpers.h').read_bytes()).hexdigest(),
        built_or_executed=False,hardware_correctness='unproved; baseline byte semantics',performance='unmeasured')
    (args.out/'manifest.json').write_text(json.dumps(manifest,indent=2)+'\n');print(json.dumps(manifest,indent=2))

if __name__=='__main__':main()
