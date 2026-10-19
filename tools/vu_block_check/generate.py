"""Generate an isolated constant-pair candidate from owned captures and live source.

Never builds or executes guest code. Generated game bytes remain in build-ninja.
Handler bodies are copied mechanically, preserving the current arithmetic.
"""
import argparse,hashlib,json,pathlib,re,struct
ROOT=pathlib.Path(__file__).resolve().parents[2]
SOURCE=ROOT/'third_party/ps2recomp/ps2xRuntime/src/lib/ps2_vu1.cpp'
OUT=ROOT/'build-ninja/m2-vu-block-proposal'
PROGRAMS=[('weighted',ROOT/'build-ninja/smoke/20261011-185621-m2-weighted-room-baseline/vu1-kevin',
 '2ea02b3628231f113edc3fe580f80c1d6ed45c98a7c98f9f83005665f8ad32ce',0x348,0x598),
 ('static',ROOT/'build-ninja/smoke/20261011-181645-m2-depth-wake-original-room-check/vu1-room',
 '5273fa3e9893df4b3833a22b1d7deec2f99a2d2af0c10f2aa0ff5b43d3b2fc25',0x260,0x3e8)]

def body(source,name):
    start=source.index(name);start=source.index('{',start)
    # Mask strings/comments without changing offsets, then balance braces.
    masked=re.sub(r'//[^\n]*|/\*.*?\*/|"(?:\\.|[^"\\])*"|\'(?:\\.|[^\'\\])*\'',
                  lambda m:' '*len(m[0]),source,flags=re.S)
    depth=0
    for i in range(start,len(source)):
        depth+=(masked[i]=='{')-(masked[i]=='}')
        if not depth:return source[start:i+1]
    raise ValueError('Unclosed function '+name)

def array(name,data):
    return 'static constexpr unsigned char '+name+'[] = {\n'+''.join(
       '  '+','.join('0x%02x'%x for x in data[i:i+24])+',\n' for i in range(0,len(data),24))+'};\n'

