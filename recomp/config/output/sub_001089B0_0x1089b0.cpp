#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001089B0
// Address: 0x1089b0 - 0x108b48
void sub_001089B0_0x1089b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001089B0_0x1089b0");
#endif

    switch (ctx->pc) {
        case 0x1089f0u: goto label_1089f0;
        default: break;
    }

    ctx->pc = 0x1089b0u;

    // 0x1089b0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1089b0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1089b4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1089b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1089b8: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x1089b8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1089bc: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x1089bcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x1089c0: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x1089c0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x1089c4: 0x24940014  addiu       $s4, $a0, 0x14
    ctx->pc = 0x1089c4u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 4), 20));
    // 0x1089c8: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1089c8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1089cc: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x1089ccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x1089d0: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x1089d0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x1089d4: 0x8c820010  lw          $v0, 0x10($a0)
    ctx->pc = 0x1089d4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 16)));
    // 0x1089d8: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1089d8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1089dc: 0x2829021  addu        $s2, $s4, $v0
    ctx->pc = 0x1089dcu;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 2)));
    // 0x1089e0: 0x2652fffc  addiu       $s2, $s2, -0x4
    ctx->pc = 0x1089e0u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 4294967292));
    // 0x1089e4: 0x8e530000  lw          $s3, 0x0($s2)
    ctx->pc = 0x1089e4u;
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x1089e8: 0xc042042  jal         func_108108
    ctx->pc = 0x1089E8u;
    SET_GPR_U32(ctx, 31, 0x1089F0u);
    ctx->pc = 0x1089ECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1089E8u;
            // 0x1089ec: 0x260202d  daddu       $a0, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x108108u;
    if (runtime->hasFunction(0x108108u)) {
        auto targetFn = runtime->lookupFunction(0x108108u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1089F0u; }
        if (ctx->pc != 0x1089F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00108108_0x108108(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1089F0u; }
        if (ctx->pc != 0x1089F0u) { return; }
    }
    ctx->pc = 0x1089F0u;
label_1089f0:
    // 0x1089f0: 0x40302d  daddu       $a2, $v0, $zero
    ctx->pc = 0x1089f0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1089f4: 0x24020020  addiu       $v0, $zero, 0x20
    ctx->pc = 0x1089f4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x1089f8: 0x461023  subu        $v0, $v0, $a2
    ctx->pc = 0x1089f8u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 6)));
    // 0x1089fc: 0x28c3000b  slti        $v1, $a2, 0xB
    ctx->pc = 0x1089fcu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 6) < (int64_t)(int32_t)11) ? 1 : 0);
    // 0x108a00: 0x1060001b  beqz        $v1, . + 4 + (0x1B << 2)
    ctx->pc = 0x108A00u;
    {
        const bool branch_taken_0x108a00 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x108A04u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x108A00u;
            // 0x108a04: 0xae020000  sw          $v0, 0x0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x108a00) {
            ctx->pc = 0x108A70u;
            goto label_108a70;
        }
    }
    ctx->pc = 0x108A08u;
    // 0x108a08: 0x2402000b  addiu       $v0, $zero, 0xB
    ctx->pc = 0x108a08u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 11));
    // 0x108a0c: 0x3c043ff0  lui         $a0, 0x3FF0
    ctx->pc = 0x108a0cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)16368 << 16));
    // 0x108a10: 0x461023  subu        $v0, $v0, $a2
    ctx->pc = 0x108a10u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 6)));
    // 0x108a14: 0x3c03ffff  lui         $v1, 0xFFFF
    ctx->pc = 0x108a14u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)65535 << 16));
    // 0x108a18: 0x3183e  dsrl32      $v1, $v1, 0
    ctx->pc = 0x108a18u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) >> (32 + 0));
    // 0x108a1c: 0x531006  srlv        $v0, $s3, $v0
    ctx->pc = 0x108a1cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 19), GPR_U32(ctx, 2) & 0x1F));
    // 0x108a20: 0x2238824  and         $s1, $s1, $v1
    ctx->pc = 0x108a20u;
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 17) & GPR_U64(ctx, 3));
    // 0x108a24: 0x441025  or          $v0, $v0, $a0
    ctx->pc = 0x108a24u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 4));
    // 0x108a28: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x108a28u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x108a2c: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x108a2cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x108a30: 0x292182b  sltu        $v1, $s4, $s2
    ctx->pc = 0x108a30u;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 20) < (uint64_t)GPR_U64(ctx, 18)) ? 1 : 0);
    // 0x108a34: 0x10600002  beqz        $v1, . + 4 + (0x2 << 2)
    ctx->pc = 0x108A34u;
    {
        const bool branch_taken_0x108a34 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x108A38u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x108A34u;
            // 0x108a38: 0x2228825  or          $s1, $s1, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 17, GPR_U64(ctx, 17) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x108a34) {
            ctx->pc = 0x108A40u;
            goto label_108a40;
        }
    }
    ctx->pc = 0x108A3Cu;
    // 0x108a3c: 0x8e44fffc  lw          $a0, -0x4($s2)
    ctx->pc = 0x108a3cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 4294967292)));
