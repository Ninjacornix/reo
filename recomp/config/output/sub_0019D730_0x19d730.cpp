#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0019D730
// Address: 0x19d730 - 0x19d910
void sub_0019D730_0x19d730(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0019D730_0x19d730");
#endif

    switch (ctx->pc) {
        case 0x19d774u: goto label_19d774;
        case 0x19d7ccu: goto label_19d7cc;
        case 0x19d818u: goto label_19d818;
        case 0x19d830u: goto label_19d830;
        case 0x19d838u: goto label_19d838;
        case 0x19d848u: goto label_19d848;
        case 0x19d860u: goto label_19d860;
        case 0x19d86cu: goto label_19d86c;
        case 0x19d8a4u: goto label_19d8a4;
        case 0x19d8b0u: goto label_19d8b0;
        case 0x19d8c0u: goto label_19d8c0;
        case 0x19d8dcu: goto label_19d8dc;
        default: break;
    }

    ctx->pc = 0x19d730u;

    // 0x19d730: 0x27bdff50  addiu       $sp, $sp, -0xB0
    ctx->pc = 0x19d730u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967120));
    // 0x19d734: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x19d734u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19d738: 0xffbf0090  sd          $ra, 0x90($sp)
    ctx->pc = 0x19d738u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 31));
    // 0x19d73c: 0x7fbe0080  sq          $fp, 0x80($sp)
    ctx->pc = 0x19d73cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 128), GPR_VEC(ctx, 30));
    // 0x19d740: 0x7fb70070  sq          $s7, 0x70($sp)
    ctx->pc = 0x19d740u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 112), GPR_VEC(ctx, 23));
    // 0x19d744: 0x7fb60060  sq          $s6, 0x60($sp)
    ctx->pc = 0x19d744u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 96), GPR_VEC(ctx, 22));
    // 0x19d748: 0xa0b82d  daddu       $s7, $a1, $zero
    ctx->pc = 0x19d748u;
    SET_GPR_U64(ctx, 23, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19d74c: 0x7fb50050  sq          $s5, 0x50($sp)
    ctx->pc = 0x19d74cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 80), GPR_VEC(ctx, 21));
    // 0x19d750: 0x80b02d  daddu       $s6, $a0, $zero
    ctx->pc = 0x19d750u;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19d754: 0x7fb40040  sq          $s4, 0x40($sp)
    ctx->pc = 0x19d754u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 20));
    // 0x19d758: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x19d758u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x19d75c: 0xa02d  daddu       $s4, $zero, $zero
    ctx->pc = 0x19d75cu;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19d760: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x19d760u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x19d764: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x19d764u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x19d768: 0x902d  daddu       $s2, $zero, $zero
    ctx->pc = 0x19d768u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19d76c: 0x10000046  b           . + 4 + (0x46 << 2)
    ctx->pc = 0x19D76Cu;
    {
        const bool branch_taken_0x19d76c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19D770u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19D76Cu;
            // 0x19d770: 0x7fb00000  sq          $s0, 0x0($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19d76c) {
            ctx->pc = 0x19D888u;
            goto label_19d888;
        }
    }
    ctx->pc = 0x19D774u;
