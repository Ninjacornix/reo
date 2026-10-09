#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001868C8
// Address: 0x1868c8 - 0x186a88
void sub_001868C8_0x1868c8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001868C8_0x1868c8");
#endif

    switch (ctx->pc) {
        case 0x1868f4u: goto label_1868f4;
        case 0x186938u: goto label_186938;
        case 0x18694cu: goto label_18694c;
        case 0x186960u: goto label_186960;
        case 0x18696cu: goto label_18696c;
        case 0x186978u: goto label_186978;
        case 0x186980u: goto label_186980;
        case 0x186990u: goto label_186990;
        case 0x1869b0u: goto label_1869b0;
        case 0x1869c0u: goto label_1869c0;
        case 0x1869ecu: goto label_1869ec;
        case 0x186a14u: goto label_186a14;
        case 0x186a30u: goto label_186a30;
        case 0x186a44u: goto label_186a44;
        case 0x186a54u: goto label_186a54;
        default: break;
    }

    ctx->pc = 0x1868c8u;

    // 0x1868c8: 0x27bdfcc0  addiu       $sp, $sp, -0x340
    ctx->pc = 0x1868c8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294966464));
    // 0x1868cc: 0xffb00310  sd          $s0, 0x310($sp)
    ctx->pc = 0x1868ccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 784), GPR_U64(ctx, 16));
    // 0x1868d0: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x1868d0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1868d4: 0xffb10318  sd          $s1, 0x318($sp)
    ctx->pc = 0x1868d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 792), GPR_U64(ctx, 17));
    // 0x1868d8: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1868d8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1868dc: 0xffb20320  sd          $s2, 0x320($sp)
    ctx->pc = 0x1868dcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 800), GPR_U64(ctx, 18));
    // 0x1868e0: 0xffb30328  sd          $s3, 0x328($sp)
    ctx->pc = 0x1868e0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 808), GPR_U64(ctx, 19));
    // 0x1868e4: 0xffb40330  sd          $s4, 0x330($sp)
    ctx->pc = 0x1868e4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 816), GPR_U64(ctx, 20));
    // 0x1868e8: 0xffbf0338  sd          $ra, 0x338($sp)
    ctx->pc = 0x1868e8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 824), GPR_U64(ctx, 31));
    // 0x1868ec: 0xc062210  jal         func_188840
    ctx->pc = 0x1868ECu;
    SET_GPR_U32(ctx, 31, 0x1868F4u);
    ctx->pc = 0x1868F0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1868ECu;
            // 0x1868f0: 0xc0902d  daddu       $s2, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x188840u;
    if (runtime->hasFunction(0x188840u)) {
        auto targetFn = runtime->lookupFunction(0x188840u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1868F4u; }
        if (ctx->pc != 0x1868F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00188840_0x188840(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1868F4u; }
        if (ctx->pc != 0x1868F4u) { return; }
    }
    ctx->pc = 0x1868F4u;
label_1868f4:
    // 0x1868f4: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1868F4u;
    {
        const bool branch_taken_0x1868f4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1868F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1868F4u;
            // 0x1868f8: 0x24030898  addiu       $v1, $zero, 0x898 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2200));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1868f4) {
            ctx->pc = 0x186908u;
            goto label_186908;
        }
    }
    ctx->pc = 0x1868FCu;
    // 0x1868fc: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x1868fcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x186900: 0x10000058  b           . + 4 + (0x58 << 2)
    ctx->pc = 0x186900u;
    {
        const bool branch_taken_0x186900 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x186904u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x186900u;
            // 0x186904: 0x34420013  ori         $v0, $v0, 0x13 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)19);
        ctx->in_delay_slot = false;
        if (branch_taken_0x186900) {
            ctx->pc = 0x186A64u;
            goto label_186a64;
        }
    }
    ctx->pc = 0x186908u;