def main():
    ap=argparse.ArgumentParser();ap.add_argument('--refresh',action='store_true')
    ap.add_argument('--source',type=pathlib.Path,default=SOURCE)
    ap.add_argument('--out',type=pathlib.Path,default=OUT)
    args=ap.parse_args();out=args.out.resolve();source=args.source.resolve()
    out.mkdir(parents=True,exist_ok=True)
    baseline=out/'ps2_vu1.baseline.cpp'
    if baseline.exists() and not args.refresh:raise SystemExit('Frozen baseline exists; use --refresh deliberately.')
    raw=source.read_bytes();src=raw.decode('utf8').replace('\r\n','\n').replace('\r','\n')
    upper=body(src,'void VU1Interpreter::execUpper(')
    lower=body(src,'void VU1Interpreter::execLower(')
    if lower.count('(void)upperInstr;')!=1:raise ValueError('Lower upperInstr contract changed')
    lower=lower.replace('(void)upperInstr;','')
    if 'upperInstr' in lower:raise ValueError('Lower now consumes paired upper; generator must be updated')
    for name in ('execUpper(','execLower('):
        if name in upper or name in lower:raise ValueError('Nested handler call requires review')
    def helper_rewrite(s):
        s=s.replace('applyDestAcc(', 'vuBlockDest(m_state.acc,')
        s=s.replace('applyDest(', 'vuBlockDest(').replace('broadcast(', 'vuBlockBroadcast(')
        # Copy the frozen decoder expressions, making template constants
        # explicit without depending on the optimizer inlining tiny helpers
        # after the much larger forced-inline handler expansion.
        for name in ('DEST','FT','FS','FD','LIT','LIS','LID','IMM11'):
            expression=re.search(r'static inline [^\n]*\b'+name+r'\(uint32_t i\)\s*\{\s*return ([^;]+);\s*\}',src)
            if not expression:raise ValueError('Unknown frozen decode helper '+name)
            value=re.sub(r'\bi\b','instr',expression[1])
            s=s.replace(name+'(instr)','('+value+')')
        lines=[]
        for line in s.splitlines():
            if 'instr' in line and ';' in line and re.match(r'\s*(?:const )?(?:uint8_t|uint16_t|int16_t|unsigned) \w+\s*=',line):
                line=re.sub(r'^(\s*)(?:const )?',r'\1constexpr ',line,count=1)
            lines.append(line)
        return '\n'.join(lines)
    helper='''
namespace {
#if defined(_MSC_VER)
#define VU_BLOCK_INLINE __forceinline
#define VU_BLOCK_NOINLINE __declspec(noinline)
#else
#define VU_BLOCK_INLINE inline __attribute__((always_inline))
#define VU_BLOCK_NOINLINE __attribute__((noinline))
#endif
thread_local bool vuBlockTracking=false;
thread_local uint64_t vuBlockHits=0;
thread_local uint64_t vuBlockFallbacks=0;
VU_BLOCK_INLINE void vuBlockDest(float* dst,const float* result,uint8_t dest)
'''+body(src,'void VU1Interpreter::applyDest(')+'''
VU_BLOCK_INLINE float vuBlockBroadcast(const float* vf,uint8_t bc)
'''+body(src,'float VU1Interpreter::broadcast(')+'''
template<uint32_t instr> VU_BLOCK_INLINE void vuBlockUpper(VU1State& m_state)
'''+helper_rewrite(upper)+'''
template<uint32_t instr> VU_BLOCK_INLINE void vuBlockLower(VU1State& m_state,
        uint8_t* vuData,uint32_t dataSize,GS& gs,PS2Memory* memory)
'''+helper_rewrite(lower)+'''
template<uint32_t lo,uint32_t hi,uint32_t pc>
VU_BLOCK_INLINE void vuBlockPair(VU1State& s,uint8_t* data,uint32_t size,GS& gs,
        PS2Memory* memory,bool& pending,uint32_t& target)
{
    // Exactly the live interpreter pair order and invariant writes.
    if constexpr((hi&0x7FFu)!=0x2FFu) vuBlockUpper<hi>(s);
    if constexpr(hi&0x80000000u) { constexpr uint32_t bits=lo; std::memcpy(&s.i,&bits,4); }
    else if constexpr(lo!=0x8000033Cu) vuBlockLower<lo>(s,data,size,gs,memory);
    const bool newBranch=(s.pc&0x80000000u)!=0;
    const uint32_t newTarget=s.pc&0x3FFFu;
    s.vf[0][0]=0;s.vf[0][1]=0;s.vf[0][2]=0;s.vf[0][3]=1;s.vi[0]=0;
    s.pc=pending?target:pc+8; if(s.pc>=16384u) s.pc=0;
    pending=newBranch;target=newTarget;
    // Generator proves no E pair and requires !ebit on entry.
}
bool vuBlockDisjoint(const uint8_t* a,size_t an,const uint8_t* b,size_t bn) {
    const uintptr_t x=reinterpret_cast<uintptr_t>(a),y=reinterpret_cast<uintptr_t>(b);
    if(!a||!b||x>UINTPTR_MAX-an||y>UINTPTR_MAX-bn) return false;
    return x+an<=y||y+bn<=x;
}
'''
    helper+=(ROOT/'tools/vu_block_check/pair_guard.inc').read_text().replace('\r\n','\n')+'\n'
    info=[]
    for index,(name,folder,digest,start,end) in enumerate(PROGRAMS,1):
        paths=sorted(folder.glob('*.code.bin'))
        if not paths:raise ValueError('No owned captures: '+str(folder))
        code=paths[0].read_bytes()
        if len(code)!=16384 or hashlib.sha256(code).hexdigest()!=digest:raise ValueError('Code identity changed')
        pairs=[]
        for pc in range(start,end+1,8):
            lo,hi=struct.unpack_from('<II',code,pc);op=(lo>>25)&127;i=bool(hi&0x80000000)
            branch=not i and op in (0x20,0x21,0x24,0x25,0x28,0x29,0x2c,0x2d,0x2e,0x2f)
            kick=not i and op==0x40 and lo&2047==0x6fc
            if hi&0x40000000 or kick or (branch and pc!=end-8):raise ValueError('Unproven control cut '+hex(pc))
            if pc==end-8 and (not branch or op!=0x28):raise ValueError('Expected terminal IBEQ')
            pairs.append((pc,lo,hi))
        helper+=array('vuBlockImage'+str(index),code)
        helper+='VU_BLOCK_NOINLINE unsigned vuBlockRun'+str(index)+'(VU1State& s,uint8_t* data,uint32_t size,GS& gs,PS2Memory* memory,bool& pending,uint32_t& target) {\n'
        for completed,(pc,lo,hi) in enumerate(pairs):
            helper+='  if(!vuBlockPairSafe<0x%08Xu,0x%08Xu>(s)) {if(vuBlockTracking) ++vuBlockFallbacks;return %du;}\n'%(lo,hi,completed)
            helper+='  vuBlockPair<0x%08Xu,0x%08Xu,0x%Xu>(s,data,size,gs,memory,pending,target);\n'%(lo,hi,pc)
        helper+='  return %du;\n}\n'%len(pairs)
        info.append({'program':name,'code_sha256':digest,'input':str(paths[0].relative_to(ROOT)),
                     'start':start,'end':end,'pairs':len(pairs),'image':index})
    helper+='''
unsigned vuBlockProgram(uint8_t* code,uint32_t codeSize,uint8_t* data,uint32_t dataSize) {
    if(codeSize!=16384u||dataSize!=16384u||!vuBlockDisjoint(code,codeSize,data,dataSize)) return 0;
    if(!std::memcmp(code,vuBlockImage1,16384)) return 1;
    if(!std::memcmp(code,vuBlockImage2,16384)) return 2;
    return 0;
}
}
void ps2VuBlockTestTracking(bool enabled) {vuBlockTracking=enabled;vuBlockHits=0;vuBlockFallbacks=0;}
uint64_t ps2VuBlockTestHits() {return vuBlockHits;}
uint64_t ps2VuBlockTestFallbacks() {return vuBlockFallbacks;}
bool ps2VuBlockTestCandidate() {return true;}
'''
    # No ABI/header/member changes: inject only the isolated copied TU.
    needle='void VU1Interpreter::run('
    candidate=src.replace(needle,helper+'\n'+needle,1)
    setup='    const unsigned compiledProgram = capture.active ? 0u : vuBlockProgram(vuCode,codeSize,vuData,dataSize);\n'
    needle='    bool branchPending = false;'
    if candidate.count(needle)!=1:raise ValueError('Run scheduler signature changed')
    candidate=candidate.replace(needle,setup+needle,1)
    gate='''        // Complete blocks only. Incoming delay/E and short budgets use the unchanged loop.
        if(compiledProgram && !branchPending && !m_state.ebit) {
'''
    for p in info:
        n=p['image'];start=p['start'];count=p['pairs']
        gate+='''            if(compiledProgram==%du && m_state.pc==0x%Xu && maxCycles-cycle>=%du &&
                    !std::memcmp(vuCode+0x%Xu,vuBlockImage%d+0x%Xu,%du)) {
                const unsigned completed=vuBlockRun%d(m_state,vuData,dataSize,gs,memory,branchPending,branchTarget);
                if(completed) {
                    if(vuBlockTracking) ++vuBlockHits;
                    cycle+=completed-1u; continue;
                }
            }
'''%(n,start,count,start,n,start,count*8,n)
    gate+='        }\n'
    needle='        uint32_t lower, upper;'
    if candidate.count(needle)!=1:raise ValueError('Run pair-fetch signature changed')
    candidate=candidate.replace(needle,gate+needle,1)
    baseline.write_bytes((src+'\nvoid ps2VuBlockTestTracking(bool) {}\nuint64_t ps2VuBlockTestHits() {return 0;}\nuint64_t ps2VuBlockTestFallbacks() {return 0;}\nbool ps2VuBlockTestCandidate() {return false;}\n').encode('utf8'))
    (out/'ps2_vu1.cpp').write_bytes(candidate.encode('utf8'))
    manifest={'live_source':str(source.relative_to(ROOT)),'live_source_sha256':hashlib.sha256(raw).hexdigest(),
              'baseline_sha256':hashlib.sha256(baseline.read_bytes()).hexdigest(),
              'candidate_sha256':hashlib.sha256((out/'ps2_vu1.cpp').read_bytes()).hexdigest(),
              'blocks':info,'generated_game_bytes':'ignored build-ninja only','compiled_or_executed':False}
    (out/'candidate-manifest.json').write_bytes((json.dumps(manifest,indent=2)+'\n').encode('utf8'))
    print(json.dumps(manifest,indent=2))

if __name__=='__main__':main()
