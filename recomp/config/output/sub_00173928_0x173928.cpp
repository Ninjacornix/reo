#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00173928
// Address: 0x173928 - 0x173990
void sub_00173928_0x173928(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00173928_0x173928");
#endif

    switch (ctx->pc) {
        case 0x17395cu: goto label_17395c;
        case 0x173974u: goto label_173974;
        default: break;
    }

    ctx->pc = 0x173928u;

    // 0x173928: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x173928u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x17392c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17392cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x173930: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x173930u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x173934: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x173934u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x173938: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x173938u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x17393c: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x17393cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x173940: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x173940u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x173944: 0x2630094c  addiu       $s0, $s1, 0x94C
    ctx->pc = 0x173944u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 17), 2380));
    // 0x173948: 0x8e020004  lw          $v0, 0x4($s0)
    ctx->pc = 0x173948u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x17394c: 0x451021  addu        $v0, $v0, $a1
    ctx->pc = 0x17394cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x173950: 0x24050025  addiu       $a1, $zero, 0x25
    ctx->pc = 0x173950u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 37));
    // 0x173954: 0xc05d58a  jal         func_175628
    ctx->pc = 0x173954u;
    SET_GPR_U32(ctx, 31, 0x17395Cu);
    ctx->pc = 0x173958u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x173954u;
            // 0x173958: 0xae020004  sw          $v0, 0x4($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175628u;
    if (runtime->hasFunction(0x175628u)) {
        auto targetFn = runtime->lookupFunction(0x175628u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17395Cu; }
        if (ctx->pc != 0x17395Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175628_0x175628(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17395Cu; }
        if (ctx->pc != 0x17395Cu) { return; }
    }
    ctx->pc = 0x17395Cu;
label_17395c:
    // 0x17395c: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x17395cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x173960: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x173960u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x173964: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x173964u;
    {
        const bool branch_taken_0x173964 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x173968u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x173964u;
            // 0x173968: 0x200302d  daddu       $a2, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x173964) {
            ctx->pc = 0x173974u;
            goto label_173974;
        }
    }
    ctx->pc = 0x17396Cu;
    // 0x17396c: 0x40f809  jalr        $v0
    ctx->pc = 0x17396Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x173974u);
        if (jumpTarget == 0u) {
            ctx->pc = 0x173974u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17395Cu: goto label_17395c;
            case 0x173974u: goto label_173974;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x173974u; }
            if (ctx->pc != 0x173974u) { return; }
        }
        }
    }
    ctx->pc = 0x173974u;
label_173974:
    // 0x173974: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x173974u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x173978: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x173978u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17397c: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x17397cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x173980: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x173980u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x173984: 0x3e00008  jr          $ra
    ctx->pc = 0x173984u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x173988u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x173984u;
            // 0x173988: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17395Cu: goto label_17395c;
            case 0x173974u: goto label_173974;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17398Cu;
    // 0x17398c: 0x0  nop
    ctx->pc = 0x17398cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