label_19d774:
    // 0x19d774: 0x3c06002a  lui         $a2, 0x2A
    ctx->pc = 0x19d774u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)42 << 16));
    // 0x19d778: 0x2e31821  addu        $v1, $s7, $v1
    ctx->pc = 0x19d778u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 23), GPR_U32(ctx, 3)));
    // 0x19d77c: 0x3c04ffff  lui         $a0, 0xFFFF
    ctx->pc = 0x19d77cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)65535 << 16));
    // 0x19d780: 0x8c650000  lw          $a1, 0x0($v1)
    ctx->pc = 0x19d780u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x19d784: 0x24c68680  addiu       $a2, $a2, -0x7980
    ctx->pc = 0x19d784u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294936192));
    // 0x19d788: 0x982d  daddu       $s3, $zero, $zero
    ctx->pc = 0x19d788u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19d78c: 0xa42024  and         $a0, $a1, $a0
    ctx->pc = 0x19d78cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 5) & GPR_U64(ctx, 4));
    // 0x19d790: 0x30b1ffff  andi        $s1, $a1, 0xFFFF
    ctx->pc = 0x19d790u;
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)65535);
    // 0x19d794: 0x48402  srl         $s0, $a0, 16
    ctx->pc = 0x19d794u;
    SET_GPR_S32(ctx, 16, (int32_t)SRL32(GPR_U32(ctx, 4), 16));
    // 0x19d798: 0x2627ffff  addiu       $a3, $s1, -0x1
    ctx->pc = 0x19d798u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967295));
    // 0x19d79c: 0x720c0  sll         $a0, $a3, 3
    ctx->pc = 0x19d79cu;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 7), 3));
    // 0x19d7a0: 0x3c030029  lui         $v1, 0x29
    ctx->pc = 0x19d7a0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)41 << 16));
    // 0x19d7a4: 0x2605ffff  addiu       $a1, $s0, -0x1
    ctx->pc = 0x19d7a4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), 4294967295));
    // 0x19d7a8: 0x873823  subu        $a3, $a0, $a3
    ctx->pc = 0x19d7a8u;
    SET_GPR_S32(ctx, 7, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 7)));
    // 0x19d7ac: 0x520c0  sll         $a0, $a1, 3
    ctx->pc = 0x19d7acu;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x19d7b0: 0x24634e80  addiu       $v1, $v1, 0x4E80
    ctx->pc = 0x19d7b0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 20096));
    // 0x19d7b4: 0x852023  subu        $a0, $a0, $a1
    ctx->pc = 0x19d7b4u;
    SET_GPR_S32(ctx, 4, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 5)));
    // 0x19d7b8: 0x420c0  sll         $a0, $a0, 3
    ctx->pc = 0x19d7b8u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 3));
    // 0x19d7bc: 0x728c0  sll         $a1, $a3, 3
    ctx->pc = 0x19d7bcu;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 7), 3));
    // 0x19d7c0: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x19d7c0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x19d7c4: 0xc5f021  addu        $fp, $a2, $a1
    ctx->pc = 0x19d7c4u;
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 5)));
    // 0x19d7c8: 0xafa300a0  sw          $v1, 0xA0($sp)
    ctx->pc = 0x19d7c8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 160), GPR_U32(ctx, 3));
label_19d7cc:
    // 0x19d7cc: 0x16600007  bnez        $s3, . + 4 + (0x7 << 2)
    ctx->pc = 0x19D7CCu;
    {
        const bool branch_taken_0x19d7cc = (GPR_U64(ctx, 19) != GPR_U64(ctx, 0));
        if (branch_taken_0x19d7cc) {
            ctx->pc = 0x19D7ECu;
            goto label_19d7ec;
        }
    }
    ctx->pc = 0x19D7D4u;
    // 0x19d7d4: 0x12200027  beqz        $s1, . + 4 + (0x27 << 2)
    ctx->pc = 0x19D7D4u;
    {
        const bool branch_taken_0x19d7d4 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x19D7D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19D7D4u;
            // 0x19d7d8: 0x2e210100  sltiu       $at, $s1, 0x100 (Delay Slot)
        SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 17) < (uint64_t)(int64_t)(int32_t)256) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x19d7d4) {
            ctx->pc = 0x19D874u;
            goto label_19d874;
        }
    }
    ctx->pc = 0x19D7DCu;
    // 0x19d7dc: 0x10200025  beqz        $at, . + 4 + (0x25 << 2)
    ctx->pc = 0x19D7DCu;
    {
        const bool branch_taken_0x19d7dc = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x19D7E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19D7DCu;
            // 0x19d7e0: 0x3c0a82d  daddu       $s5, $fp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19d7dc) {
            ctx->pc = 0x19D874u;
            goto label_19d874;
        }
    }
    ctx->pc = 0x19D7E4u;
    // 0x19d7e4: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x19D7E4u;
    {
        const bool branch_taken_0x19d7e4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19D7E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19D7E4u;
            // 0x19d7e8: 0x82a30035  lb          $v1, 0x35($s5) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 21), 53)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19d7e4) {
            ctx->pc = 0x19D804u;
            goto label_19d804;
        }
    }
    ctx->pc = 0x19D7ECu;
