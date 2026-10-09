#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0016BE38
// Address: 0x16be38 - 0x16bf80
void sub_0016BE38_0x16be38(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0016BE38_0x16be38");
#endif

    switch (ctx->pc) {
        case 0x16bef8u: goto label_16bef8;
        case 0x16bf40u: goto label_16bf40;
        default: break;
    }

    ctx->pc = 0x16be38u;

    // 0x16be38: 0x24a2000f  addiu       $v0, $a1, 0xF
    ctx->pc = 0x16be38u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), 15));
    // 0x16be3c: 0x24a5001e  addiu       $a1, $a1, 0x1E
    ctx->pc = 0x16be3cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 30));
    // 0x16be40: 0x28430000  slti        $v1, $v0, 0x0
    ctx->pc = 0x16be40u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x16be44: 0x24ca000f  addiu       $t2, $a2, 0xF
    ctx->pc = 0x16be44u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 6), 15));
    // 0x16be48: 0xa3100b  movn        $v0, $a1, $v1
    ctx->pc = 0x16be48u;
    if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 5));
    // 0x16be4c: 0x294b0000  slti        $t3, $t2, 0x0
    ctx->pc = 0x16be4cu;
    SET_GPR_U64(ctx, 11, ((int64_t)GPR_S64(ctx, 10) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x16be50: 0x21103  sra         $v0, $v0, 4
    ctx->pc = 0x16be50u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 4));
    // 0x16be54: 0x24c6001e  addiu       $a2, $a2, 0x1E
    ctx->pc = 0x16be54u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 30));
    // 0x16be58: 0x22900  sll         $a1, $v0, 4
    ctx->pc = 0x16be58u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x16be5c: 0x210c0  sll         $v0, $v0, 3
    ctx->pc = 0x16be5cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0x16be60: 0x24a8003f  addiu       $t0, $a1, 0x3F
    ctx->pc = 0x16be60u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 5), 63));
    // 0x16be64: 0x24a5007e  addiu       $a1, $a1, 0x7E
    ctx->pc = 0x16be64u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 126));
    // 0x16be68: 0x2449003f  addiu       $t1, $v0, 0x3F
    ctx->pc = 0x16be68u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 2), 63));
    // 0x16be6c: 0x2442007e  addiu       $v0, $v0, 0x7E
    ctx->pc = 0x16be6cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 126));
    // 0x16be70: 0x29030000  slti        $v1, $t0, 0x0
    ctx->pc = 0x16be70u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 8) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x16be74: 0xcb500b  movn        $t2, $a2, $t3
    ctx->pc = 0x16be74u;
    if (GPR_U64(ctx, 11) != 0) SET_GPR_VEC(ctx, 10, GPR_VEC(ctx, 6));
    // 0x16be78: 0xa3400b  movn        $t0, $a1, $v1
    ctx->pc = 0x16be78u;
    if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 8, GPR_VEC(ctx, 5));
    // 0x16be7c: 0x29230000  slti        $v1, $t1, 0x0
    ctx->pc = 0x16be7cu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 9) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x16be80: 0x43480b  movn        $t1, $v0, $v1
    ctx->pc = 0x16be80u;
    if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 9, GPR_VEC(ctx, 2));
    // 0x16be84: 0x84183  sra         $t0, $t0, 6
    ctx->pc = 0x16be84u;
    SET_GPR_S32(ctx, 8, SRA32(GPR_S32(ctx, 8), 6));
    // 0x16be88: 0xa5103  sra         $t2, $t2, 4
    ctx->pc = 0x16be88u;
    SET_GPR_S32(ctx, 10, SRA32(GPR_S32(ctx, 10), 4));
    // 0x16be8c: 0x94983  sra         $t1, $t1, 6
    ctx->pc = 0x16be8cu;
    SET_GPR_S32(ctx, 9, SRA32(GPR_S32(ctx, 9), 6));
    // 0x16be90: 0x10a1018  mult        $v0, $t0, $t2
    ctx->pc = 0x16be90u;
    { int64_t result = (int64_t)GPR_S32(ctx, 8) * (int64_t)GPR_S32(ctx, 10); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)result); }
    // 0x16be94: 0x712a5018  mult1       $t2, $t1, $t2
    ctx->pc = 0x16be94u;
    { int64_t result = (int64_t)GPR_S32(ctx, 9) * (int64_t)GPR_S32(ctx, 10); ctx->lo1 = (uint64_t)(int64_t)(int32_t)result; ctx->hi1 = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 10, (int32_t)result); }
    // 0x16be98: 0x84180  sll         $t0, $t0, 6
    ctx->pc = 0x16be98u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 6));
    // 0x16be9c: 0x94980  sll         $t1, $t1, 6
    ctx->pc = 0x16be9cu;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 6));
    // 0x16bea0: 0xa4e8000e  sh          $t0, 0xE($a3)
    ctx->pc = 0x16bea0u;
    WRITE16(ADD32(GPR_U32(ctx, 7), 14), (uint16_t)GPR_U32(ctx, 8));
    // 0x16bea4: 0xa4e9000c  sh          $t1, 0xC($a3)
    ctx->pc = 0x16bea4u;
    WRITE16(ADD32(GPR_U32(ctx, 7), 12), (uint16_t)GPR_U32(ctx, 9));
    // 0x16bea8: 0x21280  sll         $v0, $v0, 10
    ctx->pc = 0x16bea8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 10));
    // 0x16beac: 0xa5240  sll         $t2, $t2, 9
    ctx->pc = 0x16beacu;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 9));
    // 0x16beb0: 0x821021  addu        $v0, $a0, $v0
    ctx->pc = 0x16beb0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x16beb4: 0xace40008  sw          $a0, 0x8($a3)
    ctx->pc = 0x16beb4u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 8), GPR_U32(ctx, 4));
    // 0x16beb8: 0x4a5021  addu        $t2, $v0, $t2
    ctx->pc = 0x16beb8u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 10)));
    // 0x16bebc: 0xace20000  sw          $v0, 0x0($a3)
    ctx->pc = 0x16bebcu;
    WRITE32(ADD32(GPR_U32(ctx, 7), 0), GPR_U32(ctx, 2));
    // 0x16bec0: 0x3e00008  jr          $ra
    ctx->pc = 0x16BEC0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16BEC4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16BEC0u;
            // 0x16bec4: 0xacea0004  sw          $t2, 0x4($a3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 7), 4), GPR_U32(ctx, 10));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16BEF8u: goto label_16bef8;
            case 0x16BF20u: goto label_16bf20;
            case 0x16BF28u: goto label_16bf28;
            case 0x16BF40u: goto label_16bf40;
            case 0x16BF68u: goto label_16bf68;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16BEC8u;
    // 0x16bec8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x16bec8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x16becc: 0x182d  daddu       $v1, $zero, $zero
    ctx->pc = 0x16beccu;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16bed0: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x16bed0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x16bed4: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x16bed4u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16bed8: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x16bed8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x16bedc: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x16bedcu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16bee0: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x16bee0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x16bee4: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x16bee4u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16bee8: 0x1200000f  beqz        $s0, . + 4 + (0xF << 2)
    ctx->pc = 0x16BEE8u;
    {
        const bool branch_taken_0x16bee8 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x16BEECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16BEE8u;
            // 0x16beec: 0xffbf0018  sd          $ra, 0x18($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16bee8) {
            ctx->pc = 0x16BF28u;
            goto label_16bf28;
        }
    }
    ctx->pc = 0x16BEF0u;
    // 0x16bef0: 0xc05a78c  jal         func_169E30
    ctx->pc = 0x16BEF0u;
    SET_GPR_U32(ctx, 31, 0x16BEF8u);
    ctx->pc = 0x169E30u;
    if (runtime->hasFunction(0x169E30u)) {
        auto targetFn = runtime->lookupFunction(0x169E30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16BEF8u; }
        if (ctx->pc != 0x16BEF8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169E30_0x169e30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16BEF8u; }
        if (ctx->pc != 0x16BEF8u) { return; }
    }
    ctx->pc = 0x16BEF8u;
