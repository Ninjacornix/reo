#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001DA200
// Address: 0x1da200 - 0x1da30c
void sub_001DA200_0x1da200(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001DA200_0x1da200");
#endif

    switch (ctx->pc) {
        case 0x1da248u: goto label_1da248;
        case 0x1da280u: goto label_1da280;
        case 0x1da290u: goto label_1da290;
        case 0x1da2b8u: goto label_1da2b8;
        case 0x1da2ccu: goto label_1da2cc;
        case 0x1da2d4u: goto label_1da2d4;
        case 0x1da2f0u: goto label_1da2f0;
        default: break;
    }

    ctx->pc = 0x1da200u;

    // 0x1da200: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1da200u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1da204: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1da204u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1da208: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1da208u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1da20c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1da20cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1da210: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1da210u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1da214: 0x6000004  bltz        $s0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1DA214u;
    {
        const bool branch_taken_0x1da214 = (GPR_S64(ctx, 16) < 0);
        ctx->pc = 0x1DA218u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1DA214u;
            // 0x1da218: 0x2a020003  slti        $v0, $s0, 0x3 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)3) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1da214) {
            ctx->pc = 0x1DA228u;
            goto label_1da228;
        }
    }
    ctx->pc = 0x1DA21Cu;
    // 0x1da21c: 0x14400008  bnez        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1DA21Cu;
    {
        const bool branch_taken_0x1da21c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1da21c) {
            ctx->pc = 0x1DA240u;
            goto label_1da240;
        }
    }
    ctx->pc = 0x1DA224u;
    // 0x1da224: 0x0  nop
    ctx->pc = 0x1da224u;
    // NOP
label_1da228:
    // 0x1da228: 0x24020009  addiu       $v0, $zero, 0x9
    ctx->pc = 0x1da228u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
    // 0x1da22c: 0x3c010035  lui         $at, 0x35
    ctx->pc = 0x1da22cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)53 << 16));
    // 0x1da230: 0xac228c88  sw          $v0, -0x7378($at)
    ctx->pc = 0x1da230u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294937736), GPR_U32(ctx, 2));
    // 0x1da234: 0x10000030  b           . + 4 + (0x30 << 2)
    ctx->pc = 0x1DA234u;
    {
        const bool branch_taken_0x1da234 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1DA238u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1DA234u;
            // 0x1da238: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1da234) {
            ctx->pc = 0x1DA2F8u;
            goto label_1da2f8;
        }
    }
    ctx->pc = 0x1DA23Cu;
    // 0x1da23c: 0x0  nop
    ctx->pc = 0x1da23cu;
    // NOP
label_1da240:
    // 0x1da240: 0xc076514  jal         func_1D9450
    ctx->pc = 0x1DA240u;
    SET_GPR_U32(ctx, 31, 0x1DA248u);
    ctx->pc = 0x1D9450u;
    if (runtime->hasFunction(0x1D9450u)) {
        auto targetFn = runtime->lookupFunction(0x1D9450u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA248u; }
        if (ctx->pc != 0x1DA248u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D9450_0x1d9450(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA248u; }
        if (ctx->pc != 0x1DA248u) { return; }
    }
    ctx->pc = 0x1DA248u;
label_1da248:
    // 0x1da248: 0x3c020035  lui         $v0, 0x35
    ctx->pc = 0x1da248u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)53 << 16));
    // 0x1da24c: 0x108080  sll         $s0, $s0, 2
    ctx->pc = 0x1da24cu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
    // 0x1da250: 0x24428c90  addiu       $v0, $v0, -0x7370
    ctx->pc = 0x1da250u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294937744));
    // 0x1da254: 0x508821  addu        $s1, $v0, $s0
    ctx->pc = 0x1da254u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x1da258: 0x8e230000  lw          $v1, 0x0($s1)
    ctx->pc = 0x1da258u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1da25c: 0x2402fffe  addiu       $v0, $zero, -0x2
    ctx->pc = 0x1da25cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967294));
    // 0x1da260: 0x14620009  bne         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1DA260u;
    {
        const bool branch_taken_0x1da260 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x1DA264u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1DA260u;
            // 0x1da264: 0x3c020035  lui         $v0, 0x35 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)53 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1da260) {
            ctx->pc = 0x1DA288u;
            goto label_1da288;
        }
    }
    ctx->pc = 0x1DA268u;
    // 0x1da268: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x1da268u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1da26c: 0x24428c70  addiu       $v0, $v0, -0x7390
    ctx->pc = 0x1da26cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294937712));
    // 0x1da270: 0xae230000  sw          $v1, 0x0($s1)
    ctx->pc = 0x1da270u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 3));
    // 0x1da274: 0x501021  addu        $v0, $v0, $s0
    ctx->pc = 0x1da274u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x1da278: 0xc076518  jal         func_1D9460
    ctx->pc = 0x1DA278u;
    SET_GPR_U32(ctx, 31, 0x1DA280u);
    ctx->pc = 0x1DA27Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1DA278u;
            // 0x1da27c: 0xac430000  sw          $v1, 0x0($v0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D9460u;
    if (runtime->hasFunction(0x1D9460u)) {
        auto targetFn = runtime->lookupFunction(0x1D9460u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA280u; }
        if (ctx->pc != 0x1DA280u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D9460_0x1d9460(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA280u; }
        if (ctx->pc != 0x1DA280u) { return; }
    }
    ctx->pc = 0x1DA280u;
label_1da280:
    // 0x1da280: 0x1000001d  b           . + 4 + (0x1D << 2)
    ctx->pc = 0x1DA280u;
    {
        const bool branch_taken_0x1da280 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1DA284u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1DA280u;
            // 0x1da284: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1da280) {
            ctx->pc = 0x1DA2F8u;
            goto label_1da2f8;
        }
    }
    ctx->pc = 0x1DA288u;