label_19d7ec:
    // 0x19d7ec: 0x12000021  beqz        $s0, . + 4 + (0x21 << 2)
    ctx->pc = 0x19D7ECu;
    {
        const bool branch_taken_0x19d7ec = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x19D7F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19D7ECu;
            // 0x19d7f0: 0x2e010100  sltiu       $at, $s0, 0x100 (Delay Slot)
        SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 16) < (uint64_t)(int64_t)(int32_t)256) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x19d7ec) {
            ctx->pc = 0x19D874u;
            goto label_19d874;
        }
    }
    ctx->pc = 0x19D7F4u;
    // 0x19d7f4: 0x1020001f  beqz        $at, . + 4 + (0x1F << 2)
    ctx->pc = 0x19D7F4u;
    {
        const bool branch_taken_0x19d7f4 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        if (branch_taken_0x19d7f4) {
            ctx->pc = 0x19D874u;
            goto label_19d874;
        }
    }
    ctx->pc = 0x19D7FCu;
    // 0x19d7fc: 0x8fb500a0  lw          $s5, 0xA0($sp)
    ctx->pc = 0x19d7fcu;
    SET_GPR_S32(ctx, 21, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 160)));
    // 0x19d800: 0x82a30035  lb          $v1, 0x35($s5)
    ctx->pc = 0x19d800u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 21), 53)));
label_19d804:
    // 0x19d804: 0x1460001b  bnez        $v1, . + 4 + (0x1B << 2)
    ctx->pc = 0x19D804u;
    {
        const bool branch_taken_0x19d804 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x19d804) {
            ctx->pc = 0x19D874u;
            goto label_19d874;
        }
    }
    ctx->pc = 0x19D80Cu;
    // 0x19d80c: 0x86a50012  lh          $a1, 0x12($s5)
    ctx->pc = 0x19d80cu;
    SET_GPR_S32(ctx, 5, (int16_t)READ16(ADD32(GPR_U32(ctx, 21), 18)));
    // 0x19d810: 0xc067c10  jal         func_19F040
    ctx->pc = 0x19D810u;
    SET_GPR_U32(ctx, 31, 0x19D818u);
    ctx->pc = 0x19D814u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19D810u;
            // 0x19d814: 0x86a40010  lh          $a0, 0x10($s5) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 21), 16)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x19F040u;
    if (runtime->hasFunction(0x19F040u)) {
        auto targetFn = runtime->lookupFunction(0x19F040u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19D818u; }
        if (ctx->pc != 0x19D818u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0019F040_0x19f040(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19D818u; }
        if (ctx->pc != 0x19D818u) { return; }
    }
    ctx->pc = 0x19D818u;
label_19d818:
    // 0x19d818: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x19d818u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x19d81c: 0x10430007  beq         $v0, $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x19D81Cu;
    {
        const bool branch_taken_0x19d81c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x19D820u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19D81Cu;
            // 0x19d820: 0x2a0202d  daddu       $a0, $s5, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19d81c) {
            ctx->pc = 0x19D83Cu;
            goto label_19d83c;
        }
    }
    ctx->pc = 0x19D824u;
    // 0x19d824: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x19d824u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19d828: 0xc067b24  jal         func_19EC90
    ctx->pc = 0x19D828u;
    SET_GPR_U32(ctx, 31, 0x19D830u);
    ctx->pc = 0x19D82Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19D828u;
            // 0x19d82c: 0x2a0282d  daddu       $a1, $s5, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x19EC90u;
    if (runtime->hasFunction(0x19EC90u)) {
        auto targetFn = runtime->lookupFunction(0x19EC90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19D830u; }
        if (ctx->pc != 0x19D830u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0019EC90_0x19ec90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19D830u; }
        if (ctx->pc != 0x19D830u) { return; }
    }
    ctx->pc = 0x19D830u;