label_16bef8:
    // 0x16bef8: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x16bef8u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x16befc: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x16BEFCu;
    {
        const bool branch_taken_0x16befc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x16BF00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16BEFCu;
            // 0x16bf00: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16befc) {
            ctx->pc = 0x16BF20u;
            goto label_16bf20;
        }
    }
    ctx->pc = 0x16BF04u;
    // 0x16bf04: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x16bf04u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16bf08: 0x34a50181  ori         $a1, $a1, 0x181
    ctx->pc = 0x16bf08u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)385);
    // 0x16bf0c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x16bf0cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16bf10: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x16bf10u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x16bf14: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x16bf14u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x16bf18: 0x805a704  j           func_169C10
    ctx->pc = 0x16BF18u;
    ctx->pc = 0x16BF1Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16BF18u;
            // 0x16bf1c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x16BF20u;
label_16bf20:
    // 0x16bf20: 0x8e021b30  lw          $v0, 0x1B30($s0)
    ctx->pc = 0x16bf20u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 6960)));
    // 0x16bf24: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x16bf24u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
label_16bf28:
    // 0x16bf28: 0x3a220005  xori        $v0, $s1, 0x5
    ctx->pc = 0x16bf28u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) ^ (uint64_t)(uint16_t)5);
    // 0x16bf2c: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x16bf2cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16bf30: 0x60202d  daddu       $a0, $v1, $zero
    ctx->pc = 0x16bf30u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16bf34: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x16bf34u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16bf38: 0xc056daa  jal         func_15B6A8
    ctx->pc = 0x16BF38u;
    SET_GPR_U32(ctx, 31, 0x16BF40u);
    ctx->pc = 0x16BF3Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16BF38u;
            // 0x16bf3c: 0x242300b  movn        $a2, $s2, $v0 (Delay Slot)
        if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 6, GPR_VEC(ctx, 18));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15B6A8u;
    if (runtime->hasFunction(0x15B6A8u)) {
        auto targetFn = runtime->lookupFunction(0x15B6A8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16BF40u; }
        if (ctx->pc != 0x16BF40u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015B6A8_0x15b6a8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16BF40u; }
        if (ctx->pc != 0x16BF40u) { return; }
    }
    ctx->pc = 0x16BF40u;