label_1da288:
    // 0x1da288: 0xc076518  jal         func_1D9460
    ctx->pc = 0x1DA288u;
    SET_GPR_U32(ctx, 31, 0x1DA290u);
    ctx->pc = 0x1D9460u;
    if (runtime->hasFunction(0x1D9460u)) {
        auto targetFn = runtime->lookupFunction(0x1D9460u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA290u; }
        if (ctx->pc != 0x1DA290u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D9460_0x1d9460(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA290u; }
        if (ctx->pc != 0x1DA290u) { return; }
    }
    ctx->pc = 0x1DA290u;
label_1da290:
    // 0x1da290: 0x8e220000  lw          $v0, 0x0($s1)
    ctx->pc = 0x1da290u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1da294: 0x4410006  bgez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1DA294u;
    {
        const bool branch_taken_0x1da294 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x1DA298u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1DA294u;
            // 0x1da298: 0x24030009  addiu       $v1, $zero, 0x9 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1da294) {
            ctx->pc = 0x1DA2B0u;
            goto label_1da2b0;
        }
    }
    ctx->pc = 0x1DA29Cu;
    // 0x1da29c: 0x3c010035  lui         $at, 0x35
    ctx->pc = 0x1da29cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)53 << 16));
    // 0x1da2a0: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1da2a0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1da2a4: 0x10000014  b           . + 4 + (0x14 << 2)
    ctx->pc = 0x1DA2A4u;
    {
        const bool branch_taken_0x1da2a4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1DA2A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1DA2A4u;
            // 0x1da2a8: 0xac238c88  sw          $v1, -0x7378($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294937736), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1da2a4) {
            ctx->pc = 0x1DA2F8u;
            goto label_1da2f8;
        }
    }
    ctx->pc = 0x1DA2ACu;
    // 0x1da2ac: 0x0  nop
    ctx->pc = 0x1da2acu;
    // NOP