label_19d830:
    // 0x19d830: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x19D830u;
    {
        const bool branch_taken_0x19d830 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19D834u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19D830u;
            // 0x19d834: 0x2a0202d  daddu       $a0, $s5, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19d830) {
            ctx->pc = 0x19D864u;
            goto label_19d864;
        }
    }
    ctx->pc = 0x19D838u;
label_19d838:
    // 0x19d838: 0x2a0202d  daddu       $a0, $s5, $zero
    ctx->pc = 0x19d838u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
label_19d83c:
    // 0x19d83c: 0x2e0282d  daddu       $a1, $s7, $zero
    ctx->pc = 0x19d83cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19d840: 0xc067c44  jal         func_19F110
    ctx->pc = 0x19D840u;
    SET_GPR_U32(ctx, 31, 0x19D848u);
    ctx->pc = 0x19D844u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19D840u;
            // 0x19d844: 0x2c0302d  daddu       $a2, $s6, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x19F110u;
    if (runtime->hasFunction(0x19F110u)) {
        auto targetFn = runtime->lookupFunction(0x19F110u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19D848u; }
        if (ctx->pc != 0x19D848u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0019F110_0x19f110(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19D848u; }
        if (ctx->pc != 0x19D848u) { return; }
    }
    ctx->pc = 0x19D848u;
label_19d848:
    // 0x19d848: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x19d848u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x19d84c: 0x1043fffa  beq         $v0, $v1, . + 4 + (-0x6 << 2)
    ctx->pc = 0x19D84Cu;
    {
        const bool branch_taken_0x19d84c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x19d84c) {
            ctx->pc = 0x19D838u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_19d838;
        }
    }
    ctx->pc = 0x19D854u;
    // 0x19d854: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x19d854u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19d858: 0xc067b64  jal         func_19ED90
    ctx->pc = 0x19D858u;
    SET_GPR_U32(ctx, 31, 0x19D860u);
    ctx->pc = 0x19D85Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19D858u;
            // 0x19d85c: 0x2a0282d  daddu       $a1, $s5, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x19ED90u;
    if (runtime->hasFunction(0x19ED90u)) {
        auto targetFn = runtime->lookupFunction(0x19ED90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19D860u; }
        if (ctx->pc != 0x19D860u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0019ED90_0x19ed90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19D860u; }
        if (ctx->pc != 0x19D860u) { return; }
    }
    ctx->pc = 0x19D860u;
label_19d860:
    // 0x19d860: 0x2a0202d  daddu       $a0, $s5, $zero
    ctx->pc = 0x19d860u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
label_19d864:
    // 0x19d864: 0xc067390  jal         func_19CE40
    ctx->pc = 0x19D864u;
    SET_GPR_U32(ctx, 31, 0x19D86Cu);
    ctx->pc = 0x19CE40u;
    if (runtime->hasFunction(0x19CE40u)) {
        auto targetFn = runtime->lookupFunction(0x19CE40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19D86Cu; }
        if (ctx->pc != 0x19D86Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0019CE40_0x19ce40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19D86Cu; }
        if (ctx->pc != 0x19D86Cu) { return; }
    }
    ctx->pc = 0x19D86Cu;
label_19d86c:
    // 0x19d86c: 0x2a0102d  daddu       $v0, $s5, $zero
    ctx->pc = 0x19d86cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19d870: 0x26520001  addiu       $s2, $s2, 0x1
    ctx->pc = 0x19d870u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