label_108a40:
    // 0x108a40: 0x2402000b  addiu       $v0, $zero, 0xB
    ctx->pc = 0x108a40u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 11));
    // 0x108a44: 0x24c30015  addiu       $v1, $a2, 0x15
    ctx->pc = 0x108a44u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), 21));
    // 0x108a48: 0x461023  subu        $v0, $v0, $a2
    ctx->pc = 0x108a48u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 6)));
    // 0x108a4c: 0x731804  sllv        $v1, $s3, $v1
    ctx->pc = 0x108a4cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 19), GPR_U32(ctx, 3) & 0x1F));
    // 0x108a50: 0x441006  srlv        $v0, $a0, $v0
    ctx->pc = 0x108a50u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 4), GPR_U32(ctx, 2) & 0x1F));
    // 0x108a54: 0x2404ffff  addiu       $a0, $zero, -0x1
    ctx->pc = 0x108a54u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x108a58: 0x4203c  dsll32      $a0, $a0, 0
    ctx->pc = 0x108a58u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) << (32 + 0));
    // 0x108a5c: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x108a5cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x108a60: 0x2248824  and         $s1, $s1, $a0
    ctx->pc = 0x108a60u;
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 17) & GPR_U64(ctx, 4));
    // 0x108a64: 0x3183c  dsll32      $v1, $v1, 0
    ctx->pc = 0x108a64u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 0));
    // 0x108a68: 0x1000002d  b           . + 4 + (0x2D << 2)
    ctx->pc = 0x108A68u;
    {
        const bool branch_taken_0x108a68 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x108A6Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x108A68u;
            // 0x108a6c: 0x3183e  dsrl32      $v1, $v1, 0 (Delay Slot)
        SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) >> (32 + 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x108a68) {
            ctx->pc = 0x108B20u;
            goto label_108b20;
        }
    }
    ctx->pc = 0x108A70u;
label_108a70:
    // 0x108a70: 0x292102b  sltu        $v0, $s4, $s2
    ctx->pc = 0x108a70u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 20) < (uint64_t)GPR_U64(ctx, 18)) ? 1 : 0);
    // 0x108a74: 0x50400003  beql        $v0, $zero, . + 4 + (0x3 << 2)
    ctx->pc = 0x108A74u;
    {
        const bool branch_taken_0x108a74 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x108a74) {
            ctx->pc = 0x108A78u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x108A74u;
            // 0x108a78: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x108A84u;
            goto label_108a84;
        }
    }
    ctx->pc = 0x108A7Cu;
    // 0x108a7c: 0x2652fffc  addiu       $s2, $s2, -0x4
    ctx->pc = 0x108a7cu;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 4294967292));
    // 0x108a80: 0x8e470000  lw          $a3, 0x0($s2)
    ctx->pc = 0x108a80u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