label_1da2b0:
    // 0x1da2b0: 0xc076514  jal         func_1D9450
    ctx->pc = 0x1DA2B0u;
    SET_GPR_U32(ctx, 31, 0x1DA2B8u);
    ctx->pc = 0x1D9450u;
    if (runtime->hasFunction(0x1D9450u)) {
        auto targetFn = runtime->lookupFunction(0x1D9450u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA2B8u; }
        if (ctx->pc != 0x1DA2B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D9450_0x1d9450(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA2B8u; }
        if (ctx->pc != 0x1DA2B8u) { return; }
    }
    ctx->pc = 0x1DA2B8u;
label_1da2b8:
    // 0x1da2b8: 0x3c020035  lui         $v0, 0x35
    ctx->pc = 0x1da2b8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)53 << 16));
    // 0x1da2bc: 0x24428c90  addiu       $v0, $v0, -0x7370
    ctx->pc = 0x1da2bcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294937744));
    // 0x1da2c0: 0x508821  addu        $s1, $v0, $s0
    ctx->pc = 0x1da2c0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x1da2c4: 0xc075f30  jal         func_1D7CC0
    ctx->pc = 0x1DA2C4u;
    SET_GPR_U32(ctx, 31, 0x1DA2CCu);
    ctx->pc = 0x1DA2C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1DA2C4u;
            // 0x1da2c8: 0x86240000  lh          $a0, 0x0($s1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 17), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D7CC0u;
    if (runtime->hasFunction(0x1D7CC0u)) {
        auto targetFn = runtime->lookupFunction(0x1D7CC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA2CCu; }
        if (ctx->pc != 0x1DA2CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D7CC0_0x1d7cc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA2CCu; }
        if (ctx->pc != 0x1DA2CCu) { return; }
    }
    ctx->pc = 0x1DA2CCu;
label_1da2cc:
    // 0x1da2cc: 0xc076060  jal         func_1D8180
    ctx->pc = 0x1DA2CCu;
    SET_GPR_U32(ctx, 31, 0x1DA2D4u);
    ctx->pc = 0x1DA2D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1DA2CCu;
            // 0x1da2d0: 0x86240000  lh          $a0, 0x0($s1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 17), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D8180u;
    if (runtime->hasFunction(0x1D8180u)) {
        auto targetFn = runtime->lookupFunction(0x1D8180u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA2D4u; }
        if (ctx->pc != 0x1DA2D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D8180_0x1d8180(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA2D4u; }
        if (ctx->pc != 0x1DA2D4u) { return; }
    }
    ctx->pc = 0x1DA2D4u;
label_1da2d4:
    // 0x1da2d4: 0x3c020035  lui         $v0, 0x35
    ctx->pc = 0x1da2d4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)53 << 16));
    // 0x1da2d8: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x1da2d8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1da2dc: 0x24428c70  addiu       $v0, $v0, -0x7390
    ctx->pc = 0x1da2dcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294937712));
    // 0x1da2e0: 0xae230000  sw          $v1, 0x0($s1)
    ctx->pc = 0x1da2e0u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 3));
    // 0x1da2e4: 0x501021  addu        $v0, $v0, $s0
    ctx->pc = 0x1da2e4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x1da2e8: 0xc076518  jal         func_1D9460
    ctx->pc = 0x1DA2E8u;
    SET_GPR_U32(ctx, 31, 0x1DA2F0u);
    ctx->pc = 0x1DA2ECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1DA2E8u;
            // 0x1da2ec: 0xac430000  sw          $v1, 0x0($v0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D9460u;
    if (runtime->hasFunction(0x1D9460u)) {
        auto targetFn = runtime->lookupFunction(0x1D9460u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA2F0u; }
        if (ctx->pc != 0x1DA2F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D9460_0x1d9460(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA2F0u; }
        if (ctx->pc != 0x1DA2F0u) { return; }
    }
    ctx->pc = 0x1DA2F0u;
label_1da2f0:
    // 0x1da2f0: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1da2f0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1da2f4: 0x0  nop
    ctx->pc = 0x1da2f4u;
    // NOP
label_1da2f8:
    // 0x1da2f8: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1da2f8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1da2fc: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1da2fcu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1da300: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1da300u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1da304: 0x3e00008  jr          $ra
    ctx->pc = 0x1DA304u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1DA308u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1DA304u;
            // 0x1da308: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1DA228u: goto label_1da228;
            case 0x1DA240u: goto label_1da240;
            case 0x1DA248u: goto label_1da248;
            case 0x1DA280u: goto label_1da280;
            case 0x1DA288u: goto label_1da288;
            case 0x1DA290u: goto label_1da290;
            case 0x1DA2B0u: goto label_1da2b0;
            case 0x1DA2B8u: goto label_1da2b8;
            case 0x1DA2CCu: goto label_1da2cc;
            case 0x1DA2D4u: goto label_1da2d4;
            case 0x1DA2F0u: goto label_1da2f0;
            case 0x1DA2F8u: goto label_1da2f8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1DA30Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