label_19d874:
    // 0x19d874: 0x26730001  addiu       $s3, $s3, 0x1
    ctx->pc = 0x19d874u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
    // 0x19d878: 0x2a630002  slti        $v1, $s3, 0x2
    ctx->pc = 0x19d878u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0x19d87c: 0x1460ffd3  bnez        $v1, . + 4 + (-0x2D << 2)
    ctx->pc = 0x19D87Cu;
    {
        const bool branch_taken_0x19d87c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x19d87c) {
            ctx->pc = 0x19D7CCu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_19d7cc;
        }
    }
    ctx->pc = 0x19D884u;
    // 0x19d884: 0x26940001  addiu       $s4, $s4, 0x1
    ctx->pc = 0x19d884u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 20), 1));
label_19d888:
    // 0x19d888: 0x296182a  slt         $v1, $s4, $s6
    ctx->pc = 0x19d888u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 20) < (int64_t)GPR_S64(ctx, 22)) ? 1 : 0);
    // 0x19d88c: 0x1460ffb9  bnez        $v1, . + 4 + (-0x47 << 2)
    ctx->pc = 0x19D88Cu;
    {
        const bool branch_taken_0x19d88c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x19D890u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19D88Cu;
            // 0x19d890: 0x141880  sll         $v1, $s4, 2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 20), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19d88c) {
            ctx->pc = 0x19D774u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_19d774;
        }
    }
    ctx->pc = 0x19D894u;
    // 0x19d894: 0x10400011  beqz        $v0, . + 4 + (0x11 << 2)
    ctx->pc = 0x19D894u;
    {
        const bool branch_taken_0x19d894 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x19D898u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19D894u;
            // 0x19d898: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19d894) {
            ctx->pc = 0x19D8DCu;
            goto label_19d8dc;
        }
    }
    ctx->pc = 0x19D89Cu;
    // 0x19d89c: 0xc06322c  jal         func_18C8B0
    ctx->pc = 0x19D89Cu;
    SET_GPR_U32(ctx, 31, 0x19D8A4u);
    ctx->pc = 0x18C8B0u;
    if (runtime->hasFunction(0x18C8B0u)) {
        auto targetFn = runtime->lookupFunction(0x18C8B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19D8A4u; }
        if (ctx->pc != 0x19D8A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018C8B0_0x18c8b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19D8A4u; }
        if (ctx->pc != 0x19D8A4u) { return; }
    }
    ctx->pc = 0x19D8A4u;
label_19d8a4:
    // 0x19d8a4: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x19d8a4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19d8a8: 0xc063774  jal         func_18DDD0
    ctx->pc = 0x19D8A8u;
    SET_GPR_U32(ctx, 31, 0x19D8B0u);
    ctx->pc = 0x19D8ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19D8A8u;
            // 0x19d8ac: 0x24050010  addiu       $a1, $zero, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18DDD0u;
    if (runtime->hasFunction(0x18DDD0u)) {
        auto targetFn = runtime->lookupFunction(0x18DDD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19D8B0u; }
        if (ctx->pc != 0x19D8B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DDD0_0x18ddd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19D8B0u; }
        if (ctx->pc != 0x19D8B0u) { return; }
    }
    ctx->pc = 0x19D8B0u;
