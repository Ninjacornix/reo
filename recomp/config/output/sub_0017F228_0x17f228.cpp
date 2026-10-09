#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017F228
// Address: 0x17f228 - 0x17f28c
void sub_0017F228_0x17f228(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017F228_0x17f228");
#endif

    switch (ctx->pc) {
        case 0x17f244u: goto label_17f244;
        default: break;
    }

    ctx->pc = 0x17f228u;

    // 0x17f228: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x17f228u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x17f22c: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x17f22cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x17f230: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17f230u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17f234: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x17f234u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17f238: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x17f238u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x17f23c: 0xc047598  jal         func_11D660
    ctx->pc = 0x17F23Cu;
    SET_GPR_U32(ctx, 31, 0x17F244u);
    ctx->pc = 0x17F240u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17F23Cu;
            // 0x17f240: 0xa0802d  daddu       $s0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17F244u; }
        if (ctx->pc != 0x17F244u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17F244u; }
        if (ctx->pc != 0x17F244u) { return; }
    }
    ctx->pc = 0x17F244u;
label_17f244:
    // 0x17f244: 0x7a060000  lq          $a2, 0x0($s0)
    ctx->pc = 0x17f244u;
    SET_GPR_VEC(ctx, 6, READ128(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x17f248: 0x7a070010  lq          $a3, 0x10($s0)
    ctx->pc = 0x17f248u;
    SET_GPR_VEC(ctx, 7, READ128(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x17f24c: 0x7a080020  lq          $t0, 0x20($s0)
    ctx->pc = 0x17f24cu;
    SET_GPR_VEC(ctx, 8, READ128(ADD32(GPR_U32(ctx, 16), 32)));
    // 0x17f250: 0x7a090030  lq          $t1, 0x30($s0)
    ctx->pc = 0x17f250u;
    SET_GPR_VEC(ctx, 9, READ128(ADD32(GPR_U32(ctx, 16), 48)));
    // 0x17f254: 0x7e260000  sq          $a2, 0x0($s1)
    ctx->pc = 0x17f254u;
    WRITE128(ADD32(GPR_U32(ctx, 17), 0), GPR_VEC(ctx, 6));
    // 0x17f258: 0x7e270010  sq          $a3, 0x10($s1)
    ctx->pc = 0x17f258u;
    WRITE128(ADD32(GPR_U32(ctx, 17), 16), GPR_VEC(ctx, 7));
    // 0x17f25c: 0x7e280020  sq          $t0, 0x20($s1)
    ctx->pc = 0x17f25cu;
    WRITE128(ADD32(GPR_U32(ctx, 17), 32), GPR_VEC(ctx, 8));
    // 0x17f260: 0x7e290030  sq          $t1, 0x30($s1)
    ctx->pc = 0x17f260u;
    WRITE128(ADD32(GPR_U32(ctx, 17), 48), GPR_VEC(ctx, 9));
    // 0x17f264: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x17F264u;
    {
        const bool branch_taken_0x17f264 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x17F268u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17F264u;
            // 0x17f268: 0xdfbf0020  ld          $ra, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17f264) {
            ctx->pc = 0x17F27Cu;
            goto label_17f27c;
        }
    }
    ctx->pc = 0x17F26Cu;
    // 0x17f26c: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x17f26cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17f270: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17f270u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17f274: 0x80475ae  j           func_11D6B8
    ctx->pc = 0x17F274u;
    ctx->pc = 0x17F278u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17F274u;
            // 0x17f278: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17F27Cu;
label_17f27c:
    // 0x17f27c: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x17f27cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17f280: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17f280u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17f284: 0x3e00008  jr          $ra
    ctx->pc = 0x17F284u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17F288u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17F284u;
            // 0x17f288: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17F244u: goto label_17f244;
            case 0x17F27Cu: goto label_17f27c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17F28Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