label_186908:
    // 0x186908: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x186908u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x18690c: 0x2231818  mult        $v1, $s1, $v1
    ctx->pc = 0x18690cu;
    { int64_t result = (int64_t)GPR_S32(ctx, 17) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x186910: 0x3c040028  lui         $a0, 0x28
    ctx->pc = 0x186910u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)40 << 16));
    // 0x186914: 0x832021  addu        $a0, $a0, $v1
    ctx->pc = 0x186914u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0x186918: 0x8c8463d4  lw          $a0, 0x63D4($a0)
    ctx->pc = 0x186918u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 25556)));
    // 0x18691c: 0x10800051  beqz        $a0, . + 4 + (0x51 << 2)
    ctx->pc = 0x18691Cu;
    {
        const bool branch_taken_0x18691c = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x186920u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18691Cu;
            // 0x186920: 0x3442006f  ori         $v0, $v0, 0x6F (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)111);
        ctx->in_delay_slot = false;
        if (branch_taken_0x18691c) {
            ctx->pc = 0x186A64u;
            goto label_186a64;
        }
    }
    ctx->pc = 0x186924u;
    // 0x186924: 0x27b40200  addiu       $s4, $sp, 0x200
    ctx->pc = 0x186924u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 29), 512));
    // 0x186928: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x186928u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18692c: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x18692cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x186930: 0xc0609a2  jal         func_182688
    ctx->pc = 0x186930u;
    SET_GPR_U32(ctx, 31, 0x186938u);
    ctx->pc = 0x186934u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x186930u;
            // 0x186934: 0x280302d  daddu       $a2, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x182688u;
    if (runtime->hasFunction(0x182688u)) {
        auto targetFn = runtime->lookupFunction(0x182688u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x186938u; }
        if (ctx->pc != 0x186938u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00182688_0x182688(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x186938u; }
        if (ctx->pc != 0x186938u) { return; }
    }
    ctx->pc = 0x186938u;
label_186938:
    // 0x186938: 0x10400017  beqz        $v0, . + 4 + (0x17 << 2)
    ctx->pc = 0x186938u;
    {
        const bool branch_taken_0x186938 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x186938) {
            ctx->pc = 0x186998u;
            goto label_186998;
        }
    }
    ctx->pc = 0x186940u;
    // 0x186940: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x186940u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x186944: 0xc042b3a  jal         func_10ACE8
    ctx->pc = 0x186944u;
    SET_GPR_U32(ctx, 31, 0x18694Cu);
    ctx->pc = 0x186948u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x186944u;
            // 0x186948: 0x2405002f  addiu       $a1, $zero, 0x2F (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 47));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10ACE8u;
    if (runtime->hasFunction(0x10ACE8u)) {
        auto targetFn = runtime->lookupFunction(0x10ACE8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18694Cu; }
        if (ctx->pc != 0x18694Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010ACE8_0x10ace8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18694Cu; }
        if (ctx->pc != 0x18694Cu) { return; }
    }
    ctx->pc = 0x18694Cu;
label_18694c:
    // 0x18694c: 0x14400012  bnez        $v0, . + 4 + (0x12 << 2)
    ctx->pc = 0x18694Cu;
    {
        const bool branch_taken_0x18694c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x186950u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18694Cu;
            // 0x186950: 0x27b30280  addiu       $s3, $sp, 0x280 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 29), 640));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18694c) {
            ctx->pc = 0x186998u;
            goto label_186998;
        }
    }
    ctx->pc = 0x186954u;
    // 0x186954: 0x280282d  daddu       $a1, $s4, $zero
    ctx->pc = 0x186954u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x186958: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x186958u;
    SET_GPR_U32(ctx, 31, 0x186960u);
    ctx->pc = 0x18695Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x186958u;
            // 0x18695c: 0x260202d  daddu       $a0, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x186960u; }
        if (ctx->pc != 0x186960u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x186960u; }
        if (ctx->pc != 0x186960u) { return; }
    }
    ctx->pc = 0x186960u;
label_186960:
    // 0x186960: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x186960u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x186964: 0xc042dee  jal         func_10B7B8
    ctx->pc = 0x186964u;
    SET_GPR_U32(ctx, 31, 0x18696Cu);
    ctx->pc = 0x186968u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x186964u;
            // 0x186968: 0x2405002f  addiu       $a1, $zero, 0x2F (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 47));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B7B8u;
    if (runtime->hasFunction(0x10B7B8u)) {
        auto targetFn = runtime->lookupFunction(0x10B7B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18696Cu; }
        if (ctx->pc != 0x18696Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B7B8_0x10b7b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18696Cu; }
        if (ctx->pc != 0x18696Cu) { return; }
    }
    ctx->pc = 0x18696Cu;
label_18696c:
    // 0x18696c: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x18696cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x186970: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x186970u;
    SET_GPR_U32(ctx, 31, 0x186978u);
    ctx->pc = 0x186974u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x186970u;
            // 0x186974: 0x24440001  addiu       $a0, $v0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x186978u; }
        if (ctx->pc != 0x186978u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x186978u; }
        if (ctx->pc != 0x186978u) { return; }
    }
    ctx->pc = 0x186978u;
