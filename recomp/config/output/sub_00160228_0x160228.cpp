#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00160228
// Address: 0x160228 - 0x1602c4
void sub_00160228_0x160228(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00160228_0x160228");
#endif

    switch (ctx->pc) {
        case 0x16023cu: goto label_16023c;
        case 0x160254u: goto label_160254;
        case 0x160268u: goto label_160268;
        case 0x1602acu: goto label_1602ac;
        default: break;
    }

    ctx->pc = 0x160228u;

    // 0x160228: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x160228u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x16022c: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x16022cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x160230: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x160230u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x160234: 0xc057ff0  jal         func_15FFC0
    ctx->pc = 0x160234u;
    SET_GPR_U32(ctx, 31, 0x16023Cu);
    ctx->pc = 0x160238u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x160234u;
            // 0x160238: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FFC0u;
    if (runtime->hasFunction(0x15FFC0u)) {
        auto targetFn = runtime->lookupFunction(0x15FFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16023Cu; }
        if (ctx->pc != 0x16023Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FFC0_0x15ffc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16023Cu; }
        if (ctx->pc != 0x16023Cu) { return; }
    }
    ctx->pc = 0x16023Cu;
label_16023c:
    // 0x16023c: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x16023cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x160240: 0x14400007  bnez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x160240u;
    {
        const bool branch_taken_0x160240 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x160244u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x160240u;
            // 0x160244: 0x2405000f  addiu       $a1, $zero, 0xF (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 15));
        ctx->in_delay_slot = false;
        if (branch_taken_0x160240) {
            ctx->pc = 0x160260u;
            goto label_160260;
        }
    }
    ctx->pc = 0x160248u;
    // 0x160248: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x160248u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x16024c: 0xc058dd4  jal         func_163750
    ctx->pc = 0x16024Cu;
    SET_GPR_U32(ctx, 31, 0x160254u);
    ctx->pc = 0x160250u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16024Cu;
            // 0x160250: 0x2484f570  addiu       $a0, $a0, -0xA90 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294964592));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160254u; }
        if (ctx->pc != 0x160254u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160254u; }
        if (ctx->pc != 0x160254u) { return; }
    }
    ctx->pc = 0x160254u;
label_160254:
    // 0x160254: 0x10000017  b           . + 4 + (0x17 << 2)
    ctx->pc = 0x160254u;
    {
        const bool branch_taken_0x160254 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x160258u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x160254u;
            // 0x160258: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x160254) {
            ctx->pc = 0x1602B4u;
            goto label_1602b4;
        }
    }
    ctx->pc = 0x16025Cu;
    // 0x16025c: 0x0  nop
    ctx->pc = 0x16025cu;
    // NOP
label_160260:
    // 0x160260: 0xc05d562  jal         func_175588
    ctx->pc = 0x160260u;
    SET_GPR_U32(ctx, 31, 0x160268u);
    ctx->pc = 0x160264u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x160260u;
            // 0x160264: 0x8e040040  lw          $a0, 0x40($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 64)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175588u;
    if (runtime->hasFunction(0x175588u)) {
        auto targetFn = runtime->lookupFunction(0x175588u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160268u; }
        if (ctx->pc != 0x160268u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175588_0x175588(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160268u; }
        if (ctx->pc != 0x160268u) { return; }
    }
    ctx->pc = 0x160268u;
label_160268:
    // 0x160268: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x160268u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x16026c: 0x8fa40000  lw          $a0, 0x0($sp)
    ctx->pc = 0x16026cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x160270: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x160270u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x160274: 0x1083000e  beq         $a0, $v1, . + 4 + (0xE << 2)
    ctx->pc = 0x160274u;
    {
        const bool branch_taken_0x160274 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        ctx->pc = 0x160278u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x160274u;
            // 0x160278: 0x28820002  slti        $v0, $a0, 0x2 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)2) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x160274) {
            ctx->pc = 0x1602B0u;
            goto label_1602b0;
        }
    }
    ctx->pc = 0x16027Cu;
    // 0x16027c: 0x50400006  beql        $v0, $zero, . + 4 + (0x6 << 2)
    ctx->pc = 0x16027Cu;
    {
        const bool branch_taken_0x16027c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x16027c) {
            ctx->pc = 0x160280u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16027Cu;
            // 0x160280: 0x24020002  addiu       $v0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
            ctx->pc = 0x160298u;
            goto label_160298;
        }
    }
    ctx->pc = 0x160284u;
    // 0x160284: 0x1080000a  beqz        $a0, . + 4 + (0xA << 2)
    ctx->pc = 0x160284u;
    {
        const bool branch_taken_0x160284 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x160288u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x160284u;
            // 0x160288: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x160284) {
            ctx->pc = 0x1602B0u;
            goto label_1602b0;
        }
    }
    ctx->pc = 0x16028Cu;
    // 0x16028c: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x16028Cu;
    {
        const bool branch_taken_0x16028c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x160290u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16028Cu;
            // 0x160290: 0x3c040024  lui         $a0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16028c) {
            ctx->pc = 0x1602A4u;
            goto label_1602a4;
        }
    }
    ctx->pc = 0x160294u;
    // 0x160294: 0x0  nop
    ctx->pc = 0x160294u;
    // NOP
label_160298:
    // 0x160298: 0x10820005  beq         $a0, $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x160298u;
    {
        const bool branch_taken_0x160298 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        ctx->pc = 0x16029Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x160298u;
            // 0x16029c: 0x24050002  addiu       $a1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x160298) {
            ctx->pc = 0x1602B0u;
            goto label_1602b0;
        }
    }
    ctx->pc = 0x1602A0u;
    // 0x1602a0: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1602a0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
label_1602a4:
    // 0x1602a4: 0xc058dd4  jal         func_163750
    ctx->pc = 0x1602A4u;
    SET_GPR_U32(ctx, 31, 0x1602ACu);
    ctx->pc = 0x1602A8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1602A4u;
            // 0x1602a8: 0x2484f5a0  addiu       $a0, $a0, -0xA60 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294964640));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1602ACu; }
        if (ctx->pc != 0x1602ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1602ACu; }
        if (ctx->pc != 0x1602ACu) { return; }
    }
    ctx->pc = 0x1602ACu;
label_1602ac:
    // 0x1602ac: 0x2405ffff  addiu       $a1, $zero, -0x1
    ctx->pc = 0x1602acu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
label_1602b0:
    // 0x1602b0: 0xa0102d  daddu       $v0, $a1, $zero
    ctx->pc = 0x1602b0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
label_1602b4:
    // 0x1602b4: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x1602b4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1602b8: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1602b8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1602bc: 0x3e00008  jr          $ra
    ctx->pc = 0x1602BCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1602C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1602BCu;
            // 0x1602c0: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16023Cu: goto label_16023c;
            case 0x160254u: goto label_160254;
            case 0x160260u: goto label_160260;
            case 0x160268u: goto label_160268;
            case 0x160298u: goto label_160298;
            case 0x1602A4u: goto label_1602a4;
            case 0x1602ACu: goto label_1602ac;
            case 0x1602B0u: goto label_1602b0;
            case 0x1602B4u: goto label_1602b4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1602C4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