label_108a84:
    // 0x108a84: 0x24c6fff5  addiu       $a2, $a2, -0xB
    ctx->pc = 0x108a84u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967285));
    // 0x108a88: 0x10c00019  beqz        $a2, . + 4 + (0x19 << 2)
    ctx->pc = 0x108A88u;
    {
        const bool branch_taken_0x108a88 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        ctx->pc = 0x108A8Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x108A88u;
            // 0x108a8c: 0x61823  negu        $v1, $a2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 0), GPR_U32(ctx, 6)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x108a88) {
            ctx->pc = 0x108AF0u;
            goto label_108af0;
        }
    }
    ctx->pc = 0x108A90u;
    // 0x108a90: 0xd31004  sllv        $v0, $s3, $a2
    ctx->pc = 0x108a90u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 19), GPR_U32(ctx, 6) & 0x1F));
    // 0x108a94: 0x671806  srlv        $v1, $a3, $v1
    ctx->pc = 0x108a94u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 7), GPR_U32(ctx, 3) & 0x1F));
    // 0x108a98: 0x3c053ff0  lui         $a1, 0x3FF0
    ctx->pc = 0x108a98u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)16368 << 16));
    // 0x108a9c: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x108a9cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x108aa0: 0x292182b  sltu        $v1, $s4, $s2
    ctx->pc = 0x108aa0u;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 20) < (uint64_t)GPR_U64(ctx, 18)) ? 1 : 0);
    // 0x108aa4: 0x3c04ffff  lui         $a0, 0xFFFF
    ctx->pc = 0x108aa4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)65535 << 16));
    // 0x108aa8: 0x4203e  dsrl32      $a0, $a0, 0
    ctx->pc = 0x108aa8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) >> (32 + 0));
    // 0x108aac: 0x451025  or          $v0, $v0, $a1
    ctx->pc = 0x108aacu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 5));
    // 0x108ab0: 0x2248824  and         $s1, $s1, $a0
    ctx->pc = 0x108ab0u;
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 17) & GPR_U64(ctx, 4));
    // 0x108ab4: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x108ab4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x108ab8: 0x2228825  or          $s1, $s1, $v0
    ctx->pc = 0x108ab8u;
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 17) | GPR_U64(ctx, 2));
    // 0x108abc: 0x10600002  beqz        $v1, . + 4 + (0x2 << 2)
    ctx->pc = 0x108ABCu;
    {
        const bool branch_taken_0x108abc = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x108AC0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x108ABCu;
            // 0x108ac0: 0x982d  daddu       $s3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x108abc) {
            ctx->pc = 0x108AC8u;
            goto label_108ac8;
        }
    }
    ctx->pc = 0x108AC4u;
    // 0x108ac4: 0x8e53fffc  lw          $s3, -0x4($s2)
    ctx->pc = 0x108ac4u;
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 4294967292)));
label_108ac8:
    // 0x108ac8: 0x61023  negu        $v0, $a2
    ctx->pc = 0x108ac8u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 0), GPR_U32(ctx, 6)));
    // 0x108acc: 0xc71804  sllv        $v1, $a3, $a2
    ctx->pc = 0x108accu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 7), GPR_U32(ctx, 6) & 0x1F));
    // 0x108ad0: 0x531006  srlv        $v0, $s3, $v0
    ctx->pc = 0x108ad0u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 19), GPR_U32(ctx, 2) & 0x1F));
    // 0x108ad4: 0x2404ffff  addiu       $a0, $zero, -0x1
    ctx->pc = 0x108ad4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x108ad8: 0x4203c  dsll32      $a0, $a0, 0
    ctx->pc = 0x108ad8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) << (32 + 0));
    // 0x108adc: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x108adcu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x108ae0: 0x2248824  and         $s1, $s1, $a0
    ctx->pc = 0x108ae0u;
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 17) & GPR_U64(ctx, 4));
    // 0x108ae4: 0x3183c  dsll32      $v1, $v1, 0
    ctx->pc = 0x108ae4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 0));
    // 0x108ae8: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x108AE8u;
    {
        const bool branch_taken_0x108ae8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x108AECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x108AE8u;
            // 0x108aec: 0x3183e  dsrl32      $v1, $v1, 0 (Delay Slot)
        SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) >> (32 + 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x108ae8) {
            ctx->pc = 0x108B20u;
            goto label_108b20;
        }
    }
    ctx->pc = 0x108AF0u;
label_108af0:
    // 0x108af0: 0x3c023ff0  lui         $v0, 0x3FF0
    ctx->pc = 0x108af0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16368 << 16));
    // 0x108af4: 0x3c03ffff  lui         $v1, 0xFFFF
    ctx->pc = 0x108af4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)65535 << 16));
    // 0x108af8: 0x3183e  dsrl32      $v1, $v1, 0
    ctx->pc = 0x108af8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) >> (32 + 0));
    // 0x108afc: 0x2621025  or          $v0, $s3, $v0
    ctx->pc = 0x108afcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 19) | GPR_U64(ctx, 2));
    // 0x108b00: 0x2238824  and         $s1, $s1, $v1
    ctx->pc = 0x108b00u;
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 17) & GPR_U64(ctx, 3));
    // 0x108b04: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x108b04u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x108b08: 0x2404ffff  addiu       $a0, $zero, -0x1
    ctx->pc = 0x108b08u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x108b0c: 0x4203c  dsll32      $a0, $a0, 0
    ctx->pc = 0x108b0cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) << (32 + 0));
    // 0x108b10: 0x7183c  dsll32      $v1, $a3, 0
    ctx->pc = 0x108b10u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 7) << (32 + 0));
    // 0x108b14: 0x2228825  or          $s1, $s1, $v0
    ctx->pc = 0x108b14u;
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 17) | GPR_U64(ctx, 2));
    // 0x108b18: 0x3183e  dsrl32      $v1, $v1, 0
    ctx->pc = 0x108b18u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) >> (32 + 0));
    // 0x108b1c: 0x2248824  and         $s1, $s1, $a0
    ctx->pc = 0x108b1cu;
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 17) & GPR_U64(ctx, 4));
label_108b20:
    // 0x108b20: 0x2238825  or          $s1, $s1, $v1
    ctx->pc = 0x108b20u;
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 17) | GPR_U64(ctx, 3));
    // 0x108b24: 0x220102d  daddu       $v0, $s1, $zero
    ctx->pc = 0x108b24u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x108b28: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x108b28u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x108b2c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x108b2cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x108b30: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x108b30u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x108b34: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x108b34u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x108b38: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x108b38u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x108b3c: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x108b3cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x108b40: 0x3e00008  jr          $ra
    ctx->pc = 0x108B40u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x108B44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x108B40u;
            // 0x108b44: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1089F0u: goto label_1089f0;
            case 0x108A40u: goto label_108a40;
            case 0x108A70u: goto label_108a70;
            case 0x108A84u: goto label_108a84;
            case 0x108AC8u: goto label_108ac8;
            case 0x108AF0u: goto label_108af0;
            case 0x108B20u: goto label_108b20;
            default: break;
        }
        return;
    }
    ctx->pc = 0x108B48u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