label_186978:
    // 0x186978: 0xc06089c  jal         func_182270
    ctx->pc = 0x186978u;
    SET_GPR_U32(ctx, 31, 0x186980u);
    ctx->pc = 0x18697Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x186978u;
            // 0x18697c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x182270u;
    if (runtime->hasFunction(0x182270u)) {
        auto targetFn = runtime->lookupFunction(0x182270u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x186980u; }
        if (ctx->pc != 0x186980u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00182270_0x182270(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x186980u; }
        if (ctx->pc != 0x186980u) { return; }
    }
    ctx->pc = 0x186980u;
label_186980:
    // 0x186980: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x186980u;
    {
        const bool branch_taken_0x186980 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x186980) {
            ctx->pc = 0x186998u;
            goto label_186998;
        }
    }
    ctx->pc = 0x186988u;
    // 0x186988: 0xc06089c  jal         func_182270
    ctx->pc = 0x186988u;
    SET_GPR_U32(ctx, 31, 0x186990u);
    ctx->pc = 0x18698Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x186988u;
            // 0x18698c: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x182270u;
    if (runtime->hasFunction(0x182270u)) {
        auto targetFn = runtime->lookupFunction(0x182270u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x186990u; }
        if (ctx->pc != 0x186990u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00182270_0x182270(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x186990u; }
        if (ctx->pc != 0x186990u) { return; }
    }
    ctx->pc = 0x186990u;
label_186990:
    // 0x186990: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x186990u;
    {
        const bool branch_taken_0x186990 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x186990) {
            ctx->pc = 0x1869A8u;
            goto label_1869a8;
        }
    }
    ctx->pc = 0x186998u;
label_186998:
    // 0x186998: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x186998u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x18699c: 0x10000031  b           . + 4 + (0x31 << 2)
    ctx->pc = 0x18699Cu;
    {
        const bool branch_taken_0x18699c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1869A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18699Cu;
            // 0x1869a0: 0x34420016  ori         $v0, $v0, 0x16 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)22);
        ctx->in_delay_slot = false;
        if (branch_taken_0x18699c) {
            ctx->pc = 0x186A64u;
            goto label_186a64;
        }
    }
    ctx->pc = 0x1869A4u;
    // 0x1869a4: 0x0  nop
    ctx->pc = 0x1869a4u;
    // NOP
label_1869a8:
    // 0x1869a8: 0xc060880  jal         func_182200
    ctx->pc = 0x1869A8u;
    SET_GPR_U32(ctx, 31, 0x1869B0u);
    ctx->pc = 0x1869ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1869A8u;
            // 0x1869ac: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x182200u;
    if (runtime->hasFunction(0x182200u)) {
        auto targetFn = runtime->lookupFunction(0x182200u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1869B0u; }
        if (ctx->pc != 0x1869B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00182200_0x182200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1869B0u; }
        if (ctx->pc != 0x1869B0u) { return; }
    }
    ctx->pc = 0x1869B0u;
label_1869b0:
    // 0x1869b0: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1869B0u;
    {
        const bool branch_taken_0x1869b0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1869b0) {
            ctx->pc = 0x1869C8u;
            goto label_1869c8;
        }
    }
    ctx->pc = 0x1869B8u;
    // 0x1869b8: 0xc060880  jal         func_182200
    ctx->pc = 0x1869B8u;
    SET_GPR_U32(ctx, 31, 0x1869C0u);
    ctx->pc = 0x1869BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1869B8u;
            // 0x1869bc: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x182200u;
    if (runtime->hasFunction(0x182200u)) {
        auto targetFn = runtime->lookupFunction(0x182200u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1869C0u; }
        if (ctx->pc != 0x1869C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00182200_0x182200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1869C0u; }
        if (ctx->pc != 0x1869C0u) { return; }
    }
    ctx->pc = 0x1869C0u;
label_1869c0:
    // 0x1869c0: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1869C0u;
    {
        const bool branch_taken_0x1869c0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1869C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1869C0u;
            // 0x1869c4: 0x260282d  daddu       $a1, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1869c0) {
            ctx->pc = 0x1869D8u;
            goto label_1869d8;
        }
    }
    ctx->pc = 0x1869C8u;
label_1869c8:
    // 0x1869c8: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x1869c8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x1869cc: 0x10000025  b           . + 4 + (0x25 << 2)
    ctx->pc = 0x1869CCu;
    {
        const bool branch_taken_0x1869cc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1869D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1869CCu;
            // 0x1869d0: 0x3442005b  ori         $v0, $v0, 0x5B (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)91);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1869cc) {
            ctx->pc = 0x186A64u;
            goto label_186a64;
        }
    }
    ctx->pc = 0x1869D4u;
    // 0x1869d4: 0x0  nop
    ctx->pc = 0x1869d4u;
    // NOP