label_19d8b0:
    // 0x19d8b0: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x19d8b0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19d8b4: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x19d8b4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x19d8b8: 0xc063340  jal         func_18CD00
    ctx->pc = 0x19D8B8u;
    SET_GPR_U32(ctx, 31, 0x19D8C0u);
    ctx->pc = 0x19D8BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19D8B8u;
            // 0x19d8bc: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18CD00u;
    if (runtime->hasFunction(0x18CD00u)) {
        auto targetFn = runtime->lookupFunction(0x18CD00u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19D8C0u; }
        if (ctx->pc != 0x19D8C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018CD00_0x18cd00(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19D8C0u; }
        if (ctx->pc != 0x19D8C0u) { return; }
    }
    ctx->pc = 0x19D8C0u;
label_19d8c0:
    // 0x19d8c0: 0x10293c  dsll32      $a1, $s0, 4
    ctx->pc = 0x19d8c0u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 16) << (32 + 4));
    // 0x19d8c4: 0x3c07002a  lui         $a3, 0x2A
    ctx->pc = 0x19d8c4u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)42 << 16));
    // 0x19d8c8: 0x5293e  dsrl32      $a1, $a1, 4
    ctx->pc = 0x19d8c8u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) >> (32 + 4));
    // 0x19d8cc: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x19d8ccu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19d8d0: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x19d8d0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19d8d4: 0xc0633ec  jal         func_18CFB0
    ctx->pc = 0x19D8D4u;
    SET_GPR_U32(ctx, 31, 0x19D8DCu);
    ctx->pc = 0x19D8D8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19D8D4u;
            // 0x19d8d8: 0x24e7f6f0  addiu       $a3, $a3, -0x910 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4294964976));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18CFB0u;
    if (runtime->hasFunction(0x18CFB0u)) {
        auto targetFn = runtime->lookupFunction(0x18CFB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19D8DCu; }
        if (ctx->pc != 0x19D8DCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018CFB0_0x18cfb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19D8DCu; }
        if (ctx->pc != 0x19D8DCu) { return; }
    }
    ctx->pc = 0x19D8DCu;
label_19d8dc:
    // 0x19d8dc: 0x240102d  daddu       $v0, $s2, $zero
    ctx->pc = 0x19d8dcu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19d8e0: 0xdfbf0090  ld          $ra, 0x90($sp)
    ctx->pc = 0x19d8e0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 144)));
    // 0x19d8e4: 0x7bbe0080  lq          $fp, 0x80($sp)
    ctx->pc = 0x19d8e4u;
    SET_GPR_VEC(ctx, 30, READ128(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x19d8e8: 0x7bb70070  lq          $s7, 0x70($sp)
    ctx->pc = 0x19d8e8u;
    SET_GPR_VEC(ctx, 23, READ128(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x19d8ec: 0x7bb60060  lq          $s6, 0x60($sp)
    ctx->pc = 0x19d8ecu;
    SET_GPR_VEC(ctx, 22, READ128(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x19d8f0: 0x7bb50050  lq          $s5, 0x50($sp)
    ctx->pc = 0x19d8f0u;
    SET_GPR_VEC(ctx, 21, READ128(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x19d8f4: 0x7bb40040  lq          $s4, 0x40($sp)
    ctx->pc = 0x19d8f4u;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x19d8f8: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x19d8f8u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x19d8fc: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x19d8fcu;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x19d900: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x19d900u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x19d904: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x19d904u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x19d908: 0x3e00008  jr          $ra
    ctx->pc = 0x19D908u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x19D90Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19D908u;
            // 0x19d90c: 0x27bd00b0  addiu       $sp, $sp, 0xB0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 176));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x19D774u: goto label_19d774;
            case 0x19D7CCu: goto label_19d7cc;
            case 0x19D7ECu: goto label_19d7ec;
            case 0x19D804u: goto label_19d804;
            case 0x19D818u: goto label_19d818;
            case 0x19D830u: goto label_19d830;
            case 0x19D838u: goto label_19d838;
            case 0x19D83Cu: goto label_19d83c;
            case 0x19D848u: goto label_19d848;
            case 0x19D860u: goto label_19d860;
            case 0x19D864u: goto label_19d864;
            case 0x19D86Cu: goto label_19d86c;
            case 0x19D874u: goto label_19d874;
            case 0x19D888u: goto label_19d888;
            case 0x19D8A4u: goto label_19d8a4;
            case 0x19D8B0u: goto label_19d8b0;
            case 0x19D8C0u: goto label_19d8c0;
            case 0x19D8DCu: goto label_19d8dc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x19D910u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
