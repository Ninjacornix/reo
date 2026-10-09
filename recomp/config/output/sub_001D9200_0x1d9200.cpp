#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D9200
// Address: 0x1d9200 - 0x1d9280
void sub_001D9200_0x1d9200(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D9200_0x1d9200");
#endif

    switch (ctx->pc) {
        case 0x1d921cu: goto label_1d921c;
        case 0x1d9244u: goto label_1d9244;
        case 0x1d925cu: goto label_1d925c;
        default: break;
    }

    ctx->pc = 0x1d9200u;

    // 0x1d9200: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1d9200u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1d9204: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1d9204u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1d9208: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1d9208u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1d920c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1d920cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1d9210: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1d9210u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d9214: 0xc075e38  jal         func_1D78E0
    ctx->pc = 0x1D9214u;
    SET_GPR_U32(ctx, 31, 0x1D921Cu);
    ctx->pc = 0x1D9218u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9214u;
            // 0x1d9218: 0xa0802d  daddu       $s0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D78E0u;
    if (runtime->hasFunction(0x1D78E0u)) {
        auto targetFn = runtime->lookupFunction(0x1D78E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D921Cu; }
        if (ctx->pc != 0x1D921Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D78E0_0x1d78e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D921Cu; }
        if (ctx->pc != 0x1D921Cu) { return; }
    }
    ctx->pc = 0x1D921Cu;
label_1d921c:
    // 0x1d921c: 0x3c050034  lui         $a1, 0x34
    ctx->pc = 0x1d921cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)52 << 16));
    // 0x1d9220: 0x24060028  addiu       $a2, $zero, 0x28
    ctx->pc = 0x1d9220u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 40));
    // 0x1d9224: 0x3c070034  lui         $a3, 0x34
    ctx->pc = 0x1d9224u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)52 << 16));
    // 0x1d9228: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d9228u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1d922c: 0x2404003c  addiu       $a0, $zero, 0x3C
    ctx->pc = 0x1d922cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 60));
    // 0x1d9230: 0x24a57280  addiu       $a1, $a1, 0x7280
    ctx->pc = 0x1d9230u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 29312));
    // 0x1d9234: 0x24e76280  addiu       $a3, $a3, 0x6280
    ctx->pc = 0x1d9234u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 25216));
    // 0x1d9238: 0xc0402d  daddu       $t0, $a2, $zero
    ctx->pc = 0x1d9238u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d923c: 0xc075e40  jal         func_1D7900
    ctx->pc = 0x1D923Cu;
    SET_GPR_U32(ctx, 31, 0x1D9244u);
    ctx->pc = 0x1D9240u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D923Cu;
            // 0x1d9240: 0xa431729c  sh          $s1, 0x729C($at) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 1), 29340), (uint16_t)GPR_U32(ctx, 17));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D7900u;
    if (runtime->hasFunction(0x1D7900u)) {
        auto targetFn = runtime->lookupFunction(0x1D7900u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9244u; }
        if (ctx->pc != 0x1D9244u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D7900_0x1d7900(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9244u; }
        if (ctx->pc != 0x1D9244u) { return; }
    }
    ctx->pc = 0x1D9244u;
label_1d9244:
    // 0x1d9244: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d9244u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1d9248: 0x8c2262a0  lw          $v0, 0x62A0($at)
    ctx->pc = 0x1d9248u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 25248)));
    // 0x1d924c: 0xae020000  sw          $v0, 0x0($s0)
    ctx->pc = 0x1d924cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
    // 0x1d9250: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d9250u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1d9254: 0xc075e3c  jal         func_1D78F0
    ctx->pc = 0x1D9254u;
    SET_GPR_U32(ctx, 31, 0x1D925Cu);
    ctx->pc = 0x1D9258u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9254u;
            // 0x1d9258: 0x84306298  lh          $s0, 0x6298($at) (Delay Slot)
        SET_GPR_S32(ctx, 16, (int16_t)READ16(ADD32(GPR_U32(ctx, 1), 25240)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D78F0u;
    if (runtime->hasFunction(0x1D78F0u)) {
        auto targetFn = runtime->lookupFunction(0x1D78F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D925Cu; }
        if (ctx->pc != 0x1D925Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D78F0_0x1d78f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D925Cu; }
        if (ctx->pc != 0x1D925Cu) { return; }
    }
    ctx->pc = 0x1D925Cu;
label_1d925c:
    // 0x1d925c: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x1d925cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d9260: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1d9260u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1d9264: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1d9264u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d9268: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d9268u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d926c: 0x3e00008  jr          $ra
    ctx->pc = 0x1D926Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D9270u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D926Cu;
            // 0x1d9270: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D921Cu: goto label_1d921c;
            case 0x1D9244u: goto label_1d9244;
            case 0x1D925Cu: goto label_1d925c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D9274u;
    // 0x1d9274: 0x0  nop
    ctx->pc = 0x1d9274u;
    // NOP
    // 0x1d9278: 0x0  nop
    ctx->pc = 0x1d9278u;
    // NOP
    // 0x1d927c: 0x0  nop
    ctx->pc = 0x1d927cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