label_1869d8:
    // 0x1869d8: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1869d8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1869dc: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x1869dcu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1869e0: 0x27a70300  addiu       $a3, $sp, 0x300
    ctx->pc = 0x1869e0u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 768));
    // 0x1869e4: 0xc0610d8  jal         func_184360
    ctx->pc = 0x1869E4u;
    SET_GPR_U32(ctx, 31, 0x1869ECu);
    ctx->pc = 0x1869E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1869E4u;
            // 0x1869e8: 0x27a80304  addiu       $t0, $sp, 0x304 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 29), 772));
        ctx->in_delay_slot = false;
    ctx->pc = 0x184360u;
    if (runtime->hasFunction(0x184360u)) {
        auto targetFn = runtime->lookupFunction(0x184360u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1869ECu; }
        if (ctx->pc != 0x1869ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00184360_0x184360(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1869ECu; }
        if (ctx->pc != 0x1869ECu) { return; }
    }
    ctx->pc = 0x1869ECu;
label_1869ec:
    // 0x1869ec: 0x3c038101  lui         $v1, 0x8101
    ctx->pc = 0x1869ecu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33025 << 16));
    // 0x1869f0: 0x34630002  ori         $v1, $v1, 0x2
    ctx->pc = 0x1869f0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)2);
    // 0x1869f4: 0x1443001c  bne         $v0, $v1, . + 4 + (0x1C << 2)
    ctx->pc = 0x1869F4u;
    {
        const bool branch_taken_0x1869f4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x1869F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1869F4u;
            // 0x1869f8: 0xdfb00310  ld          $s0, 0x310($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 784)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1869f4) {
            ctx->pc = 0x186A68u;
            goto label_186a68;
        }
    }
    ctx->pc = 0x1869FCu;
    // 0x1869fc: 0x280282d  daddu       $a1, $s4, $zero
    ctx->pc = 0x1869fcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x186a00: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x186a00u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x186a04: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x186a04u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x186a08: 0x27a70300  addiu       $a3, $sp, 0x300
    ctx->pc = 0x186a08u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 768));
    // 0x186a0c: 0xc0610d8  jal         func_184360
    ctx->pc = 0x186A0Cu;
    SET_GPR_U32(ctx, 31, 0x186A14u);
    ctx->pc = 0x186A10u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x186A0Cu;
            // 0x186a10: 0x27a80304  addiu       $t0, $sp, 0x304 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 29), 772));
        ctx->in_delay_slot = false;
    ctx->pc = 0x184360u;
    if (runtime->hasFunction(0x184360u)) {
        auto targetFn = runtime->lookupFunction(0x184360u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x186A14u; }
        if (ctx->pc != 0x186A14u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00184360_0x184360(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x186A14u; }
        if (ctx->pc != 0x186A14u) { return; }
    }
    ctx->pc = 0x186A14u;
label_186a14:
    // 0x186a14: 0x3c038101  lui         $v1, 0x8101
    ctx->pc = 0x186a14u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33025 << 16));
    // 0x186a18: 0x34630011  ori         $v1, $v1, 0x11
    ctx->pc = 0x186a18u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)17);
    // 0x186a1c: 0x14430012  bne         $v0, $v1, . + 4 + (0x12 << 2)
    ctx->pc = 0x186A1Cu;
    {
        const bool branch_taken_0x186a1c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x186A20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x186A1Cu;
            // 0x186a20: 0xdfb00310  ld          $s0, 0x310($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 784)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x186a1c) {
            ctx->pc = 0x186A68u;
            goto label_186a68;
        }
    }
    ctx->pc = 0x186A24u;
    // 0x186a24: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x186a24u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x186a28: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x186A28u;
    SET_GPR_U32(ctx, 31, 0x186A30u);
    ctx->pc = 0x186A2Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x186A28u;
            // 0x186a2c: 0x27a40040  addiu       $a0, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x186A30u; }
        if (ctx->pc != 0x186A30u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x186A30u; }
        if (ctx->pc != 0x186A30u) { return; }
    }
    ctx->pc = 0x186A30u;