label_16bf40:
    // 0x16bf40: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x16bf40u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x16bf44: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x16BF44u;
    {
        const bool branch_taken_0x16bf44 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x16BF48u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16BF44u;
            // 0x16bf48: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16bf44) {
            ctx->pc = 0x16BF68u;
            goto label_16bf68;
        }
    }
    ctx->pc = 0x16BF4Cu;
    // 0x16bf4c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x16bf4cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16bf50: 0x34a50f12  ori         $a1, $a1, 0xF12
    ctx->pc = 0x16bf50u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)3858);
    // 0x16bf54: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x16bf54u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16bf58: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x16bf58u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x16bf5c: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x16bf5cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x16bf60: 0x805a704  j           func_169C10
    ctx->pc = 0x16BF60u;
    ctx->pc = 0x16BF64u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16BF60u;
            // 0x16bf64: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x16BF68u;
label_16bf68:
    // 0x16bf68: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x16bf68u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16bf6c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x16bf6cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16bf70: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x16bf70u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x16bf74: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x16bf74u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x16bf78: 0x3e00008  jr          $ra
    ctx->pc = 0x16BF78u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16BF7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16BF78u;
            // 0x16bf7c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16BEF8u: goto label_16bef8;
            case 0x16BF20u: goto label_16bf20;
            case 0x16BF28u: goto label_16bf28;
            case 0x16BF40u: goto label_16bf40;
            case 0x16BF68u: goto label_16bf68;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16BF80u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
