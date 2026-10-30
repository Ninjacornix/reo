"""Stage locally generated guest queue code for controlled execution tests.

Only include directives are removed; guest instructions are not rewritten.
Owned generated sources stay in ignored build output and are never bundled.
"""
from pathlib import Path
import re


def stage(root: Path, output: Path, game: str) -> None:
    file2 = game == 'file2'
    source = root / ('recomp/config/output_file2/output' if file2 else 'recomp/config/output')
    addresses = ([0x1400d0, 0x13ff80, 0x140040, 0x140210, 0x1402d0,
                  0x13fef0, 0x13fe40, 0x13f7f0] if file2 else
                 [0x1b46e0, 0x1b4590, 0x1b4650, 0x1b4820, 0x1b48e0,
                  0x1b4500, 0x1b4450, 0x1b3e00])
    texts = []
    functions = {}
    for address in addresses:
        path = next(source.glob(f'*_0x{address:x}.cpp'))
        text = path.read_text()
        name = re.search(r'void (\w+)\(uint8_t\* rdram', text)[1]
        functions[address] = name
        texts.append(re.sub(r'^#include .*$', '', text, flags=re.M))
    combined = '\n'.join(texts)
    calls = set(re.findall(r'\b((?:sub_|func_)\w+_0x[0-9a-f]+)\(rdram, ctx, runtime\)', combined))
    declarations = '\n'.join(f'void {name}(uint8_t*,R5900Context*,PS2Runtime*);'
                             for name in calls | set(functions.values()))
    stubs = []
    for name in sorted(calls - set(functions.values())):
        address = int(re.search(r'_0x([0-9a-f]+)$', name)[1], 16)
        body = ''
        if address == 0x10afc0:
            body = 'std::strcpy((char*)ram+GPR_U32(c,4),(char*)ram+GPR_U32(c,5));SET_GPR_U32(c,2,GPR_U32(c,4));'
        elif address == 0x10ae78:
            body = 'SET_GPR_S32(c,2,std::strcmp((char*)ram+GPR_U32(c,4),(char*)ram+GPR_U32(c,5)));'
        elif address == (0x13faf0 if file2 else 0x1b4100):
            body = '++draws;'
        else:
            body = 'SET_GPR_U32(c,2,0);'
        stubs.append(f'void {name}(uint8_t* ram,R5900Context* c,PS2Runtime*) {{ (void)ram;{body}c->pc=GPR_U32(c,31); }}')
    registration_text = (source / 'register_functions.cpp').read_text()
    registrations = []
    for pc, name in re.findall(r'runtime.registerFunction\(0x([0-9a-f]+), (\w+)\);', registration_text):
        if name in functions.values():
            registrations.append(f'runtime.registerFunction(0x{pc},{name});')
    for name in calls - set(functions.values()):
        address = int(re.search(r'_0x([0-9a-f]+)$', name)[1], 16)
        registrations.append(f'runtime.registerFunction(0x{address:x},{name});')
    update = 0x13f7f0 if file2 else 0x1b3e00
    draw_loop = 0x13fef0 if file2 else 0x1b4500
    draw_flag = 0x300956 if file2 else 0x3243d6
    update_flag = 0x30096b if file2 else 0x3243eb
    test = r'''
template<class Publish> void runOwnedQueueChecks(PS2Runtime& runtime,std::vector<uint8_t>& ram,R5900Context& ctx,Publish publish) {
    using namespace reo::subtitles;
    runtime.functions.clear();ram.assign(PS2_RAM_SIZE,0);
    REGISTRATIONS
    install(runtime);
    ram[DRAW_FLAG]=1;ram[UPDATE_FLAG]=1;
    auto call=[&](uint32_t pc) {
        ctx.pc=pc;runtime.lookupFunction(pc)(ram.data(),&ctx,&runtime);
        unsigned resumes=0;
        while(ctx.pc!=0xabcdef && resumes++<10000) runtime.lookupFunction(ctx.pc)(ram.data(),&ctx,&runtime);
        check(ctx.pc==0xabcdef,"Owned queue guest execution returns normally");
    };
    auto submit=[&](bool speech,bool typed,int y,bool preempt=false) {
        ctx={};SET_GPR_U32(&ctx,29,0x10000);
        const uint32_t caller=speech?(typed?typedReturns[0]:spokenReturns[0]):0x123456;
        const uint32_t target=typed?custom:front;
        store<uint32_t>(ram.data(),caller-8,0x0c000000u|(target>>2));
        SET_GPR_U32(&ctx,31,caller);
        std::strcpy((char*)ram.data()+0x20000,typed?"Spoken NPC":"Spoken actor");
        if(typed) { SET_GPR_U32(&ctx,4,100);SET_GPR_U32(&ctx,5,y);SET_GPR_U32(&ctx,6,3);SET_GPR_U32(&ctx,7,20);SET_GPR_U32(&ctx,8,0x20000);SET_GPR_U32(&ctx,9,128); }
        else { SET_GPR_U32(&ctx,4,speech?6:0);SET_GPR_U32(&ctx,5,80);SET_GPR_U32(&ctx,6,y);SET_GPR_U32(&ctx,7,3);SET_GPR_U32(&ctx,8,20);SET_GPR_U32(&ctx,9,0x20000); }
        runtime.preempt=preempt;
        ctx.pc=target;runtime.lookupFunction(target)(ram.data(),&ctx,&runtime);
        unsigned resumes=0;
        while(ctx.pc!=caller && resumes++<10000) runtime.lookupFunction(ctx.pc)(ram.data(),&ctx,&runtime);
        if(preempt)check(resumes>0,"Actual guest queue yields and resumes through registered continuations");
        check(ctx.pc==caller,"Owned enqueue returns without changing dialogue control flow");
    };
    submit(true,false,380);submit(true,true,320,true);submit(false,false,200);
    check(spokenSlots[0]&&spokenSlots[1]&&!spokenSlots[2],"Actual guest frames classify both spoken producers and preserve prompts");
    check(load<uint16_t>(ram.data(),slots)==1 && load<uint16_t>(ram.data(),slots+6)==3,"Actual allocator retains active and TTL fields");
    auto render=[&] { ctx={};SET_GPR_U32(&ctx,29,0x10000);SET_GPR_U32(&ctx,31,0xabcdef);call(DRAW_LOOP); };
    publish(true);unsigned before=draws;render();check(draws==before+3,"Actual draw loop submits two captions and prompt by default");
    publish(false);before=draws;const auto old=ram;render();
    check(draws==before+1,"Actual draw loop suppresses captions but draws prompt");
    check(std::memcmp(old.data()+slots,ram.data()+slots,32*0x8c)==0,"Actual disabled draw preserves queued text lifetime and alpha");
    ctx={};SET_GPR_U32(&ctx,29,0x10000);SET_GPR_U32(&ctx,31,0xabcdef);call(UPDATE);
    check(load<uint16_t>(ram.data(),slots+6)==2,"Actual guest TTL still advances with subtitles disabled");
    publish(true);before=draws;render();check(draws==before+3,"Actual pending captions reappear immediately");
    for(unsigned i=0;i<2;++i) { ctx={};SET_GPR_U32(&ctx,29,0x10000);SET_GPR_U32(&ctx,31,0xabcdef);call(UPDATE); }
    check(load<uint16_t>(ram.data(),slots)==0,"Actual captions expire normally");
    submit(false,false,200);publish(false);before=draws;render();
    check(!spokenSlots[0]&&draws==before+1,"Actual reused caption slot renders interaction text with subtitles off");
}
'''
    test = (test.replace('REGISTRATIONS', '\n'.join(registrations))
            .replace('DRAW_FLAG', hex(draw_flag)).replace('UPDATE_FLAG', hex(update_flag))
            .replace('DRAW_LOOP', hex(draw_loop)).replace('UPDATE', hex(update)))
    output.mkdir(parents=True, exist_ok=True)
    (output / 'owned_queue.inc').write_text(declarations + '\n' + combined + '\n' + '\n'.join(stubs) + test)