label_186a30:
    // 0x186a30: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x186a30u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x186a34: 0x8fa60300  lw          $a2, 0x300($sp)
    ctx->pc = 0x186a34u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 768)));
    // 0x186a38: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x186a38u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x186a3c: 0xc0612a8  jal         func_184AA0
    ctx->pc = 0x186A3Cu;
    SET_GPR_U32(ctx, 31, 0x186A44u);
    ctx->pc = 0x186A40u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x186A3Cu;
            // 0x186a40: 0x8fa70304  lw          $a3, 0x304($sp) (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 772)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x184AA0u;
    if (runtime->hasFunction(0x184AA0u)) {
        auto targetFn = runtime->lookupFunction(0x184AA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x186A44u; }
        if (ctx->pc != 0x186A44u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00184AA0_0x184aa0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x186A44u; }
        if (ctx->pc != 0x186A44u) { return; }
    }
    ctx->pc = 0x186A44u;
label_186a44:
    // 0x186a44: 0x14400008  bnez        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x186A44u;
    {
        const bool branch_taken_0x186a44 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x186A48u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x186A44u;
            // 0x186a48: 0xdfb00310  ld          $s0, 0x310($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 784)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x186a44) {
            ctx->pc = 0x186A68u;
            goto label_186a68;
        }
    }
    ctx->pc = 0x186A4Cu;
    // 0x186a4c: 0xc061bbc  jal         func_186EF0
    ctx->pc = 0x186A4Cu;
    SET_GPR_U32(ctx, 31, 0x186A54u);
    ctx->pc = 0x186A50u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x186A4Cu;
            // 0x186a50: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x186EF0u;
    if (runtime->hasFunction(0x186EF0u)) {
        auto targetFn = runtime->lookupFunction(0x186EF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x186A54u; }
        if (ctx->pc != 0x186A54u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00186EF0_0x186ef0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x186A54u; }
        if (ctx->pc != 0x186A54u) { return; }
    }
    ctx->pc = 0x186A54u;
label_186a54:
    // 0x186a54: 0x3c038101  lui         $v1, 0x8101
    ctx->pc = 0x186a54u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33025 << 16));
    // 0x186a58: 0x3463006f  ori         $v1, $v1, 0x6F
    ctx->pc = 0x186a58u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)111);
    // 0x186a5c: 0x2180b  movn        $v1, $zero, $v0
    ctx->pc = 0x186a5cu;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 3, GPR_VEC(ctx, 0));
    // 0x186a60: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x186a60u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
label_186a64:
    // 0x186a64: 0xdfb00310  ld          $s0, 0x310($sp)
    ctx->pc = 0x186a64u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 784)));
label_186a68:
    // 0x186a68: 0xdfb10318  ld          $s1, 0x318($sp)
    ctx->pc = 0x186a68u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 792)));
    // 0x186a6c: 0xdfb20320  ld          $s2, 0x320($sp)
    ctx->pc = 0x186a6cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 800)));
    // 0x186a70: 0xdfb30328  ld          $s3, 0x328($sp)
    ctx->pc = 0x186a70u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 808)));
    // 0x186a74: 0xdfb40330  ld          $s4, 0x330($sp)
    ctx->pc = 0x186a74u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 816)));
    // 0x186a78: 0xdfbf0338  ld          $ra, 0x338($sp)
    ctx->pc = 0x186a78u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 824)));
    // 0x186a7c: 0x3e00008  jr          $ra
    ctx->pc = 0x186A7Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x186A80u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x186A7Cu;
            // 0x186a80: 0x27bd0340  addiu       $sp, $sp, 0x340 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 832));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1868F4u: goto label_1868f4;
            case 0x186908u: goto label_186908;
            case 0x186938u: goto label_186938;
            case 0x18694Cu: goto label_18694c;
            case 0x186960u: goto label_186960;
            case 0x18696Cu: goto label_18696c;
            case 0x186978u: goto label_186978;
            case 0x186980u: goto label_186980;
            case 0x186990u: goto label_186990;
            case 0x186998u: goto label_186998;
            case 0x1869A8u: goto label_1869a8;
            case 0x1869B0u: goto label_1869b0;
            case 0x1869C0u: goto label_1869c0;
            case 0x1869C8u: goto label_1869c8;
            case 0x1869D8u: goto label_1869d8;
            case 0x1869ECu: goto label_1869ec;
            case 0x186A14u: goto label_186a14;
            case 0x186A30u: goto label_186a30;
            case 0x186A44u: goto label_186a44;
            case 0x186A54u: goto label_186a54;
            case 0x186A64u: goto label_186a64;
            case 0x186A68u: goto label_186a68;
            default: break;
        }
        return;
    }
    ctx->pc = 0x186A84u;
    // 0x186a84: 0x0  nop
    ctx->pc = 0x186a84u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
