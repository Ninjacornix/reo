#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001247A0
// Address: 0x1247a0 - 0x124860
void sub_001247A0_0x1247a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001247A0_0x1247a0");
#endif

    switch (ctx->pc) {
        case 0x1247b0u: goto label_1247b0;
        case 0x1247b8u: goto label_1247b8;
        case 0x1247e8u: goto label_1247e8;
        case 0x1247f0u: goto label_1247f0;
        default: break;
    }

    ctx->pc = 0x1247a0u;

    // 0x1247a0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1247a0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1247a4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1247a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1247a8: 0xc04d364  jal         func_134D90
    ctx->pc = 0x1247A8u;
    SET_GPR_U32(ctx, 31, 0x1247B0u);
    ctx->pc = 0x134D90u;
    if (runtime->hasFunction(0x134D90u)) {
        auto targetFn = runtime->lookupFunction(0x134D90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1247B0u; }
        if (ctx->pc != 0x1247B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00134D90_0x134d90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1247B0u; }
        if (ctx->pc != 0x1247B0u) { return; }
    }
    ctx->pc = 0x1247B0u;
label_1247b0:
    // 0x1247b0: 0xc049146  jal         func_124518
    ctx->pc = 0x1247B0u;
    SET_GPR_U32(ctx, 31, 0x1247B8u);
    ctx->pc = 0x124518u;
    if (runtime->hasFunction(0x124518u)) {
        auto targetFn = runtime->lookupFunction(0x124518u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1247B8u; }
        if (ctx->pc != 0x1247B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00124518_0x124518(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1247B8u; }
        if (ctx->pc != 0x1247B8u) { return; }
    }
    ctx->pc = 0x1247B8u;
label_1247b8:
    // 0x1247b8: 0x3c040021  lui         $a0, 0x21
    ctx->pc = 0x1247b8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)33 << 16));
    // 0x1247bc: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1247bcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1247c0: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1247c0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1247c4: 0x2484b958  addiu       $a0, $a0, -0x46A8
    ctx->pc = 0x1247c4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294949208));
    // 0x1247c8: 0x24060e40  addiu       $a2, $zero, 0xE40
    ctx->pc = 0x1247c8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 3648));
    // 0x1247cc: 0x8041f1a  j           func_107C68
    ctx->pc = 0x1247CCu;
    ctx->pc = 0x1247D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1247CCu;
            // 0x1247d0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00107C68_0x107c68(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1247D4u;
    // 0x1247d4: 0x0  nop
    ctx->pc = 0x1247d4u;
    // NOP
    // 0x1247d8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1247d8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1247dc: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1247dcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1247e0: 0xc04d36e  jal         func_134DB8
    ctx->pc = 0x1247E0u;
    SET_GPR_U32(ctx, 31, 0x1247E8u);
    ctx->pc = 0x134DB8u;
    if (runtime->hasFunction(0x134DB8u)) {
        auto targetFn = runtime->lookupFunction(0x134DB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1247E8u; }
        if (ctx->pc != 0x1247E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00134DB8_0x134db8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1247E8u; }
        if (ctx->pc != 0x1247E8u) { return; }
    }
    ctx->pc = 0x1247E8u;
label_1247e8:
    // 0x1247e8: 0xc04914e  jal         func_124538
    ctx->pc = 0x1247E8u;
    SET_GPR_U32(ctx, 31, 0x1247F0u);
    ctx->pc = 0x124538u;
    if (runtime->hasFunction(0x124538u)) {
        auto targetFn = runtime->lookupFunction(0x124538u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1247F0u; }
        if (ctx->pc != 0x1247F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00124538_0x124538(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1247F0u; }
        if (ctx->pc != 0x1247F0u) { return; }
    }
    ctx->pc = 0x1247F0u;
label_1247f0:
    // 0x1247f0: 0x3c040021  lui         $a0, 0x21
    ctx->pc = 0x1247f0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)33 << 16));
    // 0x1247f4: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1247f4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1247f8: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1247f8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1247fc: 0x2484b958  addiu       $a0, $a0, -0x46A8
    ctx->pc = 0x1247fcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294949208));
    // 0x124800: 0x24060e40  addiu       $a2, $zero, 0xE40
    ctx->pc = 0x124800u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 3648));
    // 0x124804: 0x8041f1a  j           func_107C68
    ctx->pc = 0x124804u;
    ctx->pc = 0x124808u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x124804u;
            // 0x124808: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00107C68_0x107c68(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12480Cu;
    // 0x12480c: 0x0  nop
    ctx->pc = 0x12480cu;
    // NOP
    // 0x124810: 0x8c88008c  lw          $t0, 0x8C($a0)
    ctx->pc = 0x124810u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 140)));
    // 0x124814: 0x8c82003c  lw          $v0, 0x3C($a0)
    ctx->pc = 0x124814u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 60)));
    // 0x124818: 0xaca80000  sw          $t0, 0x0($a1)
    ctx->pc = 0x124818u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 8));
    // 0x12481c: 0x8c85008c  lw          $a1, 0x8C($a0)
    ctx->pc = 0x12481cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 140)));
    // 0x124820: 0x8c830040  lw          $v1, 0x40($a0)
    ctx->pc = 0x124820u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 64)));
    // 0x124824: 0x651823  subu        $v1, $v1, $a1
    ctx->pc = 0x124824u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x124828: 0xacc30000  sw          $v1, 0x0($a2)
    ctx->pc = 0x124828u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 3));
    // 0x12482c: 0x8c850018  lw          $a1, 0x18($a0)
    ctx->pc = 0x12482cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 24)));
    // 0x124830: 0x8c830088  lw          $v1, 0x88($a0)
    ctx->pc = 0x124830u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 136)));
    // 0x124834: 0xa32823  subu        $a1, $a1, $v1
    ctx->pc = 0x124834u;
    SET_GPR_S32(ctx, 5, (int32_t)SUB32(GPR_U32(ctx, 5), GPR_U32(ctx, 3)));
    // 0x124838: 0x3e00008  jr          $ra
    ctx->pc = 0x124838u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12483Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x124838u;
            // 0x12483c: 0xace50000  sw          $a1, 0x0($a3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 7), 0), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1247B0u: goto label_1247b0;
            case 0x1247B8u: goto label_1247b8;
            case 0x1247E8u: goto label_1247e8;
            case 0x1247F0u: goto label_1247f0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x124840u;
    // 0x124840: 0x8c82008c  lw          $v0, 0x8C($a0)
    ctx->pc = 0x124840u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 140)));
    // 0x124844: 0x8c830088  lw          $v1, 0x88($a0)
    ctx->pc = 0x124844u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 136)));
    // 0x124848: 0x461021  addu        $v0, $v0, $a2
    ctx->pc = 0x124848u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 6)));
    // 0x12484c: 0x661821  addu        $v1, $v1, $a2
    ctx->pc = 0x12484cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 6)));
    // 0x124850: 0xac82008c  sw          $v0, 0x8C($a0)
    ctx->pc = 0x124850u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 140), GPR_U32(ctx, 2));
    // 0x124854: 0x3e00008  jr          $ra
    ctx->pc = 0x124854u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x124858u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x124854u;
            // 0x124858: 0xac830088  sw          $v1, 0x88($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 136), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1247B0u: goto label_1247b0;
            case 0x1247B8u: goto label_1247b8;
            case 0x1247E8u: goto label_1247e8;
            case 0x1247F0u: goto label_1247f0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12485Cu;
    // 0x12485c: 0x0  nop
    ctx->pc = 0x12485cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
